// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Vision2000.h"

#include "MainFrm.h"
#include "ControlSheet.h"

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
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_ICON_NOTIFY, OnTrayNotification)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
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
	m_TrayIcon.SetStandardIcon(IDI_ASTERISK);

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

/*
void CMainFrame::OnAppAbout() 
{
	CControlSheet csh( _T("Vision2000"), this );
	csh.Create(this);
//	csh.DoModal();
}
*/

void CMainFrame::OnControlSheet() 
{
	m_pCSh = new CControlSheet( _T("Vision2000"), this );
	m_pCSh->Create(this);
}
