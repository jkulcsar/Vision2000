// ParallelPort.cpp : implementation file
//

#include "stdafx.h"
#include "PPCOM.h"
#include "Interface.h"
#include "ParallelPort.h"

#include <conio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



/////////////////////////////////////////////////////////////////////////////
// CParallelPort


	//  IRead
	// {A417E6A0-323D-11d3-AFB0-004095D0EF62}
	static const IID IID_IRead = 
	{ 0xA417E6A0, 0x323D, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };

	//  IWrite
	// {6FF402E0-323E-11d3-AFB0-004095D0EF62}
	static const IID IID_IWrite = 
	{ 0x6FF402E0, 0x323E, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	// IGet
	// {6F448280-362F-11d3-AFB0-004095D0EF62}
	static const IID IID_IGet = 
	{ 0x6F448280, 0x362F, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	// ISet
	// {6F448281-362F-11d3-AFB0-004095D0EF62}
	static const IID IID_ISet = 
	{ 0x6F448281, 0x362F, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	// ITest
	// {6F448282-362F-11d3-AFB0-004095D0EF62}
	static const IID IID_ITest = 
	{ 0x6F448282, 0x362F, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	//  IParallelPort
	// {98757173-3237-11D3-AFB0-004095D0EF62}
	//static const IID IID_IParallelPort =
	//{ 0x98757173, 0x3237, 0x11d3, 
	//{ 0xaf, 0xb0, 0x0, 0x40, 0x95, 0xd0, 0xef, 0x62 } };



IMPLEMENT_DYNCREATE(CParallelPort, CCmdTarget)

CParallelPort::CParallelPort()
{
	m_bEnabled				= FALSE;
	m_strName				= "";
	m_strPortType			= "";
	m_usAddress				= 0;
	m_usECPModeValue		= 0; 
	m_strECPModeDescription	= "";

	// To keep the application running as long as an OLE automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();
}

CParallelPort::~CParallelPort()
{
	// To terminate the application when all objects created with
	// 	with OLE automation, the destructor calls AfxOleUnlockApp.
	
	AfxOleUnlockApp();
}


void CParallelPort::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}


BEGIN_MESSAGE_MAP(CParallelPort, CCmdTarget)
	//{{AFX_MSG_MAP(CParallelPort)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CParallelPort, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CParallelPort)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IParallelPort to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.


BEGIN_INTERFACE_MAP(CParallelPort, CCmdTarget)
	INTERFACE_PART(CParallelPort, IID_IRead, Read)
	INTERFACE_PART(CParallelPort, IID_IWrite, Write)
	INTERFACE_PART(CParallelPort, IID_IGet, Get)
	INTERFACE_PART(CParallelPort, IID_ISet, Set)
	INTERFACE_PART(CParallelPort, IID_ITest, Test)
END_INTERFACE_MAP()

// {98757174-3237-11D3-AFB0-004095D0EF62}
IMPLEMENT_OLECREATE(CParallelPort, "ParallelPort", 0x98757174, 0x3237, 0x11d3, 0xaf, 0xb0, 0x0, 0x40, 0x95, 0xd0, 0xef, 0x62)



/////////////////////////////////////////////////////////////////////////////
// CParallelPort::XRead


STDMETHODIMP_(ULONG) CParallelPort::XRead::AddRef()
{
	TRACE( _T("CParallelPort::XRead::AddRef()"));
	METHOD_PROLOGUE(CParallelPort, Read)
	return pThis->ExternalAddRef();
}


STDMETHODIMP_(ULONG) CParallelPort::XRead::Release()
{
	TRACE( _T("CParallelPort::XRead::Release()"));
	METHOD_PROLOGUE(CParallelPort, Read)
	return pThis->ExternalRelease();
}


STDMETHODIMP CParallelPort::XRead::QueryInterface( REFIID iid, LPVOID* ppvObj )
{
	TRACE( _T("CParallelPort::XRead::QueryInterface()"));
	METHOD_PROLOGUE(CParallelPort, Read)
	return pThis->ExternalQueryInterface( &iid, ppvObj );
}


STDMETHODIMP_(BYTE) CParallelPort::XRead::ReadControlPort()
{
	TRACE( _T("CParallelPort::XRead::ReadControlPort()"));
	METHOD_PROLOGUE(CParallelPort, Read)
	return pThis->ReadControlPort();
}


STDMETHODIMP_(BYTE) CParallelPort::XRead::ReadDataPort()
{
	TRACE( _T("CParallelPort::XRead::ReadDataPort()"));
	METHOD_PROLOGUE(CParallelPort, Read)
	return pThis->ReadDataPort();
}


STDMETHODIMP_(BYTE) CParallelPort::XRead::ReadStatusPort()
{
	TRACE( _T("CParallelPort::XRead::ReadStatusPort()"));
	METHOD_PROLOGUE(CParallelPort, Read)
	return pThis->ReadStatusPort();
}


/////////////////////////////////////////////////////////////////////////////
// CParallelPort::XWrite

STDMETHODIMP_(ULONG) CParallelPort::XWrite::AddRef()
{
	TRACE( _T("CParallelPort::XWrite::AddRef()"));
	METHOD_PROLOGUE(CParallelPort, Write)
	return pThis->ExternalAddRef();
}


STDMETHODIMP_(ULONG) CParallelPort::XWrite::Release()
{
	TRACE( _T("CParallelPort::XWrite::Release()"));
	METHOD_PROLOGUE(CParallelPort, Write)
	return pThis->ExternalRelease();
}


STDMETHODIMP CParallelPort::XWrite::QueryInterface( REFIID iid, LPVOID* ppvObj )
{
	TRACE( _T("CParallelPort::XWrite::QueryInterface()"));
	METHOD_PROLOGUE(CParallelPort, Write)
	return pThis->ExternalQueryInterface( &iid, ppvObj );
}


STDMETHODIMP_(void) CParallelPort::XWrite::WriteControlPort( BYTE byteToWrite )
{
	TRACE( _T("CParallelPort::XWrite::WriteControlPort()"));
	METHOD_PROLOGUE(CParallelPort, Write)
	pThis->WriteControlPort(byteToWrite);
}


STDMETHODIMP_(void) CParallelPort::XWrite::WriteDataPort( BYTE byteToWrite )
{
	TRACE( _T("CParallelPort::XWrite::WriteDataPort()"));
	METHOD_PROLOGUE(CParallelPort, Write)
	pThis->WriteDataPort(byteToWrite);
}


/////////////////////////////////////////////////////////////////////////////
// CParallelPort::XGet


STDMETHODIMP_(ULONG) CParallelPort::XGet::AddRef()
{
	TRACE( _T("CParallelPort::XGet::AddRef()"));
	METHOD_PROLOGUE(CParallelPort, Get)
	return pThis->ExternalAddRef();
}


STDMETHODIMP_(ULONG) CParallelPort::XGet::Release()
{
	TRACE( _T("CParallelPort::XGet::Release()"));
	METHOD_PROLOGUE(CParallelPort, Get)
	return pThis->ExternalRelease();
}


STDMETHODIMP CParallelPort::XGet::QueryInterface( REFIID iid, LPVOID* ppvObj )
{
	TRACE( _T("CParallelPort::XGet::QueryInterface()"));
	METHOD_PROLOGUE(CParallelPort, Get)
	return pThis->ExternalQueryInterface( &iid, ppvObj );
}


STDMETHODIMP_(LPCTSTR) CParallelPort::XGet::GetECPModeDescription()
{
	METHOD_PROLOGUE(CParallelPort, Get)
	return (LPCTSTR) pThis->GetECPModeDescription();
}


STDMETHODIMP_(LPCTSTR) CParallelPort::XGet::GetName()
{
	METHOD_PROLOGUE(CParallelPort, Get)
	return (LPCTSTR) pThis->GetName();
}


STDMETHODIMP_(LPCTSTR) CParallelPort::XGet::GetPortType()
{
	METHOD_PROLOGUE(CParallelPort, Get)
	return (LPCTSTR) pThis->GetPortType();
}


STDMETHODIMP_(unsigned short) CParallelPort::XGet::GetAddress()
{
	METHOD_PROLOGUE(CParallelPort, Get)
	return pThis->GetAddress();
}





/////////////////////////////////////////////////////////////////////////////
// CParallelPort::XSet


STDMETHODIMP_(ULONG) CParallelPort::XSet::AddRef()
{
	TRACE( _T("CParallelPort::XSet::AddRef()"));
	METHOD_PROLOGUE(CParallelPort, Set)
	return pThis->ExternalAddRef();
}


STDMETHODIMP_(ULONG) CParallelPort::XSet::Release()
{
	TRACE( _T("CParallelPort::XSet::Release()"));
	METHOD_PROLOGUE(CParallelPort, Set)
	return pThis->ExternalRelease();
}


STDMETHODIMP CParallelPort::XSet::QueryInterface( REFIID iid, LPVOID* ppvObj )
{
	TRACE( _T("CParallelPort::XSet::QueryInterface()"));
	METHOD_PROLOGUE(CParallelPort, Set)
	return pThis->ExternalQueryInterface( &iid, ppvObj );
}

STDMETHODIMP_(void) CParallelPort::XSet::SetAddress( unsigned short uiAddress )
{
	TRACE( _T("CParallelPort::XSet::SetAddress()"));
	METHOD_PROLOGUE(CParallelPort, Set)
	pThis->SetAddress(uiAddress);
}

STDMETHODIMP_(void) CParallelPort::XSet::SetName( LPCTSTR pszName )
{
	TRACE( _T("CParallelPort::XSet::SetName()"));
	METHOD_PROLOGUE(CParallelPort, Set)
	pThis->SetName(pszName);
}



/////////////////////////////////////////////////////////////////////////////
// CParallelPort::XTest


STDMETHODIMP_(ULONG) CParallelPort::XTest::AddRef()
{
	TRACE( _T("CParallelPort::XTest::AddRef()"));
	METHOD_PROLOGUE(CParallelPort, Test)
	return pThis->ExternalAddRef();
}


STDMETHODIMP_(ULONG) CParallelPort::XTest::Release()
{
	TRACE( _T("CParallelPort::XTest::Release()"));
	METHOD_PROLOGUE(CParallelPort, Test)
	return pThis->ExternalRelease();
}


STDMETHODIMP CParallelPort::XTest::QueryInterface( REFIID iid, LPVOID* ppvObj )
{
	TRACE( _T("CParallelPort::XTest::QueryInterface()"));
	METHOD_PROLOGUE(CParallelPort, Test)
	return pThis->ExternalQueryInterface( &iid, ppvObj );
}

STDMETHODIMP_(BOOL) CParallelPort::XTest::TestPort()
{
	TRACE( _T("CParallelPort::XTest::TestPort()"));
	METHOD_PROLOGUE(CParallelPort, Test)
	return pThis->TestPort();
}

STDMETHODIMP_(BOOL) CParallelPort::XTest::IsEnabled()
{
	TRACE( _T("CParallelPort::XTest::IsEnabled()"));
	METHOD_PROLOGUE(CParallelPort, Test)
	return pThis->IsEnabled();
}




/////////////////////////////////////////////////////////////////////////////

BOOL CParallelPort::IsEnabled()
{
	return m_bEnabled;
}

void CParallelPort::SetAddress(unsigned short usAddress)
{
	m_usAddress = usAddress;
}

unsigned short CParallelPort::GetAddress()
{
	return m_usAddress;
}

BOOL CParallelPort::TestPort()
{
	BOOL	bECPExists	= FALSE;
	BOOL	bEPPExists	= FALSE;
	BOOL	bSPPExists	= FALSE;
	BOOL	bPS2Exists	= FALSE;
	CString	strPortType = "";

	if( TestForECP() )
	{
		m_strPortType = "ECP";
		ReadECPModeValueAndDescription();
		EnablePort(TRUE);
	}
	else
	{
		if( TestForEPP() )
		{
			m_strPortType = "EPP";
			EnablePort(TRUE);
		}
		else
			if( TestForSPP() )
				if( TestForPS2() )
				{
					m_strPortType = "PS2";
					EnablePort(TRUE);
				}
				else
				{
					m_strPortType = "SPP";
					EnablePort(TRUE);
				}
			else
			{
				m_strPortType = "";
				EnablePort(FALSE);
				return FALSE;
			}
	}
	
	return TRUE;
}

BOOL CParallelPort::TestForECP()
{
	// Test for the presence of an ECP.
	// If the ECP is idle and the FIFO empty,
	// in the ECP's Ecr (at Base Address+402h),
	// bit 1(Fifo full)=0, and bit 0(Fifo empty)=1.
	// The first test is to see if these bits differ from the
	// corresponding bits in the control port (at Base Address+2).
	// If so, a further test is to write 34h to the Ecr,
	// then read it back. Bit 1 is read/write, and bit 0 is read-only.
	// If the value read is 35h, the port is an ECP.
	BYTE bEcrBit0;
	BYTE bEcrBit1;
	BYTE bEcrData;
	BYTE bOriginalEcrData;

	BYTE bControlBit1;
	BYTE bControlPortData;
	
	unsigned short usEcrAddress;

	BOOL	bECPResult	=	FALSE;

	usEcrAddress = m_usAddress + 0x402;

	// Read ECR bits 0 & 1 and Control Port bit 1.
	bEcrData = _inp(usEcrAddress);
	bEcrBit0 = bEcrData & 0x01;
	bEcrBit1 = (bEcrData & 0x02) >> 1;

	bControlPortData = ReadControlPort();
	bControlBit1 = (bControlPortData & 0x02) >> 1;

    // Compare control bit 1 to ECR bit 1.
    // Toggle the control bit if necessary,
    // to be sure the two registers are different.
	if( (bEcrBit0 == 1) && (bEcrBit1 == 0) )
	{
		if( bControlBit1 == 0 )
		{
			WriteControlPort(0x0F);
			bControlPortData = ReadControlPort();
			bControlBit1 = (bControlPortData & 0x02) >> 1;
		}
		if( bEcrBit1 != bControlBit1 )
		{
			bOriginalEcrData = bEcrData;
			_outp( usEcrAddress, 0x34 );
			bEcrData = _inp( usEcrAddress );
			if( bEcrData == 0x35 )
				bECPResult = TRUE;
		}
		// Restore the ECR to its original value.
		_outp( usEcrAddress, bOriginalEcrData );
	}
	return bECPResult;
}

BOOL CParallelPort::TestForEPP()
{
	// Write to an Epp register, then read it back.
	// If the reads match the writes, it's probably an Epp.
	BOOL	bEPPResult	=	FALSE;
	unsigned short usByteRead;
	unsigned short usTimeoutBit;
	unsigned short usStatusPortAddress	= m_usAddress + 0x01;
	unsigned short usEppAddressPort		= m_usAddress + 0x03;

	_outp( usEppAddressPort, 0x55 );
	
	// clear the timeout bit after each EPP operation.
	usTimeoutBit = ReadEPPTimeoutBit();
	usByteRead = _inp( usEppAddressPort );
	usTimeoutBit = ReadEPPTimeoutBit();
	if( usByteRead == 0x55 )
	{
		_outp( usEppAddressPort, 0xAA );
		usTimeoutBit = ReadEPPTimeoutBit();
		usByteRead = _inp( usEppAddressPort );
		usTimeoutBit = ReadEPPTimeoutBit();
		if( usByteRead == 0xAA )
			bEPPResult = TRUE;
	}

	return bEPPResult;
}

BOOL CParallelPort::TestForSPP()
{
	//	Write two bytes and read them back.
	//	If the reads match the writes, the port exists.
	BOOL	bSPPResult = FALSE;
	unsigned short usByteRead;

	// Be sure that control port bit 5 = 0 (data outputs enabled).
	WriteControlPort( 0x0F );

	WriteDataPort( 0x55 );
	usByteRead = ReadDataPort();
	if( usByteRead == 0x55 )
	{
		WriteDataPort( 0xAA );
		usByteRead = ReadDataPort();
		if( usByteRead == 0xAA )
			bSPPResult = TRUE;
	}

	return bSPPResult;
}


BOOL CParallelPort::TestForPS2()
{
	// Tests a parallel port's data port for bidirectional ability.
	// First, try to tri-state (disable) the data outputs by
	// setting bit 5 of the Control port.
	// Then write 2 values to the data port and read each back
	// If the values match, the data outputs are not disabled,
	// and the port is not bidirectional.
	// If the values don't match,
	// the data outputs are disabled and the port is bidirectional.
	BOOL bPS2Result = FALSE;
	unsigned short usDataInput;

	// Set Control port bit 5.
	WriteControlPort( 0x2F );

	// Write the first byte and read it back:
	WriteDataPort( 0x55 );
	usDataInput = ReadDataPort();

	// If it doesn't match, the port is bidirectional.
	if( usDataInput != 0x55 )
		bPS2Result = TRUE;
	// If it matches, write another and read it back.
	if( usDataInput == 0x55 )
	{
		WriteDataPort( 0xAA );
		usDataInput = ReadDataPort();
		// If it doesn't match, the port is bidirectional
		if( usDataInput != 0xAA)
			bPS2Result = TRUE;
	}

	// Reset Control port bit 5
	WriteControlPort( 0x0F );

	return bPS2Result;
}


void CParallelPort::ReadECPModeValueAndDescription()
{
	// The Ecr mode is in bits 5, 6, and 7 of the ECR.
	// Bit configuration (bits marked with x)
	//  76543210
	// +--------+
	// |xxx     |
	// +--------+
	
	unsigned short usEcrAddress = m_usAddress + 0x402;
	BYTE byteEcrData = _inp( usEcrAddress );
	m_usECPModeValue =  (byteEcrData & 0xE0) >> 5;

	switch( m_usECPModeValue )
	{
		case 0:
			m_strECPModeDescription = "SPP";
			break;
		case 1:
			m_strECPModeDescription = "PS/2";
			break;
		case 10:
			m_strECPModeDescription = "Fast Centronics";
			break;
		case 11:
			m_strECPModeDescription = "ECP";
			break;
		case 100:
	        m_strECPModeDescription = "EPP";
			break;
		case 110:
	        m_strECPModeDescription = "Test";
			break;
		case 111:
			m_strECPModeDescription = "Configuration";
			break;
	}

}

BYTE CParallelPort::ReadControlPort()
{
	// Reads a parallel port's control port.
	// Calculates the control-port address from the port's
	// base address, and inverts bits 0, 1, & 3 of the byte read.
	// The control-port hardware reinverts these bits,
	// so the value read matches the value at the connector.

	return _inp( (m_usAddress + 2) ^ 0x0B);
}

BYTE CParallelPort::ReadDataPort()
{
	return _inp( m_usAddress ); 
}



void CParallelPort::WriteControlPort(BYTE byteToWrite)
{
	// Writes a Value to a parallel port's control port.
	// Calculates the control-port address from the port's
	// base address, and inverts bits 0, 1, & 3.
	// The control-port hardware reinverts these bits,
	// so Value is written to the port connector.
	
	_outp( (m_usAddress + 2), byteToWrite ^ 0x0B );
}

void CParallelPort::WriteDataPort(BYTE byteDataToWrite)
{
	_outp( m_usAddress, byteDataToWrite );
}



unsigned short CParallelPort::ReadEPPTimeoutBit()
{
	// Reads and clears the EPP timeout bit (status port bit 0).
	// Should be done after each EPP operation.
	// The method for clearing the bit varies, so try 3 ways:
	// 1. Write 1 to it.
	// 2. Write 0 to it.
	// 3. Read it again.
	unsigned short usStatusPortAddress = m_usAddress + 0x01;
	unsigned short usReadAgain;
	unsigned short usEPPTimeoutBit;

	usEPPTimeoutBit = ReadStatusPort() & 0x01;
	_outp( usStatusPortAddress, 0x01 );
	_outp( usStatusPortAddress, 0x00 );
	usReadAgain = ReadStatusPort() & 0x01;

	return usEPPTimeoutBit;
}

BYTE CParallelPort::ReadStatusPort()
{
	// Reads a parallel port's status port.
	// Calculates the status-port address from the port's
	// base address, and inverts bit 7 of the byte read.
	// The status-port hardware reinverts these bits,
	// so the value read matches the value at the connector.
	BYTE byteTempRead;
	byteTempRead = _inp( m_usAddress + 0x01 );
	return ( byteTempRead ^ 0x80 );
}


void CParallelPort::EnablePort(BOOL bValue)
{
	m_bEnabled = bValue;
}


void CParallelPort::SetName(CString strName)
{
	m_strName = strName;
}

CString CParallelPort::GetPortType()
{
	return m_strPortType;
}

CString CParallelPort::GetName()
{
	return m_strName;
}

CString& CParallelPort::GetECPModeDescription()
{
	return m_strECPModeDescription;
}



/////////////////////////////////////////////////////////////////////////////
// CParallelPort message handlers
