// ButtonWizardPages.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "resource.h"
#include "ButtonWizardPages.h"

#include "SetupVCRWizardSheet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CPlayWizardPage, CIRRemoteControlPage)
IMPLEMENT_DYNCREATE(CStopWizardPage, CIRRemoteControlPage)
IMPLEMENT_DYNCREATE(CRecordWizardPage, CIRRemoteControlPage)
IMPLEMENT_DYNCREATE(CPauseWizardPage, CIRRemoteControlPage)
IMPLEMENT_DYNCREATE(CPowerWizardPage, CIRRemoteControlPage)
IMPLEMENT_DYNCREATE(CFFWizardPage, CIRRemoteControlPage)
IMPLEMENT_DYNCREATE(CREWWizardPage, CIRRemoteControlPage)
IMPLEMENT_DYNCREATE(CAddInWizardPage, CIRRemoteControlPage)


/////////////////////////////////////////////////////////////////////////////
// CPlayWizardPage property page

CPlayWizardPage::CPlayWizardPage() : CIRRemoteControlPage()
{
	//{{AFX_DATA_INIT(CPlayWizardPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPlayWizardPage::~CPlayWizardPage()
{
}

void CPlayWizardPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlayWizardPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPlayWizardPage, CIRRemoteControlPage)
	//{{AFX_MSG_MAP(CPlayWizardPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CStopWizardPage property page

CStopWizardPage::CStopWizardPage() : CIRRemoteControlPage()
{
	//{{AFX_DATA_INIT(CStopWizardPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CStopWizardPage::~CStopWizardPage()
{
}

void CStopWizardPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStopWizardPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStopWizardPage, CIRRemoteControlPage)
	//{{AFX_MSG_MAP(CStopWizardPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CRecordWizardPage property page

CRecordWizardPage::CRecordWizardPage() : CIRRemoteControlPage()
{
	//{{AFX_DATA_INIT(CRecordWizardPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CRecordWizardPage::~CRecordWizardPage()
{
}

void CRecordWizardPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecordWizardPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRecordWizardPage, CIRRemoteControlPage)
	//{{AFX_MSG_MAP(CRecordWizardPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPauseWizardPage property page

CPauseWizardPage::CPauseWizardPage() : CIRRemoteControlPage()
{
	//{{AFX_DATA_INIT(CPauseWizardPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPauseWizardPage::~CPauseWizardPage()
{
}

void CPauseWizardPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPauseWizardPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPauseWizardPage, CIRRemoteControlPage)
	//{{AFX_MSG_MAP(CPauseWizardPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CPowerWizardPage property page

CPowerWizardPage::CPowerWizardPage() : CIRRemoteControlPage()
{
	//{{AFX_DATA_INIT(CPowerWizardPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CPowerWizardPage::~CPowerWizardPage()
{
}

void CPowerWizardPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPowerWizardPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPowerWizardPage, CIRRemoteControlPage)
	//{{AFX_MSG_MAP(CPowerWizardPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CFFWizardPage property page

CFFWizardPage::CFFWizardPage() : CIRRemoteControlPage()
{
	//{{AFX_DATA_INIT(CFFWizardPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CFFWizardPage::~CFFWizardPage()
{
}

void CFFWizardPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFFWizardPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFFWizardPage, CIRRemoteControlPage)
	//{{AFX_MSG_MAP(CFFWizardPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CREWWizardPage property page

CREWWizardPage::CREWWizardPage() : CIRRemoteControlPage()
{
	//{{AFX_DATA_INIT(CREWWizardPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CREWWizardPage::~CREWWizardPage()
{
}

void CREWWizardPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CREWWizardPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CREWWizardPage, CIRRemoteControlPage)
	//{{AFX_MSG_MAP(CREWWizardPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CAddInWizardPage property page

CAddInWizardPage::CAddInWizardPage() : CIRRemoteControlPage()
{
	//{{AFX_DATA_INIT(CAddInWizardPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CAddInWizardPage::~CAddInWizardPage()
{
}

void CAddInWizardPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddInWizardPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddInWizardPage, CIRRemoteControlPage)
	//{{AFX_MSG_MAP(CAddInWizardPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



///////////////////////////////////////////////////////////////////////////////
// OnSetActive functions

BOOL CPlayWizardPage::OnSetActive() 
{
	CSetupVCRWizardSheet* pParent = (CSetupVCRWizardSheet*)GetParent();
	ASSERT_KINDOF(CSetupVCRWizardSheet, pParent);

	pParent->SetWizardButtons(PSWIZB_NEXT);	

	SetDlgItemText( IDC_IR_LABEL, _T("Set the PLAY button") );
	
	return CPropertyPage::OnSetActive();
}


BOOL CStopWizardPage::OnSetActive() 
{
	CSetupVCRWizardSheet* pParent = (CSetupVCRWizardSheet*)GetParent();
	ASSERT_KINDOF(CSetupVCRWizardSheet, pParent);

	pParent->SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);	
	
	SetDlgItemText( IDC_IR_LABEL, _T("Set the STOP button") );
	
	return CPropertyPage::OnSetActive();
}


BOOL CRecordWizardPage::OnSetActive() 
{
	CSetupVCRWizardSheet* pParent = (CSetupVCRWizardSheet*)GetParent();
	ASSERT_KINDOF(CSetupVCRWizardSheet, pParent);

	pParent->SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);	

	SetDlgItemText( IDC_IR_LABEL, _T("Set the RECORD button") );
	
	return CPropertyPage::OnSetActive();
}


