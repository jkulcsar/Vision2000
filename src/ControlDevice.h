// ControlDevice.h: interface for the CControlDevice class.
//
//////////////////////////////////////////////////////////////////////

#include "COMParallelPort.h"

#if !defined(AFX_CONTROLDEVICE_H__715A5B81_727A_11D3_AFB2_004095D0EF62__INCLUDED_)
#define AFX_CONTROLDEVICE_H__715A5B81_727A_11D3_AFB2_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CControlDevice
{
	public:
		BOOL InitializeAt( unsigned short );
		CControlDevice();
		virtual ~CControlDevice();

	protected:
		CCOMParallelPort *m_pPP;
};

#endif // !defined(AFX_CONTROLDEVICE_H__715A5B81_727A_11D3_AFB2_004095D0EF62__INCLUDED_)
