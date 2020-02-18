// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__1FAE7149_4B4C_11D3_AFB1_004095D0EF62__INCLUDED_)
#define AFX_STDAFX_H__1FAE7149_4B4C_11D3_AFB1_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "imsconf2.h"		// NetMeeting COM object interfaces
#include "interface.h"		// Parallel Port COM object interfaces
#include "ClUtil.h"
#include "MgrNtfy.h"
#include "CallNtfy.h"
#include "DataNotify.h"
#include "CnfNtfy.h"
#include "Conf.h"


/////////////////////////////////////////////////////////////////////////////
// The one and only application GUID object {A5E48460-4F49-11d3-AFB1-004095D0EF62}
static const GUID guidApp = 
{ 0xa5e48460, 0x4f49, 0x11d3, { 0xaf, 0xb1, 0x0, 0x40, 0x95, 0xd0, 0xef, 0x62 } };



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__1FAE7149_4B4C_11D3_AFB1_004095D0EF62__INCLUDED_)
