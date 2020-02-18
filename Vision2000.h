// Vision2000.h : main header file for the VISION2000 application
//

#if !defined(AFX_VISION2000_H__1FAE7145_4B4C_11D3_AFB1_004095D0EF62__INCLUDED_)
#define AFX_VISION2000_H__1FAE7145_4B4C_11D3_AFB1_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVision2000App:
// See Vision2000.cpp for the implementation of this class
//

class CVision2000App : public CWinApp
{
public:
	CVision2000App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVision2000App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVision2000App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISION2000_H__1FAE7145_4B4C_11D3_AFB1_004095D0EF62__INCLUDED_)
