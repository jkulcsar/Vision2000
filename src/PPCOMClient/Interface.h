

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

