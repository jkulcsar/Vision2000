// ControlVCR.h: interface for the CControlVCR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLVCR_H__CF033B43_7297_11D3_AFB2_004095D0EF62__INCLUDED_)
#define AFX_CONTROLVCR_H__CF033B43_7297_11D3_AFB2_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ControlDevice.h"

class CControlVCR : public CControlDevice  
{
public:
	CControlVCR();
	virtual ~CControlVCR();

	void Power();
	void Play();
	void Stop();
	void Rew();
	void FF();
	void Rec();
	void Pause();
	void VCR();
	void VPC();	// VCR Power Control
private:
	BOOL m_bPowerOn;
};

#endif // !defined(AFX_CONTROLVCR_H__CF033B43_7297_11D3_AFB2_004095D0EF62__INCLUDED_)
