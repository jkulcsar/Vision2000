// X10Device.h: interface for the CX10Device class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_X10DEVICE_H__BCBD5C02_A85E_42BB_95C5_9EED4D40D06B__INCLUDED_)
#define AFX_X10DEVICE_H__BCBD5C02_A85E_42BB_95C5_9EED4D40D06B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define MAX_BRIGHT	100
#define MIN_BRIGHT	0
#define STEP		12

#define APPLIANCE	0x00
#define LIGHT		0x01

#define ON			0x02
#define OFF			0x03
#define	DIMM		0x04
#define	BRIGHT		0x05

class CX10Device : public CObject
{
	DECLARE_SERIAL(CX10Device)

public:
	CX10Device();
	virtual ~CX10Device();

	void Serialize( CArchive& );

public:
	void SetOn( short );
	BOOL IsOn();
	UINT GetX10DeviceType();
	UINT GetX10DeviceCode();
	CHAR GetX10DeviceHouseCode();
	CString& GetX10DeviceName();
	void SetX10DeviceType( UINT );
	void SetX10DeviceCode( UINT );
	void SetX10DeviceHouseCode( CHAR );
	void SetX10DeviceName( CString& );
	void Execute( short );

private:
	short	m_shOnOff;
	UINT	m_uiType;
	short	m_shBrightness;
	UINT	m_uiDeviceCode;
	CHAR	m_chHouseCode;
	CString	m_strDeviceName;
};

#endif // !defined(AFX_X10DEVICE_H__BCBD5C02_A85E_42BB_95C5_9EED4D40D06B__INCLUDED_)
