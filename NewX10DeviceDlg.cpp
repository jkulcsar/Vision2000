// NewX10DeviceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "NewX10DeviceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewX10DeviceDlg dialog


CNewX10DeviceDlg::CNewX10DeviceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewX10DeviceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewX10DeviceDlg)
	m_strX10DeviceName = _T("");
	//}}AFX_DATA_INIT
}


void CNewX10DeviceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewX10DeviceDlg)
	DDX_Control(pDX, IDC_COMBO_X10DEVICE_TYPE, m_cbX10DeviceType);
	DDX_Control(pDX, IDC_COMBO_X10DEVICE_HOUSECODE, m_cbX10DeviceHouseCode);
	DDX_Control(pDX, IDC_COMBO_X10DEVICE_DEVICECODE, m_cbX10DeviceCode);
	DDX_Text(pDX, IDC_EDIT_X10DEVICE_NAME, m_strX10DeviceName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewX10DeviceDlg, CDialog)
	//{{AFX_MSG_MAP(CNewX10DeviceDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewX10DeviceDlg message handlers

BOOL CNewX10DeviceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_cbX10DeviceType.SetCurSel( 0 );
	m_cbX10DeviceHouseCode.SetCurSel( 0 );
	m_cbX10DeviceCode.SetCurSel( 0 );
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewX10DeviceDlg::OnOK() 
{
	// default implementation
	CDialog::OnOK();

	CSystemTrayApp* pApp = (CSystemTrayApp*) AfxGetApp();
	UINT			uiSel;
	int				nIndex;
	CString			strSel;
	CHAR			chSel;

	CTypedPtrArray<CObArray, CX10Device*>* pX10DeviceArray;
	pX10DeviceArray = pApp->GetX10DeviceArray();

	CX10Device* pX10Device = new CX10Device();
	if( pX10Device != NULL )
	{
		pX10Device->SetX10DeviceName( m_strX10DeviceName );

		nIndex	= m_cbX10DeviceHouseCode.GetCurSel();
		m_cbX10DeviceHouseCode.GetLBText( nIndex, &chSel );
		pX10Device->SetX10DeviceHouseCode( chSel );

		nIndex	= m_cbX10DeviceCode.GetCurSel();
		m_cbX10DeviceCode.GetLBText( nIndex, strSel );
		uiSel = (UINT) ::atoi( (LPCTSTR) strSel );
		pX10Device->SetX10DeviceCode( uiSel );

		nIndex = m_cbX10DeviceType.GetCurSel();
		if( nIndex == 0 )
			pX10Device->SetX10DeviceType( APPLIANCE );
		else
			pX10Device->SetX10DeviceType( LIGHT );

		// add the new X10 device to the device array
		pX10DeviceArray->Add( pX10Device );
	}
}
