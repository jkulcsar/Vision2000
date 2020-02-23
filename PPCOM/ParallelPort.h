#if !defined(AFX_PARALLELPORT_H__98757175_3237_11D3_AFB0_004095D0EF62__INCLUDED_)
#define AFX_PARALLELPORT_H__98757175_3237_11D3_AFB0_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ParallelPort.h : header file
//


/////////////////////////////////////////////////////////////////////////////
// for interface tracing purposes
void ITrace( REFIID iid, const char* str);


/////////////////////////////////////////////////////////////////////////////
// CParallelPort command target

class CParallelPort : public CCmdTarget
{
	DECLARE_DYNCREATE(CParallelPort)

	CParallelPort();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CParallelPort)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CParallelPort)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CParallelPort)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CParallelPort)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	BEGIN_INTERFACE_PART(Read, IRead)
		STDMETHOD_(BYTE, ReadControlPort) ();
		STDMETHOD_(BYTE, ReadDataPort) ();
		STDMETHOD_(BYTE, ReadStatusPort) ();
	END_INTERFACE_PART(Read)

	BEGIN_INTERFACE_PART(Write, IWrite)
		STDMETHOD_( void, WriteControlPort) ( BYTE );
		STDMETHOD_( void, WriteDataPort) ( BYTE );
	END_INTERFACE_PART(Write)

	BEGIN_INTERFACE_PART(Get, IGet)
	 	STDMETHOD_( LPCTSTR, GetECPModeDescription)();
		STDMETHOD_( LPCTSTR,  GetName) ();
		STDMETHOD_( LPCTSTR,  GetPortType)();
		STDMETHOD_( unsigned short,  GetAddress)();
	END_INTERFACE_PART(Get)

	BEGIN_INTERFACE_PART(Set, ISet)
		STDMETHOD_( void, SetAddress)( unsigned short );
		STDMETHOD_( void, SetName)( LPCTSTR );
	END_INTERFACE_PART(Set)

	BEGIN_INTERFACE_PART(Test, ITest)
	 	STDMETHOD_( BOOL, TestPort)();
		STDMETHOD_( BOOL, IsEnabled)();
	END_INTERFACE_PART(Test)


	DECLARE_INTERFACE_MAP()

public:
	CString& GetECPModeDescription();
	CString GetName();
	CString GetPortType();
	void SetName( CString strName );
	BOOL TestPort();
	unsigned short GetAddress();
	void SetAddress( unsigned short uiAddress );
	BOOL IsEnabled();
	// write functions
	void WriteControlPort( BYTE byteToWrite );
	void WriteDataPort( BYTE  byteDataToWrite );
	// read functions
	BYTE ReadControlPort();
	BYTE ReadDataPort();
	BYTE ReadStatusPort();

	virtual ~CParallelPort();

protected:

private:
	void EnablePort( BOOL );
	unsigned short ReadEPPTimeoutBit();
	void ReadECPModeValueAndDescription();
	BOOL TestForPS2();
	BOOL TestForSPP();
	BOOL TestForEPP();
	BOOL TestForECP();

private:	// member variables	
	BOOL m_bEnabled;
	BYTE m_usECPModeValue;
	CString m_strName;
	CString m_strPortType;
	CString m_strECPModeDescription;
	unsigned short m_usAddress;		// base address of port

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PARALLELPORT_H__98757175_3237_11D3_AFB0_004095D0EF62__INCLUDED_)
