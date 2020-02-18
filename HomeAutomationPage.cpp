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
	ON_BN_CLICKED(IDC_BUTTON_REMOVE_X10DEVICE, OnRemoveX10device)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY_X10DEVICE, OnModifyX10device)
	ON_BN_CLICKED(IDC_BUTTON_DIMM, OnDimm)
	ON_BN_CLICKED(IDC_BUTTON_BRIGHTEN, OnBrighten)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHomeAutomationPage message handlers

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
	CTypedPtrArray<CObArray, CX10Device*>* pX10DeviceArray;
	pX10DeviceArray = pApp->GetX10DeviceArray();

	if( AfxMessageBox( IDS_REMOVEALL_WARNING, MB_YESNO | MB_ICONEXCLAMATION	) == IDYES )
	{
		for( int i = 0; i < pX10DeviceArray->GetSize(); i++ )
			if( pX10DeviceArray->GetAt( i ) != NULL )
				delete pX10DeviceArray->GetAt( i );

		pX10DeviceArray->RemoveAll();
	}

	RefreshX10DeviceListComboBox();
	RefreshButtons();
}


void CHomeAutomationPage::OnRemoveX10device() 
{
	UINT uiCurrArrayIndex;
	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	CTypedPtrArray<CObArray, CX10Device*>*	pX10DeviceArray;
	pX10DeviceArray = pApp->GetX10DeviceArray();

	UINT uiCurrIndex = m_cbX10DeviceList.GetCurSel();
	if( uiCurrIndex != CB_ERR )
	{
		uiCurrArrayIndex = (UINT) m_cbX10DeviceList.GetItemData( uiCurrIndex );

		CX10Device* pX10Device = pX10DeviceArray->GetAt(uiCurrArrayIndex);

		CString strMessage;
		CString strToFormat;
		strToFormat.LoadString( IDS_REMOVE_WARNING );
		strMessage.Format( (LPCTSTR)strToFormat, pX10Device->GetX10DeviceName() );
		if( AfxMessageBox( strMessage, MB_YESNO | MB_ICONEXCLAMATION	) == IDYES )
		{
			if( pX10Device != NULL )
				delete pX10Device;

			pX10DeviceArray->RemoveAt( uiCurrArrayIndex );
			RefreshX10DeviceListComboBox();
		}
	}

	RefreshButtons();
}



void CHomeAutomationPage::OnSelendokComboX10deviceList() 
{
	RefreshButtons();
}

