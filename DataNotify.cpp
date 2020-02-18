// DataNotify.cpp: implementation of the CDataNotify class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Vision2000.h"
#include "DataNotify.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDataNotify::CDataNotify()
{

}

CDataNotify::CDataNotify(Conf *pConf)
{
	m_pConf = pConf;

	/* this section is temporarily disabled
	// init the parallel port
	m_pPP = new CCOMParallelPort();
	m_pPP->Initialize();
	*/
	m_pPP = NULL;	//temp

}



CDataNotify::~CDataNotify()
{
	if( m_pPP != NULL ) delete m_pPP;
}



///////////////////////////////////////////////////////////////////////////////
// Methods from IUnknown

ULONG STDMETHODCALLTYPE CDataNotify::AddRef(void)
{
	return RefCount::AddRef();
}


ULONG STDMETHODCALLTYPE CDataNotify::Release(void)
{
	return RefCount::Release();
}

HRESULT STDMETHODCALLTYPE CDataNotify::QueryInterface(REFIID riid, PVOID *ppvObject)
{
	HRESULT hr = S_OK;

	if (riid == IID_IUnknown)
	{
		*ppvObject = (IUnknown *)this;
	}
	else if (riid == IID_INmChannelDataNotify)
	{
		*ppvObject = (INmChannelDataNotify *)this;
	}
	else
	{
		hr = E_NOINTERFACE;
		*ppvObject = NULL;
	}

	if (S_OK == hr)
	{
		AddRef();
	}

	return hr;
}


///////////////////////////////////////////////////////////////////////////////
// Methods from ICNotify

HRESULT STDMETHODCALLTYPE CDataNotify::Connect(IUnknown *pUnk)
{
	return CNotify::Connect(pUnk, IID_INmChannelDataNotify, (IUnknown *)this);
}

HRESULT STDMETHODCALLTYPE CDataNotify::Disconnect(void)
{
	return CNotify::Disconnect();
}



///////////////////////////////////////////////////////////////////////////////
// Methods from INmChannelNotify

HRESULT STDMETHODCALLTYPE CDataNotify::NmUI(CONFN uNotify)
{
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CDataNotify::MemberChanged(NM_MEMBER_NOTIFY uNotify, INmMember *pMember)
{
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CDataNotify::DataSent(INmMember *pMember, ULONG uSize, LPBYTE pb)
{
//	LPTSTR psz;

//	DisplayMsg(psz, g_pMemberLocal);

	return S_OK;
}

HRESULT STDMETHODCALLTYPE CDataNotify::DataReceived(INmMember *pMember, ULONG uSize, LPBYTE pb, ULONG dwFlags)
{
	LPTSTR	psz;
	
	// Warning : Doesn't handle broken packets
	// TODO: Check dwFlags & NM_DF_SEGMENT_END

	psz = (LPTSTR) pb;
/* this section temporarily disabled
	if(m_pConf && m_pPP)
	{
		if( !strcmp(psz,"CAMERA1") )
			m_pPP->WriteDataPort( 0x00 );
		if( !strcmp(psz,"CAMERA2") )
			m_pPP->WriteDataPort( 0x02 );
		if( !strcmp(psz,"CAMERA3") )
			m_pPP->WriteDataPort( 0x01 );
		if( !strcmp(psz,"CAMERA4") )
			m_pPP->WriteDataPort( 0x03 );
	}
*/	

	return S_OK;
}


