// HomeAutomationPage.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "HomeAutomationPage.h"
#include "NewX10DeviceDlg.h"

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
	
//	m_pX10Appliance		= pApp->GetX10Appliance();
//	m_pX10Light			= pApp->GetX10Light();
}


CHomeAutomationPage::~CHomeAutomationPage()
{
}


void CHomeAutomationPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHomeAutomationPage)
	DDX_Control(pDX, IDC_BUTTON_ADD_X10DEVICE, m_btnAdd);
	DDX_Control(pDX, IDC_BUTTON_REMOVEALL_X10DEVICE, m_btnRemoveAll);
	DDX_Control(pDX, IDC_BUTTON_REMOVE_X10DEVICE, m_btnRemove);
	DDX_Control(pDX, IDC_BUTTON_MODIFY_X10DEVICE, m_btnModify);
	DDX_Control(pDX, IDC_CHECK_ONOFF, m_btnOnOff);
	DDX_Control(pDX, IDC_BUTTON_DIMM, m_btnDimm);
	DDX_Control(pDX, IDC_BUTTON_BRIGHTEN, m_btnBrighten);
	DDX_Control(pDX, IDC_COMBO_X10DEVICE_LIST, m_cbX10DeviceList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHomeAutomationPage, CPropertyPage)
	//{{AFX_MSG_MAP(CHomeAutomationPage)
	ON_BN_CLICKED(IDC_BUTTON_ADD_X10DEVICE, OnAddX10device)
	ON_BN_CLICKED(IDC_BUTTON_REMOVEALL_X10DEVICE, OnRemoveallX10device)
	ON_CBN_SELENDOK(IDC_COMBO_X10DEVICE_LIST, OnSelendokComboX10deviceList)
	ON_BN_CLICKED(IDC_CHECK_ONOFF, OnOnOff)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHomeAutomationPage message handlers
/*
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
*/
BOOL CHomeAutomationPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	RefreshX10DeviceListComboBox();
	RefreshButtons();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CHomeAutomationPage::OnAddX10device() 
{
	CNewX10DeviceDlg	dlg;
	dlg.DoModal();

	RefreshX10DeviceListComboBox();
	RefreshButtons();
}


void CHomeAutomationPage::OnRemoveallX10device() 
{
	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	CTypedPtrList<CObList, CX10Device*>* pX10DeviceList;
	pX10DeviceList = pApp->GetX10DeviceList();

	if( AfxMessageBox( IDS_REMOVEALL_WARNING, MB_YESNO | MB_ICONEXCLAMATION	) == IDYES )
		while (!pX10DeviceList->IsEmpty())
			delete pX10DeviceList->RemoveHead();

	RefreshX10DeviceListComboBox();
	RefreshButtons();

}

void CHomeAutomationPage::OnSelendokComboX10deviceList() 
{
	UINT uiCurrIndex = m_cbX10DeviceList.GetCurSel();
	POSITION pos = (POSITION) m_cbX10DeviceList.GetItemDataPtr( uiCurrIndex );

}

void CHomeAutomationPage::RefreshButtons()
{
	POSITION pos;
	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	CTypedPtrList<CObList, CX10Device*>*	pX10DeviceList;
	pX10DeviceList = pApp->GetX10DeviceList();

	
	UINT uiCurrIndex = m_cbX10DeviceList.GetCurSel();
	if( uiCurrIndex != CB_ERR )
	{
		pos = (POSITION) m_cbX10DeviceList.GetItemDataPtr( uiCurrIndex );
		CX10Device* pX10Device = pX10DeviceList->GetAt(pos);

		m_btnRemove.EnableWindow( TRUE );
		m_btnRemoveAll.EnableWindow( TRUE );
		m_btnModify.EnableWindow( TRUE );
		m_btnAdd.EnableWindow( TRUE );
		m_btnOnOff.EnableWindow( TRUE );
		if( pX10Device->IsOn() )
		{
			m_btnOnOff.SetCheck( TRUE );
			m_btnOnOff.SetWindowText( "ON" );
		}
		else
		{
			m_btnOnOff.SetCheck( FALSE );
			m_btnOnOff.SetWindowText( "OFF" );
		}
		
		if( pos != NULL )
		{
			if( pX10Device->GetX10DeviceType() == LIGHT )
			{
				m_btnBrighten.EnableWindow( TRUE );
				m_btnDimm.EnableWindow( TRUE );
			}
		}
		else
		{
			m_btnBrighten.EnableWindow( FALSE );
			m_btnDimm.EnableWindow( FALSE );
		}
	}
	else
	{
		// no selection; disable all buttons but ADD
		m_btnBrighten.EnableWindow( FALSE );
		m_btnDimm.EnableWindow( FALSE );
		m_btnOnOff.EnableWindow( FALSE );
		m_btnRemove.EnableWindow( FALSE );
		m_btnRemoveAll.EnableWindow( FALSE );
		m_btnModify.EnableWindow( FALSE );
		m_btnAdd.EnableWindow( TRUE );
	}
}

void CHomeAutomationPage::RefreshX10DeviceListComboBox()
{
	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	CTypedPtrList<CObList, CX10Device*>*	pX10DeviceList;
	pX10DeviceList = pApp->GetX10DeviceList();

	// reset the combobox; this is an overkill
	m_cbX10DeviceList.ResetContent();

	POSITION	pos = pX10DeviceList->GetHeadPosition();
	UINT		uiIndex = 0;
	while (pos != NULL)
	{
		// assign the curent X10Device position to the current index, then increment index
		m_cbX10DeviceList.SetItemDataPtr( uiIndex, pos );

		CX10Device* pX10Device = pX10DeviceList->GetNext(pos);
		m_cbX10DeviceList.InsertString( uiIndex, (LPCTSTR)pX10Device->GetX10DeviceName() );
		
		uiIndex++;
	}

	// select the first item if we have a valid list
	if( m_cbX10DeviceList.GetCount() )
		m_cbX10DeviceList.SetCurSel( 0 );
}

void CHomeAutomationPage::OnOnOff() 
{
	POSITION pos;
	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	CTypedPtrList<CObList, CX10Device*>*	pX10DeviceList;
	pX10DeviceList = pApp->GetX10DeviceList();

	
	UINT uiCurrIndex = m_cbX10DeviceList.GetCurSel();
	if( uiCurrIndex != CB_ERR )
	{
		pos = (POSITION) m_cbX10DeviceList.GetItemDataPtr( uiCurrIndex );
		CX10Device* pX10Device = pX10DeviceList->GetAt(pos);

		// toggle ON/OFF on X10 device
		if( pX10Device->IsOn() )
			pX10Device->SetOn( OFF );
		else
			pX10Device->SetOn( ON );

		RefreshButtons();
	}
}
