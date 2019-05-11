object Form1: TForm1
  Left = 213
  Top = 125
  Width = 646
  Height = 481
  Caption = '04360092_'#38515#26119#26119
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 209
    Width = 638
    Height = 3
    Cursor = crVSplit
    Align = alTop
  end
  object Memo1: TMemo
    Left = 0
    Top = 212
    Width = 638
    Height = 238
    Align = alClient
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Consolas'
    Font.Style = []
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 638
    Height = 209
    ActivePage = TabSheet1
    Align = alTop
    TabIndex = 0
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #20108#20803#27193
      object Label1: TLabel
        Left = 8
        Top = 136
        Width = 81
        Height = 16
        Caption = #25628#23563#25976#23383#65306'       '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label2: TLabel
        Left = 8
        Top = 8
        Width = 48
        Height = 16
        Caption = #25976#37327#65306'    '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label3: TLabel
        Left = 8
        Top = 40
        Width = 45
        Height = 16
        Caption = #31684#22285#65306'   '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Label4: TLabel
        Left = 8
        Top = 88
        Width = 48
        Height = 16
        Caption = #26032#22686#65306'    '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
      end
      object Edit1: TEdit
        Left = 96
        Top = 136
        Width = 57
        Height = 21
        TabOrder = 0
        Text = '10'
      end
      object Button1: TButton
        Left = 184
        Top = 136
        Width = 97
        Height = 41
        Caption = #25628#23563
        TabOrder = 1
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 184
        Top = 16
        Width = 97
        Height = 41
        Caption = #25554#20837#20098#25976
        TabOrder = 2
        OnClick = Button2Click
      end
      object Edit2: TEdit
        Left = 72
        Top = 8
        Width = 81
        Height = 21
        TabOrder = 3
        Text = '10'
      end
      object Edit3: TEdit
        Left = 72
        Top = 40
        Width = 81
        Height = 21
        TabOrder = 4
        Text = '100'
      end
      object GroupBox1: TGroupBox
        Left = 328
        Top = 8
        Width = 97
        Height = 105
        Caption = #36208#35370#26041#24335
        TabOrder = 5
        object RadioButton1: TRadioButton
          Left = 8
          Top = 16
          Width = 81
          Height = 25
          Caption = #21069#24207
          TabOrder = 0
        end
        object RadioButton2: TRadioButton
          Left = 8
          Top = 40
          Width = 65
          Height = 25
          Caption = #20013#24207
          Checked = True
          ParentShowHint = False
          ShowHint = False
          TabOrder = 1
          TabStop = True
        end
        object RadioButton3: TRadioButton
          Left = 8
          Top = 64
          Width = 65
          Height = 25
          Caption = #24460#24207
          TabOrder = 2
        end
      end
      object GroupBox2: TGroupBox
        Left = 480
        Top = 8
        Width = 81
        Height = 89
        Caption = #31243#24335#30908
        TabOrder = 6
        object RadioButton4: TRadioButton
          Left = 8
          Top = 24
          Width = 57
          Height = 17
          Caption = #36958#36852
          Checked = True
          TabOrder = 0
          TabStop = True
        end
        object RadioButton5: TRadioButton
          Left = 8
          Top = 56
          Width = 65
          Height = 17
          Caption = #38750#36958#36852
          TabOrder = 1
        end
      end
      object Button3: TButton
        Left = 496
        Top = 128
        Width = 113
        Height = 41
        Caption = #21360#20986
        TabOrder = 7
        OnClick = Button3Click
      end
      object Edit4: TEdit
        Left = 72
        Top = 88
        Width = 81
        Height = 21
        TabOrder = 8
        Text = '5'
      end
      object Button4: TButton
        Left = 184
        Top = 80
        Width = 97
        Height = 41
        Caption = #26032#22686
        TabOrder = 9
        OnClick = Button4Click
      end
    end
  end
end
