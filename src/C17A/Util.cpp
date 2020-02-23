
#include "stdafx.h"

//****************************************************************************
//
// CLASS BSTRING
//
//****************************************************************************

//****************************************************************************
//
// Constructor
//
//****************************************************************************

// We don't support construction from an ANSI string in the Unicode build.
#if !defined(UNICODE)

BSTRING::BSTRING(LPCSTR lpcString)
{
	m_bstr = NULL;

	// Compute the length of the required BSTR, including the null
	int cWC =  MultiByteToWideChar(CP_ACP, 0, lpcString, -1, NULL, 0);
	if (cWC <= 0)
		return;

	// Allocate the BSTR, including the null
	m_bstr = SysAllocStringLen(NULL, cWC - 1); // SysAllocStringLen adds another 1

	ASSERT(NULL != m_bstr);
	if (NULL == m_bstr)
	{
		return;
	}

	// Copy the string
	MultiByteToWideChar(CP_ACP, 0, lpcString, -1, (LPWSTR) m_bstr, cWC);

	// Verify that the string is null terminated
	ASSERT(0 == m_bstr[cWC - 1]);
}

#endif // !defined(UNICODE)


//****************************************************************************
//
// CLASS BTSTR
//
//****************************************************************************

//****************************************************************************
//
// Constructor
//
//****************************************************************************

BTSTR::BTSTR(BSTR bstr)
{
	m_psz = PszFromBstr(bstr);
}


//****************************************************************************
//
// Destructor
//
//****************************************************************************

BTSTR::~BTSTR()
{
	if (NULL != m_psz)
		LocalFree(m_psz);
}

//****************************************************************************
//
// LPTSTR PszFromBstr(BSTR bstr)
//
// Converts a BSTR to a LPSTR
//
//****************************************************************************

LPTSTR PszFromBstr(BSTR bstr)
{
	if (NULL == bstr)
		return NULL;
	int cch =  WideCharToMultiByte(CP_ACP, 0, (LPWSTR)bstr, -1, NULL, 0, NULL, NULL);
	if (cch <= 0)
		return NULL;

	LPTSTR psz = (char *)LocalAlloc(LPTR,cch);
	if (NULL == psz)
		return NULL;

	WideCharToMultiByte(CP_ACP, 0, (LPWSTR)bstr, -1, psz, cch+1, NULL, NULL);
	return psz;
}

