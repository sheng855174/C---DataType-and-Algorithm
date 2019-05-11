object Form1: TForm1
  Left = 201
  Top = 117
  Width = 928
  Height = 493
  Caption = '04360092_'#36039#24037#20108#20057'_'#38515#26119#26119
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
    Top = 217
    Width = 920
    Height = 8
    Cursor = crVSplit
    Align = alTop
  end
  object Label7: TLabel
    Left = 96
    Top = 8
    Width = 32
    Height = 13
    Caption = 'Label7'
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 920
    Height = 217
    ActivePage = TabSheet1
    Align = alTop
    TabIndex = 0
    TabOrder = 0
    OnChange = PageControl1Change
    object TabSheet1: TTabSheet
      Caption = #38617#21521#20018#21015
      object Label1: TLabel
        Left = 8
        Top = 112
        Width = 74
        Height = 13
        Caption = 'Search Number'
      end
      object Label2: TLabel
        Left = 16
        Top = 16
        Width = 66
        Height = 13
        Caption = 'Insert Number'
      end
      object Label3: TLabel
        Left = 400
        Top = 16
        Width = 81
        Height = 13
        Caption = 'Randdom Range'
      end
      object Label4: TLabel
        Left = 400
        Top = 48
        Width = 80
        Height = 13
        Caption = 'Random Number'
      end
      object Edit1: TEdit
        Left = 96
        Top = 16
        Width = 49
        Height = 21
        TabOrder = 0
        Text = '100'
      end
      object Button1: TButton
        Left = 168
        Top = 8
        Width = 105
        Height = 33
        Caption = 'InsertFirst'
        TabOrder = 1
        OnClick = Button1Click
      end
      object Button2: TButton
        Left = 280
        Top = 8
        Width = 97
        Height = 33
        Caption = 'InsertLast'
        TabOrder = 2
        OnClick = Button2Click
      end
      object Edit2: TEdit
        Left = 96
        Top = 112
        Width = 49
        Height = 21
        TabOrder = 3
        Text = '99'
      end
      object Button3: TButton
        Left = 168
        Top = 104
        Width = 105
        Height = 33
        Caption = 'Search'
        TabOrder = 4
        OnClick = Button3Click
      end
      object Edit3: TEdit
        Left = 488
        Top = 16
        Width = 49
        Height = 21
        TabOrder = 5
        Text = '100'
      end
      object Button4: TButton
        Left = 552
        Top = 16
        Width = 153
        Height = 49
        Caption = 'Random InsertFirst'
        TabOrder = 6
        OnClick = Button4Click
      end
      object Edit4: TEdit
        Left = 488
        Top = 48
        Width = 49
        Height = 21
        TabOrder = 7
        Text = '10'
      end
      object Button5: TButton
        Left = 168
        Top = 48
        Width = 105
        Height = 33
        Caption = 'DeleteFirst'
        TabOrder = 8
        OnClick = Button5Click
      end
      object Button6: TButton
        Left = 280
        Top = 48
        Width = 97
        Height = 33
        Caption = 'DeleteLast'
        TabOrder = 9
        OnClick = Button6Click
      end
      object Button7: TButton
        Left = 280
        Top = 104
        Width = 105
        Height = 33
        Caption = 'InsertAfter Search'
        TabOrder = 10
        OnClick = Button7Click
      end
      object Button8: TButton
        Left = 392
        Top = 104
        Width = 105
        Height = 33
        Caption = 'InsertBefore Search'
        TabOrder = 11
        OnClick = Button8Click
      end
      object Button9: TButton
        Left = 512
        Top = 104
        Width = 105
        Height = 33
        Caption = 'Delete Search'
        TabOrder = 12
        OnClick = Button9Click
      end
      object Button10: TButton
        Left = 736
        Top = 128
        Width = 97
        Height = 41
        Caption = 'All Delete'
        Font.Charset = ANSI_CHARSET
        Font.Color = clRed
        Font.Height = -13
        Font.Name = #24494#36575#27491#40657#39636
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 13
        OnClick = Button10Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #21934#21521#20018#21015
      ImageIndex = 1
      object Label5: TLabel
        Left = 8
        Top = 24
        Width = 66
        Height = 13
        Caption = 'Insert Number'
      end
      object Label6: TLabel
        Left = 8
        Top = 136
        Width = 74
        Height = 13
        Caption = 'Search Number'
      end
      object Edit5: TEdit
        Left = 80
        Top = 24
        Width = 49
        Height = 21
        TabOrder = 0
        Text = '10'
      end
      object Button11: TButton
        Left = 160
        Top = 16
        Width = 97
        Height = 33
        Caption = 'InsertFirst'
        TabOrder = 1
        OnClick = Button11Click
      end
      object Button12: TButton
        Left = 280
        Top = 16
        Width = 97
        Height = 33
        Caption = 'InsertLast'
        TabOrder = 2
        OnClick = Button12Click
      end
      object Button13: TButton
        Left = 160
        Top = 72
        Width = 97
        Height = 33
        Caption = 'DeleteFirst'
        TabOrder = 3
        OnClick = Button13Click
      end
      object Button14: TButton
        Left = 160
        Top = 128
        Width = 97
        Height = 33
        Caption = 'Search'
        TabOrder = 4
        OnClick = Button14Click
      end
      object Button15: TButton
        Left = 760
        Top = 128
        Width = 113
        Height = 49
        Caption = 'Delete All'
        TabOrder = 5
        OnClick = Button15Click
      end
      object Edit6: TEdit
        Left = 88
        Top = 136
        Width = 49
        Height = 21
        TabOrder = 6
        Text = '50'
      end
      object Button16: TButton
        Left = 280
        Top = 128
        Width = 97
        Height = 33
        Caption = 'Search InsertLast'
        TabOrder = 7
        OnClick = Button16Click
      end
    end
    object TabSheet3: TTabSheet
      Caption = #22534#30090#20018#21015
      ImageIndex = 2
      object Label8: TLabel
        Left = 8
        Top = 24
        Width = 66
        Height = 13
        Caption = 'Insert Number'
      end
      object Edit7: TEdit
        Left = 80
        Top = 24
        Width = 49
        Height = 21
        TabOrder = 0
        Text = '10'
      end
      object Button17: TButton
        Left = 152
        Top = 24
        Width = 89
        Height = 41
        Caption = 'push'
        TabOrder = 1
        OnClick = Button17Click
      end
      object Button18: TButton
        Left = 272
        Top = 24
        Width = 89
        Height = 41
        Caption = 'pop'
        TabOrder = 2
        OnClick = Button18Click
      end
    end
  end
  object PageControl2: TPageControl
    Left = 0
    Top = 225
    Width = 920
    Height = 237
    ActivePage = TabSheet4
    Align = alClient
    TabIndex = 0
    TabOrder = 1
    object TabSheet4: TTabSheet
      Caption = 'TabSheet4'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 912
        Height = 209
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlue
        Font.Height = -16
        Font.Name = 'Consolas'
        Font.Style = []
        Lines.Strings = (
          'Memo1')
        ParentFont = False
        TabOrder = 0
      end
    end
    object TabSheet5: TTabSheet
      Caption = 'TabSheet5'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 912
        Height = 209
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlue
        Font.Height = -16
        Font.Name = 'Consolas'
        Font.Style = []
        Lines.Strings = (
          'Memo2')
        ParentFont = False
        TabOrder = 0
      end
    end
    object TabSheet6: TTabSheet
      Caption = 'TabSheet6'
      ImageIndex = 2
      object Memo3: TMemo
        Left = 0
        Top = 0
        Width = 912
        Height = 209
        Align = alClient
        Font.Charset = ANSI_CHARSET
        Font.Color = clBlue
        Font.Height = -16
        Font.Name = 'Consolas'
        Font.Style = []
        Lines.Strings = (
          'Memo3')
        ParentFont = False
        TabOrder = 0
      end
    end
  end
end
