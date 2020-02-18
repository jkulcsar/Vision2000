// ControlSheet.cpp : implementation file
//

#include "stdafx.h"
#include "vision2000.h"
#include "ControlSheet.h"

#include "afxpriv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CControlSheet

IMPLEMENT_DYNAMIC(CControlSheet, CPropertySheet)

CControlSheet::CControlSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
}

CControlSheet::CControlSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage( &m_CameraControlPage );
	AddPage( &m_VCRControlPage );
	AddPage( &m_CallControlPage );
	//AddPage( &m_IRRemoteControlPage );
	AddPage( &m_SystemSettingsPage );

	SetLogoText( _T("Vision2000"));
	SetLogoFont( _T("Arial") );
}

CControlSheet::~CControlSheet()
{
}


BEGIN_MESSAGE_MAP(CControlSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CControlSheet)
	ON_WM_CLOSE()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_KICKIDLE, OnKickIdle)
	ON_BN_CLICKED(IDC_BUTTON_CLOSE, OnClose)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControlSheet message handlers


void CControlSheet::PostNcDestroy() 
{
	delete this;
}


BOOL CControlSheet::OnInitDialog()
{
	BOOL bResult = CPropertySheet::OnInitDialog();

    //Initialize ATL control containment code.
    AtlAxWinInit();

	CRect rectWnd, rectTab, rectButton;
	CRect rectVideoWnd;
	int nWidth, nHeight;

	GetWindowRect(rectWnd);
	GetWindowRect(rectVideoWnd);
	GetDlgItem(IDOK)->GetWindowRect(rectButton);
	GetTabControl()->GetWindowRect(rectTab);

	ScreenToClient(rectWnd); 
	ScreenToClient(rectTab);

	nWidth = rectButton.Width();
	nHeight = rectButton.Height();

	// resize the control sheet here to fit our controls
	SetWindowPos(	NULL, 0, 0,
					rectWnd.Width(),
					rectWnd.Height() + (2 * nHeight),
					SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);

	rectButton.right  = rectTab.right;
	rectButton.left	  = rectTab.right - nWidth;
	rectButton.top    = rectTab.bottom + (UINT)(nHeight / 2);
	rectButton.bottom = rectTab.bottom + (UINT)(nHeight / 2) + nHeight;
	
//	m_ButtonClose.Create( _T("Close"),
//			BS_PUSHBUTTON|WS_CHILD|WS_VISIBLE|WS_TABSTOP, rectButton, this, IDC_BUTTON_CLOSE);
//	m_ButtonClose.SetFont( GetFont() );

	// put the video window next to the control panel
	POINT pt;
	pt.x = rectVideoWnd.right;
	pt.y = rectVideoWnd.top;

	// make the parent of the video window the desktop, NOT our control sheet
	m_hWndRemoteVideo = CreateNetMeetingWindow( NULL /*m_hWnd*/, pt.x, pt.y, _T("RemoteNoPause"));

	UpdateWindow();

	return bResult;
}


void CControlSheet::OnClose() 
{
	if(::IsWindow(m_hWndRemoteVideo))
		::DestroyWindow(m_hWndRemoteVideo);

	CPropertySheet::OnClose();
}


LRESULT CControlSheet::OnKickIdle(WPARAM, LPARAM)
{
//	SendMessageToDescendants( WM_KICKIDLE, 0, 0, FALSE, FALSE );
//	return 0;
 
	CPropertyPage* pActivePage=GetActivePage();
	if ( (pActivePage != NULL) && (pActivePage->GetSafeHwnd() != NULL) )
		return pActivePage->SendMessage(WM_KICKIDLE);
	else
		return 0;
}


