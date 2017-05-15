//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
wchar_t ** words;
int amount;
class DynArr * arr;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GenerateClick(TObject *Sender)
{
	if ( WordLabel -> Visible == false) {
		WordLabel -> Visible = true;
		WordAmount -> Visible = true;
		Generate -> Caption = "��";
		OpenForm2 -> Visible = false;
		FileButton -> Visible = false;
		StopBut -> Visible = true;
		return;
	} else {
		if ( WordAmount -> Visible == true ) {
			if ( IsInt ( WordAmount -> Text ) ) {
				WordLabel -> Caption = "��������� ������� ������� � �������� ������ ����������";
				WordAmount -> Visible = false;
				int am = WordAmount -> Text.ToInt ( );
				Words -> RowCount = am;
				Words -> Visible = true;
				Words -> Height = ( am > 10 ) ? 280 : ( am * 27 );
				Words -> Width = ( am > 10 ) ? 321 : ( 304 );
			} else {
				ShowMessage ( "������� ����������� ����� ����" );
				return;
            }
		} else {
			if ( words ) {
				delete words;
				words = NULL;
			}
			if ( arr ) {
				delete arr;
				arr = NULL;
			}
			amount = WordAmount -> Text.ToInt ( );
			words = new wchar_t * [amount];
			for ( int i = 0; i < amount; i++) {
				words[i] = new wchar_t [Words -> Cells[0][i].Length ( ) + 1 ];
				wcscpy( words[i], Words -> Cells[0][i].w_str ( ) );
			}
			arr = new DynArr ( );
			if ( !arr -> GenerateFirst ( words, amount, CWSize -> ItemIndex - 1 ) ) {
				ShowMessage ( "�� ������� ������������� ���������" );
				delete arr;
				arr = NULL;
			} else {
				ShowMessage ( "�������" );
            }
			WordLabel -> Visible = false;
			Words -> Visible = false;
			Generate -> Caption = "������������� ���������";
			OpenForm2 -> Visible = true;
			WordAmount -> Visible = false;
			StopBut -> Visible = false;
			FileButton -> Visible = true;
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OpenForm2Click(TObject *Sender)
{
	if ( !arr ) {
		ShowMessage ( "���� ������ �������������" );
		return;
	}
	Form2 -> Showcw -> Height = Form2 -> Height - 55;
	Form2 -> Showcw -> Width = Form2 -> Width - 15;
	int cols, rows;
	wchar_t ** grid;
	grid = arr -> Show ( rows, cols );     
	Form2 -> Showcw -> ColCount = cols;
	Form2 -> Showcw -> FixedCols = 0;
	Form2 -> Showcw -> RowCount = rows;
	Form2 -> Showcw -> FixedRows = 0;
	Form2 -> Showcw -> Visible = false;
	for ( int i = 0; i < rows; i++) {
		for ( int j = 0; j < cols; j++) {
			Form2 -> Showcw -> Cells[j][rows - i - 1] = grid[i][j];
		}
		delete grid[i];
	}
	Form2 -> Showcw -> Visible = true;
	Form2 -> Show ( );
	delete grid;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileButtonClick(TObject *Sender)
{
	if ( Generate -> Visible == true ) {
		Generate -> Visible = false;
		StopBut -> Visible = true;
		OpenForm2 -> Visible = false;  
		OpenDialog1 -> Execute ( );
		FileButton -> Caption = "OK";
	} else {
		if ( OpenDialog1 -> FileName.Length ( ) ) {
			Memof -> Lines -> LoadFromFile ( OpenDialog1 -> FileName );
			if ( words ) {
				delete words;
				words = NULL;
			}
			if ( arr ) {
				delete arr;
				arr = NULL;
			}
			amount = Memof -> Lines -> Count;  
			words = new wchar_t * [amount];    
			for ( int i = 0; i < amount; i++) {    
				words[i] = new wchar_t [Memof -> Lines -> operator[] ( i ).Length ( ) + 1];
				wcscpy( words[i], Memof -> Lines -> operator[] ( i ).w_str ( ) );
			}
			arr = new DynArr ( );  
			if ( !arr -> GenerateFirst ( words, amount, CWSize -> ItemIndex - 1 ) ) {
				ShowMessage ( "�� ������� ������������� ���������" );
				delete arr;
				arr = NULL;
			} else {
                ShowMessage ( "�������" );
            }
		}   	
		Generate -> Visible = true;
		OpenForm2 -> Visible = true;
		StopBut -> Visible = false;
		FileButton -> Caption = "������� ����� �� �����";
		}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ExitButClick(TObject *Sender)
{
	Close ( );	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StopButClick(TObject *Sender)
{
	Generate -> Visible = true;
	OpenForm2 -> Visible = true;
	FileButton -> Caption = "������� ����� �� �����";
	WordLabel -> Visible = false;
	Words -> Visible = false;
	Generate -> Caption = "������������� ���������";
	OpenForm2 -> Visible = true;
	FileButton -> Visible = true;
	WordAmount -> Visible = false;
	StopBut -> Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete arr;
}
//---------------------------------------------------------------------------
