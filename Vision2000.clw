; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CPropertyPage
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "vision2000.h"
LastPage=0

ClassCount=8
Class1=CCallControlPage
Class2=CCameraControlPage
Class3=CVCRControlPage
Class4=CControlSheet
Class5=CMainFrame
Class6=CAboutDlg
Class7=CSystemTrayApp

ResourceCount=8
Resource1=IDD_VCR_CONTROL_PAGE
Resource2=IDD_ABOUTBOX
Resource3=IDD_CAMERA_CONTROL_PAGE
Resource4=IDD_IR_CONTROL_PAGE
Resource5=IDR_POPUP_MENU
Resource6=IDD_CONTROL_SHEET
Resource7=IDD_CALL_CONTROL_PAGE
Class8=CIRRemoteControlPage
Resource8=IDR_MAINFRAME

[CLS:CCallControlPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=CallControlPage.h
ImplementationFile=CallControlPage.cpp

[CLS:CCameraControlPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=CameraControlPage.h
ImplementationFile=CameraControlPage.cpp
LastObject=CCameraControlPage

[CLS:CVCRControlPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=VCRControlPage.h
ImplementationFile=VCRControlPage.cpp
LastObject=CVCRControlPage
Filter=D
VirtualFilter=idWC

[CLS:CControlSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=ControlSheet.h
ImplementationFile=ControlSheet.cpp
LastObject=CControlSheet

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp
LastObject=ID_CONTROL_SHEET
Filter=T
VirtualFilter=fWC

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Vision2000.h
ImplementationFile=Vision2000.cpp
LastObject=CAboutDlg
Filter=D
VirtualFilter=dWC

[CLS:CSystemTrayApp]
Type=0
BaseClass=CWinApp
HeaderFile=Vision2000.h
ImplementationFile=Vision2000.cpp
LastObject=CSystemTrayApp
Filter=N
VirtualFilter=AC

[DLG:IDD_CALL_CONTROL_PAGE]
Type=1
Class=CCallControlPage
ControlCount=3
Control1=IDC_STATIC,button,1342177287
Control2=IDC_MACHINE_NAME,edit,1350631552
Control3=IDC_CALL_HANGUP,button,1342242816

[DLG:IDD_CAMERA_CONTROL_PAGE]
Type=1
Class=CVCRControlPage
ControlCount=5
Control1=IDC_CAMERA1,button,1342242827
Control2=IDC_CAMERA2,button,1342242827
Control3=IDC_CAMERA3,button,1342242827
Control4=IDC_CAMERA4,button,1342242827
Control5=IDC_STATIC,button,1342177287

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308480
Control2=IDC_STATIC,static,1342308352
Control3=IDOK,button,1342373889
Control4=IDC_STATIC_ICON,static,1342177283
Control5=IDC_EMAIL,static,1342308864
Control6=IDC_WEBSITE,static,1342308864
Control7=IDC_STATIC,button,1342177287

[DLG:IDD_CONTROL_SHEET]
Type=1
Class=?
ControlCount=0

[DLG:IDD_VCR_CONTROL_PAGE]
Type=1
Class=?
ControlCount=16
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,button,1342177287
Control6=IDC_STATIC,button,1342177287
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,button,1342177287
Control9=IDC_REW,button,1342242827
Control10=IDC_REC,button,1342242827
Control11=IDC_PLAY,button,1342242827
Control12=IDC_FF,button,1342242827
Control13=IDC_STOP,button,1342242827
Control14=IDC_PAUSE,button,1342242827
Control15=IDC_VCR,button,1342242827
Control16=IDC_POWER,button,1342242827

[MNU:IDR_POPUP_MENU]
Type=1
Class=?
Command1=ID_CONTROL_SHEET
Command2=ID_APP_ABOUT
Command3=ID_APP_EXIT
CommandCount=3

[MNU:IDR_MAINFRAME]
Type=1
Class=?
CommandCount=0

[DLG:IDD_IR_CONTROL_PAGE]
Type=1
Class=CIRRemoteControlPage
ControlCount=3
Control1=IDC_IR_RECORD,button,1342242816
Control2=IDC_IR_PLAYBACK,button,1342242816
Control3=IDC_STATIC,button,1342177287

[CLS:CIRRemoteControlPage]
Type=0
HeaderFile=IRRemoteControlPage.h
ImplementationFile=IRRemoteControlPage.cpp
BaseClass=CPropertyPage
Filter=D
VirtualFilter=idWC
LastObject=CIRRemoteControlPage

