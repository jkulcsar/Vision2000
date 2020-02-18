// CameraControlPage.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "CameraControlPage.h"

#include <afxpriv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCameraControlPage property page

IMPLEMENT_DYNCREATE(CCameraControlPage, CPropertyPage)

CCameraControlPage::CCameraControlPage() : CPropertyPage(CCameraControlPage::IDD, IDS_TAB_CAMERA_CONTROL)
{
	//{{AFX_DATA_INIT(CCameraControlPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// init local copy of conference object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pConf = pApp->GetConference();
}

CCameraControlPage::~CCameraControlPage()
{
	m_pConf = NULL;
}

void CCameraControlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCameraControlPage)
	DDX_Control(pDX, IDC_CAMERA1, m_btnCamera1);
	DDX_Control(pDX, IDC_CAMERA2, m_btnCamera2);
	DDX_Control(pDX, IDC_CAMERA3, m_btnCamera3);
	DDX_Control(pDX, IDC_CAMERA4, m_btnCamera4);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCameraControlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CCameraControlPage)
		ON_BN_CLICKED(IDC_CAMERA1, OnCamera1)
		ON_BN_CLICKED(IDC_CAMERA2, OnCamera2)
		ON_BN_CLICKED(IDC_CAMERA3, OnCamera3)
		ON_BN_CLICKED(IDC_CAMERA4, OnCamera4)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCameraControlPage message handlers

BOOL CCameraControlPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_btnCamera1.LoadBitmaps( IDB_VIDEOCAMERA_U, IDB_VIDEOCAMERA_D );
	m_btnCamera1.SizeToContent();

	m_btnCamera2.LoadBitmaps( IDB_VIDEOCAMERA_U, IDB_VIDEOCAMERA_D );
	m_btnCamera2.SizeToContent();

	m_btnCamera3.LoadBitmaps( IDB_VIDEOCAMERA_U, IDB_VIDEOCAMERA_D );
	m_btnCamera3.SizeToContent();

	m_btnCamera4.LoadBitmaps( IDB_VIDEOCAMERA_U, IDB_VIDEOCAMERA_D );
	m_btnCamera4.SizeToContent();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CCameraControlPage::OnCamera1() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("CAMERA1") == S_OK )
			AfxMessageBox("CAMERA1 selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}


void CCameraControlPage::OnCamera2() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("CAMERA2") == S_OK )
			AfxMessageBox("CAMERA2 selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}


void CCameraControlPage::OnCamera3() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("CAMERA3") == S_OK )
			AfxMessageBox("CAMERA3 selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}


void CCameraControlPage::OnCamera4() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("CAMERA4") == S_OK )
			AfxMessageBox("CAMERA4 selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}


LRESULT CCameraControlPage::OnKickIdle(WPARAM, LPARAM)
{
//	UpdateDialogControls( this, FALSE );
	return 0;
}
