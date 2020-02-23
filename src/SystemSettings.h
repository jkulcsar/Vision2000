// SystemSettings.h: interface for the CSystemSettings class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSTEMSETTINGS_H__8D1F7A82_B9A1_11D3_8F6A_004033D21526__INCLUDED_)
#define AFX_SYSTEMSETTINGS_H__8D1F7A82_B9A1_11D3_8F6A_004033D21526__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IRRemoteControl.h"
#include "X10Settings.h"

#define MODE_NONE		0
#define MODE_WIRELESS	10
#define MODE_WIRED		20
#define MODE_X10		30

class CSystemSettings : public CObject
{
	DECLARE_SERIAL(CSystemSettings)

public:
	short CreateInitX10CM();
	CX10Settings* GetX10Settings();
	CControlCM* GetX10ControlModule();
	UINT GetMode();
	void SetMode( UINT );
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
	CCOMParallelPort*	m_pPP;
	CControlCM*			m_pX10CM;
	CX10Settings*		m_pX10Settings;

private:
	DWORD	m_dwIndexLPT;
	DWORD	m_dwMRUCount;
	BOOL	m_bLocalMode;
	BOOL	m_bWireless;

	UINT	m_uiMode;

	CTypedPtrArray < CObArray, CIRRemoteControl* > m_arrayIR;
	CStringArray	m_arrayMRU;
};

#endif // !defined(AFX_SYSTEMSETTINGS_H__8D1F7A82_B9A1_11D3_8F6A_004033D21526__INCLUDED_)
