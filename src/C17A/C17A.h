// C17A.h : main header file for the C17A application
//

#if !defined(AFX_C17A_H__38C73DB3_89E6_4A10_B510_7727BCEFA0B2__INCLUDED_)
#define AFX_C17A_H__38C73DB3_89E6_4A10_B510_7727BCEFA0B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CC17AApp:
// See C17A.cpp for the implementation of this class
//

class CC17AApp : public CWinApp
{
public:
	CC17AApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC17AApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CC17AApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C17A_H__38C73DB3_89E6_4A10_B510_7727BCEFA0B2__INCLUDED_)
