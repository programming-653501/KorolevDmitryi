/*struct VList{struct VList* next; struct VList* prev; class Vacansy* vac;} extern *vlist;
struct Arh{struct VList* vl; struct CList* cl; struct Arh* next; struct Arh* prev;}
extern *arh;
void Delv(struct VList* v);
void Delc(struct CList* v);
bool Suits(struct CList* cli, struct VList* vli);
struct CList{struct CList* next; struct CList* prev; class Client* cl;} extern *clist;   */

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit3.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
struct CList extern *clist;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
	int i=Form5->ComboBox1->ItemIndex;
	if(i==-1){
		ShowMessage("Выберите вакансию");
		return;
	}
	struct CList* ctemp=clist;
	struct VList* vtemp=vlist;
	while(i>0){
		vtemp=vtemp->next;
	}
	while(ctemp!=NULL){
		if(Suits(ctemp,vtemp)){
			String Temp=ctemp->cl->Name();
			Temp+=", ";
			Temp+=ctemp->cl->Contacts();
			Form5->ListBox1->Items->Add(Temp);
		}
		ctemp=ctemp->next;
	}
	return;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button2Click(TObject *Sender)
{
	int i=Form5->ComboBox1->ItemIndex;
	if(i==-1){
		ShowMessage("Выберите вакансию");
		return;
	}
	struct CList* ctemp=clist;
	struct VList* vtemp=vlist;
	while(i>0){
		vtemp=vtemp->next;
	}
	i=ListBox1->ItemIndex;
	if(i==-1){
		ShowMessage("Выберите соискателя");
		return;
	}
	while(i>0){
		if(Suits(ctemp,vtemp)){
			i--;
		}
		ctemp=ctemp->next;
	}
	while(!Suits(ctemp,vtemp)){
		ctemp=ctemp->next;
	}

	if(arh==NULL){
		arh=new struct Arh();
		arh->next=arh->prev=NULL;
		arh->cl=ctemp;
		arh->vl=vtemp;
		Delv(vtemp);
		Delc(ctemp);
	}else{
		Arh* tempo=new struct Arh();
		tempo->prev=NULL;
		tempo->next=arh;
		arh->prev=tempo;
		arh=tempo;
		arh->cl=ctemp;
		arh->vl=vtemp;
		Delv(vtemp);
		Delc(ctemp);
	}
	Button3Click(Sender);
	return;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button3Click(TObject *Sender)
{
	Form5->ListBox1->ItemIndex=-1;
	ListBox1->Items->Clear();
	Form5->Close();
}
//---------------------------------------------------------------------------
