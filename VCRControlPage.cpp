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
		// NOTE: the ClassWizard will add DDX and DDV calls here
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
			AfxMessageBox("VCR selected", MB_OK);
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
