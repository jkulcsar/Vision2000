//****************************************************************************
//  File:       CALLNTFY.CPP
//  Content:    
//****************************************************************************

#include "stdafx.h"

//****************************************************************************
//
// Constructor
//
//****************************************************************************

CCallNotify::CCallNotify()
{

}


CCallNotify::CCallNotify(Conf *pConf)
{
	m_pConf = pConf;
}


//****************************************************************************
//
// Destructor
//
//****************************************************************************

CCallNotify::~CCallNotify()
{

}


//****************************************************************************
//
// methods from IUnknown
//
//****************************************************************************

ULONG STDMETHODCALLTYPE CCallNotify::AddRef()
{
	return RefCount::AddRef();
}

ULONG STDMETHODCALLTYPE CCallNotify::Release()
{
	return RefCount::Release();
}

HRESULT STDMETHODCALLTYPE CCallNotify::QueryInterface(REFIID riid, PVOID * ppvObject)
{
	*ppvObject = NULL;
	
	if (riid == IID_IUnknown)
		*ppvObject = (PVOID *)this;
	else if (riid == IID_INmCallNotify)
		*ppvObject = (PVOID *)this;
	else
		return E_NOINTERFACE;

	AddRef();
	return S_OK;
}


//****************************************************************************
//
// Sink connection methods
//
//****************************************************************************

HRESULT CCallNotify::Connect(IUnknown * pUnkOuter)
{
	return CNotify::Connect(pUnkOuter, IID_INmCallNotify, (IUnknown *)this);
}

HRESULT CCallNotify::Disconnect()
{
	return CNotify::Disconnect();
}


//****************************************************************************
//
// Main sink notification methods
//
//****************************************************************************

HRESULT STDMETHODCALLTYPE CCallNotify::Failed(ULONG uError)
{
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CCallNotify::Accepted(INmConference *pConference)
{
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CCallNotify::NmUI(CONFN uNotify)
{
	return S_OK;
}

HRESULT STDMETHODCALLTYPE CCallNotify::StateChanged(NM_CALL_STATE uState)
{
	switch (uState)
	{
		case NM_CALL_RING:
		
			// This is a good place to query whether to accept the call and notify my Conf object the result.
			// if (MessageBox(NULL,"Accept incoming call?","Call",MB_YESNO|MB_TASKMODAL)== IDYES)
			//			m_pConf->AcceptCall();
			//		else
			//			m_pConf->RejectCall();

			// for our app it's good enough to accept it directly or based on an automated conditioning

			m_pConf->AcceptCall();
			break;

		case NM_CALL_REJECTED:

			// Notify my Conf object that the call was rejected.
			m_pConf->CallRejected();
			break;

		case NM_CALL_ACCEPTED:

			// Notify my Conf object that the call was accepted
			m_pConf->CallAccepted();
			break;
	}
	return S_OK;
}

