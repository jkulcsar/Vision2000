// VCRControlPage.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "VCRControlPage.h"

#include <afxpriv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVCRControlPage property page

IMPLEMENT_DYNCREATE(CVCRControlPage, CPropertyPage)

CVCRControlPage::CVCRControlPage() : CPropertyPage(CVCRControlPage::IDD, IDS_TAB_VCR_CONTROL)
{
	//{{AFX_DATA_INIT(CVCRControlPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// init local copy of conference object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pConf = pApp->GetConference();
	m_pSystemSettings = pApp->GetSystemSettings();
	m_pControlVCR = pApp->GetControlVCR();
}

CVCRControlPage::~CVCRControlPage()
{
	m_pConf = NULL;
	m_pSystemSettings = NULL;
	m_pControlVCR = NULL;
}

void CVCRControlPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVCRControlPage)
	DDX_Control(pDX, IDC_VCR, m_btnVCR);
	DDX_Control(pDX, IDC_STOP, m_btnStop);
	DDX_Control(pDX, IDC_REW, m_btnREW);
	DDX_Control(pDX, IDC_REC, m_btnRec);
	DDX_Control(pDX, IDC_POWER, m_btnPower);
	DDX_Control(pDX, IDC_PLAY, m_btnPlay);
	DDX_Control(pDX, IDC_PAUSE, m_btnPause);
	DDX_Control(pDX, IDC_FF, m_btnFF);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVCRControlPage, CPropertyPage)
	//{{AFX_MSG_MAP(CVCRControlPage)
	ON_BN_CLICKED(IDC_VCR, OnVcr)
	ON_BN_CLICKED(IDC_POWER, OnPower)
	ON_BN_CLICKED(IDC_REW, OnRew)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	ON_BN_CLICKED(IDC_FF, OnFf)
	ON_BN_CLICKED(IDC_REC, OnRec)
	ON_BN_CLICKED(IDC_STOP, OnStop)
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
	ON_UPDATE_COMMAND_UI( IDC_VCR, OnUpdateVcr )
	ON_UPDATE_COMMAND_UI( IDC_POWER, OnUpdatePower )
	ON_UPDATE_COMMAND_UI( IDC_REW, OnUpdateRew )
	ON_UPDATE_COMMAND_UI( IDC_PLAY, OnUpdatePlay )
	ON_UPDATE_COMMAND_UI( IDC_FF, OnUpdateFf )
	ON_UPDATE_COMMAND_UI( IDC_REC, OnUpdateRec )
	ON_UPDATE_COMMAND_UI( IDC_STOP, OnUpdateStop )
	ON_UPDATE_COMMAND_UI( IDC_PAUSE, OnUpdatePause )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVCRControlPage message handlers

void CVCRControlPage::OnVcr() 
{
	// unlike the other buttons, we have to press the REC button TWICE
	if( m_pSystemSettings->InLocalMode() )
	{
		m_pControlVCR->VCR();
		m_pControlVCR->VCR();
	}
	else
		if (m_pConf->InConnection()) 
		{
			m_pConf->SendText("VCR");
			m_pConf->SendText("VCR");
		}
}

void CVCRControlPage::OnPower() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlVCR->Power();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("POWER");
}

void CVCRControlPage::OnRew() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlVCR->Rew();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("REW");
}

void CVCRControlPage::OnPlay() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlVCR->Play();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("PLAY");
}

void CVCRControlPage::OnFf() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlVCR->FF();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("FF");
}

void CVCRControlPage::OnRec() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlVCR->Rec();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("REC");
}

void CVCRControlPage::OnStop() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlVCR->Stop();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("STOP");
}

void CVCRControlPage::OnPause() 
{
	if( m_pSystemSettings->InLocalMode() )
		m_pControlVCR->Pause();
	else
		if (m_pConf->InConnection()) 
			m_pConf->SendText("PAUSE");
}


BOOL CVCRControlPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_btnPlay.LoadBitmaps( IDB_PLAY_U, IDB_PLAY_D, IDB_PLAY_U, IDB_PLAY_X );
	m_btnPlay.SizeToContent();

	m_btnStop.LoadBitmaps( IDB_STOP_U, IDB_STOP_D, IDB_STOP_U, IDB_STOP_X );
	m_btnStop.SizeToContent();

	m_btnRec.LoadBitmaps( IDB_REC_U, IDB_REC_D, IDB_REC_U, IDB_REC_X );
	m_btnRec.SizeToContent();

	m_btnREW.LoadBitmaps( IDB_REW_U, IDB_REW_D, IDB_REW_U, IDB_REW_X );
	m_btnREW.SizeToContent();

	m_btnFF.LoadBitmaps( IDB_FF_U, IDB_FF_D, IDB_FF_U, IDB_FF_X );
	m_btnFF.SizeToContent();

	m_btnPause.LoadBitmaps( IDB_PAUSE_U, IDB_PAUSE_D, IDB_PAUSE_U, IDB_PAUSE_X );
	m_btnPause.SizeToContent();

	m_btnPower.LoadBitmaps( IDB_POWER_U, IDB_POWER_D, IDB_POWER_U, IDB_POWER_X );
	m_btnPower.SizeToContent();

	m_btnVCR.LoadBitmaps( IDB_VCR_U, IDB_VCR_D, IDB_VCR_U, IDB_VCR_X );
	m_btnVCR.SizeToContent();



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


LRESULT CVCRControlPage::OnKickIdle(WPARAM, LPARAM)
{
	UpdateDialogControls( this, FALSE );
	return 0;
}


///////////////////////////////////////////////////////////////////////////////
// CVCRControlPage::OnUpdate???? functions

void CVCRControlPage::OnUpdatePlay( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CVCRControlPage::OnUpdateStop( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CVCRControlPage::OnUpdateFf( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CVCRControlPage::OnUpdateRew( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CVCRControlPage::OnUpdatePause( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CVCRControlPage::OnUpdateRec( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CVCRControlPage::OnUpdatePower( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
}


void CVCRControlPage::OnUpdateVcr( CCmdUI* pCmdUI )
{
	if( m_pSystemSettings->InLocalMode() )
			pCmdUI->Enable( TRUE );
	else
		pCmdUI->Enable( m_pConf->InConnection() );
	
}

///////////////////////////////////////////////////////////////////////////////
