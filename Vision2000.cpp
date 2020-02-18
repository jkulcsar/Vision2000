// SystemTray.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Vision2000.h"

#include "MainFrm.h"
#include "ControlSheet.h"
#include <initguid.h>
#include <afxpriv.h>
#include "Vision2000_i.c"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
	m_hIcon = NULL;
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_WEBSITE, m_website);
	DDX_Control(pDX, IDC_EMAIL, m_email);
	//}}AFX_DATA_MAP
}


BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CStatic*	pstIcon;

	pstIcon = (CStatic*) GetDlgItem(IDC_STATIC_ICON);
	m_hIcon = (HICON) LoadImage( AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_VISION2000), 
						IMAGE_ICON, 89, 65, LR_DEFAULTCOLOR  );
	pstIcon->SetIcon(m_hIcon);


	// set up the hyperlinks
	m_email.SetURL("mailto:support@snettech.com");
	m_email.SetUnderline(FALSE);
	m_website.SetURL("www.snettech.com");
	m_website.SetUnderline(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog

void CSystemTrayApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CSystemTrayApp

BEGIN_MESSAGE_MAP(CSystemTrayApp, CWinApp)
	//{{AFX_MSG_MAP(CSystemTrayApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemTrayApp construction

CSystemTrayApp::CSystemTrayApp()
{
	m_pConf = NULL;
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSystemTrayApp object
CSystemTrayApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSystemTrayApp initialization

BOOL CSystemTrayApp::InitInstance()
{

	if (!InitATL())
		return FALSE;

    //Initialize ATL control containment code.
    AtlAxWinInit();


// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

	// for COM support
	// AfxOleInit();

	// Initialize the conference object
	m_pConf=new Conf(m_pMainWnd->GetSafeHwnd());

	if (FAILED(m_pConf->Initialize()))
	{
		AfxMessageBox("NetMeeting may not be installed");
		return -1;	// destroy window; can not continue
	}


	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSystemTrayApp commands

int CSystemTrayApp::ExitInstance() 
{
	// Hangup if in a call
	if (m_pConf->InConnection())
		m_pConf->HangUp();

	m_pConf->Uninitialize();
	if(m_pConf != NULL)
	{
		delete m_pConf;
		m_pConf = NULL;
	}

	if (m_bATLInited)
	{
		_Module.RevokeClassObjects();
		_Module.Term();
		CoUninitialize();
	}

	return CWinApp::ExitInstance();
}



Conf* CSystemTrayApp::GetConference()
{
	return m_pConf;
}


/////////////////////////////////////////////////////////////////////
// CVision2000Module object

CVision2000Module _Module;

BEGIN_OBJECT_MAP(ObjectMap)
END_OBJECT_MAP()

LONG CVision2000Module::Unlock()
{
	AfxOleUnlockApp();
	return 0;
}

LONG CVision2000Module::Lock()
{
	AfxOleLockApp();
	return 1;
}

LPCTSTR CVision2000Module::FindOneOf(LPCTSTR p1, LPCTSTR p2)
{
	while (*p1 != NULL)
	{
		LPCTSTR p = p2;
		while (*p != NULL)
		{
			if (*p1 == *p)
				return CharNext(p1);
			p = CharNext(p);
		}
		p1++;
	}
	return NULL;
}


BOOL CSystemTrayApp::InitATL()
{
	m_bATLInited = TRUE;

#if _WIN32_WINNT >= 0x0400
	HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);
#else
	HRESULT hRes = CoInitialize(NULL);
#endif

	if (FAILED(hRes))
	{
		m_bATLInited = FALSE;
		return FALSE;
	}

	_Module.Init(ObjectMap, AfxGetInstanceHandle());
	_Module.dwThreadID = GetCurrentThreadId();

	LPTSTR lpCmdLine = GetCommandLine(); //this line necessary for _ATL_MIN_CRT
	TCHAR szTokens[] = _T("-/");

	BOOL bRun = TRUE;
	LPCTSTR lpszToken = _Module.FindOneOf(lpCmdLine, szTokens);
	while (lpszToken != NULL)
	{
		if (lstrcmpi(lpszToken, _T("UnregServer"))==0)
		{
			_Module.UpdateRegistryFromResource(IDR_VISION2000, FALSE);
			_Module.UnregisterServer(TRUE); //TRUE means typelib is unreg'd
			bRun = FALSE;
			break;
		}
		if (lstrcmpi(lpszToken, _T("RegServer"))==0)
		{
			_Module.UpdateRegistryFromResource(IDR_VISION2000, TRUE);
			_Module.RegisterServer(TRUE);
			bRun = FALSE;
			break;
		}
		lpszToken = _Module.FindOneOf(lpszToken, szTokens);
	}

	if (!bRun)
	{
		m_bATLInited = FALSE;
		_Module.Term();
		CoUninitialize();
		return FALSE;
	}

	hRes = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, 
		REGCLS_MULTIPLEUSE);
	if (FAILED(hRes))
	{
		m_bATLInited = FALSE;
		CoUninitialize();
		return FALSE;
	}	

	return TRUE;
}



BOOL CSystemTrayApp::OnIdle(LONG lCount) 
{
	if( m_pMainWnd != NULL )
		::SendMessage( m_pMainWnd->GetSafeHwnd(), WM_IDLEUPDATECMDUI, 0, 0 );
	
	return CWinApp::OnIdle(lCount);
}
