object Form1: TForm1
  Left = 226
  Top = 112
  Width = 975
  Height = 602
  HorzScrollBar.Position = 258
  Caption = '04360092'#38515#26119#26119
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = -242
    Top = 8
    Width = 57
    Height = 20
    Caption = #36664#20837'n    '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = -242
    Top = 56
    Width = 84
    Height = 20
    Caption = #36664#20837#31684#22285'     '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 342
    Top = 8
    Width = 212
    Height = 16
    Caption = #36664#20837#22686#21152#37327' ('#35531#20808#29986#29983#20098#25976')                       '
  end
  object Label3: TLabel
    Left = -194
    Top = 448
    Width = 368
    Height = 16
    Caption = #36664#20837#25628#23563#30446#27161#25976#23383' ('#38499#21015#20098#25976#26377#37325#35079#25976#23383#21482#26371#23563#19968#20491')                               '
  end
  object Edit1: TEdit
    Left = -234
    Top = 32
    Width = 129
    Height = 24
    TabOrder = 0
    Text = '10000'
  end
  object Edit2: TEdit
    Left = -234
    Top = 80
    Width = 129
    Height = 24
    TabOrder = 1
    Text = '1000'
  end
  object Button1: TButton
    Left = -234
    Top = 136
    Width = 137
    Height = 33
    Caption = #29986#29983#20098#25976
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = -234
    Top = 176
    Width = 137
    Height = 33
    Caption = #27873#27819#25490#24207
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = -234
    Top = 216
    Width = 137
    Height = 33
    Caption = #36984#25799#25490#24207
    TabOrder = 4
    OnClick = Button3Click
  end
  object Memo1: TMemo
    Left = -74
    Top = 8
    Width = 193
    Height = 337
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object Memo2: TMemo
    Left = 134
    Top = 8
    Width = 193
    Height = 337
    Lines.Strings = (
      'Memo2')
    ScrollBars = ssVertical
    TabOrder = 6
  end
  object CheckBox1: TCheckBox
    Left = -218
    Top = 104
    Width = 137
    Height = 25
    Caption = #19981#39023#31034
    Checked = True
    State = cbChecked
    TabOrder = 7
  end
  object Memo4: TMemo
    Left = -154
    Top = 384
    Width = 491
    Height = 57
    Alignment = taCenter
    BiDiMode = bdLeftToRight
    Color = clMenuBar
    Constraints.MaxWidth = 500
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -21
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Lines.Strings = (
      'Memo4')
    ParentBiDiMode = False
    ParentFont = False
    TabOrder = 8
  end
  object Chart1: TChart
    Left = 350
    Top = 120
    Width = 617
    Height = 417
    AllowPanning = pmVertical
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    BottomWall.Color = 33023
    Gradient.StartColor = clLime
    Gradient.Visible = True
    MarginBottom = 5
    MarginLeft = 0
    MarginRight = 0
    MarginTop = 0
    Title.Font.Charset = DEFAULT_CHARSET
    Title.Font.Color = clBlue
    Title.Font.Height = -16
    Title.Font.Name = 'Arial'
    Title.Font.Style = [fsBold]
    Title.Text.Strings = (
      #25490#24207#28436#31639#27861#27604#36611)
    LeftAxis.MinorTickCount = 0
    LeftAxis.MinorTickLength = 0
    LeftAxis.TickLength = 0
    Legend.ColorWidth = 20
    Legend.ShadowSize = 0
    BevelOuter = bvNone
    TabOrder = 9
    object Series1: TLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      Pointer.InflateMargins = True
      Pointer.Style = psRectangle
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Button4: TButton
    Left = 344
    Top = 64
    Width = 111
    Height = 41
    Caption = #20998#26512#22294#34920
    TabOrder = 10
    OnClick = Button4Click
  end
  object Edit3: TEdit
    Left = 350
    Top = 32
    Width = 137
    Height = 24
    TabOrder = 11
    Text = '1000'
  end
  object Button5: TButton
    Left = -50
    Top = 472
    Width = 137
    Height = 33
    Caption = #20108#20803#25628#23563#27861
    TabOrder = 12
    OnClick = Button5Click
  end
  object Edit4: TEdit
    Left = -202
    Top = 472
    Width = 121
    Height = 24
    TabOrder = 13
    Text = '0'
  end
  object Button6: TButton
    Left = -234
    Top = 256
    Width = 137
    Height = 33
    Caption = 'Heap Sort'
    TabOrder = 14
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = -234
    Top = 296
    Width = 137
    Height = 33
    Caption = 'BST'#20013#24207
    TabOrder = 15
    OnClick = Button7Click
  end
  object CheckBox2: TCheckBox
    Left = 534
    Top = 32
    Width = 147
    Height = 25
    Caption = #21152#20837#20013#24207#36208#35370
    Checked = True
    State = cbChecked
    TabOrder = 16
  end
  object Button8: TButton
    Left = -234
    Top = 336
    Width = 137
    Height = 33
    Caption = #20013#24207#38750#36958#36852
    TabOrder = 17
    OnClick = Button8Click
  end
  object CheckBox3: TCheckBox
    Left = 536
    Top = 56
    Width = 153
    Height = 33
    Caption = #21152#20837#20013#36208#35370#38750#36958#36852
    Checked = True
    State = cbChecked
    TabOrder = 18
  end
  object CheckBox4: TCheckBox
    Left = 536
    Top = 8
    Width = 145
    Height = 25
    Caption = #21152#20837#27873#27819#25490#24207
    Checked = True
    State = cbChecked
    TabOrder = 19
  end
  object CheckBox5: TCheckBox
    Left = 536
    Top = 80
    Width = 129
    Height = 33
    Caption = #21152#20837#36984#25799#25490#24207
    Checked = True
    State = cbChecked
    TabOrder = 20
  end
  object CheckBox6: TCheckBox
    Left = 688
    Top = 8
    Width = 121
    Height = 33
    Caption = #21152#20837'Heap Sort'
    Checked = True
    State = cbChecked
    TabOrder = 21
  end
  object CheckBox7: TCheckBox
    Left = 688
    Top = 40
    Width = 129
    Height = 33
    Caption = #25554#20837#25490#24207#27861
    Checked = True
    State = cbChecked
    TabOrder = 22
  end
  object CheckBox8: TCheckBox
    Left = 688
    Top = 72
    Width = 121
    Height = 33
    Caption = #24555#36895#25490#24207#27861
    Checked = True
    State = cbChecked
    TabOrder = 23
  end
end
