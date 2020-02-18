// SystemSettings.cpp: implementation of the CSystemSettings class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "SystemSettings.h"

#include "RegistryKey.hpp"

using namespace JetByteTools;

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
	m_pPP			= new CCOMParallelPort();
	m_bLocalMode	= FALSE;
	m_bWireless		=	TRUE;	// wireless version; will be changeable from UI
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
	DWORD dwPPIndex = 1;	// holds the index of the PP: LPTx where x is dwPPIndex
	DWORD dwLocalMode = FALSE;

	try
	{
		CRegistryKey key = CRegistryKey(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\sNET Technologies, Inc.\\Vision2000"));
	    for (CRegistryKey::SubkeyIterator it = key.BeginSubkeyIteration();
		     it != key.EndSubkeyIteration();
			 ++it)
		{
			CRegistryKey thisKey = it.OpenKey();
			thisKey.QueryValue( _T("Parallel Port"), dwPPIndex);
			thisKey.QueryValue( _T("Local Mode"), dwLocalMode );
		}
	}
	catch (CRegistryKey::Exception &e)
	{
		e.MessageBox();
	}

	
	m_bLocalMode = (BOOL) dwLocalMode;

	if( dwPPIndex == 1 )
		if( m_pPP->InitializeAt(LPT1) )
			m_pPP->SetName("LPT1");
		else
			return FALSE;

	if( dwPPIndex == 2 )
		if( m_pPP->InitializeAt(LPT2) )
			m_pPP->SetName("LPT2");
		else
			return FALSE;


	if( dwPPIndex == 3 )
		if( m_pPP->InitializeAt(LPT3) )
			m_pPP->SetName("LPT3");
		else
			return FALSE;


	return TRUE;
}


void CSystemSettings::Save()
{
	DWORD dwPPIndex = 1;	// holds the index of the PP: LPTx where x is dwPPIndex
	DWORD dwLocalMode = FALSE;

	dwLocalMode = (DWORD)m_bLocalMode;

	if( !strcmp( m_pPP->GetName(), "LPT1" ) && m_pPP->IsEnabled() )
		dwPPIndex = 1;

	if( !strcmp( m_pPP->GetName(), "LPT2" ) && m_pPP->IsEnabled() )
		dwPPIndex = 2;

	if( !strcmp( m_pPP->GetName(), "LPT3" ) && m_pPP->IsEnabled() )
		dwPPIndex = 3;	

	try
	{
		CRegistryKey key = CRegistryKey(HKEY_LOCAL_MACHINE, _T("SOFTWARE\\sNET Technologies, Inc.\\Vision2000"));
	    for (CRegistryKey::SubkeyIterator it = key.BeginSubkeyIteration();
		     it != key.EndSubkeyIteration();
			 ++it)
		{
			CRegistryKey thisKey = it.OpenKey();
			thisKey.SetValue( _T("Parallel Port"), dwPPIndex);
			thisKey.SetValue( _T("Local Mode"), dwLocalMode );
		}
	}
	catch (CRegistryKey::Exception &e)
	{
		e.MessageBox();
	}
}



CCOMParallelPort* CSystemSettings::GetParallelPort()
{
	return m_pPP;
}


CArray< CIRRemoteControl*, CIRRemoteControl* >* CSystemSettings::GetArrayIR()
{
	return &m_arrayIR;
}


BOOL CSystemSettings::InLocalMode()
{
	return m_bLocalMode;
}


void CSystemSettings::SetLocalMode( BOOL bLocalMode )
{
	m_bLocalMode = bLocalMode;
}




BOOL CSystemSettings::IsWireless()
{
	return m_bWireless;
}
