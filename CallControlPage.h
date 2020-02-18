#if !defined(AFX_CALLCONTROLPAGE_H__598AFC62_74C0_11D3_AFB2_004095D0EF62__INCLUDED_)
#define AFX_CALLCONTROLPAGE_H__598AFC62_74C0_11D3_AFB2_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CallControlPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCallControlPage dialog

class CCallControlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CCallControlPage)

private:
	Conf* m_pConf;

// Construction
public:
	CCallControlPage();
	~CCallControlPage();

// Dialog Data
	//{{AFX_DATA(CCallControlPage)
	enum { IDD = IDD_CALL_CONTROL_PAGE };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CCallControlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CCallControlPage)
	afx_msg void OnCallHangup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLCONTROLPAGE_H__598AFC62_74C0_11D3_AFB2_004095D0EF62__INCLUDED_)
