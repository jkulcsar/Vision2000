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

class CX10Device  
{
public:
	CX10Device();
	virtual ~CX10Device();

public:
	void DIMM( BOOL );
	void TurnApplianceOFF();
	void TurnApplianceON();
	void TurnLampOFF();
	void TurnLampON();

private:
	// this is volatile; don't save it from one session to other;
	// is very device and time specific
	short m_shBrightness;
};

#endif // !defined(AFX_X10DEVICE_H__BCBD5C02_A85E_42BB_95C5_9EED4D40D06B__INCLUDED_)
