#if !defined(AFX_CONTROLSHEET_H__7C5516B1_6F33_11D3_8949_004095D0EF62__INCLUDED_)
#define AFX_CONTROLSHEET_H__7C5516B1_6F33_11D3_8949_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ControlSheet.h : header file
//

#include "CameraControlPage.h"
#include "VCRControlPage.h"


/////////////////////////////////////////////////////////////////////////////
// CControlSheet

class CControlSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CControlSheet)

private:
	CCameraControlPage m_CameraControlPage;
	CVCRControlPage m_VCRControlPage;
	CButton m_ButtonClose;
	CEdit m_edit;
	CString m_strLogoText;
	CFont m_fontLogo;

// Construction
public:
	CControlSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CControlSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CControlSheet)
	public:
	virtual BOOL OnInitDialog();
	protected:
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetLogoText(CString strText);
	void SetLogoFont(CString Name, int nHeight = 24, int nWeight = FW_BOLD,
						BYTE bItalic = true, BYTE bUnderline = false);

	virtual ~CControlSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CControlSheet)
	afx_msg void OnClose();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLSHEET_H__7C5516B1_6F33_11D3_8949_004095D0EF62__INCLUDED_)