// IRRemoteControl.cpp: implementation of the CIRRemoteControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "IRRemoteControl.h"

#include <conio.h>
#include <dos.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define MAXSAMPLE 50000

//////////////////////////////////////////////////////////////////////
// class CIRRemoteControl

IMPLEMENT_SERIAL( CIRRemoteControl, CObject, 1 )

//////////////////////////////////////////////////////////////////////
// Construction/Destruction

CIRRemoteControl::CIRRemoteControl()
{

	m_pbyteData	=	NULL;
	m_dwLength	=	0;

	m_pbyteData = new BYTE[MAXSAMPLE];
	for(DWORD i=0; i<MAXSAMPLE; i++ )
		m_pbyteData[i] = 0;


	// init local copy of COM parallel port object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pPP = pApp->GetSystemSettings()->GetParallelPort();
}


CIRRemoteControl::~CIRRemoteControl()
{
/*
	if( m_pbData != NULL )
	{
		delete m_pbData;
		m_pbData = NULL;
	}
*/
}


//////////////////////////////////////////////////////////////////////
// Serialize the CIRRemoteControl object

void CIRRemoteControl::Serialize( CArchive& archive )
{
    // call base class function first
    // base class is CObject in this case
    CObject::Serialize( archive );

    // now do the stuff for our specific class
    if( archive.IsStoring() )
	{
		// do storing
        m_byteDataArray.Serialize( archive );
	}
    else
	{
		// do retrieve
        m_byteDataArray.Serialize( archive );
	}
}


//////////////////////////////////////////////////////////////////////////
// CIRRemoteControl::Record()

void CIRRemoteControl::Record()
{
	DWORD	i, j, len;
	BYTE	mask, d;
//	BYTE	bStatus;

	CCriticalSection criticalSection;

	BYTE byteMask		= 0x00;
	BYTE byteTemp		= 0x00;
	BYTE byteDevice		= 0x00;
	BYTE byteToWrite	= 0x00;

//////////////////////////////////////////////////////////////////////////
// code for the test board

	criticalSection.Lock();

	// set D1 on 1
	byteMask		= 0xFD;	// mask out D1
	byteTemp		= 0x00;
	byteDevice		= 0x02;
	byteToWrite		= 0x00;

//	byteToWrite	= m_pPP->ReadDataPort();
	byteToWrite	= _inp(LPT3);

	byteTemp	= byteMask & byteToWrite;
	byteToWrite = byteTemp | byteDevice;

//	m_pPP->WriteDataPort( byteToWrite );
	_outp(LPT3,byteToWrite);


//	while( (bStatus = m_pPP->ReadStatusPort() & 16) == 0);
//	while( (bStatus = m_pPP->ReadStatusPort() & 16) == 16);	// Wait for 1st data
	while ((_inp(LPT3+1)&16)==0);
	while ((_inp(LPT3+1)&16)==16); 

	for (i=0; i<MAXSAMPLE; i++)
	{
		mask=128;
		d=0;
		for (j=0; j<8; j++)
		{
//			if ( (bStatus = m_pPP->ReadStatusPort() & 16 ) == 0) d |= mask;
			if ((_inp(LPT3+1)&16)==0) d |= mask;
			mask=mask>>1;
		}
		m_pbyteData[i] = d;
	}


	// set D1 on 0
	byteMask	= 0xFD;	// mask out D1
	byteTemp	= 0x00;
	byteDevice	= 0x00;
	byteToWrite	= 0x00;

//	byteToWrite	= m_pPP->ReadDataPort();
	byteToWrite	= _inp(LPT3);

	byteTemp	= byteMask & byteToWrite;
	byteToWrite = byteTemp | byteDevice;

//	m_pPP->WriteDataPort( byteToWrite );
	_outp(LPT3, byteToWrite); 


	// Chop off ending
	for (len=MAXSAMPLE-1; len; len--)
	{
		if (m_pbyteData[len] != 0xFF) 
		{
			m_dwLength = len;
			break;
		}
	}

	// make a copy into our CByteArray
	for( i=0; i < m_dwLength; i++ )
		m_byteDataArray.Add( m_pbyteData[i] );

	criticalSection.Unlock();

// code for the test board
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// the code for the real board	
/*
	criticalSection.Lock();

	// set D3 ON (the IR wizard LED)
	byteMask		= 0xF7;	// mask out D3
	byteTemp		= 0x00;
	byteDevice		= 0x08;
	byteToWrite		= 0x00;

//	byteToWrite	= m_pPP->ReadDataPort();
	byteToWrite = _inp( LPT1 );

	byteTemp	= byteMask & byteToWrite;
	byteToWrite = byteTemp | byteDevice;

//	m_pPP->WriteDataPort( byteToWrite );
	_outp(LPT1,byteToWrite);	


	
	// set D6 on 1
	byteMask		= 0xBF;	// mask out D6
	byteTemp		= 0x00;
	byteDevice		= 0x40;
	byteToWrite		= 0x00;

//	byteToWrite	= m_pPP->ReadDataPort();
	byteToWrite = _inp( LPT1 );

	byteTemp	= byteMask & byteToWrite;
	byteToWrite = byteTemp | byteDevice;

//	m_pPP->WriteDataPort( byteToWrite );
	_outp(LPT1,byteToWrite);

//	while( (bStatus = m_pPP->ReadStatusPort() & 16) == 0);
//	while( (bStatus = m_pPP->ReadStatusPort() & 16) == 16);	// Wait for 1st data
	while ((_inp(LPT1+1)&16)==0);
	while ((_inp(LPT1+1)&16)==16); 
	

	for (i=0; i<MAXSAMPLE; i++)
	{
		mask=128;
		d=0;
		for (j=0; j<8; j++)
		{
//			if ( (bStatus = m_pPP->ReadStatusPort() & 16 ) == 0) d |= mask;
			if ((_inp(LPT1+1)&16)==0) d |= mask;
			mask=mask>>1;
		}
		m_pbyteData[i] = d;
	}

	
	// set D6 on 0
	byteMask	= 0xBF;	// mask out D6
	byteTemp	= 0x00;
	byteDevice	= 0x00;
	byteToWrite	= 0x00;

//	byteToWrite	= m_pPP->ReadDataPort();
	byteToWrite = _inp( LPT1 );

	byteTemp	= byteMask & byteToWrite;
	byteToWrite = byteTemp | byteDevice;

//	m_pPP->WriteDataPort( byteToWrite );
	_outp(LPT1,byteToWrite);


	
	// set D3 OFF (the IR wizard LED)
	byteMask		= 0xF7;	// mask out D3
	byteTemp		= 0x00;
	byteDevice		= 0x00;
	byteToWrite		= 0x00;

//	byteToWrite	= m_pPP->ReadDataPort();
	byteToWrite = _inp( LPT1 );

	byteTemp	= byteMask & byteToWrite;
	byteToWrite = byteTemp | byteDevice;

//	m_pPP->WriteDataPort( byteToWrite );
	_outp(LPT1,byteToWrite);


	// Chop off ending
	for (len=MAXSAMPLE-1; len; len--)
	{
		if (m_pbyteData[len] != 0xFF) 
		{
			m_dwLength = len;
			break;
		}
	}

	// make a copy into our CByteArray
	for( i=0; i < m_dwLength; i++ )
		m_byteDataArray.Add( m_pbyteData[i] );

	criticalSection.Unlock();
*/
// code for the real board
//////////////////////////////////////////////////////////////////////////

}


