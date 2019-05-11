object Form1: TForm1
  Left = 76
  Top = 122
  Width = 1283
  Height = 562
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
    Left = 16
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
    Left = 16
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
    Left = 848
    Top = 64
    Width = 87
    Height = 16
    Caption = #36664#20837#22686#21152#37327'         '
  end
  object Label3: TLabel
    Left = 200
    Top = 448
    Width = 368
    Height = 16
    Caption = #36664#20837#25628#23563#30446#27161#25976#23383' ('#38499#21015#20098#25976#26377#37325#35079#25976#23383#21482#26371#23563#19968#20491')                               '
  end
  object Edit1: TEdit
    Left = 48
    Top = 32
    Width = 129
    Height = 24
    TabOrder = 0
    Text = '10000'
  end
  object Edit2: TEdit
    Left = 48
    Top = 80
    Width = 129
    Height = 24
    TabOrder = 1
    Text = '100'
  end
  object Button1: TButton
    Left = 32
    Top = 136
    Width = 145
    Height = 73
    Caption = #29986#29983#20098#25976
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 32
    Top = 232
    Width = 145
    Height = 73
    Caption = #27873#27819#25490#24207
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 32
    Top = 328
    Width = 145
    Height = 81
    Caption = #36984#25799#25490#24207
    TabOrder = 4
    OnClick = Button3Click
  end
  object Memo1: TMemo
    Left = 200
    Top = 8
    Width = 193
    Height = 337
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object Memo2: TMemo
    Left = 416
    Top = 8
    Width = 193
    Height = 337
    Lines.Strings = (
      'Memo2')
    ScrollBars = ssVertical
    TabOrder = 6
  end
  object Memo3: TMemo
    Left = 632
    Top = 8
    Width = 193
    Height = 337
    Lines.Strings = (
      'Memo3')
    ScrollBars = ssVertical
    TabOrder = 7
  end
  object CheckBox1: TCheckBox
    Left = 40
    Top = 104
    Width = 145
    Height = 25
    Caption = #19981#39023#31034
    Checked = True
    State = cbChecked
    TabOrder = 8
  end
  object Memo4: TMemo
    Left = 248
    Top = 360
    Width = 500
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
    TabOrder = 9
  end
  object Chart1: TChart
    Left = 840
    Top = 168
    Width = 417
    Height = 337
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'TChart')
    View3D = False
    TabOrder = 10
    object Series1: TFastLineSeries
      Marks.ArrowLength = 8
      Marks.Visible = False
      SeriesColor = clRed
      LinePen.Color = clRed
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
    Left = 1048
    Top = 48
    Width = 185
    Height = 97
    Caption = #20998#26512#22294#34920
    TabOrder = 11
    OnClick = Button4Click
  end
  object Edit3: TEdit
    Left = 872
    Top = 88
    Width = 137
    Height = 24
    TabOrder = 12
    Text = '100'
  end
  object Button5: TButton
    Left = 32
    Top = 432
    Width = 145
    Height = 81
    Caption = #20108#20803#25628#23563#27861
    TabOrder = 13
    OnClick = Button5Click
  end
  object Edit4: TEdit
    Left = 200
    Top = 472
    Width = 121
    Height = 24
    TabOrder = 14
    Text = '0'
  end
end
