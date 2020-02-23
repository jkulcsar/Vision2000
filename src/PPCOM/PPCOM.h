// PPCOM.h : main header file for the PPCOM DLL
//

#if !defined(AFX_PPCOM_H__9875716B_3237_11D3_AFB0_004095D0EF62__INCLUDED_)
#define AFX_PPCOM_H__9875716B_3237_11D3_AFB0_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPPCOMApp
// See PPCOM.cpp for the implementation of this class
//

class CPPCOMApp : public CWinApp
{
public:
	CPPCOMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPCOMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CPPCOMApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPCOM_H__9875716B_3237_11D3_AFB0_004095D0EF62__INCLUDED_)
