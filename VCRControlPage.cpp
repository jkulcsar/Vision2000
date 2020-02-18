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

CVCRControlPage::CVCRControlPage() : CPropertyPage(CVCRControlPage::IDD, IDS_TAB_VCR_CONTROL)
{
	//{{AFX_DATA_INIT(CVCRControlPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	// init local copy of conference object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pConf = pApp->GetConference();
}

CVCRControlPage::~CVCRControlPage()
{
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
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVCRControlPage message handlers


void CVCRControlPage::OnVcr() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("VCR") == S_OK )
			AfxMessageBox("VCR selected... please allow a few seconds for the URC to initialize", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVCRControlPage::OnPower() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("POWER") == S_OK )
			AfxMessageBox("POWER selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVCRControlPage::OnRew() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("REW") == S_OK )
			AfxMessageBox("REW selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVCRControlPage::OnPlay() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("PLAY") == S_OK )
			AfxMessageBox("PLAY selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVCRControlPage::OnFf() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("FF") == S_OK )
			AfxMessageBox("FF selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVCRControlPage::OnRec() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("REC") == S_OK )
			AfxMessageBox("REC selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVCRControlPage::OnStop() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("STOP") == S_OK )
			AfxMessageBox("STOP selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

void CVCRControlPage::OnPause() 
{
	if (m_pConf->InConnection()) 
	{
		if( m_pConf->SendText("PAUSE") == S_OK )
			AfxMessageBox("PAUSE selected", MB_OK);
		else
			AfxMessageBox("Command NOT sent!", MB_OK);
	}
	else
	{
		AfxMessageBox("Not in a connection!", MB_OK);
	}
}

BOOL CVCRControlPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_btnPlay.LoadBitmaps( IDB_PLAY_U, IDB_PLAY_D );
	m_btnPlay.SizeToContent();

	m_btnStop.LoadBitmaps( IDB_STOP_U, IDB_STOP_D );
	m_btnStop.SizeToContent();

	m_btnRec.LoadBitmaps( IDB_REC_U, IDB_REC_D );
	m_btnRec.SizeToContent();

	m_btnREW.LoadBitmaps( IDB_REW_U, IDB_REW_D );
	m_btnREW.SizeToContent();

	m_btnFF.LoadBitmaps( IDB_FF_U, IDB_FF_D );
	m_btnFF.SizeToContent();

	m_btnPause.LoadBitmaps( IDB_PAUSE_U, IDB_PAUSE_D );
	m_btnPause.SizeToContent();

	m_btnPower.LoadBitmaps( IDB_POWER_U, IDB_POWER_D );
	m_btnPower.SizeToContent();

	m_btnVCR.LoadBitmaps( IDB_VCR_U, IDB_VCR_D );
	m_btnVCR.SizeToContent();



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
