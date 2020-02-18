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
	CHomeAutomationPage();
	~CHomeAutomationPage();

// Dialog Data
	//{{AFX_DATA(CHomeAutomationPage)
	enum { IDD = IDD_HOME_AUTOMATION };
	CComboBox	m_cbLampCode;
	CComboBox	m_cbApplianceCode;
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
	afx_msg void OnApplianceOn();
	afx_msg void OnApplianceOff();
	afx_msg void OnLampOn();
	afx_msg void OnLampOff();
	afx_msg void OnLampDown();
	afx_msg void OnLampUp();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelendokComboCodeAppliance();
	afx_msg void OnSelendokComboCodeLamp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CSystemSettings*	m_pSystemSettings;
	Conf*				m_pConf;	

private:	
	CX10Device* m_pX10Light;
	CX10Device* m_pX10Appliance;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOMEAUTOMATIONPAGE_H__E0F0D34C_EBF8_4ACB_91C9_31E74E63EDAB__INCLUDED_)
