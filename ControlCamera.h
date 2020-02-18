// ControlCamera.h: interface for the CControlCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLCAMERA_H__CF033B41_7297_11D3_AFB2_004095D0EF62__INCLUDED_)
#define AFX_CONTROLCAMERA_H__CF033B41_7297_11D3_AFB2_004095D0EF62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ControlDevice.h"

class CControlCamera : public CControlDevice  
{
public:
	void Show( BYTE );
	CControlCamera();
	virtual ~CControlCamera();

};

#endif // !defined(AFX_CONTROLCAMERA_H__CF033B41_7297_11D3_AFB2_004095D0EF62__INCLUDED_)
