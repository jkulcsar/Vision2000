// CameraControlPage.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "CameraControlPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCameraControlPage property page

IMPLEMENT_DYNCREATE(CCameraControlPage, CPropertyPage)

CCameraControlPage::CCameraControlPage() : CPropertyPage(CCameraControlPage::IDD)
{
	//{{AFX_DATA_INIT(CCameraControlPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CCameraControlPage::~CCameraControlPage()
{
}

void CCameraControlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCameraControlPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCameraControlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CCameraControlPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCameraControlPage message handlers

BOOL CCameraControlPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_btnCamera1.AutoLoad(IDC_CAMERA1, this );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
