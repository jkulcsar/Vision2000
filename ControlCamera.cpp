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

}

CControlCamera::~CControlCamera()
{

}

void CControlCamera::Show(BYTE byteNr)
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
