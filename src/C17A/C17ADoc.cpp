// C17ADoc.cpp : implementation of the CC17ADoc class
//

#include "stdafx.h"
#include "C17A.h"

#include "C17ADoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CC17ADoc

IMPLEMENT_DYNCREATE(CC17ADoc, CDocument)

BEGIN_MESSAGE_MAP(CC17ADoc, CDocument)
	//{{AFX_MSG_MAP(CC17ADoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CC17ADoc construction/destruction

CC17ADoc::CC17ADoc()
{
}

CC17ADoc::~CC17ADoc()
{
}

BOOL CC17ADoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CC17ADoc serialization

void CC17ADoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CC17ADoc diagnostics

#ifdef _DEBUG
void CC17ADoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CC17ADoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CC17ADoc commands
