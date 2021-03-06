//****************************************************************************
//  File:       CONF.CPP
//  Content:    
//****************************************************************************

#include "stdafx.h"

const UINT MAX_ATTEMPTS = 10; //this is an arbitrary number


//****************************************************************************
//
// CLASS Conf
//
//****************************************************************************

//****************************************************************************
//
// Construction/Destruction
//
//****************************************************************************

Conf::Conf(HWND hWnd)
{
	// Create Sink Objects.
	// During construction, AddRef occurs
	m_pMgrNotify = new CMgrNotify(this);  
	m_pCallNotify = new CCallNotify(this);
	m_pConfNotify = new CConfNotify(this);
	m_pDataNotify = new CDataNotify(this);

	// Initialize other member variables
	m_pINmMgr=NULL;
	m_pINmConf=NULL;
	m_pINmCall=NULL;
	m_pINmChannelData = NULL;
	m_bInConnection=FALSE;
	m_hWnd=hWnd;
}

Conf::~Conf()
{
	//clean up the notification sink objects
	m_pMgrNotify->Release();  
	m_pCallNotify->Release();
	m_pConfNotify->Release();
	m_pDataNotify->Release();
}


//****************************************************************************
//
// HRESULT Conf::Initialize()
//
// Initiate NetMeeting, obtain a pointer to INmManager, connect the MgrNotify 
// sink object and initialize INmManager.
//
//****************************************************************************

HRESULT Conf::Initialize()
{
	HRESULT hr=S_OK;

	if (FAILED(CoCreateInstance(CLSID_NmManager,NULL,CLSCTX_INPROC_SERVER,IID_INmManager,(VOID **)&m_pINmMgr)))
		return E_FAIL;
	
	ULONG uOptions = NM_INIT_CONTROL; // Don't display the NetMeeting UI
//	ULONG uOptions = NM_INIT_BACKGROUND; // Netmeeting 3 recommends this init mode...
	ULONG uCaps = NMCH_AUDIO|NMCH_VIDEO|NMCH_DATA;
	
	hr =m_pMgrNotify->Connect(m_pINmMgr);
	if (SUCCEEDED (hr))
		hr=m_pINmMgr->Initialize(&uOptions,&uCaps);

	return hr;
}


//****************************************************************************
//
// HRESULT Conf::Uninitialize()
//
// Disconnect MgrNotify sink object and release the interface INmManager 
//
//****************************************************************************

HRESULT Conf::Uninitialize()
{
	

	m_pMgrNotify->Disconnect();
	if (m_pINmMgr)
		m_pINmMgr->Release();

	return S_OK;
}




//****************************************************************************
//
// HRESULT Conf::CreateDataChannel(void)
//
// This function initiates a data channel
//
//****************************************************************************

HRESULT Conf::CreateDataChannel(void)
{
    HRESULT hr=S_FALSE;

	if( m_pINmChannelData == NULL )
	{
		hr = m_pINmConf->CreateDataChannel(&m_pINmChannelData, guidApp);    
		if (S_OK == hr) 
		{
			//m_pDataNotify = new CDataNotify;
			if( NULL != m_pDataNotify ) 
			{
				hr = m_pDataNotify->Connect(m_pINmChannelData);        
			}
		}
		return hr;
	}
	else
		return hr;
}



HRESULT Conf::CheckDataChannel()
{
	if( m_pINmChannelData == NULL )
		return CreateDataChannel();
	else
		return S_FALSE;
}




HRESULT Conf::SendText(LPTSTR psz)
{    
	HRESULT hr;    
	ULONG cb = lstrlen(psz);
    if ( (0 == cb) || (NULL == m_pINmChannelData)
                   || (S_OK != m_pINmChannelData->IsActive()) ) 
	{
        return S_FALSE; // data channel not available    
	}	
    
	//INmMember *pMember = GetSelectedMember();    
	cb++; // include final null
    hr = m_pINmChannelData->SendData(NULL /*pMember*/, cb, (unsigned char*)psz, 0);    
	
	return hr;
}



//****************************************************************************
//
// HRESULT Conf::Call(LPSTR szMachineName)
//
// This function initiates an AV conference to the remote machine specified 
// by szMachineName.
//
//****************************************************************************

HRESULT Conf::Call(LPSTR szMachineName)
{
	HRESULT hr = S_OK;
	BSTRING bstrName(szMachineName);
	hr = m_pINmMgr->CreateCall(&m_pINmCall,NM_CALL_DEFAULT ,NM_ADDR_MACHINENAME ,bstrName,NULL);
	
	if (FAILED(hr))
	{
		// Call object sometimes needs to be released.
		if (m_pINmCall)
		{
			m_pCallNotify->Disconnect();
			m_pINmCall->Release();
		}
	}

	return hr;
}



HRESULT Conf::CallConference(LPSTR szMachineName, LPSTR lpstrConfName, LPSTR lpstrPassword)
{
	HRESULT hr = S_OK;
	BSTRING bstrName(szMachineName);
	BSTRING bstrConfName( lpstrConfName );
	BSTRING bstrPassword( lpstrPassword );

	hr = m_pINmMgr->CallConference(
							&m_pINmCall,
							NM_CALL_DEFAULT,
							NM_ADDR_MACHINENAME,
							bstrName,
							bstrConfName,
							bstrPassword
						);
	
	if (FAILED(hr))
	{
		// Call object sometimes needs to be released.
		if (m_pINmCall)
		{
			m_pCallNotify->Disconnect();
			m_pINmCall->Release();
		}
	}

	return hr;

}




