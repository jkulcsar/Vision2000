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
	m_bOnOff		=	OFF;
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
        archive << m_uiType << m_bOnOff << m_shBrightness << m_uiDeviceCode << m_strDeviceName;
	}
    else
	{
		// do retrieve
		archive >> m_uiType >> m_bOnOff >> m_shBrightness >> m_uiDeviceCode >> m_strDeviceName;
	}
}

/*
void CX10Device::TurnApplianceON()
{
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();

	UINT uiMode = pApp->GetSystemSettings()->GetMode();

	CControlCM*		pCM				=	pApp->GetSystemSettings()->GetX10ControlModule();
	CX10Settings*	pX10Settings	=	pApp->GetSystemSettings()->GetX10Settings();

	CString strHouseCode( pX10Settings->GetHouseCode() );
	UINT uiApplianceCode	= pX10Settings->GetApplianceCode();
	CString strDeviceCode;
	BSTRING bstrHouseCode(strHouseCode);
		
	short shBrightness	= MIN_BRIGHT;
	short shCommand;

	strDeviceCode.Format( "%d", uiApplianceCode );
	BSTRING bstrDeviceCode(strDeviceCode);

	shCommand		= 2;	// ON

	::Sleep( 200 );

	// turn ON
	pCM->Exec(	bstrHouseCode.GetLPBSTR(), 
				bstrDeviceCode.GetLPBSTR(), 
				&shCommand, 
				&shBrightness 
			);
}

void CX10Device::TurnApplianceOFF()
{
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();

	UINT uiMode = pApp->GetSystemSettings()->GetMode();

	CControlCM*		pCM				=	pApp->GetSystemSettings()->GetX10ControlModule();
	CX10Settings*	pX10Settings	=	pApp->GetSystemSettings()->GetX10Settings();

	CString strHouseCode( pX10Settings->GetHouseCode() );
	UINT uiApplianceCode	= pX10Settings->GetApplianceCode();
	CString strDeviceCode;
	BSTRING bstrHouseCode(strHouseCode);
		
	short shBrightness	= MIN_BRIGHT;
	short shCommand;

	strDeviceCode.Format( "%d", uiApplianceCode );
	BSTRING bstrDeviceCode(strDeviceCode);

	shCommand		= 3;	// OFF

	::Sleep( 200 );

	// turn OFF
	pCM->Exec(	bstrHouseCode.GetLPBSTR(), 
				bstrDeviceCode.GetLPBSTR(), 
				&shCommand, 
				&shBrightness 
			);
}


void CX10Device::TurnLampON()
{
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();

	UINT uiMode = pApp->GetSystemSettings()->GetMode();

	// X10 version
	if( uiMode == MODE_X10 )
	{
		CControlCM*		pCM				=	pApp->GetSystemSettings()->GetX10ControlModule();
		CX10Settings*	pX10Settings	=	pApp->GetSystemSettings()->GetX10Settings();

		CString strHouseCode( pX10Settings->GetHouseCode() );
		UINT uiLampCode	= pX10Settings->GetLampCode();
		CString strDeviceCode;
		BSTRING bstrHouseCode(strHouseCode);
		
		short shCommand;

		strDeviceCode.Format( "%d", uiLampCode );
		BSTRING bstrDeviceCode(strDeviceCode);

		shCommand		= 2;	// ON

		::Sleep( 200 );

		// turn ON
		pCM->Exec(	bstrHouseCode.GetLPBSTR(), 
					bstrDeviceCode.GetLPBSTR(), 
					&shCommand, 
					&m_shBrightness 
				);
	}
}


void CX10Device::TurnLampOFF()
{
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();

	UINT uiMode = pApp->GetSystemSettings()->GetMode();

	CControlCM*		pCM				=	pApp->GetSystemSettings()->GetX10ControlModule();
	CX10Settings*	pX10Settings	=	pApp->GetSystemSettings()->GetX10Settings();

	CString strHouseCode( pX10Settings->GetHouseCode() );
	UINT uiLampCode	= pX10Settings->GetLampCode();
	CString strDeviceCode;
	BSTRING bstrHouseCode(strHouseCode);
		
	short shBrightness	= 0;
	short shCommand;

	strDeviceCode.Format( "%d", uiLampCode );
	BSTRING bstrDeviceCode(strDeviceCode);

	shCommand		= 3;	// OFF

	::Sleep( 200 );

	// turn OFF
	pCM->Exec(	bstrHouseCode.GetLPBSTR(), 
				bstrDeviceCode.GetLPBSTR(), 
				&shCommand, 
				&m_shBrightness 
			);
}


void CX10Device::DIMM(BOOL bDIMM)
{
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();

	UINT uiMode = pApp->GetSystemSettings()->GetMode();

	CControlCM*		pCM				=	pApp->GetSystemSettings()->GetX10ControlModule();
	CX10Settings*	pX10Settings	=	pApp->GetSystemSettings()->GetX10Settings();

	CString strHouseCode( pX10Settings->GetHouseCode() );
	UINT uiLampCode	= pX10Settings->GetLampCode();
	CString strDeviceCode;
	BSTRING bstrHouseCode(strHouseCode);
		
	short shBrightness	= 0;
	short shCommand;

	strDeviceCode.Format( "%d", uiLampCode );
	BSTRING bstrDeviceCode(strDeviceCode);


	if( bDIMM )	// dimm down the light
	{
		shCommand		= 4;	// DIMM

		m_shBrightness -= STEP;
		if( m_shBrightness < MIN_BRIGHT )
			m_shBrightness = MIN_BRIGHT;
	}
	else		// brighten up light
	{
		shCommand		= 5;	// BRIGHTEN

		m_shBrightness += STEP;
		if( m_shBrightness > MAX_BRIGHT )
			m_shBrightness = MAX_BRIGHT;
	}

	::Sleep( 200 );

	pCM->Exec(	bstrHouseCode.GetLPBSTR(), 
				bstrDeviceCode.GetLPBSTR(), 
				&shCommand, 
				&m_shBrightness 
			);
}
*/

void CX10Device::SetX10DeviceName(CString& strName)
{
	m_strDeviceName = strName;
}

void CX10Device::SetX10DeviceHouseCode(UINT uiHouseCode)
{
	m_uiHouseCode = uiHouseCode;
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


UINT CX10Device::GetX10DeviceHouseCode()
{
	return m_uiHouseCode;
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
	return m_bOnOff;
}

void CX10Device::SetOn(BOOL bOnOff)
{
	m_bOnOff = bOnOff;
}
