object Form1: TForm1
  Left = 243
  Top = 120
  Width = 660
  Height = 454
  Caption = '04360092'#38515#26119#26119
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
    Top = 105
    Width = 652
    Height = 8
    Cursor = crVSplit
    Align = alTop
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 652
    Height = 105
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 24
      Width = 73
      Height = 20
      Caption = #36664#20837'n'#65306'    '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 376
      Top = 16
      Width = 123
      Height = 13
      Caption = #22855#25976#38499#21015#25490#21015#36984#25799'         '
    end
    object Edit1: TEdit
      Left = 96
      Top = 24
      Width = 89
      Height = 21
      TabOrder = 0
      Text = '5'
    end
    object Button1: TButton
      Left = 208
      Top = 16
      Width = 137
      Height = 65
      Caption = #30906#23450
      TabOrder = 1
      OnClick = Button1Click
    end
    object RadioButton1: TRadioButton
      Left = 376
      Top = 32
      Width = 121
      Height = 33
      Caption = 'left-top'
      Checked = True
      TabOrder = 2
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 448
      Top = 32
      Width = 105
      Height = 33
      Caption = 'right-top'
      TabOrder = 3
    end
    object RadioButton3: TRadioButton
      Left = 376
      Top = 56
      Width = 113
      Height = 33
      Caption = 'left-bottom'
      TabOrder = 4
    end
    object RadioButton4: TRadioButton
      Left = 448
      Top = 64
      Width = 105
      Height = 17
      Caption = 'right-bottom'
      TabOrder = 5
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 113
    Width = 652
    Height = 310
    ActivePage = TabSheet3
    Align = alClient
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabIndex = 2
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'ListBox'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 644
        Height = 282
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'FixedSpaceBox'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 644
        Height = 282
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'Rich+FixedBox(Test)'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 644
        Height = 282
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Consolas'
        Font.Style = [fsBold]
        Lines.Strings = (
          'Memo3')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'Rich+FixedBox'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Consolas'
      Font.Style = [fsBold]
      ImageIndex = 3
      ParentFont = False
      object Memo4: TMemo
        Left = 0
        Top = 0
        Width = 644
        Height = 282
        Align = alClient
        Lines.Strings = (
          'Memo4')
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'DataGridView'
      ImageIndex = 4
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 644
        Height = 282
        Align = alClient
        Color = clInfoBk
        FixedCols = 0
        FixedRows = 0
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Consolas'
        Font.Style = [fsBold]
        GridLineWidth = 2
        ParentFont = False
        TabOrder = 0
        OnDrawCell = StringGrid1DrawCell
      end
    end
  end
end
