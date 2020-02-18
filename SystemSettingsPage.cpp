// SystemSettingsPage.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "SystemSettingsPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSystemSettingsPage property page

IMPLEMENT_DYNCREATE(CSystemSettingsPage, CPropertyPage)

CSystemSettingsPage::CSystemSettingsPage() : CPropertyPage(CSystemSettingsPage::IDD, IDS_TAB_SETTINGS)
{
	//{{AFX_DATA_INIT(CSystemSettingsPage)
	//}}AFX_DATA_INIT

	// init local copy of system settings object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pSystemSettings = pApp->GetSystemSettings();
}

CSystemSettingsPage::~CSystemSettingsPage()
{
	m_pSystemSettings = NULL;	// do not deallocate ! It will be deleted in CWinApp object !
}

void CSystemSettingsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSystemSettingsPage)
	DDX_Control(pDX, IDC_LOCAL_MODE, m_ctlLocalMode);
	DDX_Control(pDX, IDC_TEST_PORT, m_ctlTestPort);
	DDX_Control(pDX, IDC_RADIO_LPT1, m_ctlRadioButtonLPT1);
	DDX_Control(pDX, IDC_RADIO_LPT2, m_ctlRadioButtonLPT2);
	DDX_Control(pDX, IDC_RADIO_LPT3, m_ctlRadioButtonLPT3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSystemSettingsPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSystemSettingsPage)
	ON_BN_CLICKED(IDC_TEST_PORT, OnTestPort)
	ON_BN_CLICKED(IDC_RADIO_LPT1, OnRadioLPT1)
	ON_BN_CLICKED(IDC_RADIO_LPT2, OnRadioLPT2)
	ON_BN_CLICKED(IDC_RADIO_LPT3, OnRadioLPT3)
	ON_BN_CLICKED(IDC_LOCAL_MODE, OnLocalMode)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemSettingsPage message handlers

void CSystemSettingsPage::OnTestPort() 
{
	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();
	if( pPP->TestPort() )
		AfxMessageBox("Test passed!");
	else
		AfxMessageBox("Test failed!");
}

BOOL CSystemSettingsPage::OnInitDialog() 
{
	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();

	CPropertyPage::OnInitDialog();

	if( m_pSystemSettings->InLocalMode() )
		m_ctlLocalMode.SetCheck(TRUE);
	else
		m_ctlLocalMode.SetCheck(FALSE);

	if( !strcmp( pPP->GetName(), "LPT1" ) && pPP->IsEnabled() )
		CheckLPT1();

	if( !strcmp( pPP->GetName(), "LPT2" ) && pPP->IsEnabled() )
		CheckLPT2();

	if( !strcmp( pPP->GetName(), "LPT3" ) && pPP->IsEnabled() )
		CheckLPT3();	

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSystemSettingsPage::OnRadioLPT1() 
{
	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();

	if( !pPP->InitializeAt(LPT1) )
		UnCheckAll();
	else
	{
		pPP->SetName("LPT1");
		CheckLPT1();
	}
}

void CSystemSettingsPage::OnRadioLPT2() 
{
	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();

	if( !pPP->InitializeAt(LPT2) )
		UnCheckAll();
	else
	{
		pPP->SetName("LPT2");
		CheckLPT2();
	}
}

void CSystemSettingsPage::OnRadioLPT3() 
{
	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();

	if( !pPP->InitializeAt(LPT3) )
		UnCheckAll();
	else
	{
		pPP->SetName("LPT3");
		CheckLPT3();
	}
}


void CSystemSettingsPage::UnCheckAll()
{
	m_ctlRadioButtonLPT1.SetCheck( BST_UNCHECKED );
	m_ctlRadioButtonLPT2.SetCheck( BST_UNCHECKED );
	m_ctlRadioButtonLPT3.SetCheck( BST_UNCHECKED );
}

void CSystemSettingsPage::CheckLPT1()
{
	m_ctlRadioButtonLPT1.SetCheck( BST_CHECKED );
	m_ctlRadioButtonLPT2.SetCheck( BST_UNCHECKED );
	m_ctlRadioButtonLPT3.SetCheck( BST_UNCHECKED );
}

void CSystemSettingsPage::CheckLPT2()
{
	m_ctlRadioButtonLPT1.SetCheck( BST_UNCHECKED );
	m_ctlRadioButtonLPT2.SetCheck( BST_CHECKED );
	m_ctlRadioButtonLPT3.SetCheck( BST_UNCHECKED );
}

void CSystemSettingsPage::CheckLPT3()
{
	m_ctlRadioButtonLPT1.SetCheck( BST_UNCHECKED );
	m_ctlRadioButtonLPT2.SetCheck( BST_UNCHECKED );
	m_ctlRadioButtonLPT3.SetCheck( BST_CHECKED );
}

void CSystemSettingsPage::OnLocalMode() 
{
	if( m_ctlLocalMode.GetCheck() )
		m_pSystemSettings->SetLocalMode( TRUE );
	else
		m_pSystemSettings->SetLocalMode( FALSE );
}
