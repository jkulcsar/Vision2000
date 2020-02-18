// SystemSettingsPage.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "SystemSettingsPage.h"

#include "SetupVCRWizardSheet.h"

#include <afxpriv.h>

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
	DDX_Control(pDX, IDC_COMBO_HOUSE_CODE, m_cbHouseCode);
	DDX_Control(pDX, IDC_COMBO_COM_PORT, m_cbCOMPort);
	DDX_Control(pDX, IDC_COMBO_CAMERA_FROM, m_cbDeviceCodeBase);
	DDX_Control(pDX, IDC_LOCAL_MODE, m_ctlLocalMode);
	DDX_Control(pDX, IDC_WIRELESS_MODE, m_ctlWirelessMode);
	DDX_Control(pDX, IDC_WIRED_MODE, m_ctlWiredMode);
	DDX_Control(pDX, IDC_X10_MODE, m_ctlX10Mode);
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
	ON_BN_CLICKED(IDC_WIRELESS_MODE, OnWirelessMode)
	ON_BN_CLICKED(IDC_WIRED_MODE, OnWiredMode)
	ON_BN_CLICKED(IDC_X10_MODE, OnX10Mode)
	ON_BN_CLICKED(IDC_IR_WIZARD, OnIRWizard)
	ON_CBN_SELENDOK(IDC_COMBO_CAMERA_FROM, OnSelendokComboCameraFrom)
	ON_CBN_SELENDOK(IDC_COMBO_COM_PORT, OnSelendokComboComPort)
	ON_CBN_SELENDOK(IDC_COMBO_HOUSE_CODE, OnSelendokComboHouseCode)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
	ON_UPDATE_COMMAND_UI( IDC_LOCAL_MODE, OnUpdateLocalMode )

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemSettingsPage message handlers

void CSystemSettingsPage::OnTestPort() 
{
	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();
	if( pPP != NULL )
	{
		if( pPP->TestPort() )
			AfxMessageBox("Test passed!");
		else
			AfxMessageBox("Test failed!");
	}
	else
		AfxMessageBox("There is no valid parallel port set up!");
}

