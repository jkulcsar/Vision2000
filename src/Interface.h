
	//  IRead
	// {A417E6A0-323D-11d3-AFB0-004095D0EF62}
	static const IID IID_IRead = 
	{ 0xA417E6A0, 0x323D, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };

	//  IWrite
	// {6FF402E0-323E-11d3-AFB0-004095D0EF62}
	static const IID IID_IWrite = 
	{ 0x6FF402E0, 0x323E, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	// IGet
	// {6F448280-362F-11d3-AFB0-004095D0EF62}
	static const IID IID_IGet = 
	{ 0x6F448280, 0x362F, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	// ISet
	// {6F448281-362F-11d3-AFB0-004095D0EF62}
	static const IID IID_ISet = 
	{ 0x6F448281, 0x362F, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };


	// ITest
	// {6F448282-362F-11d3-AFB0-004095D0EF62}
	static const IID IID_ITest = 
	{ 0x6F448282, 0x362F, 0x11d3,
	{ 0xAF, 0xB0, 0x00, 0x40, 0x95, 0xD0, 0xEF, 0x62 } };
	


	//  IParallelPort
	// {98757173-3237-11D3-AFB0-004095D0EF62}
	//static const IID IID_IParallelPort =
	//{ 0x98757173, 0x3237, 0x11d3, 
	//{ 0xaf, 0xb0, 0x0, 0x40, 0x95, 0xd0, 0xef, 0x62 } };



 struct IRead : public IUnknown
 {
	STDMETHOD_( BYTE, ReadControlPort) () = 0;
	STDMETHOD_(	BYTE, ReadDataPort) () = 0;
	STDMETHOD_(	BYTE, ReadStatusPort) () = 0;
 };


 struct IWrite : public IUnknown
 {
	STDMETHOD_(	void, WriteControlPort)( BYTE ) = 0;
	STDMETHOD_(	void, WriteDataPort)( BYTE ) = 0;
 };


 struct IGet : public IUnknown
 {
 	STDMETHOD_( LPCTSTR, GetECPModeDescription) () = 0;
	STDMETHOD_( LPCTSTR, GetName) () = 0;
	STDMETHOD_( LPCTSTR, GetPortType) () = 0;
	STDMETHOD_( unsigned short,  GetAddress) () = 0;
 };

	
 struct ISet : public IUnknown
 {
	STDMETHOD_( void, SetAddress)( unsigned short ) = 0;
	STDMETHOD_( void, SetName)( LPCTSTR ) = 0;
 };

 struct ITest : public IUnknown
 {
 	STDMETHOD_( BOOL, TestPort)() = 0;
	STDMETHOD_( BOOL, IsEnabled)() = 0;
 };

