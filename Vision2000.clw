; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCallControlPage
LastTemplate=CDaoRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "vision2000.h"
LastPage=0

ClassCount=21
Class1=CPlayWizardPage
Class2=CStopWizardPage
Class3=CRecordWizardPage
Class4=CPauseWizardPage
Class5=CPowerWizardPage
Class6=CFFWizardPage
Class7=CREWWizardPage
Class8=CAddInWizardPage
Class9=CCallControlPage
Class10=CCameraControlPage
Class11=CVCRControlPage
Class12=CControlSheet
Class13=CHyperLink
Class14=CIRRemoteControlPage
Class15=CMainFrame
Class16=CPreviewWnd
Class17=CSetupVCRWizardSheet
Class18=CSystemSettingsPage
Class19=CAboutDlg
Class20=CSystemTrayApp

ResourceCount=17
Resource1=IDD_IR_CONTROL_PAGE
Resource2=IDD_CAMERA_CONTROL_PAGE
Resource3=IDD_CONTROL_SHEET
Resource4=IDD_ABOUTBOX
Resource5=IDD_PROPPAGE8
Resource6=IDD_PROPPAGE4
Resource7=IDD_PROPPAGE2
Resource8=IDD_VCR_CONTROL_PAGE
Resource9=IDD_PROPPAGE7
Resource10=IDD_PROPPAGE3
Resource11=IDR_MAINFRAME
Resource12=IDD_PROPPAGE5
Resource13=IDD_PROPPAGE6
Resource14=IDR_POPUP_MENU
Resource15=IDD_SETTINGS_PAGE
Resource16=IDD_PROPPAGE1
Class21=CIRPattern
Resource17=IDD_CALL_CONTROL_PAGE

[CLS:CPlayWizardPage]
Type=0
BaseClass=CIRRemoteControlPage
HeaderFile=ButtonWizardPages.h
ImplementationFile=ButtonWizardPages.cpp

[CLS:CStopWizardPage]
Type=0
BaseClass=CIRRemoteControlPage
HeaderFile=ButtonWizardPages.h
ImplementationFile=ButtonWizardPages.cpp

[CLS:CRecordWizardPage]
Type=0
BaseClass=CIRRemoteControlPage
HeaderFile=ButtonWizardPages.h
ImplementationFile=ButtonWizardPages.cpp

[CLS:CPauseWizardPage]
Type=0
BaseClass=CIRRemoteControlPage
HeaderFile=ButtonWizardPages.h
ImplementationFile=ButtonWizardPages.cpp

[CLS:CPowerWizardPage]
Type=0
BaseClass=CIRRemoteControlPage
HeaderFile=ButtonWizardPages.h
ImplementationFile=ButtonWizardPages.cpp

[CLS:CFFWizardPage]
Type=0
BaseClass=CIRRemoteControlPage
HeaderFile=ButtonWizardPages.h
ImplementationFile=ButtonWizardPages.cpp

[CLS:CREWWizardPage]
Type=0
BaseClass=CIRRemoteControlPage
HeaderFile=ButtonWizardPages.h
ImplementationFile=ButtonWizardPages.cpp

[CLS:CAddInWizardPage]
Type=0
BaseClass=CIRRemoteControlPage
HeaderFile=ButtonWizardPages.h
ImplementationFile=ButtonWizardPages.cpp
LastObject=CAddInWizardPage

