// ControlDevice.cpp: implementation of the CControlDevice class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "ControlDevice.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CControlDevice::CControlDevice()
{
	// init the parallel port
	m_pPP = new CCOMParallelPort();
}

CControlDevice::~CControlDevice()
{
	if( m_pPP != NULL )
	{
		delete m_pPP;
		m_pPP = NULL;
	}
}

BOOL CControlDevice::InitializeAt(unsigned short uiAddress)
{
	if( !m_pPP->InitializeAt(uiAddress) )
	{
		m_pPP = NULL;
		return FALSE;
	}
	else
		return TRUE;
}
