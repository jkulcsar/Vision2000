// X10Device.cpp: implementation of the CX10Device class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "X10Device.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// class CX10Device

IMPLEMENT_SERIAL( CX10Device, CObject, 1 )

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CX10Device::CX10Device()
{
	m_uiType		=	APPLIANCE;
	m_shOnOff		=	OFF;
	m_shBrightness	=	MAX_BRIGHT;
	m_uiDeviceCode	=	1;
	m_strDeviceName.Empty();
}

CX10Device::~CX10Device()
{

}

//////////////////////////////////////////////////////////////////////
// Serialize the CSystemSettings object

void CX10Device::Serialize( CArchive& archive )
{
	// call base class function first
    // base class is CObject in this case
    CObject::Serialize( archive );

    // now do the stuff for our specific class
    if( archive.IsStoring() )
	{
		// do storing
        archive << m_uiType << m_shOnOff << m_shBrightness << m_uiDeviceCode << m_chHouseCode << m_strDeviceName;
	}
    else
	{
		// do retrieve
		archive >> m_uiType >> m_shOnOff >> m_shBrightness >> m_uiDeviceCode >> m_chHouseCode >> m_strDeviceName;
	}
}


void CX10Device::Execute( short shCommand )
{
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();

	UINT uiMode = pApp->GetSystemSettings()->GetMode();

	CControlCM*		pCM				=	pApp->GetSystemSettings()->GetX10ControlModule();
	CX10Settings*	pX10Settings	=	pApp->GetSystemSettings()->GetX10Settings();

	CString strHouseCode( m_chHouseCode );
	CString strDeviceCode;
	BSTRING bstrHouseCode(strHouseCode);
		
	strDeviceCode.Format( "%d", m_uiDeviceCode );
	BSTRING bstrDeviceCode(strDeviceCode);

	::Sleep( 100 );


	if( shCommand == DIMM )	
	{
		m_shBrightness -= STEP;
		if( m_shBrightness < MIN_BRIGHT )
			m_shBrightness = MIN_BRIGHT;
	}

	if( shCommand == BRIGHT )			
	{
		m_shBrightness += STEP;
		if( m_shBrightness > MAX_BRIGHT )
			m_shBrightness = MAX_BRIGHT;
	}



	if( (pCM != NULL) && ::IsWindow( pCM->GetSafeHwnd() ) )
		
		pCM->Exec(	bstrHouseCode.GetLPBSTR(), 
					bstrDeviceCode.GetLPBSTR(), 
					&shCommand, 
					&m_shBrightness 
				);
}


void CX10Device::SetX10DeviceName(CString& strName)
{
	m_strDeviceName = strName;
}

void CX10Device::SetX10DeviceHouseCode(CHAR chHouseCode)
{
	m_chHouseCode = chHouseCode;
}

void CX10Device::SetX10DeviceCode(UINT uiDeviceCode)
{
	m_uiDeviceCode = uiDeviceCode;
}

void CX10Device::SetX10DeviceType(UINT uiType)
{
	m_uiType = uiType;
}

CString& CX10Device::GetX10DeviceName()
{
	return m_strDeviceName;
}


CHAR CX10Device::GetX10DeviceHouseCode()
{
	return m_chHouseCode;
}

UINT CX10Device::GetX10DeviceCode()
{
	return m_uiDeviceCode;
}

UINT CX10Device::GetX10DeviceType()
{
	return m_uiType;
}

BOOL CX10Device::IsOn()
{
	return ( m_shOnOff == ON );
}

void CX10Device::SetOn(short shOnOff)
{
	if( (shOnOff == ON) || (shOnOff == OFF) )
		m_shOnOff = shOnOff;
}