[CLS:CCallControlPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=CallControlPage.h
ImplementationFile=CallControlPage.cpp
LastObject=IDC_BUTTON_HOST
Filter=D
VirtualFilter=idWC

[CLS:CCameraControlPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=CameraControlPage.h
ImplementationFile=CameraControlPage.cpp
LastObject=CCameraControlPage
Filter=D

[CLS:CVCRControlPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=VCRControlPage.h
ImplementationFile=VCRControlPage.cpp

[CLS:CControlSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=ControlSheet.h
ImplementationFile=ControlSheet.cpp

[CLS:CHyperLink]
Type=0
BaseClass=CStatic
HeaderFile=HyperLink.h
ImplementationFile=HyperLink.cpp

[CLS:CIRRemoteControlPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=IRRemoteControlPage.h
ImplementationFile=IRRemoteControlPage.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=mainfrm.h
ImplementationFile=mainfrm.cpp

[CLS:CPreviewWnd]
Type=0
BaseClass=CWnd
HeaderFile=PreviewWnd.h
ImplementationFile=PreviewWnd.cpp

[CLS:CSetupVCRWizardSheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=SetupVCRWizardSheet.h
ImplementationFile=SetupVCRWizardSheet.cpp

[CLS:CSystemSettingsPage]
Type=0
BaseClass=CPropertyPage
HeaderFile=SystemSettingsPage.h
ImplementationFile=SystemSettingsPage.cpp

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

[DLG:IDD_PROPPAGE1]
Type=1
Class=CPlayWizardPage
ControlCount=0

[DLG:IDD_PROPPAGE2]
Type=1
Class=CStopWizardPage
ControlCount=0

[DLG:IDD_PROPPAGE3]
Type=1
Class=CRecordWizardPage
ControlCount=0

[DLG:IDD_PROPPAGE4]
Type=1
Class=CPauseWizardPage
ControlCount=0

[DLG:IDD_PROPPAGE5]
Type=1
Class=CPowerWizardPage
ControlCount=0

[DLG:IDD_PROPPAGE6]
Type=1
Class=CFFWizardPage
ControlCount=0

[DLG:IDD_PROPPAGE7]
Type=1
Class=CREWWizardPage
ControlCount=0

[DLG:IDD_PROPPAGE8]
Type=1
Class=CAddInWizardPage
ControlCount=0

[DLG:IDD_CALL_CONTROL_PAGE]
Type=1
Class=CCallControlPage
ControlCount=11
Control1=IDC_STATIC,button,1342177287
Control2=IDC_MACHINE_NAME,combobox,1344340226
Control3=IDC_CALL_HANGUP,button,1342242816
Control4=IDC_JOIN_CONFERENCE,button,1342177289
Control5=IDC_HOST_CONFERENCE,button,1342177289
Control6=IDC_BUTTON_HOST,button,1342242816
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_COFERENCE_NAME,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_CONFERENCE_PASSWORD,edit,1350631584

[DLG:IDD_CAMERA_CONTROL_PAGE]
Type=1
Class=CVCRControlPage
ControlCount=17
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_CAMERA1,button,1342242880
Control4=IDC_STATIC,button,1342177287
Control5=IDC_CAMERA2,button,1342242880
Control6=IDC_STATIC,button,1342177287
Control7=IDC_CAMERA3,button,1342242880
Control8=IDC_STATIC,button,1342177287
Control9=IDC_CAMERA4,button,1342242880
Control10=IDC_STATIC,button,1342177287
Control11=IDC_CAMERA5,button,1342242880
Control12=IDC_STATIC,button,1342177287
Control13=IDC_CAMERA6,button,1342242880
Control14=IDC_STATIC,button,1342177287
Control15=IDC_CAMERA7,button,1342242880
Control16=IDC_STATIC,button,1342177287
Control17=IDC_CAMERA8,button,1342242880

[DLG:IDD_IR_CONTROL_PAGE]
Type=1
Class=CIRRemoteControlPage
ControlCount=8
Control1=IDC_IR_RECORD,button,1342242816
Control2=IDC_IR_PLAYBACK,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_IR_LABEL,static,1342308352
Control5=IDC_IR_START,button,1342242816
Control6=IDC_IR_FIRST,button,1342242816
Control7=IDC_IR_SECOND,button,1342242816
Control8=IDC_IR_THIRD,button,1342242816

[DLG:IDD_SETTINGS_PAGE]
Type=1
Class=CSystemSettingsPage
ControlCount=8
Control1=IDC_STATIC,button,1342177287
Control2=IDC_RADIO_LPT1,button,1342181385
Control3=IDC_RADIO_LPT2,button,1342181385
Control4=IDC_RADIO_LPT3,button,1342181385
Control5=IDC_TEST_PORT,button,1342242816
Control6=IDC_LOCAL_MODE,button,1342242819
Control7=IDC_STATIC,button,1342177287
Control8=IDC_IR_WIZARD,button,1342242816

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

[CLS:CIRPattern]
Type=0
HeaderFile=IRPattern.h
ImplementationFile=IRPattern.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x

[DB:CIRPattern]
DB=1
DBType=DAO
ColumnCount=0

