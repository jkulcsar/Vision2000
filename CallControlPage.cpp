// CallControlPage.cpp : implementation file
//

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
	m_pSystemSettings = pApp->GetSystemSettings();
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
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCallControlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CCallControlPage)
	ON_BN_CLICKED(IDC_CALL_HANGUP, OnCallHangup)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
	ON_UPDATE_COMMAND_UI( IDC_CALL_HANGUP, OnUpdateCallHangup )
	ON_UPDATE_COMMAND_UI( IDC_MACHINE_NAME, OnUpdateMachineName )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCallControlPage message handlers

void CCallControlPage::OnCallHangup() 
{
	// If not in a call, then call szMachineName, otherwise hang up.
	if (!m_pConf->InConnection()) 
	{
		CString strMachineName;
		GetDlgItemText(IDC_MACHINE_NAME,strMachineName);
		if( !strMachineName.IsEmpty() )
			m_pConf->Call((LPTSTR)(LPCTSTR)strMachineName);
		else
			AfxMessageBox("Enter a machine name first!", MB_OK);
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

///////////////////////////////////////////////////////////////////////////////