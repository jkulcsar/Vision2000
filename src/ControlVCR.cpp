// ControlVCR.cpp: implementation of the CControlVCR class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "ControlVCR.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CControlVCR::CControlVCR()
{
	m_bPowerOn			= FALSE;
	m_bURCInitialized	= FALSE;

	// init local copy of COM parallel port object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pPP = pApp->GetSystemSettings()->GetParallelPort();
	m_bWireless = pApp->GetSystemSettings()->IsWireless();
	m_pArrayIR = pApp->GetSystemSettings()->GetArrayIR();

}

CControlVCR::~CControlVCR()
{
	//de-init local copy of COM parallel port object
	m_pPP = NULL;
}

void CControlVCR::Play()
{
	if( m_bWireless )	// wireless case
	{
		// send IR command
		if( m_pArrayIR->GetSize() > 0 )
			if( m_pArrayIR->GetAt(0) != NULL )
				m_pArrayIR->GetAt(0)->Playback();
	}
	else
	{

		//Toggle the necessary bits (Bits number 2-5  -  REMEMBER THE FIRST BIT IS BIT 0)
		// using the following method;  read the status port. Create a temporary variable
		// to represent the data port and assign all 1's to the pins except for those pins
		// Numbered 2-5 that you want to be 0. AND this temp. var with the eresult of the
		// data port read. Create a second temp variable and assign a 0 to each pin except
		// for those Numbered 2-5 that should be 1. Finally OR the two temp variable together
		// write the result to the data port.
	
		// This method only changes the values of the pins numbered 2-5

		BYTE byteTemp1;
		BYTE byteTemp2;
		BYTE byteToWrite;

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xFB;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x38;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );

		::Sleep(250);

		// Clear the data port (pins # 2-5) using the above method
		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xC3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x00;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );
	}
}


void CControlVCR::Stop()
{
	if( m_bWireless )	// wireless case
	{
		// send IR command
		if( m_pArrayIR->GetSize() > 0 )
			if( m_pArrayIR->GetAt(1) != NULL )
				m_pArrayIR->GetAt(1)->Playback();
	}
	else
	{
		//Toggle the necessary bits (Bits number 2-5  -  REMEMBER THE FIRST BIT IS BIT 0)
		// using the following method;  read the status port. Create a temporary variable
		// to represent the data port and assign all 1's to the pins except for those pins
		// Numbered 2-5 that you want to be 0. AND this temp. var with the eresult of the
		// data port read. Create a second temp variable and assign a 0 to each pin except
		// for those Numbered 2-5 that should be 1. Finally OR the two temp variable together
		// write the result to the data port.
	
		// This method only changes the values of the pins numbered 2-5

		BYTE byteTemp1;
		BYTE byteTemp2;
		BYTE byteToWrite;

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xEF;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x2C;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );

		::Sleep(250);

		// Clear the data port (pins # 2-5) using the above method
		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xC3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x00;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );
	}
}


void CControlVCR::FF()
{
	if( m_bWireless )	// wireless case
	{
		// send IR command
		if( m_pArrayIR->GetSize() > 0 )
			if( m_pArrayIR->GetAt(5) != NULL )
				m_pArrayIR->GetAt(5)->Playback();
	}
	else
	{
		//Toggle the necessary bits (Bits number 2-5  -  REMEMBER THE FIRST BIT IS BIT 0)
		// using the following method;  read the status port. Create a temporary variable
		// to represent the data port and assign all 1's to the pins except for those pins
		// Numbered 2-5 that you want to be 0. AND this temp. var with the eresult of the
		// data port read. Create a second temp variable and assign a 0 to each pin except
		// for those Numbered 2-5 that should be 1. Finally OR the two temp variable together
		// write the result to the data port.
	
		// This method only changes the values of the pins numbered 2-5

		BYTE byteTemp1;
		BYTE byteTemp2;
		BYTE byteToWrite;

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xE7;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x24;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );

		::Sleep(250);

		// Clear the data port (pins # 2-5) using the above method
		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xC3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x00;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );
	}
}


void CControlVCR::Rew()
{
	if( m_bWireless )	// wireless case
	{
		// send IR command
		if( m_pArrayIR->GetSize() > 0 )
			if( m_pArrayIR->GetAt(6) != NULL )
				m_pArrayIR->GetAt(6)->Playback();
	}
	else
	{
		//Toggle the necessary bits (Bits number 2-5  -  REMEMBER THE FIRST BIT IS BIT 0)
		// using the following method;  read the status port. Create a temporary variable
		// to represent the data port and assign all 1's to the pins except for those pins
		// Numbered 2-5 that you want to be 0. AND this temp. var with the eresult of the
		// data port read. Create a second temp variable and assign a 0 to each pin except
		// for those Numbered 2-5 that should be 1. Finally OR the two temp variable together
		// write the result to the data port.
	
		// This method only changes the values of the pins numbered 2-5

		BYTE byteTemp1;
		BYTE byteTemp2;
		BYTE byteToWrite;

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xEB;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x28;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );

		::Sleep(250);

		// Clear the data port (pins # 2-5) using the above method
		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xC3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x00;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );
	}
}


