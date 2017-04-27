//---------------------------------------------------------------------------
struct CList{struct CList* next; struct CList* prev; class Client* cl;} extern *clist;
#include <vcl.h>
#pragma hdrstop

#include "Unit7.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
void Delc(struct CList* delv);
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
	int i=Form7->ListBox1->ItemIndex;
	if(i==-1){
		ShowMessage("Выберите соискателя");
		return;
	}
	struct CList* vtemp=clist;
	while(i>0){
		vtemp=vtemp->next;
	}
	Delc(vtemp);
	Button2Click(Sender);
	return;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button2Click(TObject *Sender)
{
	Form7->ListBox1->ItemIndex=-1;
	Form7->Close();
}
//---------------------------------------------------------------------------