void CHomeAutomationPage::RefreshButtons()
{
	UINT uiCurrArrayIndex;
	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	CTypedPtrArray<CObArray, CX10Device*>*	pX10DeviceArray;
	pX10DeviceArray = pApp->GetX10DeviceArray();

	
	UINT uiCurrIndex = m_cbX10DeviceList.GetCurSel();
	if( uiCurrIndex != CB_ERR )
	{
		uiCurrArrayIndex = (UINT) m_cbX10DeviceList.GetItemData( uiCurrIndex );
		CX10Device* pX10Device = pX10DeviceArray->GetAt( uiCurrArrayIndex );

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
		
//		if( pos != NULL )
//		{
			if( pX10Device->GetX10DeviceType() == LIGHT )
			{
				m_btnBrighten.EnableWindow( TRUE );
				m_btnDimm.EnableWindow( TRUE );
			}
			else
			{
				m_btnBrighten.EnableWindow( FALSE );
				m_btnDimm.EnableWindow( FALSE );
			}
//		}
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
	CTypedPtrArray<CObArray, CX10Device*>*	pX10DeviceArray;
	pX10DeviceArray = pApp->GetX10DeviceArray();

	// reset the combobox; this is an overkill
	m_cbX10DeviceList.ResetContent();

	for( int i = 0; i < pX10DeviceArray->GetSize(); i++ )
	{
		// assign the curent X10DeviceArray index to the current combobox-index
		CX10Device* pX10Device = pX10DeviceArray->GetAt( i );
		m_cbX10DeviceList.InsertString( i, (LPCTSTR)pX10Device->GetX10DeviceName() );
		m_cbX10DeviceList.SetItemData( i, i );
	}

	// select the first item if we have a valid list
	if( m_cbX10DeviceList.GetCount() )
		m_cbX10DeviceList.SetCurSel( 0 );
}

void CHomeAutomationPage::OnOnOff() 
{
	UINT uiCurrArrayIndex;
	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	CTypedPtrArray<CObArray, CX10Device*>*	pX10DeviceArray;
	pX10DeviceArray = pApp->GetX10DeviceArray();

	CString strCommand;
	strCommand.Empty();
	
	UINT uiCurrIndex = m_cbX10DeviceList.GetCurSel();
	if( uiCurrIndex != CB_ERR )
	{
		uiCurrArrayIndex = (UINT) m_cbX10DeviceList.GetItemData( uiCurrIndex );
		CX10Device* pX10Device = pX10DeviceArray->GetAt( uiCurrArrayIndex );

		// toggle ON/OFF on X10 device
		if( pX10Device->IsOn() )
		{
			if( m_pSystemSettings->InLocalMode() )
			{
				pX10Device->Execute( OFF );
				pX10Device->SetOn( OFF );
			}
			else
				if (m_pConf->InConnection()) 
				{
					strCommand.Format( "%d %d", OFF, uiCurrArrayIndex );
					m_pConf->SendText( (char*)(LPCTSTR) strCommand );
					pX10Device->SetOn( OFF );
				}
		}
		else
		{
			if( m_pSystemSettings->InLocalMode() )
			{
				pX10Device->Execute( ON );
				pX10Device->SetOn( ON );
			}
			else
				if (m_pConf->InConnection()) 
				{
					strCommand.Format( "%d %d", ON, uiCurrArrayIndex );
					m_pConf->SendText( (char*)(LPCTSTR) strCommand );
					pX10Device->SetOn( ON );
				}
		}

		RefreshButtons();
	}
}


void CHomeAutomationPage::OnDimm() 
{
	UINT uiCurrArrayIndex;
	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	CTypedPtrArray<CObArray, CX10Device*>*	pX10DeviceArray;
	pX10DeviceArray = pApp->GetX10DeviceArray();

	CString strCommand;
	strCommand.Empty();
	
	UINT uiCurrIndex = m_cbX10DeviceList.GetCurSel();
	if( uiCurrIndex != CB_ERR )
	{
		uiCurrArrayIndex = (UINT) m_cbX10DeviceList.GetItemData( uiCurrIndex );
		CX10Device* pX10Device = pX10DeviceArray->GetAt( uiCurrArrayIndex );

		if( pX10Device->GetX10DeviceType() == LIGHT )
		{
			if( m_pSystemSettings->InLocalMode() )
				pX10Device->Execute( DIMM );
			else
				if (m_pConf->InConnection())
				{					
					strCommand.Format( "%d %d", DIMM, uiCurrArrayIndex );
					m_pConf->SendText( (char*)(LPCTSTR) strCommand );
				}
		}
	}
}



void CHomeAutomationPage::OnBrighten() 
{
	UINT uiCurrArrayIndex;
	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	CTypedPtrArray<CObArray, CX10Device*>*	pX10DeviceArray;
	pX10DeviceArray = pApp->GetX10DeviceArray();

	CString strCommand;
	strCommand.Empty();
	
	UINT uiCurrIndex = m_cbX10DeviceList.GetCurSel();
	if( uiCurrIndex != CB_ERR )
	{
		uiCurrArrayIndex = (UINT) m_cbX10DeviceList.GetItemData( uiCurrIndex );
		CX10Device* pX10Device = pX10DeviceArray->GetAt( uiCurrArrayIndex );

		if( pX10Device->GetX10DeviceType() == LIGHT )
		{
			if( m_pSystemSettings->InLocalMode() )
				pX10Device->Execute( BRIGHT );
			else
				if (m_pConf->InConnection()) 
				{					
					strCommand.Format( "%d %d", BRIGHT, uiCurrArrayIndex );
					m_pConf->SendText( (char*)(LPCTSTR) strCommand );
				}
		}
	}
}



void CHomeAutomationPage::OnModifyX10device() 
{
}
