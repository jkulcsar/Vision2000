// IRRemoteControlPage.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "IRRemoteControlPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CIRRemoteControlPage property page

IMPLEMENT_DYNCREATE(CIRRemoteControlPage, CPropertyPage)

CIRRemoteControlPage::CIRRemoteControlPage() : CPropertyPage(CIRRemoteControlPage::IDD, IDS_TAB_REMOTE_CONTROL)
{
	//{{AFX_DATA_INIT(CIRRemoteControlPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	m_pIRRemoteControl = NULL;
}


CIRRemoteControlPage::~CIRRemoteControlPage()
{
/*	do not destroy the CIRRemoteControl object here !
	the pointer to this newly allocated object is stored in CArray, 
	it will be destroyed there !

	if( m_pIRRemoteControl != NULL )
	{
		delete m_pIRRemoteControl;
		m_pIRRemoteControl = NULL;
	}
*/
}


CIRRemoteControl* CIRRemoteControlPage::GetIRRemoteControl()
{
	return m_pIRRemoteControl;
}


void CIRRemoteControlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CIRRemoteControlPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CIRRemoteControlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CIRRemoteControlPage)
	ON_BN_CLICKED(IDC_IR_PLAYBACK, OnIRPlayback)
	ON_BN_CLICKED(IDC_IR_RECORD, OnIRRecord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CIRRemoteControlPage message handlers

void CIRRemoteControlPage::OnIRPlayback() 
{
	if( m_pIRRemoteControl != NULL )
		m_pIRRemoteControl->Playback();
}


void CIRRemoteControlPage::OnIRRecord() 
{
	if( m_pIRRemoteControl != NULL )
		m_pIRRemoteControl->Record();
}


BOOL CIRRemoteControlPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_pIRRemoteControl = new CIRRemoteControl;

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
