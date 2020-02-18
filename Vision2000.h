// SystemTray.h : main header file for the SYSTEMTRAY application
//

#if !defined(AFX_SYSTEMTRAY_H__E2B26DD3_886E_11D1_9BF5_00A0243D1382__INCLUDED_)
#define AFX_SYSTEMTRAY_H__E2B26DD3_886E_11D1_9BF5_00A0243D1382__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "Vision2000_i.h"

#include "HyperLink.h"		// for the hyperlink feature in the About Box.


/////////////////////////////////////////////////////////////////////////////
// NmInitStruct

struct NmInitStruct
{
	WORD wSize;
	OLECHAR str[MAX_PATH];
};



/////////////////////////////////////////////////////////////////////////////
// CSystemTrayApp:
// See SystemTray.cpp for the implementation of this class
//

class CSystemTrayApp : public CWinApp
{
private:
	CWinThread*			m_pPollingThread;			// interrupt polling thread
	BOOL				m_bContinuePolling;			// flag to continue or not
	CCriticalSection	m_criticalSection;
	static UINT PollingThreadFunc(LPVOID);	// the polling thread function

	BOOL m_bATLInited;
	BOOL InitATL();

private:
	HWND CreateNetMeetingWindow(HWND hWndParent, int x, int y, LPCTSTR szMode);
	HWND m_hWndRemoteVideo;
	HWND m_hWndLocalVideo;



	// the main conference object
	// it is created and intialized by the CWinApp object
	// it's destroyed also by the CWinApp object
	Conf* m_pConf;	

	// the one and only CSystemSettings object to hold the overall system settings
	// for details see the SystemSettings.h file
	CSystemSettings* m_pSystemSettings;

	CControlCamera* m_pControlCamera;
	CControlVCR* m_pControlVCR;


public:
	CControlCamera*		GetControlCamera();
	CControlVCR*		GetControlVCR();
	Conf*				GetConference();
	CSystemSettings*	GetSystemSettings();
	CSystemTrayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemTrayApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSystemTrayApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CHyperLink	m_website;
	CHyperLink	m_email;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HICON m_hIcon;
};


/////////////////////////////////////////////////////////////////////////////
// THREADPARAMS
typedef struct tagTHREADPARAMS
{
	BOOL*	pContinueFlag;
	LPARAM	lParam1;
	LPARAM	lParam2;
	LPARAM	lParam3;
} THREADPARAMS;


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMTRAY_H__E2B26DD3_886E_11D1_9BF5_00A0243D1382__INCLUDED_)
