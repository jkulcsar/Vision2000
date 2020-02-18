// COMParallelPort.h: interface for the CCOMParallelPort class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPARALLELPORT_H__53B42BA1_56F1_11D3_AFB1_004095D0EF62__INCLUDED_)
#define AFX_COMPARALLELPORT_H__53B42BA1_56F1_11D3_AFB1_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CCOMParallelPort  
{
	private:
		IRead	*m_pRead;
		IWrite	*m_pWrite;
		ITest	*m_pTest;
		IGet	*m_pGet;
		ISet	*m_pSet;

	    CLSID			clsid;
		LPCLASSFACTORY	m_pClf; 
		LPUNKNOWN		m_pUnk;

	public:
		void WriteDataPort(BYTE);
		BYTE ReadDataPort();
		BOOL InitializeAt(unsigned short);
		BOOL IsEnabled();
		CCOMParallelPort();
		virtual ~CCOMParallelPort();

};

#endif // !defined(AFX_COMPARALLELPORT_H__53B42BA1_56F1_11D3_AFB1_004095D0EF62__INCLUDED_)
