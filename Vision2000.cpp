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
	m_pConf				=	NULL;
	m_pSystemSettings	=	NULL;
	m_pPollingThread	=	NULL;
	m_bContinuePolling	=	TRUE;	// start polling as soon as the thread is started
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

	// Initialize the system settings CSystemSettings object
	m_pSystemSettings = new CSystemSettings;

	if( FAILED(m_pSystemSettings->Initialize()) )
	{
		AfxMessageBox("Failed to initialize system settings!");
		return -1;	// destroy window; can not continue
	}


	m_pControlCamera = new CControlCamera;
	m_pControlVCR = new CControlVCR;


	// Initialize the conference object
	m_pConf=new Conf(m_pMainWnd->GetSafeHwnd());

	if (FAILED(m_pConf->Initialize()))
	{
		AfxMessageBox("NetMeeting may not be installed");
		return -1;	// destroy window; can not continue
	}

	// after all the init sequence, set up the interrup polling thread
	if( m_pPollingThread == NULL )	// create the polling thread
	{
		THREADPARAMS*	pThreadParams = new THREADPARAMS;
		pThreadParams->pContinueFlag = &m_bContinuePolling;
		pThreadParams->lParam1 = (LPARAM) m_pSystemSettings;
		pThreadParams->lParam2 = (LPARAM) m_pControlCamera;
		pThreadParams->lParam3 = (LPARAM) m_pControlVCR;

		m_pPollingThread = AfxBeginThread( PollingThreadFunc, pThreadParams ) ;
	}

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSystemTrayApp commands

