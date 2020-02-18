; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSystemTrayApp
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "vision2000.h"
LastPage=0

ClassCount=7
Class1=CCameraControlPage
Class2=CVCRControlPage
Class3=CControlSheet
Class4=CMainFrame
Class5=CAboutDlg
Class6=CSystemTrayApp
Class7=CVision2000Dlg

ResourceCount=6
Resource1=IDD_CAMERA_CONTROL_PAGE
Resource2=IDD_ABOUTBOX
Resource3=IDD_VCR_CONTROL_PAGE
Resource4=IDD_CONTROL_SHEET
Resource5=IDR_POPUP_MENU
Resource6=IDR_MAINFRAME

[CLS:CCameraControlPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=CameraControlPage.h
ImplementationFile=CameraControlPage.cpp
LastObject=CCameraControlPage
Filter=D
VirtualFilter=idWC

[CLS:CVCRControlPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=VCRControlPage.h
ImplementationFile=VCRControlPage.cpp
Filter=D
VirtualFilter=idWC
LastObject=CVCRControlPage

[CLS:CControlSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=ControlSheet.h
ImplementationFile=ControlSheet.cpp
LastObject=CControlSheet
Filter=W
VirtualFilter=hWC

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp

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
Filter=N
VirtualFilter=AC
LastObject=ID_APP_ABOUT

[CLS:CVision2000Dlg]
Type=0
BaseClass=CDialog
HeaderFile=Vision2000Dlg.h
ImplementationFile=Vision2000Dlg.cpp

[DLG:IDD_CAMERA_CONTROL_PAGE]
Type=1
Class=CVCRControlPage
ControlCount=5
Control1=IDC_CAMERA1,button,1342242816
Control2=IDC_CAMERA2,button,1342242816
Control3=IDC_CAMERA3,button,1342242816
Control4=IDC_CAMERA4,button,1342242816
Control5=IDC_STATIC,button,1342177287

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

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
Control9=IDC_REW,button,1342242816
Control10=IDC_REC,button,1342242816
Control11=IDC_PLAY,button,1342242816
Control12=IDC_FF,button,1342242816
Control13=IDC_STOP,button,1342242816
Control14=IDC_PAUSE,button,1342242816
Control15=IDC_VCR,button,1342242816
Control16=IDC_POWER,button,1342242816

[MNU:IDR_POPUP_MENU]
Type=1
Class=?
Command1=ID_APP_ABOUT
Command2=ID_CONTROL_SHEET
Command3=ID_CALL_HANGUP
Command4=ID_APP_EXIT
CommandCount=4

[MNU:IDR_MAINFRAME]
Type=1
Class=?
CommandCount=0

