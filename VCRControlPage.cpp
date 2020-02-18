// VCRControlPage.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "VCRControlPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVCRControlPage property page

IMPLEMENT_DYNCREATE(CVCRControlPage, CPropertyPage)

CVCRControlPage::CVCRControlPage() : CPropertyPage(CVCRControlPage::IDD)
{
	//{{AFX_DATA_INIT(CVCRControlPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CVCRControlPage::~CVCRControlPage()
{
}

void CVCRControlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVCRControlPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVCRControlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CVCRControlPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVCRControlPage message handlers

