// COMParallelPort.cpp: implementation of the CCOMParallelPort class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Vision2000.h"
#include "COMParallelPort.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCOMParallelPort::CCOMParallelPort()
{
    HRESULT			hr;

	// init interface pointers
	m_pRead		= NULL;
	m_pWrite	= NULL;
	m_pTest		= NULL;
	m_pGet		= NULL;
	m_pSet		= NULL;


    if ((hr = ::CLSIDFromProgID(L"ParallelPort", &clsid)) != NOERROR) {
        TRACE("unable to find Program ID -- error = %x\n", hr);
        return;
    }
    if ((hr = ::CoGetClassObject(clsid, CLSCTX_INPROC_SERVER,
        NULL, IID_IClassFactory, (void **) &m_pClf)) != NOERROR) 
	{
        TRACE("unable to find CLSID -- error = %x\n", hr);
        return;
    }

    m_pClf->CreateInstance(NULL, IID_IUnknown, (void**) &m_pUnk);

    m_pUnk->QueryInterface(		IID_IRead,	(void**) &m_pRead);	
    m_pRead->QueryInterface(	IID_IWrite,	(void**) &m_pWrite);
	m_pWrite->QueryInterface(	IID_IGet,	(void**) &m_pGet);
	m_pGet->QueryInterface(		IID_ISet,	(void**) &m_pSet);
	m_pSet->QueryInterface(		IID_ITest,	(void**) &m_pTest);

}



CCOMParallelPort::~CCOMParallelPort()
{
    if( m_pClf != NULL ) m_pClf->Release();
    if( m_pUnk != NULL ) m_pUnk->Release();


	if( m_pRead != NULL ) m_pRead->Release();
	if( m_pWrite != NULL ) m_pWrite->Release();
	if( m_pTest != NULL ) m_pTest->Release();
	if( m_pGet != NULL ) m_pGet->Release();
	if( m_pSet != NULL ) m_pSet->Release();
}
