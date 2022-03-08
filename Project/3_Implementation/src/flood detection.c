Option Explicit
Dim BUFFERS$
Private Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)
Dim message As Integer
Dim search As String
Dim gsmsearch As String
Dim mints As Integer
Dim mints2 As Integer
Dim mints3 As Integer
Dim seconds As Integer
Dim seconds2 As Integer
Dim seconds3 As Integer
Dim i As Integer
 
Dim counter1 As Integer
Dim mytext As String
 
 
 
 
 
Private Sub Check6_Click()
mytext = Text1.Text
 
 
 
Open "c:\myfile.txt" For Append As #1
Write #1, mytext
Close #1
End Sub
 
 
 
 
 
 
 
 
Private Sub Command1_Click()
frmAbout.Show
 
End Sub
 
Private Sub Command2_Click()
Shape1.FillColor = &HFF00&
Shape2.FillColor = &HFF00&
Shape3.FillColor = &HFF00&
Timer2.Enabled = False
Timer6.Enabled = False
Timer7.Enabled = False
 
mints = 0
mints2 = 0
mints3 = 0
 
seconds = 0
seconds2 = 0
seconds3 = 0
End Sub
 
Private Sub Form_Load()
 
 
 
 
 
    With MSComm2         ' gsm connected here
        .CommPort = 5
        .Settings = "9600,N,8,1"
        .Handshaking = comRTS
        .RTSEnable = True
        .DTREnable = True
        .RThreshold = 1
        .SThreshold = 1
        .InputMode = comInputModeText
        .InputLen = 0
        .PortOpen = True 'must be the last
    End With
 
counter1 = 1
 
Timer8.Enabled = False
End Sub
 
 
 
 
 
 
 
 
Private Sub Timer1_Timer()
'txtrec.Text = ""
 
txtrec.Text = txtrec.Text + MSComm2.Input
 
Label2.Caption = txtrec.Text
search = txtrec.Text
 
 
 
 
If InStr(search, "critical situation 2") Then
Timer8.Enabled = True
 
shpcs2.FillColor = &HFF&
shpcs1.FillColor = &HFF&
shplh2.FillColor = &HFF&
shplh1.FillColor = &HFF&
shpml2.FillColor = &HFF&
shpml1.FillColor = &HFF&
shpn.FillColor = &HFF&
shpl.FillColor = &HFF&
 
txtrec.Text = ""
Timer2.Enabled = True
 
ElseIf InStr(search, "critical situation 1") Then
Timer8.Enabled = True
 
shpcs2.FillColor = &HFF00& ' green color
shpcs1.FillColor = &HFF& ' red color
shplh2.FillColor = &HFF&
shplh1.FillColor = &HFF&
shpml2.FillColor = &HFF&
shpml1.FillColor = &HFF&
shpn.FillColor = &HFF&
shpl.FillColor = &HFF&
 
 
txtrec.Text = ""
Timer6.Enabled = True
 
ElseIf InStr(search, "level high2") Then
Timer8.Enabled = True
 
shpcs1.FillColor = &HFF00&  ' green
shpcs2.FillColor = &HFF00& ' green color
 
shplh2.FillColor = &HFF&
shplh1.FillColor = &HFF&
shpml2.FillColor = &HFF&
shpml1.FillColor = &HFF&
shpn.FillColor = &HFF&
shpl.FillColor = &HFF&
txtrec.Text = ""
Timer7.Enabled = True
 
 
ElseIf InStr(search, "level high1") Then
Timer8.Enabled = True
 
shpcs1.FillColor = &HFF00&  ' green
shpcs2.FillColor = &HFF00& ' green color
shplh2.FillColor = &HFF00& ' green color
 
shplh1.FillColor = &HFF& ' red
shpml2.FillColor = &HFF&
shpml1.FillColor = &HFF&
shpn.FillColor = &HFF&
shpl.FillColor = &HFF&
txtrec.Text = ""
 
 
ElseIf InStr(search, "medium level 2") Then
Timer8.Enabled = True
 
shpcs1.FillColor = &HFF00&  ' green color
shpcs2.FillColor = &HFF00& ' green color
shplh2.FillColor = &HFF00& ' green color
shplh1.FillColor = &HFF00& ' green color
 
shpml2.FillColor = &HFF& ' red
shpml1.FillColor = &HFF&
shpn.FillColor = &HFF&
shpl.FillColor = &HFF&
txtrec.Text = ""
 
 
 
ElseIf InStr(search, "medium level 1") Then
Timer8.Enabled = True
 
shpcs1.FillColor = &HFF00&  ' green color
shpcs2.FillColor = &HFF00& ' green color
shplh2.FillColor = &HFF00& ' green color
shplh1.FillColor = &HFF00& ' green color
shpml2.FillColor = &HFF00& ' green color
 
shpml1.FillColor = &HFF& ' red color
shpn.FillColor = &HFF&
shpl.FillColor = &HFF&
txtrec.Text = ""
 
 
ElseIf InStr(search, "normal level") Then
Timer8.Enabled = True
 
shpcs1.FillColor = &HFF00&  ' green color
shpcs2.FillColor = &HFF00& ' green color
shplh2.FillColor = &HFF00& ' green color
shplh1.FillColor = &HFF00& ' green color
shpml2.FillColor = &HFF00& ' green color
 
shpml1.FillColor = &HFF00& ' green color
shpn.FillColor = &HFF& ' red color
shpl.FillColor = &HFF&
 
 
txtrec.Text = ""
 
 
 
 
ElseIf InStr(search, "lower") Then
Timer8.Enabled = True
 
shpcs1.FillColor = &HFF00&  ' green color
shpcs2.FillColor = &HFF00& ' green color
shplh2.FillColor = &HFF00& ' green color
shplh1.FillColor = &HFF00& ' green color
shpml2.FillColor = &HFF00& ' green color
shpml1.FillColor = &HFF00& ' green color
shpn.FillColor = &HFF00& ' green color
 
shpl.FillColor = &HFF& ' red color
 
 
txtrec.Text = ""
 
End If
 
'Sleep (1000)
 
 
End Sub
 
 
 
 
 
Private Sub Timer2_Timer()
seconds = seconds + 1
Label9.Caption = seconds
If seconds = 59 Then
seconds = 0
mints = mints + 1
Label10.Caption = mints
End If
End Sub
 
Private Sub Timer4_Timer()
Text2.Text = Time
Text3.Text = Date
 
End Sub
 
 
Private Sub Timer6_Timer()
seconds2 = seconds2 + 1
Label11.Caption = seconds2
If seconds2 = 59 Then
seconds = 0
mints2 = mints2 + 1
Label12.Caption = mints2
End If
End Sub
 
Private Sub Timer7_Timer()
seconds3 = seconds3 + 1
Label13.Caption = seconds3
If seconds3 = 59 Then
seconds3 = 0
mints3 = mints3 + 1
Label14.Caption = mints3
End If
End Sub