void CIRRemoteControl::Playback()
{

	DWORD	i, j;
	BYTE	mask, d;

	BYTE	byteMask		= 0x00;
	BYTE	byteTemp		= 0x00;
	BYTE	byteDevice		= 0x00;
	BYTE	byteToWrite		= 0x00;
	BYTE	byteToWriteSET	= 0x00;
	BYTE	byteToWriteRESET= 0x00;

	CCriticalSection criticalSection;

	// make a copy of the actual IR pattern
	if( m_byteDataArray.GetSize() > 0 )
	{
		m_dwLength = m_byteDataArray.GetSize();
		for( DWORD i=0; i < m_dwLength; i++ )
			m_pbyteData[i] = m_byteDataArray[i];
	}


//////////////////////////////////////////////////////////////////////////
// code for the test board

	criticalSection.Lock();


	for (i=0; i < m_dwLength; i++)
	{
		mask = 128;
		d = m_pbyteData[i];
		for (j=0; j<8; j++)
		{
			if ( d & mask) 
				_outp(LPT1, 0x80);	// set D7 on 1
			else 
				_outp(LPT1, 0);	// set D7 on 0
			
			mask=mask>>1;
		}
	}

	criticalSection.Unlock();

// code for the test board
//////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// code for the real board
/*
	criticalSection.Lock();

	// set D3 and D5 on 1
	byteMask		= 0xD7;	
	byteTemp		= 0x00;
	byteDevice		= 0x28;
	byteToWriteSET	= 0x00;

//	byteToWrite	= m_pPP->ReadDataPort();
	byteToWriteSET = _inp( LPT1 );

	byteTemp		= byteMask & byteToWriteSET;
	byteToWriteSET	= byteTemp | byteDevice;


	// set D3 and D5 on 0
	byteMask			= 0xD7;	// mask out D3 and D5
	byteTemp			= 0x00;
	byteDevice			= 0x00;
	byteToWriteRESET	= 0x00;


//	byteToWrite	= m_pPP->ReadDataPort();
	byteToWriteRESET	= _inp( LPT1 );

	byteTemp			= byteMask & byteToWriteRESET;
	byteToWriteRESET	= byteTemp | byteDevice;
	
	
	for (i=0; i<m_dwLength; i++)
	{
		mask = 128;
		d = m_pbyteData[i];
		for (j=0; j<8; j++)
		{
			if ( d & mask) 
				_outp(LPT1, byteToWriteSET);
			else 
				_outp(LPT1, byteToWriteRESET);
			
			mask=mask>>1;
		}
	}

	
	// make sure we turn the LED off
	// set D3 and D5 on 0
	_outp(LPT1, byteToWriteRESET);
	

	criticalSection.Unlock();
*/
// code for the real board
//////////////////////////////////////////////////////////////////////////

}
