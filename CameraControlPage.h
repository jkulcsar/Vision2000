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
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
//	CBitmapButton m_btnCamera1;
	Conf* m_pConf;	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMERACONTROLPAGE_H__B4330204_6F38_11D3_8949_004095D0EF62__INCLUDED_)
