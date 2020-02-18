#if !defined(AFX_HOMEAUTOMATIONPAGE_H__E0F0D34C_EBF8_4ACB_91C9_31E74E63EDAB__INCLUDED_)
#define AFX_HOMEAUTOMATIONPAGE_H__E0F0D34C_EBF8_4ACB_91C9_31E74E63EDAB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HomeAutomationPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHomeAutomationPage dialog

class CHomeAutomationPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CHomeAutomationPage)

// Construction
public:
	void RefreshX10DeviceListComboBox();
	void RefreshButtons();
	CHomeAutomationPage();
	~CHomeAutomationPage();

// Dialog Data
	//{{AFX_DATA(CHomeAutomationPage)
	enum { IDD = IDD_HOME_AUTOMATION };
	CButton	m_btnAdd;
	CButton	m_btnRemoveAll;
	CButton	m_btnRemove;
	CButton	m_btnModify;
	CButton	m_btnOnOff;
	CButton	m_btnDimm;
	CButton	m_btnBrighten;
	CComboBox	m_cbX10DeviceList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CHomeAutomationPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CHomeAutomationPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnAddX10device();
	afx_msg void OnRemoveallX10device();
	afx_msg void OnSelendokComboX10deviceList();
	afx_msg void OnOnOff();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CSystemSettings*	m_pSystemSettings;
	Conf*				m_pConf;	

private:	
//	CX10Device* m_pX10Light;
//	CX10Device* m_pX10Appliance;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOMEAUTOMATIONPAGE_H__E0F0D34C_EBF8_4ACB_91C9_31E74E63EDAB__INCLUDED_)
