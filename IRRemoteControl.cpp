// IRRemoteControl.cpp: implementation of the CIRRemoteControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "IRRemoteControl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define MAXSAMPLE 10000

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIRRemoteControl::CIRRemoteControl()
{
	m_pbData	=	NULL;
	m_dwLength	=	0;

	m_pbData = new BYTE[MAXSAMPLE];
	for(DWORD i=0; i<MAXSAMPLE; i++ )
		m_pbData[i] = 0;

	// init local copy of COM parallel port object
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	m_pPP = pApp->GetSystemSettings()->GetParallelPort();
}


CIRRemoteControl::~CIRRemoteControl()
{
	if( m_pbData != NULL )
	{
		delete m_pbData;
		m_pbData = NULL;
	}
}


void CIRRemoteControl::Record()
{
	DWORD i, j, len;
	unsigned char mask, d;
	BYTE bStatus;
	

//	_disable();
	m_criticalSection.Lock();

	m_pPP->WriteDataPort(2);

	while( (bStatus = m_pPP->ReadStatusPort() & 16) == 0);
	while( (bStatus = m_pPP->ReadStatusPort() & 16) == 16);	// Wait for 1st data

	for (i=0; i<MAXSAMPLE; i++)
	{
		mask=128;
		d=0;
		for (j=0; j<8; j++)
		{
			if ( (bStatus = m_pPP->ReadStatusPort() & 16 ) == 0) d |= mask;
			mask=mask>>1;
		}
		m_pbData[i] = d;
	}

	m_pPP->WriteDataPort(0);

//	_enable();
	m_criticalSection.Unlock();

	/* Chop off ending zeros */
	for (len=MAXSAMPLE-1; len; len--)
		if (m_pbData[len]) break;

	m_dwLength = len;
}


void CIRRemoteControl::Playback()
{
	DWORD i, j;
	unsigned char mask, d;

	
	m_criticalSection.Lock();
//	_disable();

	for (i=0; i<m_dwLength; i++)
	{
		mask = 128;
		d = m_pbData[i];
		for (j=0; j<8; j++)
		{
			if ( d & mask) 
				m_pPP->WriteDataPort(1);
			else 
				m_pPP->WriteDataPort(0);
			
			mask=mask>>1;
		}
	}
//	_enable();
	m_criticalSection.Unlock();

	m_pPP->WriteDataPort(0);
}
