#if !defined(AFX_NEWX10DEVICEDLG_H__4CDFCCD6_EA40_4E51_9E4A_4BA8B0153004__INCLUDED_)
#define AFX_NEWX10DEVICEDLG_H__4CDFCCD6_EA40_4E51_9E4A_4BA8B0153004__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewX10DeviceDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewX10DeviceDlg dialog

class CNewX10DeviceDlg : public CDialog
{
// Construction
public:
	CNewX10DeviceDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewX10DeviceDlg)
	enum { IDD = IDD_DIALOG_NEW_X10DEVICE };
	CComboBox	m_cbX10DeviceType;
	CComboBox	m_cbX10DeviceHouseCode;
	CComboBox	m_cbX10DeviceCode;
	CString	m_strX10DeviceName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewX10DeviceDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewX10DeviceDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWX10DEVICEDLG_H__4CDFCCD6_EA40_4E51_9E4A_4BA8B0153004__INCLUDED_)
