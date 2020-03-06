VERSION 5.00
Begin VB.Form frmNewPortAddress 
   Appearance      =   0  'Flat
   BackColor       =   &H80000005&
   Caption         =   "Parallel Port Resource"
   ClientHeight    =   1485
   ClientLeft      =   870
   ClientTop       =   1410
   ClientWidth     =   4095
   BeginProperty Font 
      Name            =   "MS Sans Serif"
      Size            =   8.25
      Charset         =   0
      Weight          =   700
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   ForeColor       =   &H80000008&
   LinkTopic       =   "Form1"
   PaletteMode     =   1  'UseZOrder
   ScaleHeight     =   1485
   ScaleWidth      =   4095
   Begin VB.CommandButton cmdCancel 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      Caption         =   "Cancel"
      Height          =   492
      Left            =   1560
      TabIndex        =   4
      Top             =   840
      Width           =   852
   End
   Begin VB.CommandButton cmdOK 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      Caption         =   "OK"
      Height          =   492
      Left            =   2640
      TabIndex        =   3
      Top             =   840
      Width           =   852
   End
   Begin VB.TextBox txtAddressOfNonStandardPort 
      Appearance      =   0  'Flat
      Height          =   372
      Left            =   3000
      TabIndex        =   0
      Top             =   240
      Width           =   612
   End
   Begin VB.Label lblh 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      Caption         =   "h"
      ForeColor       =   &H80000008&
      Height          =   372
      Left            =   3720
      TabIndex        =   2
      Top             =   240
      Width           =   252
   End
   Begin VB.Label lblAddressOfNonStandardPort 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      Caption         =   "Address of nonstandard port:"
      ForeColor       =   &H80000008&
      Height          =   372
      Left            =   120
      TabIndex        =   1
      Top             =   240
      Width           =   2772
   End
End
Attribute VB_Name = "frmNewPortAddress"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub cmdCancel_Click()
frmNewPortAddress.Hide
End Sub

Private Sub cmdOK_Click()
Dim NewPortAddress%
Dim IndexOfNewPort%
Dim Character$
Dim ValidEntry%
ValidEntry = True
IndexOfNewPort = 3
'Read the port address entered by the user.
'If the address is within the accepted range, hide this form,
'enable the port's option button, and display the address.
'If the address is out of range, display a message.
'If the text box is empty, disable the port's option button.
Select Case txtAddressOfNonStandardPort.Text
    Case ""
        NewPortAddress = 0
        Port(IndexOfNewPort).Address = 0
        Port(IndexOfNewPort).PortType = ""
        Port(IndexOfNewPort).Enabled = False
        frmSelectPort.optPortName(0).Value = True
        frmNewPortAddress.Hide
        UpdateLabels
    Case Else
        NewPortAddress = CInt(Val("&h" & txtAddressOfNonStandardPort.Text))
        If NewPortAddress > 0 And NewPortAddress < &H800 Then
            Port(IndexOfNewPort).Address = NewPortAddress
            Port(IndexOfNewPort).Enabled = True
            frmSelectPort.optPortName(IndexOfNewPort).Value = True
            frmNewPortAddress.Hide
            UpdateLabels
        Else
            MsgBox "The port address must be between 0 and 7FFF. Leave the address blank if there is no port."
        End If
End Select
End Sub

Private Sub Form_Load()
Left = (Screen.Width - Width) / 2
Top = (Screen.Height - Height) / 2
End Sub

