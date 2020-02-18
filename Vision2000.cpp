// SystemTray.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Vision2000.h"

#include "MainFrm.h"
#include "ControlSheet.h"

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
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
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
	ON_COMMAND(ID_CALL_HANGUP, OnCallHangup)
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
	AfxOleInit();

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

void CSystemTrayApp::OnCallHangup() 
{
	// If not in a call, then call szMachineName, otherwise hang up.
	if (!m_pConf->InConnection()) 
	{
		CString strMachineName("tester");
		//GetDlgItemText(IDC_MACHINENAME,strMachineName);
		if( !strMachineName.IsEmpty() )
			m_pConf->Call((LPTSTR)(LPCTSTR)strMachineName);
		else
			AfxMessageBox("Enter a machine name first!", MB_OK);
	}
	else
		m_pConf->HangUp();
}


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
	
	return CWinApp::ExitInstance();
}



Conf* CSystemTrayApp::GetConference()
{
	return m_pConf;
}

