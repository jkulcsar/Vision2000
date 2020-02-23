// PPCOMClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PPCOMClient.h"
#include "PPCOMClientDlg.h"
#include "Interface.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


	//  IRead
	// {A417E6A0-323D-11d3-AFB0-004095D0EF62}
	static const IID IID_IRead = 
	{ 0xA417E6A0, 0x323D, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };

	//  IWrite
	// {6FF402E0-323E-11d3-AFB0-004095D0EF62}
	static const IID IID_IWrite = 
	{ 0x6FF402E0, 0x323E, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	// IGet
	// {6F448280-362F-11d3-AFB0-004095D0EF62}
	static const IID IID_IGet = 
	{ 0x6F448280, 0x362F, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	// ISet
	// {6F448281-362F-11d3-AFB0-004095D0EF62}
	static const IID IID_ISet = 
	{ 0x6F448281, 0x362F, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	// ITest
	// {6F448282-362F-11d3-AFB0-004095D0EF62}
	static const IID IID_ITest = 
	{ 0x6F448282, 0x362F, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };
	


	//  IParallelPort
	// {98757173-3237-11D3-AFB0-004095D0EF62}
	//static const IID IID_IParallelPort =
	//{ 0x98757173, 0x3237, 0x11d3, 
	//{ 0xaf, 0xb0, 0x0, 0x40, 0x95, 0xd0, 0xef, 0x62 } };



/////////////////////////////////////////////////////////////////////////////
// CPPCOMClientDlg dialog

CPPCOMClientDlg::CPPCOMClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPPCOMClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPPCOMClientDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPPCOMClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPPCOMClientDlg)
	DDX_Control(pDX, IDC_LPT3_NAME, m_LPT3_Name);
	DDX_Control(pDX, IDC_LPT3_ECPMODE, m_LPT3_ECPMode);
	DDX_Control(pDX, IDC_LPT2_NAME, m_LPT2_Name);
	DDX_Control(pDX, IDC_LPT2_ECPMODE, m_LPT2_ECPMode);
	DDX_Control(pDX, IDC_LPT1_ECPMODE, m_LPT1_ECPMode);
	DDX_Control(pDX, IDC_LPT1_NAME, m_LPT1_Name);
	DDX_Control(pDX, IDC_LPT3_TYPE, m_LPT3_Type);
	DDX_Control(pDX, IDC_LPT2_TYPE, m_LPT2_Type);
	DDX_Control(pDX, IDC_LPT1_TYPE, m_LPT1_Type);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPPCOMClientDlg, CDialog)
	//{{AFX_MSG_MAP(CPPCOMClientDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FINDPORT, OnFindport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPPCOMClientDlg message handlers

BOOL CPPCOMClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPPCOMClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

HCURSOR CPPCOMClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPPCOMClientDlg::OnFindport() 
{
    CLSID clsid;
    LPCLASSFACTORY pClf; 
    LPUNKNOWN pUnk;
    IRead* pRead;
    IWrite* pWrite;
	IGet* pGet;
	ISet* pSet;
	ITest* pTest;
    HRESULT hr;

    if ((hr = ::CLSIDFromProgID(L"ParallelPort", &clsid)) != NOERROR) {
        TRACE("unable to find Program ID -- error = %x\n", hr);
        return;
    }
    if ((hr = ::CoGetClassObject(clsid, CLSCTX_INPROC_SERVER,
        NULL, IID_IClassFactory, (void **) &pClf)) != NOERROR) 
	{
        TRACE("unable to find CLSID -- error = %x\n", hr);
        return;
    }

    pClf->CreateInstance(NULL, IID_IUnknown, (void**) &pUnk);
    pUnk->QueryInterface(IID_IRead, (void**) &pRead);	
    pRead->QueryInterface(IID_IWrite, (void**) &pWrite);
	pWrite->QueryInterface(IID_IGet, (void**) &pGet);
	pGet->QueryInterface(IID_ISet, (void**) &pSet);
	pSet->QueryInterface(IID_ITest, (void**) &pTest);
    
	TRACE("main: pUnk = %p, pRead = %p, pWrite = %p, pGet = %p, pSet = %p, pTest = %p\n", 
		pUnk, pRead, pWrite, pGet, pSet, pTest);
    
    // Test all the interface virtual functions
	pSet->SetAddress( 0x378 );
	pTest->TestPort();
	if( pTest->IsEnabled() )
	{
		BYTE byteRead = pRead->ReadDataPort();
		TRACE("byteRead = %d\n", byteRead);

		pWrite->WriteDataPort(0xFF);

		byteRead = pRead->ReadDataPort();
		TRACE("byteRead = %d\n", byteRead);

		// Now take care of the UI
		pSet->SetName( "LPT1");

		// now take care of the user interface:
		m_LPT1_Name.SetWindowText( pGet->GetName() );
		m_LPT1_Type.SetWindowText( pGet->GetPortType() );
		m_LPT1_ECPMode.SetWindowText( pGet->GetECPModeDescription() );
		UpdateData( FALSE ); // update dialog box

	}

    pClf->Release();
    pUnk->Release();
    pRead->Release();
    pWrite->Release();
	pGet->Release();
	pSet->Release();
	pTest->Release();

    AfxMessageBox("Test succeeded. See also the Debug window for output.");

}
