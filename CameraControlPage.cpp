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

	// init local copy of conference object and system settings object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pConf = pApp->GetConference();
	m_pSystemSettings = pApp->GetSystemSettings();
	m_pControlCamera = pApp->GetControlCamera();
}

CCameraControlPage::~CCameraControlPage()
{
	m_pConf = NULL;
	m_pSystemSettings = NULL;
	m_pControlCamera = NULL;
}

void CCameraControlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCameraControlPage)
	DDX_Control(pDX, IDC_CAMERA1, m_btnCamera1);
	DDX_Control(pDX, IDC_CAMERA2, m_btnCamera2);
	DDX_Control(pDX, IDC_CAMERA3, m_btnCamera3);
	DDX_Control(pDX, IDC_CAMERA4, m_btnCamera4);
	DDX_Control(pDX, IDC_CAMERA5, m_btnCamera5);
	DDX_Control(pDX, IDC_CAMERA6, m_btnCamera6);
	DDX_Control(pDX, IDC_CAMERA7, m_btnCamera7);
	DDX_Control(pDX, IDC_CAMERA8, m_btnCamera8);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCameraControlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CCameraControlPage)
		ON_BN_CLICKED(IDC_CAMERA1, OnCamera1)
		ON_BN_CLICKED(IDC_CAMERA2, OnCamera2)
		ON_BN_CLICKED(IDC_CAMERA3, OnCamera3)
		ON_BN_CLICKED(IDC_CAMERA4, OnCamera4)
		ON_BN_CLICKED(IDC_CAMERA5, OnCamera5)
		ON_BN_CLICKED(IDC_CAMERA6, OnCamera6)
		ON_BN_CLICKED(IDC_CAMERA7, OnCamera7)
		ON_BN_CLICKED(IDC_CAMERA8, OnCamera8)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
	ON_UPDATE_COMMAND_UI( IDC_CAMERA1, OnUpdateCamera1 )
	ON_UPDATE_COMMAND_UI( IDC_CAMERA2, OnUpdateCamera2 )
	ON_UPDATE_COMMAND_UI( IDC_CAMERA3, OnUpdateCamera3 )
	ON_UPDATE_COMMAND_UI( IDC_CAMERA4, OnUpdateCamera4 )
	ON_UPDATE_COMMAND_UI( IDC_CAMERA5, OnUpdateCamera5 )
	ON_UPDATE_COMMAND_UI( IDC_CAMERA6, OnUpdateCamera6 )
	ON_UPDATE_COMMAND_UI( IDC_CAMERA7, OnUpdateCamera7 )
	ON_UPDATE_COMMAND_UI( IDC_CAMERA8, OnUpdateCamera8 )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCameraControlPage message handlers

BOOL CCameraControlPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_btnCamera1.LoadBitmaps( IDB_CAMERA_SMALL_U, IDB_CAMERA_SMALL_D );
	m_btnCamera1.SizeToContent();

	m_btnCamera2.LoadBitmaps( IDB_CAMERA_SMALL_U, IDB_CAMERA_SMALL_D );
	m_btnCamera2.SizeToContent();

	m_btnCamera3.LoadBitmaps( IDB_CAMERA_SMALL_U, IDB_CAMERA_SMALL_D );
	m_btnCamera3.SizeToContent();

	m_btnCamera4.LoadBitmaps( IDB_CAMERA_SMALL_U, IDB_CAMERA_SMALL_D );
	m_btnCamera4.SizeToContent();

	m_btnCamera5.LoadBitmaps( IDB_CAMERA_SMALL_U, IDB_CAMERA_SMALL_D );
	m_btnCamera5.SizeToContent();

	m_btnCamera6.LoadBitmaps( IDB_CAMERA_SMALL_U, IDB_CAMERA_SMALL_D );
	m_btnCamera6.SizeToContent();

	m_btnCamera7.LoadBitmaps( IDB_CAMERA_SMALL_U, IDB_CAMERA_SMALL_D );
	m_btnCamera7.SizeToContent();

	m_btnCamera8.LoadBitmaps( IDB_CAMERA_SMALL_U, IDB_CAMERA_SMALL_D );
	m_btnCamera8.SizeToContent();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CCameraControlPage::OnCamera1() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlCamera->Show(1);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("CAMERA1");
}


void CCameraControlPage::OnCamera2() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlCamera->Show(2);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("CAMERA2");
}



void CCameraControlPage::OnCamera3() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlCamera->Show(3);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("CAMERA3");
}



void CCameraControlPage::OnCamera4() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlCamera->Show(4);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("CAMERA4");
}



void CCameraControlPage::OnCamera5() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlCamera->Show(5);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("CAMERA5");
}


void CCameraControlPage::OnCamera6() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlCamera->Show(6);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("CAMERA6");
}



void CCameraControlPage::OnCamera7() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlCamera->Show(7);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("CAMERA7");
}



void CCameraControlPage::OnCamera8() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlCamera->Show(8);
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("CAMERA8");
}



LRESULT CCameraControlPage::OnKickIdle(WPARAM, LPARAM)
{
	UpdateDialogControls( this, FALSE );
	return 0;
}


///////////////////////////////////////////////////////////////////////////////
// CCameraControlPage::OnUpdate???? functions

void CCameraControlPage::OnUpdateCamera1( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CCameraControlPage::OnUpdateCamera2( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CCameraControlPage::OnUpdateCamera3( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CCameraControlPage::OnUpdateCamera4( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CCameraControlPage::OnUpdateCamera5( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CCameraControlPage::OnUpdateCamera6( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CCameraControlPage::OnUpdateCamera7( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CCameraControlPage::OnUpdateCamera8( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}

///////////////////////////////////////////////////////////////////////////////
