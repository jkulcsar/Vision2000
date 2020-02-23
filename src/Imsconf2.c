/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sat Aug 07 20:23:24 1999
 */
/* Compiler settings for C:\Program Files\Microsoft Visual Studio\MyProjects\Vision2000\Imsconf2.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_INmManager = {0x068B0701,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmManagerNotify = {0x068B0702,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmSysInfo = {0x068B0703,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmCall = {0x068B0704,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmCallNotify = {0x068B0705,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmConference = {0x068B0710,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmConferenceNotify = {0x068B0711,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmMember = {0x068B0712,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannel = {0x068B0720,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelNotify = {0x068B0721,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelData = {0x068B0722,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelDataNotify = {0x068B0723,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelAudio = {0x068B0724,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelAudioNotify = {0x068B0725,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelVideo = {0x068B0726,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelVideoNotify = {0x068B0727,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelFt = {0x068B0728,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelFtNotify = {0x068B0729,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmFt = {0x068B0732,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelAppShare = {0x068B072A,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmChannelAppShareNotify = {0x068B072B,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_INmSharableApp = {0x068B0734,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_IEnumNmConference = {0x068B0741,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_IEnumNmMember = {0x068B0742,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_IEnumNmChannel = {0x068B0743,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_IEnumNmCall = {0x068B0744,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID IID_IEnumNmSharableApp = {0x068B0745,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const IID LIBID_NmManager = {0x068B07FF,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


const CLSID CLSID_NmManager = {0x068B0700,0x718C,0x11d0,{0x8B,0x1A,0x00,0xA0,0xC9,0x1B,0xC9,0x0E}};


#ifdef __cplusplus
}
#endif

