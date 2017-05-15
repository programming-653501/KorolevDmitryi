object Form1: TForm1
  Left = 0
  Top = 0
  Caption = #1043#1077#1085#1077#1088#1072#1090#1086#1088' '#1082#1088#1086#1089#1089#1074#1086#1088#1076#1086#1074
  ClientHeight = 296
  ClientWidth = 726
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object WordLabel: TLabel
    Left = 347
    Top = 168
    Width = 131
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1083#1086#1074
    Visible = False
  end
  object Generate: TButton
    Left = 539
    Top = 8
    Width = 179
    Height = 25
    Caption = #1057#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100' '#1082#1088#1086#1089#1089#1074#1086#1088#1076
    TabOrder = 0
    OnClick = GenerateClick
  end
  object WordAmount: TEdit
    Left = 347
    Top = 187
    Width = 131
    Height = 21
    TabOrder = 1
    Visible = False
  end
  object Words: TStringGrid
    Left = 8
    Top = 8
    Width = 321
    Height = 240
    ColCount = 1
    DefaultColWidth = 300
    FixedCols = 0
    RowCount = 11
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 2
    Visible = False
  end
  object CWSize: TRadioGroup
    Left = 347
    Top = 8
    Width = 185
    Height = 105
    Caption = #1056#1072#1089#1087#1086#1083#1072#1075#1072#1090#1100' '#1089#1083#1086#1074#1072
    ItemIndex = 1
    Items.Strings = (
      #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086' '#1086#1090#1076#1072#1083#1105#1085#1085#1086
      #1057#1083#1091#1095#1072#1081#1085#1099#1084' '#1086#1073#1088#1072#1079#1086#1084
      #1052#1072#1082#1089#1080#1084#1072#1083#1100#1085#1086' '#1087#1083#1086#1090#1085#1086)
    TabOrder = 3
  end
  object OpenForm2: TButton
    Left = 539
    Top = 70
    Width = 179
    Height = 25
    Caption = #1055#1088#1086#1089#1084#1086#1090#1088#1077#1090#1100' '#1082#1088#1086#1089#1089#1074#1086#1088#1076
    TabOrder = 4
    OnClick = OpenForm2Click
  end
  object FileButton: TButton
    Left = 539
    Top = 39
    Width = 179
    Height = 25
    Caption = #1057#1095#1080#1090#1072#1090#1100' '#1089#1083#1086#1074#1072' '#1080#1079' '#1092#1072#1081#1083#1072
    TabOrder = 5
    OnClick = FileButtonClick
  end
  object Memof: TMemo
    Left = 96
    Top = 88
    Width = 185
    Height = 89
    Lines.Strings = (
      'Memof')
    TabOrder = 6
    Visible = False
  end
  object ExitBut: TButton
    Left = 539
    Top = 263
    Width = 179
    Height = 25
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 7
    OnClick = ExitButClick
  end
  object StopBut: TButton
    Left = 539
    Top = 101
    Width = 179
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 8
    Visible = False
    OnClick = StopButClick
  end
  object OpenDialog1: TOpenDialog
    Filter = '*.txt|*.txt'
    InitialDir = '0'
    Left = 416
    Top = 64
  end
end
