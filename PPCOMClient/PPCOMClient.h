// PPCOMClient.h : main header file for the PPCOMCLIENT application
//

#if !defined(AFX_PPCOMCLIENT_H__5F088CC4_383E_11D3_AFB0_004095D0EF62__INCLUDED_)
#define AFX_PPCOMCLIENT_H__5F088CC4_383E_11D3_AFB0_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPPCOMClientApp:
// See PPCOMClient.cpp for the implementation of this class
//

class CPPCOMClientApp : public CWinApp
{
public:
	CPPCOMClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPCOMClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPPCOMClientApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPCOMCLIENT_H__5F088CC4_383E_11D3_AFB0_004095D0EF62__INCLUDED_)
