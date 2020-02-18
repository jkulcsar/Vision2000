#if !defined(AFX_IRREMOTECONTROLPAGE_H__452F81A5_B0CA_11D3_BA58_00C0DF25CE83__INCLUDED_)
#define AFX_IRREMOTECONTROLPAGE_H__452F81A5_B0CA_11D3_BA58_00C0DF25CE83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IRRemoteControlPage.h : header file
//

#include "IRRemoteControl.h"

/////////////////////////////////////////////////////////////////////////////
// CIRRemoteControlPage dialog

class CIRRemoteControlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CIRRemoteControlPage)

// Construction
public:
	CIRRemoteControlPage();
	~CIRRemoteControlPage();

// Dialog Data
	//{{AFX_DATA(CIRRemoteControlPage)
	enum { IDD = IDD_IR_CONTROL_PAGE };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CIRRemoteControlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CIRRemoteControlPage)
	afx_msg void OnIRPlayback();
	afx_msg void OnIRRecord();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CIRRemoteControl* m_pIRRemoteControl;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IRREMOTECONTROLPAGE_H__452F81A5_B0CA_11D3_BA58_00C0DF25CE83__INCLUDED_)
