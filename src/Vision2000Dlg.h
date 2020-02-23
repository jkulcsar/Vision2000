// Vision2000Dlg.h : header file
//
#if !defined(AFX_VISION2000DLG_H__1FAE7147_4B4C_11D3_AFB1_004095D0EF62__INCLUDED_)
#define AFX_VISION2000DLG_H__1FAE7147_4B4C_11D3_AFB1_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVision2000Dlg dialog

class CVision2000Dlg : public CDialog
{
// Construction
public:
	CVision2000Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVision2000Dlg)
	enum { IDD = IDD_VISION2000_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVision2000Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVision2000Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg LONG OnDisconnected(WPARAM, LPARAM);
	afx_msg LONG OnConnect(WPARAM, LPARAM);
	afx_msg void OnCallhangup();
	afx_msg void OnOpenData();
	afx_msg void OnCamera1();
	afx_msg void OnCamera2();
	afx_msg void OnCamera3();
	afx_msg void OnCamera4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	Conf* pConf;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VISION2000DLG_H__1FAE7147_4B4C_11D3_AFB1_004095D0EF62__INCLUDED_)
