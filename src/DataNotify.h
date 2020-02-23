// DataNotify.h: interface for the CDataNotify class.
//
//////////////////////////////////////////////////////////////////////

#include "ControlCamera.h"
#include "ControlVCR.h"

#if !defined(AFX_DATANOTIFY_H__32F6DDA1_4F25_11D3_AFB1_004095D0EF62__INCLUDED_)
#define AFX_DATANOTIFY_H__32F6DDA1_4F25_11D3_AFB1_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDataNotify  :
	public INmChannelDataNotify, 
	public RefCount, 
	public CNotify 
{
private:
	Conf *m_pConf; // Back pointer to Conf object
	CDataNotify(); // prevent default construction

public:
	CDataNotify(Conf *);
	virtual ~CDataNotify();

	// INmChannelDataNotify
	HRESULT STDMETHODCALLTYPE NmUI(CONFN uNotify);
	HRESULT STDMETHODCALLTYPE MemberChanged(NM_MEMBER_NOTIFY uNotify, INmMember * pMember);
	HRESULT STDMETHODCALLTYPE DataSent(INmMember *pMember, ULONG uSize, LPBYTE pb);
	HRESULT STDMETHODCALLTYPE DataReceived(INmMember *pMember, ULONG uSize, LPBYTE pb, ULONG dwFlags);

	// ICNotify methods
	HRESULT STDMETHODCALLTYPE Connect (IUnknown *pUnk);
	HRESULT STDMETHODCALLTYPE Disconnect(void);

	// IUnknown methods
	ULONG STDMETHODCALLTYPE AddRef(void);
	ULONG STDMETHODCALLTYPE Release(void);
	HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, PVOID *ppvObj);
};

#endif // !defined(AFX_DATANOTIFY_H__32F6DDA1_4F25_11D3_AFB1_004095D0EF62__INCLUDED_)
