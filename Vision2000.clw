; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CVCRControlPage
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

ResourceCount=7
Resource1=IDD_CONTROL_SHEET
Resource2=IDD_VISION2000_DIALOG
Resource3=IDD_ABOUTBOX
Resource4=IDR_POPUP_MENU
Resource5=IDD_VCR_CONTROL_PAGE
Resource6=IDD_CAMERA_CONTROL_PAGE
Resource7=IDR_MAINFRAME

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

[CLS:CVision2000Dlg]
Type=0
BaseClass=CDialog
HeaderFile=Vision2000Dlg.h
ImplementationFile=Vision2000Dlg.cpp

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

[DLG:IDD_CONTROL_SHEET]
Type=1
Class=?
ControlCount=0

[DLG:IDD_VCR_CONTROL_PAGE]
Type=1
Class=?
ControlCount=0

[MNU:IDR_POPUP_MENU]
Type=1
Class=?
Command1=ID_APP_ABOUT
Command2=ID_CONTROL_SHEET
Command3=ID_CALL_HANGUP
Command4=ID_SEND_TEXT
Command5=ID_APP_EXIT
CommandCount=5

[MNU:IDR_MAINFRAME]
Type=1
Class=?
CommandCount=0