int CSystemTrayApp::ExitInstance() 
{
	// Before exit, save current settings
	m_pSystemSettings->Save();
	
	// Hangup if in a call
	if (m_pConf->InConnection())
		m_pConf->HangUp();

	m_pConf->Uninitialize();
	if(m_pConf != NULL)
	{
		delete m_pConf;
		m_pConf = NULL;
	}

	/////////////////////////////////////////////////////////////////////////
	// we must terminate the polling thread before destroying the CSystemSettings object
	if( m_pPollingThread != NULL )
	{
		HANDLE hThread = m_pPollingThread->m_hThread;
		m_bContinuePolling = FALSE;
		::WaitForSingleObject( hThread, INFINITE );
		m_pPollingThread = NULL;
	}

	if(m_pSystemSettings != NULL)
	{
		delete m_pSystemSettings;
		m_pSystemSettings = NULL;
	}

	if( m_pControlVCR != NULL )
	{
		delete m_pControlVCR;
		m_pControlVCR = NULL;
	}

	if( m_pControlCamera != NULL )
	{
		delete m_pControlCamera;
		m_pControlCamera = NULL;
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


CSystemSettings* CSystemTrayApp::GetSystemSettings()
{
	return m_pSystemSettings;
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


CControlCamera* CSystemTrayApp::GetControlCamera()
{
	return m_pControlCamera;
}


CControlVCR* CSystemTrayApp::GetControlVCR()
{
	return m_pControlVCR;
}


//////////////////////////////////////////////////////////////////////////////
// Polling Thread related
UINT CSystemTrayApp::PollingThreadFunc(LPVOID pParam)
{
	UINT uiCameraID;

	if( pParam != NULL )
	{
		THREADPARAMS*		pThreadParams = (THREADPARAMS*) pParam;
		BOOL*				pContinueFlag = pThreadParams->pContinueFlag;
		CSystemSettings*	pSystemSettings = (CSystemSettings*) pThreadParams->lParam1;
		CControlCamera*		pControlCamera = (CControlCamera*) pThreadParams->lParam2;
		CControlVCR*		pControlVCR = (CControlVCR*) pThreadParams->lParam3;

		delete pThreadParams;	// deallocate previously allocated memory

		while( *pContinueFlag )
		{
			// do the polling
			if( pSystemSettings != NULL )
			{
				CCOMParallelPort* pPP = pSystemSettings->GetParallelPort();
				BOOL bWireless = pSystemSettings->IsWireless();
				if( pPP->IsEnabled() )
				{
					if( bWireless )		// wireless version
					{
/*
						BYTE bStatusPort = 0; 
						BYTE bControlPort = 0;
						BYTE bInterruptMask = 0x40; //we're looking for bit 6 of the status port (S6)
						bStatusPort = pPP->ReadStatusPort();
						bControlPort = pPP->ReadControlPort();
						//if( (bStatusPort & bInterruptMask) == 0 ) // interrupt detected !
						if( ((bStatusPort  & 0x40) != 0) ||
							((bStatusPort  & 0x80) != 0) ||
							((bStatusPort  & 0x20) != 0) ||
							((bStatusPort  & 0x10) != 0) ||
							((bControlPort & 0x01) != 0) ||
							((bControlPort & 0x02) != 0) ||
							((bControlPort & 0x04) != 0) ||
							((bControlPort & 0x08) != 0)
						  )
						{
							//m_criticalSection.Lock();
							// first, find out which camera triggered the interrupt
							// check S6 if camera1
							if( (bStatusPort & 0x40) != 0 )
								uiCameraID = 1;
							// check S7 if camera2
							if( (bStatusPort & 0x80) != 0 )
								uiCameraID = 2;
							// check S5 if camera3
							if( (bStatusPort & 0x20) != 0 )
								uiCameraID = 3;
							// check S3 if camera4
							if( (bStatusPort & 0x10) != 0 )
								uiCameraID = 4;
							// check C0 if camera8
							if( (bControlPort & 0x01) != 0 )
								uiCameraID = 8;
							// check C1 if camera7
							if( (bControlPort & 0x02) != 0 )
								uiCameraID = 7;
							// check C2 if camera6
							if( (bControlPort & 0x04) != 0 )
								uiCameraID = 6;
							// check C3 if camera5
							if( (bControlPort & 0x08) != 0 )
								uiCameraID = 5;

							// in order to issue commands, we must first go in LOCAL MODE
							BOOL bOldMode = pSystemSettings->InLocalMode();
							pSystemSettings->SetLocalMode( TRUE );
							pControlCamera->Show( uiCameraID );
							pControlVCR->Rec();
							pSystemSettings->SetLocalMode( bOldMode );

							// now clear the interrupt ( D7 in the wireless case ! )
							BYTE bFlipFlopClearBit = 0x7F;
							BYTE bFlipFlopSetBit = 0xFF;
							BYTE bDataPort = pPP->ReadDataPort();

							pPP->WriteDataPort( bDataPort & bFlipFlopClearBit );
							pPP->WriteDataPort( bDataPort & bFlipFlopSetBit );

						}
*/
					}
					else				// wired version
					{
						BYTE bStatusPort = 0; 
						BYTE bInterruptMask = 0x40; //we're looking for bit 6 of the status port (S6)
						bStatusPort = pPP->ReadStatusPort();
						//if( (bStatusPort & bInterruptMask) == 0 ) // interrupt detected !
						if( ((bStatusPort & 0x08) != 0) ||
							((bStatusPort & 0x10) != 0) ||
							((bStatusPort & 0x20) != 0) ||
							((bStatusPort & 0x80) != 0)
							)
						{
							//m_criticalSection.Lock();
							// first, find out which camera triggered the interrupt
							// check S3 if camera1
							if( (bStatusPort & 0x08) != 0 )
								uiCameraID = 1;
							// check S4 if camera2
							if( (bStatusPort & 0x10) != 0 )
								uiCameraID = 2;
							// check S5 if camera3
							if( (bStatusPort & 0x20) != 0 )
								uiCameraID = 3;
							// check S7 if camera4
							if( (bStatusPort & 0x80) != 0 )
								uiCameraID = 4;



							// in order to issue commands, we must first go in LOCAL MODE
							BOOL bOldMode = pSystemSettings->InLocalMode();
							pSystemSettings->SetLocalMode( TRUE );
							pControlCamera->Show( uiCameraID );
							pControlVCR->Rec();
							pControlVCR->Rec();
							pSystemSettings->SetLocalMode( bOldMode );

							// now clear the interrupt ( C0/ in the wired version ! )
							BYTE bFlipFlopClearBit = 0xFE;
							BYTE bFlipFlopSetBit = 0xFF;
							BYTE bControlPort = pPP->ReadControlPort();

							pPP->WriteControlPort( bControlPort & bFlipFlopClearBit );
							pPP->WriteControlPort( bControlPort & bFlipFlopSetBit );
	
							//m_criticalSection.Unlock();
						}	// end of wired version
					}
				}
			}

			::Sleep( 1000 );
		}
	
		return 0;
	}
	else
		return 0; // checking...
}
