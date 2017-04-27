//---------------------------------------------------------------------------
struct VList{struct VList* next; struct VList* prev; class Vacansy* vac;} extern *vlist;
#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}

void Delv(struct VList* v);

//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
	int i=Form6->ListBox1->ItemIndex;
	if(i==-1){
		ShowMessage("Выберите вакансию");
		return;
	}
	struct VList* vtemp=vlist;
	while(i>0){
		vtemp=vtemp->next;
	}
	Delv(vtemp);
	Button2Click(Sender);
	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
	Form6->ListBox1->ItemIndex=-1;
	Form6->Close();
}
//---------------------------------------------------------------------------

