// SystemSettings.h: interface for the CSystemSettings class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSTEMSETTINGS_H__8D1F7A82_B9A1_11D3_8F6A_004033D21526__INCLUDED_)
#define AFX_SYSTEMSETTINGS_H__8D1F7A82_B9A1_11D3_8F6A_004033D21526__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IRRemoteControl.h"

class CSystemSettings  
{
public:
	BOOL IsWireless();
	void Save();
	BOOL InLocalMode();
	CCOMParallelPort* GetParallelPort();
	CArray< CIRRemoteControl*, CIRRemoteControl* >* GetArrayIR();
	void SetLocalMode( BOOL );
	BOOL Initialize();
	CSystemSettings();
	virtual ~CSystemSettings();

protected:
	CCOMParallelPort *m_pPP;

private:
	BOOL m_bLocalMode;
	BOOL m_bWireless;

	CArray< CIRRemoteControl*, CIRRemoteControl* > m_arrayIR;
};

#endif // !defined(AFX_SYSTEMSETTINGS_H__8D1F7A82_B9A1_11D3_8F6A_004033D21526__INCLUDED_)
