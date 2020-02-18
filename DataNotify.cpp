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
	
	m_pControlCamera = new CControlCamera;
	if(m_pControlCamera != NULL )
		m_pControlCamera->InitializeAt(LPT1);

	m_pControlVCR = new CControlVCR;
	if(m_pControlVCR != NULL )
		m_pControlVCR->InitializeAt(LPT1);

}



CDataNotify::~CDataNotify()
{
	if( m_pControlVCR != NULL )
	{
		delete m_pControlVCR;
		m_pControlVCR = NULL;
	}

	if( m_pControlCamera != NULL )
	{
		delete m_pControlCamera;
		m_pControlCamera = NULL;
	}
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
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CDataNotify::DataReceived(INmMember *pMember, ULONG uSize, LPBYTE pb, ULONG dwFlags)
{
	LPTSTR	psz;
	
	// Warning : Doesn't handle broken packets
	// TODO: Check dwFlags & NM_DF_SEGMENT_END

	psz = (LPTSTR) pb;

	if(m_pConf)
	{
		//////////////////////////////////////////////////////////////////////////
		// the new command model

		if( !strcmp(psz,"CAMERA1") )
			m_pControlCamera->Show(1);	// show camera 1
		if( !strcmp(psz,"CAMERA2") )
			m_pControlCamera->Show(2);	// show camera 2
		if( !strcmp(psz,"CAMERA3") )
			m_pControlCamera->Show(3);	// show camera 3
		if( !strcmp(psz,"CAMERA4") )
			m_pControlCamera->Show(4);	// show camera 4


		if( !strcmp(psz,"PLAY") )
			m_pControlVCR->Play();		// send Play command to VCR
		if( !strcmp(psz,"STOP") )
			m_pControlVCR->Stop();		// send Stop command to VCR
		if( !strcmp(psz,"FF") )
			m_pControlVCR->FF();		// send Ff command to VCR
		if( !strcmp(psz,"REW") )
			m_pControlVCR->Rew();		// send Rew command to VCR
		if( !strcmp(psz,"REC") )
			m_pControlVCR->Rec();		// send Rec command to VCR
		if( !strcmp(psz,"PAUSE") )
			m_pControlVCR->Pause();		// send Pause command to VCR
		if( !strcmp(psz,"VCR") )
			m_pControlVCR->VCR();		// send VCR command to VCR
		if( !strcmp(psz,"POWER") )
			m_pControlVCR->Power();		// send Power command to VCR
  }
	return S_OK;
}


