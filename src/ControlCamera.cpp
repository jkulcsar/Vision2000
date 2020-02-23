// ControlCamera.cpp: implementation of the CControlCamera class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "ControlCamera.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CControlCamera::CControlCamera()
{
	// init local copy of COM parallel port object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pPP = pApp->GetSystemSettings()->GetParallelPort();
	m_bWireless = pApp->GetSystemSettings()->IsWireless();

	m_uiPreviousCamera = 0;	// no camera is turned ON !!
}

CControlCamera::~CControlCamera()
{
	//de-init local copy of COM parallel port object
	m_pPP = NULL;
}

void CControlCamera::Show(BYTE byteNr)
{
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();

	m_uiMode = pApp->GetSystemSettings()->GetMode();

	// X10 version
	if( m_uiMode == MODE_X10 )
	{
		CControlCM*		pCM				=	pApp->GetSystemSettings()->GetX10ControlModule();
		CX10Settings*	pX10Settings	=	pApp->GetSystemSettings()->GetX10Settings();

		CString strHouseCode( pX10Settings->GetHouseCode() );
		UINT uiDeviceCodeBase	= pX10Settings->GetDeviceCodeBase();
		UINT uiCamera			= byteNr;
		CString strDeviceCode;
		BSTRING bstrHouseCode(strHouseCode);
		
		short shBrightness	= 0;
		short shCommand;

		if( uiCamera != m_uiPreviousCamera )
		{
			strDeviceCode.Format( "%d", uiDeviceCodeBase + m_uiPreviousCamera - 1 );
			BSTRING bstrPrevDeviceCode(strDeviceCode);

			shCommand		= 3;	// OFF

			// turn off the previous camera
			pCM->Exec(	bstrHouseCode.GetLPBSTR(), 
						bstrPrevDeviceCode.GetLPBSTR(), 
						&shCommand, 
						&shBrightness 
					);

			strDeviceCode.Format("%d", uiDeviceCodeBase + uiCamera - 1 );
			BSTRING bstrCurrDeviceCode(strDeviceCode);

			shCommand		= 2;	// ON

			::Sleep( 200 );

			// turn ON the currently selected camera
			pCM->Exec(	bstrHouseCode.GetLPBSTR(), 
						bstrCurrDeviceCode.GetLPBSTR(), 
						&shCommand, 
						&shBrightness 
					);

			// make the currently selected camera the old one (previous)
			m_uiPreviousCamera = uiCamera;
		}
	}

	// wireless version
	if( m_uiMode == MODE_WIRELESS )
	{
		BYTE byteMask		= 0xF8;
		BYTE byteTemp		= 0x00;
		BYTE byteDevice		= 0x00;
		BYTE byteToWrite	= 0x00;

		switch( byteNr )
		{
			case 1:
				byteDevice = 0x04;
				break;

			case 2:
				byteDevice = 0x05;
				break;

			case 3:
				byteDevice = 0x06;
				break;

			case 4:
				byteDevice = 0x07;
				break;

			case 5:
				byteDevice = 0x00;
				break;

			case 6:
				byteDevice = 0x01;
				break;

			case 7:
				byteDevice = 0x02;
				break;

			case 8:
				byteDevice = 0x03;
				break;
		}

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp	= byteMask & byteToWrite;
		byteToWrite = byteTemp | byteDevice;

		m_pPP->WriteDataPort( byteToWrite );

	}

	// wired version
	if( m_uiMode == MODE_WIRED )
	{
		BYTE byteTemp1;
		BYTE byteTemp2;
		BYTE byteDevice1;
		BYTE byteDevice0;
		BYTE byteToWrite;

		switch( byteNr )
		{
			case 1:
				byteDevice1 = 0x0C;
				byteDevice0 = 0x00;
				break;

			case 2:
				byteDevice1 = 0x0E;
				byteDevice0 = 0x02;
				break;

			case 3:
				byteDevice1 = 0x0D;
				byteDevice0 = 0x01;
				break;

			case 4:
				byteDevice1 = 0x0F;
				byteDevice0 = 0x03;
				break;
		}

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1	= 0xF0 | byteDevice1;
		byteTemp2	= byteToWrite & byteTemp1;
		byteTemp1	= byteDevice0;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );
	}
}
