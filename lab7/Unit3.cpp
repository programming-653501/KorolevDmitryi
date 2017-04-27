#include "Unit4.cpp"
struct VList{struct VList* next; struct VList* prev; class Vacansy* vac;} extern *vlist;
struct Arh{struct VList* vl; struct CList* cl; struct Arh* next; struct Arh* prev;};
struct Arh *arh=NULL;
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
struct CList extern *clist;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}

void Delv(struct VList* v){
	if(v==vlist){
		vlist=vlist->next;
		if(vlist)vlist->prev=NULL;
		return;
	}
	if(v->next!=NULL){
		v->next->prev=v->prev;
	}
	v->prev->next=v->next;
	return;
}

void Delc(struct CList* v){
	if(v==clist){
		clist=clist->next;
		if(clist)clist->prev=NULL;
		return;
	}
	if(v->next!=NULL){
		v->next->prev=v->prev;
	}
	v->prev->next=v->next;
	return;
}

bool Suits(struct CList* cli, struct VList* vli){
	if((cli->cl->City()!=vli->vac->City())||(cli->cl->Age()>vli->vac->Age())||(cli->cl->Specialisation()!=vli->vac->Specialisation())||(cli->cl->Salary()>vli->vac->Salary())){
		return false;
	}
	if(vli->vac->Sex()!=a&&vli->vac->Sex()!=cli->cl->Sex()){
		return false;
	}
	if(cli->cl->Busyness()!=any&&cli->cl->Busyness()!=vli->vac->Busyness()){
		return false;
	}
	if(vli->vac->Family()!=nomatter&&vli->vac->Family()!=cli->cl->Family()){
		return false;
	}
	if(vli->vac->Edu()==high&&cli->cl->Edu()!=high){
		return false;
	}
	if(vli->vac->Edu()==spec&&!(cli->cl->Edu()==high||cli->cl->Edu()==spec)){
		return false;
	}
	if(vli->vac->Edu()==secon&&cli->cl->Edu()==non){
		return false;
	}
	return true;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
	int i=Form3->ComboBox1->ItemIndex;
	if(i==-1){
		ShowMessage("Выберите соискателя");
		return;
	}
	struct CList* ctemp=clist;
	struct VList* vtemp=vlist;
	while(i>0){
		ctemp=ctemp->next;
	}
	while(vtemp!=NULL){
		if(Suits(ctemp,vtemp)){
			String Temp=vtemp->vac->Firm();
			Temp+=", ";
			Temp+=vtemp->vac->Job();
			Form3->ListBox1->Items->Add(Temp);
		}
		vtemp=vtemp->next;
	}
	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
	int i=Form3->ComboBox1->ItemIndex;
	if(i==-1){
		ShowMessage("Выберите соискателя");
		return;
	}
	struct CList* ctemp=clist;
	struct VList* vtemp=vlist;
	while(i>0){
		ctemp=ctemp->next;
	}
	i=ListBox1->ItemIndex;
	if(i==-1){
		ShowMessage("Выберите вакансию");
		return;
	}
	while(i>0){
		if(Suits(ctemp,vtemp)){
			i--;
		}
		vtemp=vtemp->next;
	}
	while(!Suits(ctemp,vtemp)){
		vtemp=vtemp->next;
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

void __fastcall TForm3::Button3Click(TObject *Sender)
{
	Form3->ListBox1->ItemIndex=-1;
	ListBox1->Items->Clear();
	Form3->Close();
}
//---------------------------------------------------------------------------

