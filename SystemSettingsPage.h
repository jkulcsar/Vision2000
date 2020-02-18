#if !defined(AFX_SystemSettingsPage_H__F9AC09C1_B8B1_11D3_BA58_00C0DF25CE83__INCLUDED_)
#define AFX_SystemSettingsPage_H__F9AC09C1_B8B1_11D3_BA58_00C0DF25CE83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SystemSettingsPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSystemSettingsPage dialog

class CSystemSettingsPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CSystemSettingsPage)

// Construction
public:
	CSystemSettingsPage();
	~CSystemSettingsPage();

// Dialog Data
	//{{AFX_DATA(CSystemSettingsPage)
	enum { IDD = IDD_SETTINGS_PAGE };
	CButton	m_ctlLocalMode;
	CButton	m_ctlTestPort;
	CButton m_ctlRadioButtonLPT1;
	CButton m_ctlRadioButtonLPT2;
	CButton m_ctlRadioButtonLPT3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CSystemSettingsPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CSystemSettingsPage)
	afx_msg void OnTestPort();
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioLPT1();
	afx_msg void OnRadioLPT2();
	afx_msg void OnRadioLPT3();
	afx_msg void OnLocalMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CSystemSettings* m_pSystemSettings;
	void UnCheckAll();
	void CheckLPT1();
	void CheckLPT2();
	void CheckLPT3();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SystemSettingsPage_H__F9AC09C1_B8B1_11D3_BA58_00C0DF25CE83__INCLUDED_)
