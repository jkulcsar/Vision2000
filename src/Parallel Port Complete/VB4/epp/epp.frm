VERSION 4.00
Begin VB.Form frmMain 
   Appearance      =   0  'Flat
   BackColor       =   &H80000005&
   Caption         =   "Parallel Port Complete"
   ClientHeight    =   2532
   ClientLeft      =   3900
   ClientTop       =   4188
   ClientWidth     =   4224
   BeginProperty Font 
      name            =   "MS Sans Serif"
      charset         =   1
      weight          =   700
      size            =   7.8
      underline       =   0   'False
      italic          =   0   'False
      strikethrough   =   0   'False
   EndProperty
   ForeColor       =   &H00C0C0C0&
   Height          =   3192
   Left            =   3852
   LinkTopic       =   "Form1"
   ScaleHeight     =   2532
   ScaleWidth      =   4224
   Top             =   3576
   Width           =   4320
   Begin VB.TextBox txtDataOut 
      Appearance      =   0  'Flat
      Height          =   372
      Left            =   120
      MaxLength       =   16
      MultiLine       =   -1  'True
      TabIndex        =   2
      Text            =   "EPP.frx":0000
      Top             =   1560
      Width           =   1932
   End
   Begin VB.CommandButton cmdReadDataFromPort 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      Caption         =   "Receive"
      Height          =   732
      Left            =   2280
      TabIndex        =   1
      Top             =   120
      Width           =   1572
   End
   Begin VB.Timer tmrTimedOut 
      Enabled         =   0   'False
      Interval        =   5000
      Left            =   3720
      Top             =   2040
   End
   Begin VB.CommandButton cmdWriteDataToPort 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      Caption         =   "Send"
      Height          =   732
      Left            =   240
      TabIndex        =   0
      Top             =   120
      Width           =   1572
   End
   Begin VB.Label lblByte 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      Caption         =   "(EPP Mode)"
      ForeColor       =   &H80000008&
      Height          =   252
      Left            =   2280
      TabIndex        =   6
      Top             =   1200
      Width           =   1572
   End
   Begin VB.Label lblCompatibility 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      Caption         =   "(EPP Mode)"
      ForeColor       =   &H80000008&
      Height          =   372
      Left            =   120
      TabIndex        =   7
      Top             =   1200
      Width           =   1812
   End
   Begin VB.Label lblDataInDisplay 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BorderStyle     =   1  'Fixed Single
      ForeColor       =   &H80000008&
      Height          =   372
      Left            =   2160
      TabIndex        =   5
      Top             =   1560
      Width           =   1932
      WordWrap        =   -1  'True
   End
   Begin VB.Label lblDataIn 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      Caption         =   "Data In"
      ForeColor       =   &H80000008&
      Height          =   252
      Left            =   2400
      TabIndex        =   4
      Top             =   960
      Width           =   1332
   End
   Begin VB.Label lblDataOut 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      Caption         =   "DataOut"
      ForeColor       =   &H80000008&
      Height          =   252
      Left            =   240
      TabIndex        =   3
      Top             =   960
      Width           =   1584
      WordWrap        =   -1  'True
   End
   Begin VB.Menu mnuSetup 
      Caption         =   "&Setup"
      Index           =   0
      Begin VB.Menu mnuPort 
         Caption         =   "&Port..."
         Index           =   0
      End
   End
End
Attribute VB_Name = "frmMain"
Attribute VB_Creatable = False
Attribute VB_Exposed = False
Option Explicit

Dim StatusPortData%
Dim ControlPortData%
Dim TimedOut%
Dim DirectionSet%
Dim DataIn%
Dim LowNibble%
Dim HighNibble%
Dim ReadAnother%
Dim Character$

Private Sub cmdReadDataFromPort_Click()
'Read characters from the parallel port.
'Display the received characters on the form.
Dim CharNumber%
CharNumber = 0
TimedOut = False
lblDataInDisplay.Caption = ""
DirectionSet = DirectionRequest("PeripheralToPc")
tmrTimedOut.Enabled = True

'Read bytes at the port.
'After each byte, read the status port.
'Stop reading if S3 =1 (indicates end of transmission).
ReadAnother = True
Do Until ReadAnother = False Or TimedOut = True
    DoEvents
    ReadByteFromPort
    lblDataInDisplay.Caption = lblDataInDisplay.Caption + Chr$(DataIn)
    CharNumber = CharNumber + 1
Loop
    If Not (TimedOut) Then
        MsgBox "Successful transfer", 0, "Result"
    End If
