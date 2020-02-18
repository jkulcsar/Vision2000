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
}

CControlCamera::~CControlCamera()
{
	//de-init local copy of COM parallel port object
	m_pPP = NULL;
}

void CControlCamera::Show(BYTE byteNr)
{
	if( m_bWireless )	// wireless version
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
	else				// wired version
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
