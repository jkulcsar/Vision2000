// ButtonWizardPages.h : header file
//

#ifndef __BUTTONWIZARDPAGES_H__
#define __BUTTONWIZARDPAGES_H__

#include "IRRemoteControlPage.h"


/////////////////////////////////////////////////////////////////////////////
// CPlayWizardPage dialog

class CPlayWizardPage : public CIRRemoteControlPage
{
	DECLARE_DYNCREATE(CPlayWizardPage)

// Construction
public:
	CPlayWizardPage();
	~CPlayWizardPage();

// Dialog Data
	//{{AFX_DATA(CPlayWizardPage)
	enum { IDD = IDD_PROPPAGE1 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPlayWizardPage)
	public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPlayWizardPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CStopWizardPage dialog

class CStopWizardPage : public CIRRemoteControlPage
{
	DECLARE_DYNCREATE(CStopWizardPage)

// Construction
public:
	CStopWizardPage();
	~CStopWizardPage();

// Dialog Data
	//{{AFX_DATA(CStopWizardPage)
	enum { IDD = IDD_PROPPAGE2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CStopWizardPage)
	public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CStopWizardPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CRecordWizardPage dialog

class CRecordWizardPage : public CIRRemoteControlPage
{
	DECLARE_DYNCREATE(CRecordWizardPage)

// Construction
public:
	CRecordWizardPage();
	~CRecordWizardPage();

// Dialog Data
	//{{AFX_DATA(CRecordWizardPage)
	enum { IDD = IDD_PROPPAGE3 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRecordWizardPage)
	public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CRecordWizardPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CPauseWizardPage dialog

class CPauseWizardPage : public CIRRemoteControlPage
{
	DECLARE_DYNCREATE(CPauseWizardPage)

// Construction
public:
	CPauseWizardPage();
	~CPauseWizardPage();

// Dialog Data
	//{{AFX_DATA(CPauseWizardPage)
	enum { IDD = IDD_PROPPAGE4 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPauseWizardPage)
	public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPauseWizardPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CPowerWizardPage dialog

class CPowerWizardPage : public CIRRemoteControlPage
{
	DECLARE_DYNCREATE(CPowerWizardPage)

// Construction
public:
	CPowerWizardPage();
	~CPowerWizardPage();

// Dialog Data
	//{{AFX_DATA(CPowerWizardPage)
	enum { IDD = IDD_PROPPAGE5 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPowerWizardPage)
	public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CPowerWizardPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CFFWizardPage dialog

class CFFWizardPage : public CIRRemoteControlPage
{
	DECLARE_DYNCREATE(CFFWizardPage)

// Construction
public:
	CFFWizardPage();
	~CFFWizardPage();

// Dialog Data
	//{{AFX_DATA(CFFWizardPage)
	enum { IDD = IDD_PROPPAGE6 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CFFWizardPage)
	public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CFFWizardPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CREWWizardPage dialog

class CREWWizardPage : public CIRRemoteControlPage
{
	DECLARE_DYNCREATE(CREWWizardPage)

// Construction
public:
	CREWWizardPage();
	~CREWWizardPage();

// Dialog Data
	//{{AFX_DATA(CREWWizardPage)
	enum { IDD = IDD_PROPPAGE7 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CREWWizardPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnWizardFinish();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CREWWizardPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};


/////////////////////////////////////////////////////////////////////////////
// CAddInWizardPage dialog

class CAddInWizardPage : public CIRRemoteControlPage
{
	DECLARE_DYNCREATE(CAddInWizardPage)

// Construction
public:
	CAddInWizardPage();
	~CAddInWizardPage();

// Dialog Data
	//{{AFX_DATA(CAddInWizardPage)
	enum { IDD = IDD_PROPPAGE8 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CAddInWizardPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CAddInWizardPage)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};



#endif // __BUTTONWIZARDPAGES_H__
