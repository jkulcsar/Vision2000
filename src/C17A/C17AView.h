// C17AView.h : interface of the CC17AView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_C17AVIEW_H__3416D488_28F5_409C_ACD5_63A3366ED75B__INCLUDED_)
#define AFX_C17AVIEW_H__3416D488_28F5_409C_ACD5_63A3366ED75B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CC17AView : public CListView
{
protected: // create from serialization only
	CC17AView();
	DECLARE_DYNCREATE(CC17AView)

// Attributes
public:
	CC17ADoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CC17AView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CC17AView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CC17AView)
	//}}AFX_MSG
	afx_msg void OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in C17AView.cpp
inline CC17ADoc* CC17AView::GetDocument()
   { return (CC17ADoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_C17AVIEW_H__3416D488_28F5_409C_ACD5_63A3366ED75B__INCLUDED_)
