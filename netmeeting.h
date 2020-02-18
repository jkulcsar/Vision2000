/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jan 07 02:45:41 2000
 */
/* Compiler settings for F:\work\programming\Vision2000\netmeeting.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __netmeeting_h__
#define __netmeeting_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __INetMeeting_FWD_DEFINED__
#define __INetMeeting_FWD_DEFINED__
typedef interface INetMeeting INetMeeting;
#endif 	/* __INetMeeting_FWD_DEFINED__ */


#ifndef ___INetMeetingEvents_FWD_DEFINED__
#define ___INetMeetingEvents_FWD_DEFINED__
typedef interface _INetMeetingEvents _INetMeetingEvents;
#endif 	/* ___INetMeetingEvents_FWD_DEFINED__ */


#ifndef __NetMeeting_FWD_DEFINED__
#define __NetMeeting_FWD_DEFINED__

#ifdef __cplusplus
typedef class NetMeeting NetMeeting;
#else
typedef struct NetMeeting NetMeeting;
#endif /* __cplusplus */

#endif 	/* __NetMeeting_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __INetMeeting_INTERFACE_DEFINED__
#define __INetMeeting_INTERFACE_DEFINED__

/* interface INetMeeting */
/* [helpstring][nonextensible][hidden][dual][uuid][object] */ 


EXTERN_C const IID IID_INetMeeting;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5572984E-7A76-11d2-9334-0000F875AE17")
    INetMeeting : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Version( 
            /* [retval][out] */ long __RPC_FAR *pdwBuildNumber) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnDock( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IsInConference( 
            /* [retval][out] */ BOOL __RPC_FAR *pbInConference) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CallTo( 
            /* [in] */ BSTR strCallToString) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LeaveConference( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct INetMeetingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            INetMeeting __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            INetMeeting __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            INetMeeting __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            INetMeeting __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            INetMeeting __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            INetMeeting __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            INetMeeting __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Version )( 
            INetMeeting __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *pdwBuildNumber);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UnDock )( 
            INetMeeting __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsInConference )( 
            INetMeeting __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pbInConference);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CallTo )( 
            INetMeeting __RPC_FAR * This,
            /* [in] */ BSTR strCallToString);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LeaveConference )( 
            INetMeeting __RPC_FAR * This);
        
        END_INTERFACE
    } INetMeetingVtbl;

    interface INetMeeting
    {
        CONST_VTBL struct INetMeetingVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INetMeeting_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define INetMeeting_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define INetMeeting_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define INetMeeting_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define INetMeeting_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define INetMeeting_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define INetMeeting_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define INetMeeting_Version(This,pdwBuildNumber)	\
    (This)->lpVtbl -> Version(This,pdwBuildNumber)

#define INetMeeting_UnDock(This)	\
    (This)->lpVtbl -> UnDock(This)

#define INetMeeting_IsInConference(This,pbInConference)	\
    (This)->lpVtbl -> IsInConference(This,pbInConference)

#define INetMeeting_CallTo(This,strCallToString)	\
    (This)->lpVtbl -> CallTo(This,strCallToString)

#define INetMeeting_LeaveConference(This)	\
    (This)->lpVtbl -> LeaveConference(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetMeeting_Version_Proxy( 
    INetMeeting __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *pdwBuildNumber);


void __RPC_STUB INetMeeting_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetMeeting_UnDock_Proxy( 
    INetMeeting __RPC_FAR * This);


void __RPC_STUB INetMeeting_UnDock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetMeeting_IsInConference_Proxy( 
    INetMeeting __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pbInConference);


void __RPC_STUB INetMeeting_IsInConference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetMeeting_CallTo_Proxy( 
    INetMeeting __RPC_FAR * This,
    /* [in] */ BSTR strCallToString);


void __RPC_STUB INetMeeting_CallTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE INetMeeting_LeaveConference_Proxy( 
    INetMeeting __RPC_FAR * This);


void __RPC_STUB INetMeeting_LeaveConference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __INetMeeting_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_netmeeting_0208 */
/* [local] */ 

enum { NetMeetingLib_Ver_Major = 1};
enum { NetMeetingLib_Ver_Minor = 1};


extern RPC_IF_HANDLE __MIDL_itf_netmeeting_0208_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_netmeeting_0208_v0_0_s_ifspec;


#ifndef __NetMeetingLib_LIBRARY_DEFINED__
#define __NetMeetingLib_LIBRARY_DEFINED__

/* library NetMeetingLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_NetMeetingLib;

#ifndef ___INetMeetingEvents_DISPINTERFACE_DEFINED__
#define ___INetMeetingEvents_DISPINTERFACE_DEFINED__

/* dispinterface _INetMeetingEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__INetMeetingEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3E9BAF2C-7A79-11d2-9334-0000F875AE17")
    _INetMeetingEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _INetMeetingEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _INetMeetingEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _INetMeetingEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _INetMeetingEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _INetMeetingEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _INetMeetingEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _INetMeetingEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _INetMeetingEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _INetMeetingEventsVtbl;

    interface _INetMeetingEvents
    {
        CONST_VTBL struct _INetMeetingEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _INetMeetingEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _INetMeetingEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _INetMeetingEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _INetMeetingEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _INetMeetingEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _INetMeetingEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _INetMeetingEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___INetMeetingEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_NetMeeting;

#ifdef __cplusplus

class DECLSPEC_UUID("3E9BAF2D-7A79-11d2-9334-0000F875AE17")
NetMeeting;
#endif
#endif /* __NetMeetingLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
