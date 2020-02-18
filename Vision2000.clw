; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSystemTrayApp
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "vision2000.h"
LastPage=0

ClassCount=4
Class1=CMainFrame
Class2=CAboutDlg
Class3=CSystemTrayApp
Class4=CVision2000Dlg

ResourceCount=4
Resource1=IDD_VISION2000_DIALOG
Resource2=IDR_POPUP_MENU
Resource3=IDD_ABOUTBOX
Resource4=IDR_MAINFRAME

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp
LastObject=ID_APP_ABOUT
Filter=T
VirtualFilter=fWC

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Vision2000.h
ImplementationFile=Vision2000.cpp
LastObject=CAboutDlg

[CLS:CSystemTrayApp]
Type=0
BaseClass=CWinApp
HeaderFile=Vision2000.h
ImplementationFile=Vision2000.cpp
LastObject=ID_SEND_TEXT
Filter=N
VirtualFilter=AC

[CLS:CVision2000Dlg]
Type=0
BaseClass=CDialog
HeaderFile=Vision2000Dlg.h
ImplementationFile=Vision2000Dlg.cpp
LastObject=CVision2000Dlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_VISION2000_DIALOG]
Type=1
Class=CVision2000Dlg
ControlCount=9
Control1=IDC_MACHINENAME,edit,1350631552
Control2=IDC_CALLHANGUP,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_OPEN_DATA,button,1342242816
Control5=IDC_CAMERA_1,button,1342242816
Control6=IDC_CAMERA_2,button,1342242816
Control7=IDC_CAMERA_3,button,1342242816
Control8=IDC_CAMERA_4,button,1342242816
Control9=IDC_STATIC,button,1342177287

[MNU:IDR_POPUP_MENU]
Type=1
Class=?
Command1=ID_APP_ABOUT
Command2=ID_CALL_HANGUP
Command3=ID_SEND_TEXT
Command4=ID_APP_EXIT
CommandCount=4

[MNU:IDR_MAINFRAME]
Type=1
Class=?
CommandCount=0

