// IRRemoteControl.h: interface for the CIRRemoteControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IRREMOTECONTROL_H__452F81A4_B0CA_11D3_BA58_00C0DF25CE83__INCLUDED_)
#define AFX_IRREMOTECONTROL_H__452F81A4_B0CA_11D3_BA58_00C0DF25CE83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CIRRemoteControl : public CObject
{
	DECLARE_SERIAL(CIRRemoteControl)

public:
	void Playback();
	void Record();

	CIRRemoteControl();
	virtual ~CIRRemoteControl();

	void Serialize( CArchive& archive );

private:
	BYTE* m_pbyteData;
//	BYTE*				m_pbData;
	CByteArray			m_byteDataArray;
	DWORD				m_dwLength;
	CCOMParallelPort	*m_pPP;

protected:
	CCriticalSection	m_criticalSection;
};

#endif // !defined(AFX_IRREMOTECONTROL_H__452F81A4_B0CA_11D3_BA58_00C0DF25CE83__INCLUDED_)
