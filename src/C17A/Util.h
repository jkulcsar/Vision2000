

//****************************************************************************
//
// CLASS BSTRING
//
//****************************************************************************

class BSTRING
{
private:
	BSTR   m_bstr;

public:
	// Constructors
	BSTRING() {m_bstr = NULL;}

	inline BSTRING(LPCWSTR lpcwString);

#if !defined(UNICODE)
	// We don't support construction from an ANSI string in the Unicode build.
	BSTRING(LPCSTR lpcString);
#endif // !defined(UNICODE)

	// Destructor
	inline ~BSTRING();

	// Cast to BSTR
	operator BSTR() {return m_bstr;}
	inline LPBSTR GetLPBSTR(void);
};

BSTRING::BSTRING(LPCWSTR lpcwString)
{
	if (NULL != lpcwString)
	{
		m_bstr = SysAllocString(lpcwString);
		ASSERT(NULL != m_bstr);
	}
	else
	{
		m_bstr = NULL;
	}
}

BSTRING::~BSTRING()
{
	if (NULL != m_bstr)
	{
		SysFreeString(m_bstr);
	}
}

inline LPBSTR BSTRING::GetLPBSTR(void)
{
	ASSERT(NULL != m_bstr);

	return &m_bstr;
}



//****************************************************************************
//
// CLASS BTSTR
//
//****************************************************************************

class BTSTR
{
private:
	LPTSTR m_psz;

public:
	BTSTR(BSTR bstr);
	~BTSTR();

	// Cast to BSTR
	operator LPTSTR() {return (NULL == m_psz) ? TEXT("<null>") : m_psz;}
};

LPTSTR PszFromBstr(BSTR bst);