CharNumber = 0
tmrTimedOut.Enabled = False
'Re-enable the data outputs.
DirectionSet = DirectionRequest("PcToPeripheral")
End Sub

Private Sub cmdWriteDataToPort_Click()
Dim CharNumber%
TimedOut = False
tmrTimedOut.Enabled = True
ControlPortData = ControlPortRead(BaseAddress)
BitSet ControlPortData, 1
ControlPortWrite ControlPortData, BaseAddress
'Write the characters in the text box to the parallel port.
For CharNumber = 1 To 16
    If Not (TimedOut) Then
        'Write each character in sequence
        Character = Mid$(txtDataOut.Text, CharNumber, 1)
        If Character = "" Then Character = " "
        WriteByteToPort
    End If
Next CharNumber
If Not (TimedOut) Then
    MsgBox "Successful transfer", 0, "Result"
End If
tmrTimedOut.Enabled = False
End Sub

Private Function DirectionRequest%(Direction$)
Dim S3%
Dim C3%
Direction = LCase$(Direction)
ControlPortData = ControlPortRead(BaseAddress)
BitSet ControlPortData, 1
'Set Control port bits to match the selected direction.
'For control bit 5,
'0 enables the data outputs, 1 tristates the outputs.
Select Case Direction
    Case "pctoperipheral"
        BitSet ControlPortData, 3
        BitReset ControlPortData, 5
        C3 = 1
    Case "peripheraltopc"
        BitReset ControlPortData, 3
        BitSet ControlPortData, 5
        C3 = 0
    Case Else
    End Select
ControlPortWrite BaseAddress, ControlPortData
tmrTimedOut.Enabled = True
Do
    'Wait for the peripheral to acknowldege the
    'direction change.
    StatusPortData = StatusPortRead(BaseAddress)
    S3 = BitRead(StatusPortData, 3)
    DoEvents
    If TimedOut Then Exit Function
Loop Until C3 = S3
If C3 = S3 Then tmrTimedOut.Enabled = False
End Function

Private Sub Form_Load()
StartUp
DirectionSet = DirectionRequest("PcToPeripheral")
'Timeout limit for peripheral.
tmrTimedOut.Interval = 5000
tmrTimedOut.Enabled = False
EppDataPort0Address = BaseAddress + 4
'Initial test data
txtDataOut.Text = "0123456789ABCDEF"

End Sub

Private Sub Form_Unload(Cancel%)
ShutDown
End
End Sub

Private Sub mnuPort_Click(Index%)
frmSelectPort.Show

End Sub

Private Sub ReadByteFromPort()
'Read one character from the parallel port.
'Uses EPP mode.
Dim S7%
Dim S3%
Dim DataPortData%
'Wait for S7=0.
Do
    StatusPortData = StatusPortRead(BaseAddress)
    S7 = BitRead(StatusPortData, 7)
    If ReadEppTimeoutBit(BaseAddress) = 1 Then
        tmrTimedOut_Timer
    End If
    DoEvents
    If TimedOut Then Exit Sub
Loop Until S7 = 0
'Read the byte
DataIn = DataPortRead(EppDataPort0Address)

'Check the timeout bit.
'If it's set, clear it and display the timeout message.
Dim ByteTimeout%
ByteTimeout = ReadEppTimeoutBit(BaseAddress)
If ByteTimeout = 1 Then
    tmrTimedOut_Timer
End If

'If S3 =1, the transmission is complete.
StatusPortData = StatusPortRead(BaseAddress)
If (StatusPortData And 8) > 0 Then
    ReadAnother = False
End If
End Sub

Private Sub tmrTimedOut_Timer()
'On timeout, display a message and switch
'direction to PC-to-peripheral.
TimedOut = True
MsgBox "Peripheral not responding", 0, "Warning"
DirectionSet = DirectionRequest("PcToPeripheral")
tmrTimedOut.Enabled = False
End Sub

Private Sub WriteByteToPort()
'Write one character to the parallel port.
'Uses EPP mode.
Dim S7%
Dim ByteTimeout%
'Wait for Busy (S7)=0, then write a byte to the data port.
Do
    StatusPortData = StatusPortRead(BaseAddress)
    S7 = BitRead(StatusPortData, 7)
    DoEvents
    If TimedOut Then Exit Sub
Loop Until S7 = 0
If Character = "" Then Character = " "
DataPortWrite EppDataPort0Address, Asc(Character)

'Check the timeout bit.
'If it's set, clear it and display the timeout message.
ByteTimeout = ReadEppTimeoutBit(BaseAddress)
If ByteTimeout = 1 Then
    tmrTimedOut_Timer
End If
End Sub

