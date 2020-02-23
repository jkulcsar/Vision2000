// C17AView.cpp : implementation of the CC17AView class
//

#include "stdafx.h"
#include "C17A.h"

#include "C17ADoc.h"
#include "C17AView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC17AView

IMPLEMENT_DYNCREATE(CC17AView, CListView)

BEGIN_MESSAGE_MAP(CC17AView, CListView)
	//{{AFX_MSG_MAP(CC17AView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC17AView construction/destruction

CC17AView::CC17AView()
{
}

CC17AView::~CC17AView()
{
}

BOOL CC17AView::PreCreateWindow(CREATESTRUCT& cs)
{
	return CListView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CC17AView drawing

void CC17AView::OnDraw(CDC* pDC)
{
	CC17ADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CListCtrl& refCtrl = GetListCtrl();
	refCtrl.InsertItem(0, "Item!");
}

void CC17AView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

}

/////////////////////////////////////////////////////////////////////////////
// CC17AView diagnostics

#ifdef _DEBUG
void CC17AView::AssertValid() const
{
	CListView::AssertValid();
}

void CC17AView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

CC17ADoc* CC17AView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CC17ADoc)));
	return (CC17ADoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CC17AView message handlers
void CC17AView::OnStyleChanged(int nStyleType, LPSTYLESTRUCT lpStyleStruct)
{
}
