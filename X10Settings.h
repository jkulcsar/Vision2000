// X10Settings.h: interface for the CX10Settings class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_X10SETTINGS_H__A677E761_B121_11D4_8F6D_004033D21526__INCLUDED_)
#define AFX_X10SETTINGS_H__A677E761_B121_11D4_8F6D_004033D21526__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CX10Settings : public CObject  
{
	DECLARE_SERIAL(CX10Settings)

public:
	void SetLampCode( UINT );
	void SetApplianceCode( UINT );
	UINT GetLampCode();
	UINT GetApplianceCode();
	void SetCOMPort( UINT );
	void SetDeviceCodeBase( UINT );
	void SetHouseCode( CHAR );
	UINT GetCOMPort();
	UINT GetDeviceCodeBase();
	CHAR GetHouseCode();

	CX10Settings();
	virtual ~CX10Settings();

	void Serialize( CArchive& );

private:
	CHAR	m_chHouseCode;
	UINT	m_uiDeviceCodeBase;
	UINT	m_uiApplianceCode;
	UINT	m_uiLampCode;
	UINT	m_uiCOMPort;

};

#endif // !defined(AFX_X10SETTINGS_H__A677E761_B121_11D4_8F6D_004033D21526__INCLUDED_)