BOOL CSystemSettingsPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	CX10Settings*	pX10Settings	=	m_pSystemSettings->GetX10Settings();

	CString strBuffer;

	// init the X10 setting controls
	strBuffer.Format( "%c", pX10Settings->GetHouseCode() );
	m_cbHouseCode.SelectString(0, strBuffer );

	strBuffer.Format( "%d", pX10Settings->GetCOMPort() );
	m_cbCOMPort.SelectString(0, strBuffer);

	strBuffer.Format( "%d", pX10Settings->GetDeviceCodeBase() );
	m_cbDeviceCodeBase.SelectString(0, strBuffer);


	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();

	// init the MODE_ radios

	if( m_pSystemSettings->InLocalMode() )
		m_ctlLocalMode.SetCheck(TRUE);
	else
		m_ctlLocalMode.SetCheck(FALSE);

	if( m_pSystemSettings->GetMode() == MODE_WIRED )
		m_ctlWiredMode.SetCheck(TRUE);
	else
		m_ctlWiredMode.SetCheck(FALSE);

	if( m_pSystemSettings->GetMode() == MODE_WIRELESS )
		m_ctlWirelessMode.SetCheck(TRUE);
	else
		m_ctlWirelessMode.SetCheck(FALSE);

	if( m_pSystemSettings->GetMode() == MODE_X10 )
		m_ctlX10Mode.SetCheck(TRUE);
	else
		m_ctlX10Mode.SetCheck(FALSE);


	// check if we have a PP first
	if( pPP != NULL )
	{
		if( !strcmp( pPP->GetName(), "LPT1" ) && pPP->IsEnabled() )
			CheckLPT1();

		if( !strcmp( pPP->GetName(), "LPT2" ) && pPP->IsEnabled() )
			CheckLPT2();

		if( !strcmp( pPP->GetName(), "LPT3" ) && pPP->IsEnabled() )
			CheckLPT3();	
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSystemSettingsPage::OnRadioLPT1() 
{
	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();

	if( pPP != NULL )
	{
		if( !pPP->InitializeAt(LPT1) )
			UnCheckAll();
		else
		{
			pPP->SetName("LPT1");
			CheckLPT1();
		}
	}
	else
		UnCheckAll();
}

void CSystemSettingsPage::OnRadioLPT2() 
{
	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();

	if( pPP != NULL )
	{
		if( !pPP->InitializeAt(LPT2) )
			UnCheckAll();
		else
		{
			pPP->SetName("LPT2");
			CheckLPT2();
		}
	}
	else
		UnCheckAll();
}

void CSystemSettingsPage::OnRadioLPT3() 
{
	CCOMParallelPort* pPP = m_pSystemSettings->GetParallelPort();

	if( pPP != NULL )
	{
		if( !pPP->InitializeAt(LPT3) )
			UnCheckAll();
		else
		{
			pPP->SetName("LPT3");
			CheckLPT3();
		}
	}
	else
		UnCheckAll();
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


void CSystemSettingsPage::OnWirelessMode() 
{
	if( m_ctlWirelessMode.GetCheck() )
		m_pSystemSettings->SetMode( MODE_WIRELESS );
}


void CSystemSettingsPage::OnWiredMode() 
{
	if( m_ctlWiredMode.GetCheck() )
		m_pSystemSettings->SetMode( MODE_WIRED );
}


void CSystemSettingsPage::OnX10Mode() 
{
	if( m_ctlX10Mode.GetCheck() )
		m_pSystemSettings->SetMode( MODE_X10 );

	CControlCM*		pCM				=	m_pSystemSettings->GetX10ControlModule();
	CX10Settings*	pX10Settings	=	m_pSystemSettings->GetX10Settings();

	// check if X10 CM not null and if it's not window
	// if it's window, it was already created!
	if( (pCM != NULL) && !::IsWindow( pCM->GetSafeHwnd() ) )
	{
		// create and init X10 control
		RECT rect;
		rect.top	=	100;
		rect.bottom	=	0;
		rect.left	=	0;
		rect.right	=	100;

		BOOL bResult;
		if( pCM != NULL )
		{
			bResult = pCM->Create(	_T("X10"),
										NULL,
										rect,
										this,  // this should be the MAINFRAME!!!
										6699
									);
			if( bResult == 0 )	// create failed
			{
				// destroy the object;
				// no point to exist if create failed (ActiveX control not installed!)
				if( pCM != NULL )
				{
					delete pCM;
					pCM= NULL;
				}
			}
		}

		if( pCM != NULL )
		{
			pCM->SetComport( pX10Settings->GetCOMPort() );
			short shInitResult = pCM->Init();
			if( shInitResult != FALSE )
			{
				// init of X10 module failed!
				m_pSystemSettings->SetMode( MODE_NONE );
				m_ctlX10Mode.SetCheck( BST_UNCHECKED );
			}
		}
	}
}

LRESULT CSystemSettingsPage::OnKickIdle(WPARAM, LPARAM)
{
	UpdateDialogControls( this, FALSE );
	return 0;
}

///////////////////////////////////////////////////////////////////////////////
// CSystemSettingsPage::OnUpdate???? functions

void CSystemSettingsPage::OnUpdateLocalMode( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->SetCheck( TRUE );
	else
		pCmdUI->SetCheck( FALSE );
}



void CSystemSettingsPage::OnIRWizard() 
{
	CSetupVCRWizardSheet propSheet;

	propSheet.DoModal();

	// This is where you would retrieve information from the property
	// sheet if propSheet.DoModal() returned IDOK.  We aren't doing
	// anything for simplicity.
}

void CSystemSettingsPage::OnSelendokComboCameraFrom() 
{
	CX10Settings*	pX10Settings	=	m_pSystemSettings->GetX10Settings();
	UINT			uiSel;
	int				nIndex;
	CString			strSel;

	nIndex	= m_cbDeviceCodeBase.GetCurSel();
	m_cbDeviceCodeBase.GetLBText( nIndex, strSel );
	uiSel = (UINT) ::atoi( (LPCTSTR) strSel );

	if( pX10Settings != NULL )
		pX10Settings->SetDeviceCodeBase( uiSel );
}

void CSystemSettingsPage::OnSelendokComboComPort() 
{
	CX10Settings*	pX10Settings	=	m_pSystemSettings->GetX10Settings();
	UINT			uiSel;
	int				nIndex;
	CString			strSel;

	nIndex	= m_cbCOMPort.GetCurSel();
	m_cbCOMPort.GetLBText( nIndex, strSel );
	uiSel = (UINT) ::atoi( (LPCTSTR) strSel );

	if( pX10Settings != NULL )
		pX10Settings->SetCOMPort( uiSel );
}

void CSystemSettingsPage::OnSelendokComboHouseCode() 
{
	CX10Settings*	pX10Settings	=	m_pSystemSettings->GetX10Settings();
	CHAR			chSel;
	int				nIndex;
	CString			strSel;

	nIndex	= m_cbHouseCode.GetCurSel();
	m_cbHouseCode.GetLBText( nIndex, strSel );
	if( !strSel.IsEmpty() )
	{
		chSel = (CHAR) strSel.GetAt( 0 );

		if( pX10Settings != NULL )
			pX10Settings->SetHouseCode( chSel );
	}
}
