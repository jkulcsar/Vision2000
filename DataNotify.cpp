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
}



CDataNotify::~CDataNotify()
{
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

	CControlCamera*		pControlCamera;
	CControlVCR*		pControlVCR;
	CX10Device*			pX10Appliance;
	CX10Device*			pX10Light;

	// init local copy of camera control 'objects'
	CSystemTrayApp* pApp;
	pApp = (CSystemTrayApp*) AfxGetApp();
	pControlCamera	= pApp->GetControlCamera();
	pControlVCR		= pApp->GetControlVCR();

//	pX10Appliance	= pApp->GetX10Appliance();
//	pX10Light		= pApp->GetX10Light();

	if(m_pConf)
	{
		//////////////////////////////////////////////////////////////////////////
		// the new command model

		if( !strcmp(psz,"CAMERA1") )
			pControlCamera->Show(1);	// show camera 1
		if( !strcmp(psz,"CAMERA2") )
			pControlCamera->Show(2);	// show camera 2
		if( !strcmp(psz,"CAMERA3") )
			pControlCamera->Show(3);	// show camera 3
		if( !strcmp(psz,"CAMERA4") )
			pControlCamera->Show(4);	// show camera 4
		if( !strcmp(psz,"CAMERA5") )
			pControlCamera->Show(5);	// show camera 5
		if( !strcmp(psz,"CAMERA6") )
			pControlCamera->Show(6);	// show camera 6
		if( !strcmp(psz,"CAMERA7") )
			pControlCamera->Show(7);	// show camera 7
		if( !strcmp(psz,"CAMERA8") )
			pControlCamera->Show(8);	// show camera 8


		if( !strcmp(psz,"PLAY") )
			pControlVCR->Play();		// send Play command to VCR
		if( !strcmp(psz,"STOP") )
			pControlVCR->Stop();		// send Stop command to VCR
		if( !strcmp(psz,"FF") )
			pControlVCR->FF();		// send Ff command to VCR
		if( !strcmp(psz,"REW") )
			pControlVCR->Rew();		// send Rew command to VCR
		if( !strcmp(psz,"REC") )
			pControlVCR->Rec();		// send Rec command to VCR
		if( !strcmp(psz,"PAUSE") )
			pControlVCR->Pause();		// send Pause command to VCR
		if( !strcmp(psz,"VCR") )
			pControlVCR->VCR();		// send VCR command to VCR
		if( !strcmp(psz,"POWER") )
			pControlVCR->Power();		// send Power command to VCR

/*
		if( !strcmp(psz,"APPLIANCEON") )
			pX10Appliance->TurnApplianceON();
		if( !strcmp(psz,"APPLIANCEOFF") )
			pX10Appliance->TurnApplianceOFF();

		if( !strcmp(psz,"LIGHTON") )
			pX10Light->TurnLampON();
		if( !strcmp(psz,"LIGHTOFF") )
			pX10Light->TurnLampOFF();

		if( !strcmp(psz,"DIMM") )
			pX10Light->DIMM( TRUE );
		if( !strcmp(psz,"BRIGHTEN") )
			pX10Light->DIMM( FALSE );

*/




  }
	return S_OK;
}