HRESULT Conf::CreateConference(LPSTR lpstrConfName, LPSTR lpstrPassword)
{
	HRESULT hr = S_OK;
	BSTRING bstrConfName( lpstrConfName );
	BSTRING bstrPassword( lpstrPassword );
	ULONG	uCaps = NMCH_AUDIO|NMCH_VIDEO|NMCH_DATA;

	hr = m_pINmMgr->CreateConference(
						&m_pINmConf,
						bstrConfName,
						bstrPassword,
						uCaps
						);
	if (FAILED(hr))
	{
		// error handling
	}

	return hr;
}



//****************************************************************************
//
// HRESULT Conf::HangUp()
//
// Leave the conference
//
//****************************************************************************


HRESULT Conf::HangUp()
{
	HRESULT hr=S_OK;

	// if call hungup before Call accepted or rejected, release INmCall and 
	// disconnect CallNotify sink
	if (m_pINmCall)
	{
		hr = m_pINmCall->Cancel();
		m_pCallNotify->Disconnect();
		m_pINmCall->Release();
		m_pINmCall=NULL;
	}
	else
		if (m_pINmConf)
			hr = m_pINmConf->Leave();

	// Release INmChannelData and disconnect the DataNotify sink
	if (m_pINmChannelData)
	{
		m_pDataNotify->Disconnect();
		m_pINmChannelData->Release();
		m_pINmChannelData=NULL;
	}

	// Release INmConf and disconnect the ConfNotify sink
	if (m_pINmConf)
	{
		m_pINmConf->Release();
		m_pINmConf=NULL;
		m_pConfNotify->Disconnect();
	}
	
	m_bInConnection=FALSE;

	if (m_hWnd)
		SendMessage(m_hWnd,WM_DISCONNECTED,0,0);

	return hr;
}

//****************************************************************************
//
// HRESULT Conf::CallCreated(INmCall * pCall)
//
// Callback from the MgrNotify sink object
//
//****************************************************************************

HRESULT Conf::CallCreated(INmCall * pCall)
{
	m_pINmCall = pCall;
	m_pINmCall->AddRef();
	m_pCallNotify->Connect(pCall);
	m_bInConnection=TRUE;

	if (m_hWnd)
		SendMessage(m_hWnd,WM_CONNECTING,0,0);
	return S_OK;
}

//****************************************************************************
//
// HRESULT Conf::AcceptCall()
//
// Accept the incoming call
//
//****************************************************************************

HRESULT Conf::AcceptCall()
{
	if( IsHosting() )
		return m_pINmCall->Accept();
	else
		return RejectCall();
}

//****************************************************************************
//
// HRESULT Conf::RejectCall()
//
// Reject the incoming call
//
//****************************************************************************

HRESULT Conf::RejectCall()  
{
	return m_pINmCall->Reject();
}

//****************************************************************************
//
// HRESULT Conf::ConferenceCreated(INmConference *pINmConf)
//
// Callback from the MgrNotify sink object that a new conference has been 
// created
//
//****************************************************************************

HRESULT Conf::ConferenceCreated(INmConference *pINmConf)
{	
	//Add Conference notification sink to handle channels.
	m_pINmConf=pINmConf;
	m_pINmConf->AddRef();
	m_pConfNotify->Connect(pINmConf);
	m_bInConnection=TRUE;

	if (m_hWnd)
		SendMessage(m_hWnd,WM_CONNECTED,0,0);
	return S_OK;
}


//****************************************************************************
//
// HRESULT Conf::CallAccepted()  
//
// Callback from the CallNotify sink object that the new call has been accepted
//
//****************************************************************************

HRESULT Conf::CallAccepted()  
{
	// Release INmCall, and let send window message that a user has connected
	if (m_pINmCall)
		m_pINmCall->Release();

	m_pINmCall=NULL;
	m_pCallNotify->Disconnect();

	m_bInConnection=TRUE;

	return S_OK;
}

//****************************************************************************
//
// HRESULT Conf::CallRejected()  
//
// Callback from the CallNotify sink object that the new call has been rejected
//
//****************************************************************************

HRESULT Conf::CallRejected() 
{					
	// Release INmCall, INmConf, disconnect CallNotify and ConfNotify
	// sink objects, and send message to main window that the user has 
	// disconnected.
	
	if (m_pINmCall)
	{
		m_pCallNotify->Disconnect();
		m_pINmCall->Release();
		m_pINmCall=NULL;
	}

	if (m_pINmConf)
	{
		m_pINmConf->Release();
		m_pINmConf=NULL;
	}
	m_pConfNotify->Disconnect();
	m_bInConnection=FALSE;

	if (m_hWnd)
		SendMessage(m_hWnd,WM_DISCONNECTED,0,0);

	return S_OK;
}

//****************************************************************************
//
// HRESULT Conf::RemoteHungup()
//
// Callback from the ConfNotify sink object that a member has left the
// conference
//
//****************************************************************************

HRESULT Conf::RemoteHungup()
{	
	// Release INmChannelData and disconnect the DataNotify sink
	if (m_pINmChannelData)
	{
		m_pDataNotify->Disconnect();
		m_pINmChannelData->Release();
		m_pINmChannelData=NULL;
	}


	// Release INmConf, disconnect ConfNotify sink object, and send message to 
	// main window that the remote node has disconnected.
	m_pINmConf->Release();
	m_pINmConf=NULL;
	m_pConfNotify->Disconnect();
	m_bInConnection=FALSE;

	if (m_hWnd)
		SendMessage(m_hWnd,WM_DISCONNECTED,0,0);
	
	return S_OK;
}

//****************************************************************************
//
// BOOL Conf::InConference()
//
//****************************************************************************

BOOL Conf::InConnection()
{	
	return m_bInConnection;
}


HRESULT Conf::IsHosting()
{
	if (m_pINmConf)
	{
		return m_pINmConf->IsHosting();
	}
	else
		return S_FALSE;

}
