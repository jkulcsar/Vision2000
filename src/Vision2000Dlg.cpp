// Vision2000Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Vision2000.h"
#include "Vision2000Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#define MAX_SZ 256

/////////////////////////////////////////////////////////////////////////////
// CVision2000Dlg dialog

CVision2000Dlg::CVision2000Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVision2000Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVision2000Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	// initialize private members
	pConf = NULL;
}

void CVision2000Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVision2000Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CVision2000Dlg, CDialog)
	//{{AFX_MSG_MAP(CVision2000Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CALLHANGUP, OnCallhangup)
	ON_BN_CLICKED(IDC_OPEN_DATA, OnOpenData)
	ON_BN_CLICKED(IDC_CAMERA_1, OnCamera1)
	ON_BN_CLICKED(IDC_CAMERA_2, OnCamera2)
	ON_BN_CLICKED(IDC_CAMERA_3, OnCamera3)
	ON_BN_CLICKED(IDC_CAMERA_4, OnCamera4)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_DISCONNECTED, OnDisconnected)
	ON_MESSAGE(WM_CONNECTING, OnConnect)
	ON_MESSAGE(WM_CONNECTED, OnConnect)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVision2000Dlg message handlers

BOOL CVision2000Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// Initialize the conference object
	pConf=new Conf(m_hWnd);

	if (FAILED(pConf->Initialize()))
	{
		AfxMessageBox("NetMeeting may not be installed");
		EndDialog(FALSE);
		return FALSE;
	}

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CVision2000Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVision2000Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CVision2000Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CVision2000Dlg::OnClose() 
{
	// Hangup if in a call
	if (pConf->InConnection())
		pConf->HangUp();

	pConf->Uninitialize();
	delete pConf;
//	EndDialog(hWnd,0);

	CDialog::OnClose();
}


LONG CVision2000Dlg::OnConnect(WPARAM wParam, LPARAM lParam)
{
	SetDlgItemText(IDC_CALLHANGUP,"H&ang Up");
	return 0;
}


LONG CVision2000Dlg::OnDisconnected(WPARAM wParam, LPARAM lParam)
{
	SetDlgItemText(IDC_CALLHANGUP,"C&all");
	return 0;
}

void CVision2000Dlg::OnCallhangup() 
{
	// If not in a call, then call szMachineName, otherwise hang up.
	if (!pConf->InConnection()) 
	{
		CString strMachineName;
		GetDlgItemText(IDC_MACHINENAME,strMachineName);
		if( !strMachineName.IsEmpty() )
			pConf->Call((LPTSTR)(LPCTSTR)strMachineName);
		else
			AfxMessageBox("Enter a machine name first!", MB_OK);
	}
}

void CVision2000Dlg::OnOpenData() 
{
	if (pConf->InConnection()) 
	{
		if( pConf->CreateDataChannel() == S_OK )
			AfxMessageBox("Data channel opened successfully!", MB_OK);
		else
			AfxMessageBox("Data channel NOT opened!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}


void CVision2000Dlg::OnCamera1() 
{
	if (pConf->InConnection()) 
	{
		if( pConf->SendText("CAMERA1") == S_OK )
			AfxMessageBox("CAMERA1 selected", MB_OK);
		else
			AfxMessageBox("Text NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVision2000Dlg::OnCamera2() 
{
	if (pConf->InConnection()) 
	{
		if( pConf->SendText("CAMERA2") == S_OK )
			AfxMessageBox("CAMERA2 selected", MB_OK);
		else
			AfxMessageBox("Text NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVision2000Dlg::OnCamera3() 
{
	if (pConf->InConnection()) 
	{
		if( pConf->SendText("CAMERA3") == S_OK )
			AfxMessageBox("CAMERA3 selected", MB_OK);
		else
			AfxMessageBox("Text NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVision2000Dlg::OnCamera4() 
{
	if (pConf->InConnection()) 
	{
		if( pConf->SendText("CAMERA4") == S_OK )
			AfxMessageBox("CAMERA4 selected", MB_OK);
		else
			AfxMessageBox("Text NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}
