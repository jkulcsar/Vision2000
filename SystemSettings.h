// SystemSettings.h: interface for the CSystemSettings class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSTEMSETTINGS_H__8D1F7A82_B9A1_11D3_8F6A_004033D21526__INCLUDED_)
#define AFX_SYSTEMSETTINGS_H__8D1F7A82_B9A1_11D3_8F6A_004033D21526__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IRRemoteControl.h"

class CSystemSettings : public CObject
{
	DECLARE_SERIAL(CSystemSettings)

public:
	BOOL IsWireless();
	void Save();
	BOOL InLocalMode();
	CCOMParallelPort* GetParallelPort();
	CTypedPtrArray < CObArray, CIRRemoteControl* >* GetArrayIR();
	CStringArray* GetMRU();
	void SetLocalMode( BOOL );
	BOOL Initialize();
	
	CSystemSettings();
	virtual ~CSystemSettings();

	void Serialize( CArchive& );

protected:
	CCOMParallelPort *m_pPP;

private:
	DWORD m_dwIndexLPT;
	DWORD m_dwMRUCount;
	BOOL m_bLocalMode;
	BOOL m_bWireless;

	CTypedPtrArray < CObArray, CIRRemoteControl* > m_arrayIR;
	CStringArray	m_arrayMRU;
};

#endif // !defined(AFX_SYSTEMSETTINGS_H__8D1F7A82_B9A1_11D3_8F6A_004033D21526__INCLUDED_)
