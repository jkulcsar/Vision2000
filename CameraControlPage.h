#if !defined(AFX_CAMERACONTROLPAGE_H__B4330204_6F38_11D3_8949_004095D0EF62__INCLUDED_)
#define AFX_CAMERACONTROLPAGE_H__B4330204_6F38_11D3_8949_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CameraControlPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCameraControlPage dialog

class CCameraControlPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CCameraControlPage)

// Construction
public:
	CCameraControlPage();
	~CCameraControlPage();

// Dialog Data
	//{{AFX_DATA(CVCRControlPage)
	enum { IDD = IDD_CAMERA_CONTROL_PAGE };
	CBitmapButton	m_btnCamera1;
	CBitmapButton	m_btnCamera2;
	CBitmapButton	m_btnCamera3;
	CBitmapButton	m_btnCamera4;
	CBitmapButton	m_btnCamera5;
	CBitmapButton	m_btnCamera6;
	CBitmapButton	m_btnCamera7;
	CBitmapButton	m_btnCamera8;
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
	//{{AFX_MSG(CCameraControlPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnCamera1();
	afx_msg void OnCamera2();
	afx_msg void OnCamera3();
	afx_msg void OnCamera4();
	afx_msg void OnCamera5();
	afx_msg void OnCamera6();
	afx_msg void OnCamera7();
	afx_msg void OnCamera8();
	//}}AFX_MSG
	afx_msg LRESULT OnKickIdle(WPARAM, LPARAM);
	afx_msg void OnUpdateCamera1( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCamera2( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCamera3( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCamera4( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCamera5( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCamera6( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCamera7( CCmdUI* pCmdUI );
	afx_msg void OnUpdateCamera8( CCmdUI* pCmdUI );
	DECLARE_MESSAGE_MAP()

private:
	CSystemSettings* m_pSystemSettings;
	Conf* m_pConf;	
	CControlCamera* m_pControlCamera;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMERACONTROLPAGE_H__B4330204_6F38_11D3_8949_004095D0EF62__INCLUDED_)
