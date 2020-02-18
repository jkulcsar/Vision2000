// HomeAutomationPage.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "HomeAutomationPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHomeAutomationPage property page

IMPLEMENT_DYNCREATE(CHomeAutomationPage, CPropertyPage)

CHomeAutomationPage::CHomeAutomationPage() : CPropertyPage(CHomeAutomationPage::IDD, IDS_TAB_HOME_AUTOMATION)
{
	//{{AFX_DATA_INIT(CHomeAutomationPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// init local copy of conference object and system settings object
	CSystemTrayApp* pApp;
	pApp				= (CSystemTrayApp*) AfxGetApp();
	m_pConf				= pApp->GetConference();
	m_pSystemSettings	= pApp->GetSystemSettings();
	
	m_pX10Appliance		= pApp->GetX10Appliance();
	m_pX10Light			= pApp->GetX10Light();
}


CHomeAutomationPage::~CHomeAutomationPage()
{
}


void CHomeAutomationPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHomeAutomationPage)
	DDX_Control(pDX, IDC_COMBO_CODE_LAMP, m_cbLampCode);
	DDX_Control(pDX, IDC_COMBO_CODE_APPLIANCE, m_cbApplianceCode);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHomeAutomationPage, CPropertyPage)
	//{{AFX_MSG_MAP(CHomeAutomationPage)
	ON_BN_CLICKED(IDC_RADIO_APPLIANCE_ON, OnApplianceOn)
	ON_BN_CLICKED(IDC_RADIO_APPLIANCE_OFF, OnApplianceOff)
	ON_BN_CLICKED(IDC_RADIO_LAMP_ON, OnLampOn)
	ON_BN_CLICKED(IDC_RADIO_LAMP_OFF, OnLampOff)
	ON_BN_CLICKED(IDC_BUTTON_LAMP_DOWN, OnLampDown)
	ON_BN_CLICKED(IDC_BUTTON_LAMP_UP, OnLampUp)
	ON_CBN_SELENDOK(IDC_COMBO_CODE_APPLIANCE, OnSelendokComboCodeAppliance)
	ON_CBN_SELENDOK(IDC_COMBO_CODE_LAMP, OnSelendokComboCodeLamp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHomeAutomationPage message handlers

void CHomeAutomationPage::OnApplianceOn() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pX10Appliance->TurnApplianceON();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("APPLIANCEON");
}


void CHomeAutomationPage::OnApplianceOff() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pX10Appliance->TurnApplianceOFF();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("APPLIANCEOFF");
}


void CHomeAutomationPage::OnLampOn() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pX10Light->TurnLampON();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("LIGHTON");
}



void CHomeAutomationPage::OnLampOff() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pX10Light->TurnLampOFF();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("LIGHTOFF");
}


void CHomeAutomationPage::OnLampDown() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pX10Light->DIMM(TRUE);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("DIMM");
}


void CHomeAutomationPage::OnLampUp() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pX10Light->DIMM(FALSE);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("BRIGHTEN");
	
}

BOOL CHomeAutomationPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	CX10Settings*	pX10Settings	=	m_pSystemSettings->GetX10Settings();

	CString strBuffer;

	// init the X10 setting controls
	strBuffer.Format( "%d", pX10Settings->GetApplianceCode() );
	m_cbApplianceCode.SelectString(0, strBuffer );

	strBuffer.Format( "%d", pX10Settings->GetLampCode() );
	m_cbLampCode.SelectString(0, strBuffer);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CHomeAutomationPage::OnSelendokComboCodeAppliance() 
{
	CX10Settings*	pX10Settings	=	m_pSystemSettings->GetX10Settings();
	UINT			uiSel;
	int				nIndex;
	CString			strSel;

	nIndex	= m_cbApplianceCode.GetCurSel();
	m_cbApplianceCode.GetLBText( nIndex, strSel );
	uiSel = (UINT) ::atoi( (LPCTSTR) strSel );

	if( pX10Settings != NULL )
		pX10Settings->SetApplianceCode( uiSel );
}



void CHomeAutomationPage::OnSelendokComboCodeLamp() 
{
	CX10Settings*	pX10Settings	=	m_pSystemSettings->GetX10Settings();
	UINT			uiSel;
	int				nIndex;
	CString			strSel;

	nIndex	= m_cbLampCode.GetCurSel();
	m_cbLampCode.GetLBText( nIndex, strSel );
	uiSel = (UINT) ::atoi( (LPCTSTR) strSel );

	if( pX10Settings != NULL )
		pX10Settings->SetLampCode( uiSel );
	
}
