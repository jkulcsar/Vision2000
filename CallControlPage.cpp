//////////////////////////////////////////////////////////////////////
//
// CallControlPage.cpp : implementation file
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "CallControlPage.h"

#include <afxpriv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCallControlPage property page

IMPLEMENT_DYNCREATE(CCallControlPage, CPropertyPage)

CCallControlPage::CCallControlPage() : CPropertyPage(CCallControlPage::IDD, IDS_TAB_CALL_CONTROL)
{
	//{{AFX_DATA_INIT(CCallControlPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// init local copy of conference object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pConf = pApp->GetConference();

	// local copy of system settings object	
	m_pSystemSettings = pApp->GetSystemSettings();

	m_dwInsertIndex = 1;	// index of where to insert the new entry 
							// in both the array and the combobox
							// it is 1 based, not 0 based
}

CCallControlPage::~CCallControlPage()
{
	m_pConf = NULL;
	m_pSystemSettings = NULL;
}

void CCallControlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCallControlPage)
	DDX_Control(pDX, IDC_MACHINE_NAME, m_ctlMachineName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCallControlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CCallControlPage)
	ON_BN_CLICKED(IDC_CALL_HANGUP, OnCallHangup)
	ON_BN_CLICKED(IDC_HOST_CONFERENCE, OnHostConference)
	ON_BN_CLICKED(IDC_JOIN_CONFERENCE, OnJoinConference)
	ON_BN_CLICKED(IDC_BUTTON_HOST, OnHost)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
	ON_UPDATE_COMMAND_UI( IDC_CALL_HANGUP, OnUpdateCallHangup )
	ON_UPDATE_COMMAND_UI( IDC_MACHINE_NAME, OnUpdateMachineName )
	ON_UPDATE_COMMAND_UI( IDC_HOST_CONFERENCE, OnUpdateHostConference )
	ON_UPDATE_COMMAND_UI( IDC_JOIN_CONFERENCE, OnUpdateJoinConference )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCallControlPage message handlers

void CCallControlPage::OnCallHangup() 
{
	CStringArray*	pMRU;
	
	// If not in a call, then call szMachineName, otherwise hang up.
	if (!m_pConf->InConnection()) 
	{
		CString strMachineName;
		GetDlgItemText(IDC_MACHINE_NAME,strMachineName);
		pMRU = m_pSystemSettings->GetMRU();
		
		if( !strMachineName.IsEmpty() )
		{
			// place the call
			m_pConf->Call((LPTSTR)(LPCTSTR)strMachineName);

			// update the call list
			if( CB_ERR == m_ctlMachineName.FindString( -1, (LPCTSTR)strMachineName ) )
			{
				m_ctlMachineName.InsertString( 0, (LPCTSTR)strMachineName );
				pMRU->InsertAt( 0 /*m_dwInsertIndex-1*/, (LPCTSTR)strMachineName );
				m_dwInsertIndex++;
				if( m_dwInsertIndex >= 5 )
					m_dwInsertIndex = 1;
			}
		}
		else
			AfxMessageBox( IDS_MACHINE_NAME, MB_OK | MB_ICONEXCLAMATION );
	}
	else
		m_pConf->HangUp();
}


LRESULT CCallControlPage::OnKickIdle(WPARAM, LPARAM)
{
	UpdateDialogControls( this, FALSE );
	return 0;
}


///////////////////////////////////////////////////////////////////////////////
// CCallControlPage::OnUpdate???? functions

void CCallControlPage::OnUpdateCallHangup( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( FALSE );
	else
	{
		pCmdUI->Enable( TRUE );
		if( m_pConf->InConnection() )
			pCmdUI->SetText( _T("&Hang up") );
		else
			pCmdUI->SetText( _T("&Call") );
	}
}


void CCallControlPage::OnUpdateMachineName( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( FALSE );
	else
		pCmdUI->Enable( !m_pConf->InConnection() );
}


void CCallControlPage::OnUpdateHostConference( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( FALSE );
	else
		pCmdUI->Enable( !m_pConf->InConnection() );
}


void CCallControlPage::OnUpdateJoinConference( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( FALSE );
	else
		pCmdUI->Enable( !m_pConf->InConnection() );
}


///////////////////////////////////////////////////////////////////////////////

BOOL CCallControlPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	CStringArray*	pMRU;
	pMRU = m_pSystemSettings->GetMRU();

	// fill in the listbox of the combobox
	for( int i = pMRU->GetSize(); i > 0; i-- )
	{
		m_ctlMachineName.InsertString( 0, (LPCTSTR) pMRU->GetAt( i-1 )/*->GetBuffer(32)*/ );
		//pMRU->GetAt( i-1 )->ReleaseBuffer();
	}

	// make the first machine name as selected
	m_ctlMachineName.SetCurSel(0);

	// disable conference param controls
	// will be active only if option selected
	GetDlgItem(IDC_EDIT_COFERENCE_NAME)->EnableWindow(FALSE);	
	GetDlgItem(IDC_EDIT_CONFERENCE_PASSWORD)->EnableWindow(FALSE);	

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCallControlPage::OnHostConference() 
{
	GetDlgItem(IDC_EDIT_COFERENCE_NAME)->EnableWindow();	
	GetDlgItem(IDC_EDIT_CONFERENCE_PASSWORD)->EnableWindow();	
}

void CCallControlPage::OnJoinConference() 
{
	GetDlgItem(IDC_EDIT_COFERENCE_NAME)->EnableWindow();	
	GetDlgItem(IDC_EDIT_CONFERENCE_PASSWORD)->EnableWindow();	
}

void CCallControlPage::OnHost() 
{
	
}