void CControlVCR::Rec()
{
	if( m_bWireless )	// wireless case
	{
		// send IR command
		if( m_pArrayIR->GetSize() > 0 )
			if( m_pArrayIR->GetAt(2) != NULL )
				m_pArrayIR->GetAt(2)->Playback();
	}
	else
	{
		//Toggle the necessary bits (Bits number 2-5  -  REMEMBER THE FIRST BIT IS BIT 0)
		// using the following method;  read the status port. Create a temporary variable
		// to represent the data port and assign all 1's to the pins except for those pins
		// Numbered 2-5 that you want to be 0. AND this temp. var with the eresult of the
		// data port read. Create a second temp variable and assign a 0 to each pin except
		// for those Numbered 2-5 that should be 1. Finally OR the two temp variable together
		// write the result to the data port.
	
		// This method only changes the values of the pins numbered 2-5

		BYTE byteTemp1;
		BYTE byteTemp2;
		BYTE byteToWrite;

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xF7;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x34;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );

		::Sleep(250);

		// Clear the data port (pins # 2-5) using the above method
		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xC3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x00;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );
	}
}


void CControlVCR::Pause()
{
	if( m_bWireless )	// wireless case
	{
		// send IR command
		if( m_pArrayIR->GetSize() > 0 )
			if( m_pArrayIR->GetAt(3) != NULL )
				m_pArrayIR->GetAt(3)->Playback();
	}
	else
	{
		// Toggle the necessary bits (Bits number 2-5  -  REMEMBER THE FIRST BIT IS BIT 0)
		// using the following method;  read the status port. Create a temporary variable
		// to represent the data port and assign all 1's to the pins except for those pins
		// Numbered 2-5 that you want to be 0. AND this temp. var with the eresult of the
		// data port read. Create a second temp variable and assign a 0 to each pin except
		// for those Numbered 2-5 that should be 1. Finally OR the two temp variable together
		// write the result to the data port.
	
		// This method only changes the values of the pins numbered 2-5

		BYTE byteTemp1;
		BYTE byteTemp2;
		BYTE byteToWrite;

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xFF;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x3C;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );

		::Sleep(250);

		// Clear the data port (pins # 2-5) using the above method
		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xC3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x00;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );
	}
}


void CControlVCR::VCR()
{
	if( m_bWireless )	// wireless case
	{
		// send IR command
	}
	else
	{
		// Toggle the necessary bits (Bits number 2-5  -  REMEMBER THE FIRST BIT IS BIT 0)
		// using the following method;  read the status port. Create a temporary variable
		// to represent the data port and assign all 1's to the pins except for those pins
		// Numbered 2-5 that you want to be 0. AND this temp. var with the eresult of the
		// data port read. Create a second temp variable and assign a 0 to each pin except
		// for those Numbered 2-5 that should be 1. Finally OR the two temp variable together
		// write the result to the data port.
	
		// This method only changes the values of the pins numbered 2-5

		BYTE byteTemp1;
		BYTE byteTemp2;
		BYTE byteToWrite;

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xE3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x20;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );

		//::Sleep(250);

		// check first if URC is initialized
	//	if( !m_bURCInitialized )  
	//	{
			// set the wait cursor
			m_hOldCursor = ::SetCursor( ::LoadCursor(NULL, IDC_WAIT) );

			::Sleep(5000);

			// press the Power button 3 times with 1sec interval
			for(int i=0; i<3; i++)
			{
				Power();
				::Sleep(1000);
			}

			// press the Stop button
			Stop(); 

	//		m_bURCInitialized = TRUE;

			// restore old cursor
			::SetCursor( m_hOldCursor );

	//	}

		Power(); // press power for Power OFF; see the function for details

			// Clear the data port (pins # 2-5) using the above method
		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xC3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x00;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );
	}
}



void CControlVCR::Power()
{
	if( m_bWireless )	// wireless case
	{
		// send IR command
		if( m_pArrayIR->GetSize() > 0 )
			if( m_pArrayIR->GetAt(4) != NULL )
				m_pArrayIR->GetAt(4)->Playback();
	}
	else
	{
		//Toggle the necessary bits (Bits number 2-5  -  REMEMBER THE FIRST BIT IS BIT 0)
		// using the following method;  read the status port. Create a temporary variable
		// to represent the data port and assign all 1's to the pins except for those pins
		// Numbered 2-5 that you want to be 0. AND this temp. var with the eresult of the
		// data port read. Create a second temp variable and assign a 0 to each pin except
		// for those Numbered 2-5 that should be 1. Finally OR the two temp variable together
		// write the result to the data port.
	
		// This method only changes the values of the pins numbered 2-5

		BYTE byteTemp1;
		BYTE byteTemp2;
		BYTE byteToWrite;

		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xF3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x30;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );

		::Sleep(250);

		// Clear the data port (pins # 2-5) using the above method
		byteToWrite	= m_pPP->ReadDataPort();

		byteTemp1 = 0xC3;
		byteTemp2 = byteToWrite & byteTemp1;
		byteTemp1 = 0x00;
		byteToWrite = byteTemp1 | byteTemp2;

		m_pPP->WriteDataPort( byteToWrite );
	}
}


void CControlVCR::VPC()
{
	if( m_bWireless )	// wireless case
	{
		// send IR command
	}
	else
	{
		if(m_bPowerOn == FALSE)
		{
			Power();
			m_bPowerOn = TRUE;
		}
		else
			Power();
	}
}