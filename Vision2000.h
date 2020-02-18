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

/////////////////////////////////////////////////////////////////////////////
// CSystemTrayApp:
// See SystemTray.cpp for the implementation of this class
//

class CSystemTrayApp : public CWinApp
{
private:
	// the main conference object
	// it is created and intialized by the CWinApp object
	// it's destroyed also by the CWinApp object
	Conf* m_pConf;	

public:
	CSystemTrayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSystemTrayApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSystemTrayApp)
	afx_msg void OnCallHangup();
	afx_msg void OnSendText();
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
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMTRAY_H__E2B26DD3_886E_11D1_9BF5_00A0243D1382__INCLUDED_)