void CControlSheet::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	if (m_strLogoText.IsEmpty())
	return;

	BOOL bWizMode; 
        
	// Get the current style from PROPSHEETHEADER structure 
	if( m_psh.dwFlags & PSH_WIZARD ) 
		bWizMode = TRUE;                // It's in wizard mode
	else 
		bWizMode = FALSE;               // It's in property sheet mode


	// If this is a Wizard, cannot retrieve the tab control dimension. 
	// So Get the Dialog's Window Rect  

	CRect rectTabCtrl;
	if( bWizMode ) 
	{ 
		GetWindowRect(rectTabCtrl); 
		rectTabCtrl.OffsetRect(14,0);	// A little correction
	} 
	else 
	{ 
		GetTabControl()->GetWindowRect(rectTabCtrl);
	} 
	ScreenToClient(rectTabCtrl);


	CRect rectOk;
	GetDlgItem(IDOK)->GetWindowRect(rectOk);
	ScreenToClient(rectOk);

	dc.SetBkMode(TRANSPARENT);

	CRect rectText;
	rectText.left = rectTabCtrl.left;
	rectText.top = rectOk.top;
	rectText.bottom = rectOk.bottom;
	rectText.right = 2 * rectOk.left; // make it 2*wider than a simple button

	CFont * OldFont = dc.SelectObject(&m_fontLogo);

	// draw text in DC
	COLORREF OldColor = dc.SetTextColor( ::GetSysColor( COLOR_3DHILIGHT));

	dc.DrawText(m_strLogoText, rectText + CPoint(1,1), 
	            DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	dc.SetTextColor( ::GetSysColor( COLOR_3DSHADOW));
	dc.DrawText( m_strLogoText, rectText, DT_SINGLELINE | DT_LEFT | DT_VCENTER);

	// restore old text color
	dc.SetTextColor( OldColor);

	// restore old font
	dc.SelectObject(OldFont);

	// Do not call CPropertySheet::OnPaint() for painting messages
}

void CControlSheet::SetLogoText(CString strText)
{
	m_strLogoText = strText;
}


void CControlSheet::SetLogoFont(CString Name, int nHeight/* = 24*/,
	int nWeight/* = FW_BOLD*/, BYTE bItalic/* = true*/, BYTE bUnderline/* = false*/)
{
	if(m_fontLogo.m_hObject)
		m_fontLogo.Detach();

	m_fontLogo.CreateFont(nHeight, 0, 0, 0, nWeight, bItalic, bUnderline,0,0,0,0,0,0, Name);
}


HWND CControlSheet::CreateNetMeetingWindow(HWND hWndParent, int x, int y, LPCTSTR szMode)
{
	USES_CONVERSION;
		
	TCHAR szFormatModeString[MAX_PATH];
	wsprintf(szFormatModeString, _T("MODE=%s"), szMode);

	NmInitStruct nmis;
	nmis.wSize = sizeof(nmis.str);
	wcscpy(nmis.str, T2OLE(szFormatModeString));

	LPOLESTR strGUIDNetMeetingActiveXControl = NULL;
	if( S_OK != StringFromCLSID(CLSID_NetMeeting, &strGUIDNetMeetingActiveXControl) )
		return NULL;

      HWND hWndCtl = 
		::CreateWindow("AtlAxWin",
			// Use ATL's string conversion routine to convert to a LPTSTR from an LPOLESTR
         OLE2T(strGUIDNetMeetingActiveXControl),
         WS_POPUPWINDOW | WS_CAPTION | WS_SIZEBOX | WS_VISIBLE  /*| WS_GROUP*/, 
		 x, 
		 y, 
		 0, 
		 0, 
		 hWndParent, 
		 NULL,
         ::GetModuleHandle(NULL), 
		 &nmis
		 );	

		// Remember to free memory given to you by StringFromCLSID
	CoTaskMemFree(strGUIDNetMeetingActiveXControl );

	if(hWndCtl)
	{
			// get the IUnknown for the video window (we want to get it's size)
		IUnknown* pUnk = NULL;
		HRESULT hr = AtlAxGetControl(hWndCtl, &pUnk);
		if(SUCCEEDED(hr))
		{
				// Now get the IOleObject interface for the netmeeting control
			IOleObject* pOleObjVideoWindow = NULL;
			hr = pUnk->QueryInterface(&pOleObjVideoWindow);
			if(SUCCEEDED(hr))
			{
					// get the Extent
				SIZEL sizel = {0, 0};
				hr = pOleObjVideoWindow->GetExtent(DVASPECT_CONTENT, &sizel);
				if(SUCCEEDED(hr))
				{
						// Convert the Extent from HIMETRIC to pixels.
					SIZEL sizeInPixels = {0, 0};
					AtlHiMetricToPixel(&sizel, &sizeInPixels);
					::SetWindowPos(hWndCtl, NULL, 0, 0, sizeInPixels.cx, sizeInPixels.cy, SWP_NOMOVE | SWP_NOZORDER | SWP_NOACTIVATE);
				}

					// Don't forget to release interfaces!
				pOleObjVideoWindow->Release();
			}

				// Don't forget to release interfaces!
			pUnk->Release();
		}
	}

	return hWndCtl;
}
