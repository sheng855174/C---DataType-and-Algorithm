object Form1: TForm1
  Left = 312
  Top = 115
  Width = 1044
  Height = 615
  Caption = '04360092_'#38515#26119#26119'_HW5'
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
    Left = 313
    Top = 0
    Width = 7
    Height = 584
    Cursor = crHSplit
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 313
    Height = 584
    Align = alLeft
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 8
      Width = 91
      Height = 28
      Caption = 'G=(V,E)'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -24
      Font.Name = 'Consolas'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 24
      Top = 48
      Width = 40
      Height = 22
      Caption = '|V|='
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 24
      Top = 88
      Width = 120
      Height = 22
      Caption = 'range(w(e))='
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 24
      Top = 120
      Width = 90
      Height = 22
      Caption = 'if(w(e))>'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 24
      Top = 152
      Width = 220
      Height = 22
      Caption = 'w(e)=MaxInt(         )'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 24
      Top = 192
      Width = 80
      Height = 22
      Caption = 'source ='
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 72
      Top = 48
      Width = 73
      Height = 30
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '4'
    end
    object Edit2: TEdit
      Left = 152
      Top = 88
      Width = 73
      Height = 30
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = '20'
    end
    object Edit3: TEdit
      Left = 120
      Top = 120
      Width = 73
      Height = 30
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Text = '20'
    end
    object Edit4: TEdit
      Left = 152
      Top = 152
      Width = 73
      Height = 30
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      Text = '99999'
    end
    object Button1: TButton
      Left = 40
      Top = 240
      Width = 169
      Height = 41
      Caption = 'Generate G'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = Button1Click
    end
    object CheckBox1: TCheckBox
      Left = 32
      Top = 296
      Width = 145
      Height = 25
      Caption = #21360#20986#30697#38499
      Checked = True
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Consolas'
      Font.Style = [fsBold]
      ParentFont = False
      State = cbChecked
      TabOrder = 5
    end
    object RadioButton1: TRadioButton
      Left = 176
      Top = 48
      Width = 97
      Height = 25
      Caption = #26377#21521#22294
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object RadioButton2: TRadioButton
      Left = 176
      Top = 16
      Width = 97
      Height = 25
      Caption = #28961#21521#22294
      Checked = True
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      TabStop = True
    end
    object Button2: TButton
      Left = 40
      Top = 336
      Width = 169
      Height = 41
      Caption = 'Source'#21040#20854#20182#40670
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = Button2Click
    end
    object Edit5: TEdit
      Left = 112
      Top = 192
      Width = 73
      Height = 30
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      Text = '0'
    end
    object Button3: TButton
      Left = 40
      Top = 392
      Width = 169
      Height = 41
      Caption = #25152#26377#26368#30701#36317#38626
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = Button3Click
    end
    object CheckBox2: TCheckBox
      Left = 144
      Top = 296
      Width = 145
      Height = 25
      Caption = #21360#20986#32080#26524
      Checked = True
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Consolas'
      Font.Style = [fsBold]
      ParentFont = False
      State = cbChecked
      TabOrder = 11
    end
    object Button4: TButton
      Left = 40
      Top = 448
      Width = 169
      Height = 41
      Caption = #36958#31227#23553#38281
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Consolas'
      Font.Style = []
      ParentFont = False
      TabOrder = 12
      OnClick = Button4Click
    end
  end
  object PageControl1: TPageControl
    Left = 320
    Top = 0
    Width = 716
    Height = 584
    ActivePage = TabSheet3
    Align = alClient
    TabIndex = 2
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = #26368#30701#36335#24465
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 708
        Height = 556
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlue
        Font.Height = -16
        Font.Name = 'Consolas'
        Font.Style = []
        Lines.Strings = (
          'Memo1')
        ParentFont = False
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'V*V'#21021#22987#30697#38499
      ImageIndex = 1
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 708
        Height = 556
        Align = alClient
        Color = clInfoBk
        DefaultColWidth = 50
        DefaultRowHeight = 50
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
    object TabSheet3: TTabSheet
      Caption = #36958#31227#23553#38281
      ImageIndex = 2
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 708
        Height = 556
        Align = alClient
        Color = clInfoBk
        DefaultColWidth = 50
        DefaultRowHeight = 50
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
        OnDrawCell = StringGrid2DrawCell
      end
    end
  end
end