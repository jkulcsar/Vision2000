// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Vision2000.h"

#include "MainFrm.h"
#include "ControlSheet.h"

#include <afxpriv.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define	WM_ICON_NOTIFY			WM_USER+10


/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_CONTROL_SHEET, OnControlSheet)
	ON_MESSAGE(WM_IDLEUPDATECMDUI, OnIdleUpdateCmdUI)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_ICON_NOTIFY, OnTrayNotification)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_pCSh	=	NULL;
	m_hIcon	=	NULL;
}

CMainFrame::~CMainFrame()
{
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// Create the tray icon
	if (!m_TrayIcon.Create(this, WM_ICON_NOTIFY, _T("Vision2000"), NULL, IDR_POPUP_MENU))
		return -1;

	m_hIcon = (HICON) LoadImage( AfxGetInstanceHandle(), MAKEINTRESOURCE(IDI_VISION2000), 
						IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR  );

	if( m_hIcon != NULL )
		m_TrayIcon.SetIcon(m_hIcon);

	return 0;
}

LRESULT CMainFrame::OnTrayNotification(WPARAM wParam, LPARAM lParam)
{
	// Delegate all the work back to the default implementation in
	// CTrayIcon.
	return m_TrayIcon.OnTrayNotification(wParam, lParam);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame/CTrayIcon menu message handlers


void CMainFrame::OnClose() 
{
	CFrameWnd::OnClose();
}


void CMainFrame::OnControlSheet() 
{
	m_pCSh = new CControlSheet( _T("Vision2000"), this );
	if( m_pCSh != NULL )
		m_pCSh->Create(
						this, 
						WS_SYSMENU | WS_POPUP | WS_CAPTION | DS_MODALFRAME | WS_VISIBLE | WS_MINIMIZEBOX
					);
}


LRESULT CMainFrame::OnIdleUpdateCmdUI(WPARAM, LPARAM)
{
	if( (m_pCSh != NULL) && (::IsWindow(m_pCSh->GetSafeHwnd())) )
		m_pCSh->SendMessage(WM_KICKIDLE);

	return 0;
	
}


