// SystemSettings.cpp: implementation of the CSystemSettings class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "SystemSettings.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSystemSettings::CSystemSettings()
{
	// init the parallel port
	m_pPP = new CCOMParallelPort();
}


CSystemSettings::~CSystemSettings()
{
	if( m_pPP != NULL )
	{
		delete m_pPP;
		m_pPP = NULL;
	}
}

BOOL CSystemSettings::Initialize()
{
/*
	if( !m_pPP->InitializeAt(LPT1) )
	{
		m_pPP = NULL;
		return FALSE;
	}
	else
	{
		m_pPP->SetName("LPT1");
		return TRUE;
	}
*/
	return TRUE;	// assume success until a proper init sequence from registry is in place
}

CCOMParallelPort* CSystemSettings::GetParallelPort()
{
	return m_pPP;
}
