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
}

CIRRemoteControlPage::~CIRRemoteControlPage()
{
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
	// TODO: Add your control notification handler code here
	
}

void CIRRemoteControlPage::OnIRRecord() 
{
	// TODO: Add your control notification handler code here
	
}
