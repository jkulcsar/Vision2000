// PPCOMClientDlg.h : header file
//

#if !defined(AFX_PPCOMCLIENTDLG_H__5F088CC6_383E_11D3_AFB0_004095D0EF62__INCLUDED_)
#define AFX_PPCOMCLIENTDLG_H__5F088CC6_383E_11D3_AFB0_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPPCOMClientDlg dialog

class CPPCOMClientDlg : public CDialog
{
// Construction
public:
	CPPCOMClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPPCOMClientDlg)
	enum { IDD = IDD_PPCOMCLIENT_DIALOG };
		CStatic	m_LPT3_Name;
	CStatic	m_LPT3_ECPMode;
	CStatic	m_LPT2_Name;
	CStatic	m_LPT2_ECPMode;
	CStatic	m_LPT1_ECPMode;
	CStatic	m_LPT1_Name;
	CStatic	m_LPT3_Type;
	CStatic	m_LPT2_Type;
	CStatic	m_LPT1_Type;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPCOMClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPPCOMClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnFindport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPCOMCLIENTDLG_H__5F088CC6_383E_11D3_AFB0_004095D0EF62__INCLUDED_)
