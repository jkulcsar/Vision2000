// SetupVCRWizardSheet.h : header file
//
// This class defines custom modal property sheet 
// CSetupVCRWizardSheet.
 // CSetupVCRWizardSheet has been customized to include
// a preview window.
 
#ifndef __SETUPVCRWIZARDSHEET_H__
#define __SETUPVCRWIZARDSHEET_H__

#include "ButtonWizardPages.h"
#include "PreviewWnd.h"

#include "IRRemoteControl.h"

/////////////////////////////////////////////////////////////////////////////
// CSetupVCRWizardSheet

class CSetupVCRWizardSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CSetupVCRWizardSheet)

// Construction
public:
	CSetupVCRWizardSheet(CWnd* pWndParent = NULL);

// Attributes
public:
	CPlayWizardPage m_Page1;
	CStopWizardPage m_Page2;
	CRecordWizardPage m_Page3;
	CPauseWizardPage m_Page4;
	CPowerWizardPage m_Page5;
	CFFWizardPage m_Page6;
	CREWWizardPage m_Page7;
	CAddInWizardPage m_Page8;
	CPreviewWnd m_wndPreview;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetupVCRWizardSheet)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSetupVCRWizardSheet();
		 virtual BOOL OnInitDialog();

// Generated message map functions
protected:
	//{{AFX_MSG(CSetupVCRWizardSheet)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif	// __SETUPVCRWIZARDSHEET_H__
