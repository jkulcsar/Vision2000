#if !defined(AFX_VCRCONTROLPAGE_H__B4330203_6F38_11D3_8949_004095D0EF62__INCLUDED_)
#define AFX_VCRCONTROLPAGE_H__B4330203_6F38_11D3_8949_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VCRControlPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVCRControlPage dialog

class CVCRControlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CVCRControlPage)

// Construction
public:
	Conf* m_pConf;
	CVCRControlPage();
	~CVCRControlPage();

// Dialog Data
	//{{AFX_DATA(CVCRControlPage)
	enum { IDD = IDD_VCR_CONTROL_PAGE };
	CBitmapButton	m_btnVCR;
	CBitmapButton	m_btnStop;
	CBitmapButton	m_btnREW;
	CBitmapButton	m_btnRec;
	CBitmapButton	m_btnPower;
	CBitmapButton	m_btnPlay;
	CBitmapButton	m_btnPause;
	CBitmapButton	m_btnFF;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CVCRControlPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CVCRControlPage)
	afx_msg void OnVcr();
	afx_msg void OnPower();
	afx_msg void OnRew();
	afx_msg void OnPlay();
	afx_msg void OnFf();
	afx_msg void OnRec();
	afx_msg void OnStop();
	afx_msg void OnPause();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCRCONTROLPAGE_H__B4330203_6F38_11D3_8949_004095D0EF62__INCLUDED_)