BOOL CPauseWizardPage::OnSetActive() 
{
	CSetupVCRWizardSheet* pParent = (CSetupVCRWizardSheet*)GetParent();
	ASSERT_KINDOF(CSetupVCRWizardSheet, pParent);

	pParent->SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);	

	SetDlgItemText( IDC_IR_LABEL, _T("Set the PAUSE button") );
	
	return CPropertyPage::OnSetActive();
}


BOOL CPowerWizardPage::OnSetActive() 
{
	CSetupVCRWizardSheet* pParent = (CSetupVCRWizardSheet*)GetParent();
	ASSERT_KINDOF(CSetupVCRWizardSheet, pParent);

	pParent->SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);	
	
	SetDlgItemText( IDC_IR_LABEL, _T("Set the POWER button") );

	return CPropertyPage::OnSetActive();
}


BOOL CFFWizardPage::OnSetActive() 
{
	CSetupVCRWizardSheet* pParent = (CSetupVCRWizardSheet*)GetParent();
	ASSERT_KINDOF(CSetupVCRWizardSheet, pParent);

	pParent->SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);	

	SetDlgItemText( IDC_IR_LABEL, _T("Set the FF (Fast Forward) button") );
	
	return CPropertyPage::OnSetActive();
}


BOOL CREWWizardPage::OnSetActive() 
{
	CSetupVCRWizardSheet* pParent = (CSetupVCRWizardSheet*)GetParent();
	ASSERT_KINDOF(CSetupVCRWizardSheet, pParent);

	pParent->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);	

	SetDlgItemText( IDC_IR_LABEL, _T("Set the REW (Rewind) button") );
	
	return CPropertyPage::OnSetActive();
}


///////////////////////////////////////////////////////////////////////////////
// OnWizardNext() functions

LRESULT CPlayWizardPage::OnWizardNext() 
{
	// init local copy InfraRed array object (from the system settings)
	CSystemTrayApp* pApp;
	CArray< CIRRemoteControl*, CIRRemoteControl* >* pArrayIR ;
	pApp = (CSystemTrayApp*) AfxGetApp();
	pArrayIR = pApp->GetSystemSettings()->GetArrayIR();
	pArrayIR->Add( GetIRRemoteControl() );

	return CPropertyPage::OnWizardNext();
}

LRESULT CPauseWizardPage::OnWizardNext() 
{
	// init local copy InfraRed array object (from the system settings)
	CSystemTrayApp* pApp;
	CArray< CIRRemoteControl*, CIRRemoteControl* >* pArrayIR ;
	pApp = (CSystemTrayApp*) AfxGetApp();
	pArrayIR = pApp->GetSystemSettings()->GetArrayIR();
	pArrayIR->Add( GetIRRemoteControl() );
	
	return CPropertyPage::OnWizardNext();
}

LRESULT CPowerWizardPage::OnWizardNext() 
{
	// init local copy InfraRed array object (from the system settings)
	CSystemTrayApp* pApp;
	CArray< CIRRemoteControl*, CIRRemoteControl* >* pArrayIR ;
	pApp = (CSystemTrayApp*) AfxGetApp();
	pArrayIR = pApp->GetSystemSettings()->GetArrayIR();
	pArrayIR->Add( GetIRRemoteControl() );

	return CPropertyPage::OnWizardNext();
}

LRESULT CRecordWizardPage::OnWizardNext() 
{
	// init local copy InfraRed array object (from the system settings)
	CSystemTrayApp* pApp;
	CArray< CIRRemoteControl*, CIRRemoteControl* >* pArrayIR ;
	pApp = (CSystemTrayApp*) AfxGetApp();
	pArrayIR = pApp->GetSystemSettings()->GetArrayIR();
	pArrayIR->Add( GetIRRemoteControl() );

	return CPropertyPage::OnWizardNext();
}

LRESULT CStopWizardPage::OnWizardNext() 
{
	// init local copy InfraRed array object (from the system settings)
	CSystemTrayApp* pApp;
	CArray< CIRRemoteControl*, CIRRemoteControl* >* pArrayIR ;
	pApp = (CSystemTrayApp*) AfxGetApp();
	pArrayIR = pApp->GetSystemSettings()->GetArrayIR();
	pArrayIR->Add( GetIRRemoteControl() );

	return CPropertyPage::OnWizardNext();
}


LRESULT CFFWizardPage::OnWizardNext() 
{
	// init local copy InfraRed array object (from the system settings)
	CSystemTrayApp* pApp;
	CArray< CIRRemoteControl*, CIRRemoteControl* >* pArrayIR ;
	pApp = (CSystemTrayApp*) AfxGetApp();
	pArrayIR = pApp->GetSystemSettings()->GetArrayIR();
	pArrayIR->Add( GetIRRemoteControl() );

	return CPropertyPage::OnWizardNext();
}


BOOL CREWWizardPage::OnWizardFinish() 
{
	// init local copy InfraRed array object (from the system settings)
	CSystemTrayApp* pApp;
	CArray< CIRRemoteControl*, CIRRemoteControl* >* pArrayIR ;
	pApp = (CSystemTrayApp*) AfxGetApp();
	pArrayIR = pApp->GetSystemSettings()->GetArrayIR();
	pArrayIR->Add( GetIRRemoteControl() );

	return CPropertyPage::OnWizardFinish();
}

