//////////////////////////////////////////////////////////////////////
//
// SystemSettings.cpp: implementation of the CSystemSettings class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "vision2000.h"
#include "SystemSettings.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// class CSystemSettings

IMPLEMENT_SERIAL( CSystemSettings, CObject, 1 )

//////////////////////////////////////////////////////////////////////
// Construction/Destruction

CSystemSettings::CSystemSettings()
{
	// init the parallel port
	m_pPP			=	new CCOMParallelPort();
//	m_pPP			=	NULL;

	// create X10 settings and ActiveX object
	// init later, after settings loaded
	m_pX10Settings	=	new CX10Settings();
	m_pX10CM		=	new CControlCM();
	
	m_bLocalMode	=	FALSE;
	m_bWireless		=	TRUE;			// wireless version; will be changeable from UI
	m_uiMode		=	MODE_NONE;		// default mode: none
}


CSystemSettings::~CSystemSettings()
{
	if( m_pPP != NULL )
	{
		delete m_pPP;
		m_pPP = NULL;
	}

	if( m_pX10Settings != NULL )
	{
		delete m_pX10Settings;
		m_pX10Settings= NULL;
	}

	if( m_pX10CM != NULL )
	{
		delete m_pX10CM;
		m_pX10CM= NULL;
	}
}


//////////////////////////////////////////////////////////////////////
// Serialize the CSystemSettings object

void CSystemSettings::Serialize( CArchive& archive )
{
	// call base class function first
    // base class is CObject in this case
    CObject::Serialize( archive );

    // now do the stuff for our specific class
    if( archive.IsStoring() )
	{
		// do storing
        archive << m_dwIndexLPT << m_bLocalMode;
		if( m_pX10Settings != NULL )
			m_pX10Settings->Serialize( archive );
		m_arrayMRU.Serialize( archive );
		m_arrayIR.Serialize( archive );
	}
    else
	{
		// do retrieve
        archive >> m_dwIndexLPT >> m_bLocalMode;
		if( m_pX10Settings != NULL )
			m_pX10Settings->Serialize( archive );
		m_arrayMRU.Serialize( archive );
		m_arrayIR.Serialize( archive );
	}
}


BOOL CSystemSettings::Initialize()
{
	CFile		file;
	char		chCurrentDir[ MAX_PATH ];
	CString		strFullPath;
	CString		strSettingsFileName;

	::GetCurrentDirectory( MAX_PATH, chCurrentDir );
	strFullPath.Empty();
	strFullPath += chCurrentDir;
	strSettingsFileName.LoadString( IDS_SETTINGS_FILE );
	if( !strFullPath.IsEmpty() && !strSettingsFileName.IsEmpty() )
	{
		strFullPath += _T("\\");
		strFullPath += strSettingsFileName;
		
		if( file.Open( strFullPath, CFile::modeRead ) )
		{
			CArchive archive( &file, CArchive::load );

			Serialize( archive );

			archive.Close();
			file.Close();
		}
	}


	// init parallel port
	if( m_pPP != NULL )
	{
		if( m_dwIndexLPT == 1 )
			if( m_pPP->InitializeAt(LPT1) )
				m_pPP->SetName("LPT1");
			else
				return FALSE;

		if( m_dwIndexLPT == 2 )
			if( m_pPP->InitializeAt(LPT2) )
				m_pPP->SetName("LPT2");
			else
				return FALSE;

		if( m_dwIndexLPT == 3 )
			if( m_pPP->InitializeAt(LPT3) )
				m_pPP->SetName("LPT3");
			else
				return FALSE;
	}


	return TRUE;
}


void CSystemSettings::Save()
{
	DWORD m_dwIndexLPT = 1;	// holds the index of the PP: LPTx where x is m_dwIndexLPT
	DWORD dwLocalMode = FALSE;

	if( m_pPP != NULL )
	{
		if( !strcmp( m_pPP->GetName(), "LPT1" ) && m_pPP->IsEnabled() )
			m_dwIndexLPT = 1;

		if( !strcmp( m_pPP->GetName(), "LPT2" ) && m_pPP->IsEnabled() )
			m_dwIndexLPT = 2;

		if( !strcmp( m_pPP->GetName(), "LPT3" ) && m_pPP->IsEnabled() )
			m_dwIndexLPT = 3;	
	}


	CFile		file;
	char		chCurrentDir[ MAX_PATH ];
	CString		strFullPath;
	CString		strSettingsFileName;

	::GetCurrentDirectory( MAX_PATH, chCurrentDir );
	strFullPath.Empty();
	strFullPath += chCurrentDir;
	strSettingsFileName.LoadString( IDS_SETTINGS_FILE );
	if( !strFullPath.IsEmpty() && !strSettingsFileName.IsEmpty() )
	{
		strFullPath += _T("\\");
		strFullPath += strSettingsFileName;
		
		if( file.Open( strFullPath, CFile::modeCreate | CFile::modeWrite ) )
		{
			CArchive archive( &file, CArchive::store );

			Serialize( archive );

			archive.Close();
			file.Close();
		}
	}
}



CCOMParallelPort* CSystemSettings::GetParallelPort()
{
	return m_pPP;
}


CTypedPtrArray < CObArray, CIRRemoteControl* >* CSystemSettings::GetArrayIR()
{
	return &m_arrayIR;
}


CStringArray* CSystemSettings::GetMRU()
{
	return &m_arrayMRU;
}



BOOL CSystemSettings::InLocalMode()
{
	return m_bLocalMode;
}


void CSystemSettings::SetLocalMode( BOOL bLocalMode )
{
	m_bLocalMode = bLocalMode;
}




BOOL CSystemSettings::IsWireless()
{
	return m_bWireless;
}



void CSystemSettings::SetMode( UINT uiMode )
{
	m_uiMode = uiMode;
}



UINT CSystemSettings::GetMode()
{
	return m_uiMode;
}


CControlCM* CSystemSettings::GetX10ControlModule()
{
	return m_pX10CM;
}

CX10Settings* CSystemSettings::GetX10Settings()
{
	return m_pX10Settings;
}
