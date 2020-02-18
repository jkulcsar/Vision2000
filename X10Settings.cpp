// X10Settings.cpp: implementation of the CX10Settings class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "X10Settings.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// class CX10Settings

IMPLEMENT_SERIAL( CX10Settings, CObject, 1 )

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CX10Settings::CX10Settings()
{
	m_chHouseCode		=	_T('A');
	m_uiDeviceCodeBase	=	1;
	m_uiCOMPort			=	1;
	m_uiApplianceCode	=	1;
	m_uiLampCode		=	1;
}

CX10Settings::~CX10Settings()
{

}


//////////////////////////////////////////////////////////////////////
// Serialize the CX10Settings object

void CX10Settings::Serialize( CArchive& archive )
{
	// call base class function first
    // base class is CObject in this case
    CObject::Serialize( archive );

    // now do the stuff for our specific class
    if( archive.IsStoring() )
	{
		// do storing
        archive << m_chHouseCode << m_uiDeviceCodeBase << m_uiCOMPort;
		archive << m_uiApplianceCode << m_uiLampCode;
	}
    else
	{
		// do retrieve
        archive >> m_chHouseCode >> m_uiDeviceCodeBase >> m_uiCOMPort;
		archive >> m_uiApplianceCode >> m_uiLampCode;
	}
}


//////////////////////////////////////////////////////////////////////
// Get/Set functions
//////////////////////////////////////////////////////////////////////

CHAR CX10Settings::GetHouseCode()
{
	return m_chHouseCode;
}

UINT CX10Settings::GetDeviceCodeBase()
{
	return m_uiDeviceCodeBase;
}

UINT CX10Settings::GetCOMPort()
{
	return m_uiCOMPort;
}

void CX10Settings::SetHouseCode(CHAR chHouseCode)
{
	m_chHouseCode = chHouseCode;
}

void CX10Settings::SetDeviceCodeBase(UINT uiDeviceCodeBase)
{
	m_uiDeviceCodeBase = uiDeviceCodeBase;
}

void CX10Settings::SetCOMPort(UINT uiCOMPort)
{
	m_uiCOMPort = uiCOMPort;
}


UINT CX10Settings::GetApplianceCode()
{
	return m_uiApplianceCode;
}


UINT CX10Settings::GetLampCode()
{
	return m_uiLampCode;
}


void CX10Settings::SetApplianceCode(UINT uiApplianceCode)
{
	m_uiApplianceCode = uiApplianceCode;
}


void CX10Settings::SetLampCode(UINT uiLampCode)
{
	m_uiLampCode = uiLampCode;
}
