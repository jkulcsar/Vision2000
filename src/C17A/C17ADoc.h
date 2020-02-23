// C17ADoc.h : interface of the CC17ADoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_C17ADOC_H__D0B1BB68_5133_4B33_84F4_3F82B298B25B__INCLUDED_)
#define AFX_C17ADOC_H__D0B1BB68_5133_4B33_84F4_3F82B298B25B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CC17ADoc : public CDocument
{
protected: // create from serialization only
	CC17ADoc();
	DECLARE_DYNCREATE(CC17ADoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC17ADoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CC17ADoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CC17ADoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C17ADOC_H__D0B1BB68_5133_4B33_84F4_3F82B298B25B__INCLUDED_)
