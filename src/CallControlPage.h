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

// Construction
public:
	CCallControlPage();
	~CCallControlPage();

// Dialog Data
	//{{AFX_DATA(CCallControlPage)
	enum { IDD = IDD_CALL_CONTROL_PAGE };
	CComboBox	m_ctlMachineName;
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
	virtual BOOL OnInitDialog();
	afx_msg void OnHostConference();
	afx_msg void OnJoinConference();
	afx_msg void OnHost();
	//}}AFX_MSG
	afx_msg LRESULT OnKickIdle(WPARAM, LPARAM);
	afx_msg void OnUpdateCallHangup( CCmdUI* pCmdUI );
	afx_msg void OnUpdateMachineName( CCmdUI* pCmdUI );
	afx_msg void OnUpdateHostConference( CCmdUI* pCmdUI );
	afx_msg void OnUpdateJoinConference( CCmdUI* pCmdUI );
	DECLARE_MESSAGE_MAP()

private:
	DWORD m_dwInsertIndex;
	Conf* m_pConf;
	CSystemSettings* m_pSystemSettings;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLCONTROLPAGE_H__598AFC62_74C0_11D3_AFB2_004095D0EF62__INCLUDED_)
