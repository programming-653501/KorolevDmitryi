
#include "Unit5.cpp"
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
extern struct VList* vlist;
extern struct Arh* arh;
extern struct CList* clist;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Form3->Show(); Form3->ComboBox1->ItemIndex=-1;
	Form3->ComboBox1->Text="Выберите соискателя";

	Form3->ComboBox1->Items->Clear();
	String Temp;
	struct CList* ctemp=clist;
	while(ctemp!=NULL){
		Temp=ctemp->cl->Name();
		Temp+=", ";
		Temp+=ctemp->cl->Contacts();
		Form3->ComboBox1->Items->Add(Temp);
		ctemp=ctemp->next;
	}
	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Form5->Show();  Form5->ComboBox1->ItemIndex=-1;
	Form5->ComboBox1->Text="Выберите вакансию";
	Form5->ComboBox1->Items->Clear();
	String Temp;
	struct VList* vtemp=vlist;
	while(vtemp!=NULL){
		Temp=vtemp->vac->Firm();
		Temp+=", ";
		Temp+=vtemp->vac->Job();
		Form5->ComboBox1->Items->Add(Temp);
		vtemp=vtemp->next;
	}
	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Form6->Show();
	Form6->ListBox1->Items->Clear();
	String Temp;
	struct VList* vtemp=vlist;
	while(vtemp!=NULL){
		Temp=vtemp->vac->Firm();
		Temp+=", ";
		Temp+=vtemp->vac->Job();
		Form6->ListBox1->Items->Add(Temp);
		vtemp=vtemp->next;
	}
	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Form7->Show();
	Form7->ListBox1->Items->Clear();
	String Temp;
	struct CList* vtemp=clist;
	while(vtemp!=NULL){
		Temp=vtemp->cl->Name();
		Temp+=", ";
		Temp+=vtemp->cl->Contacts();
		Form7->ListBox1->Items->Add(Temp);
		vtemp=vtemp->next;
	}
	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Form8->Show();
	Form8->ListBox1->Items->Clear();
	String Temp;
	struct CList* ctemp=clist;
	struct VList* vtemp=vlist;
	while(ctemp!=NULL){
		vtemp=vlist;
		while(vtemp!=NULL){
			if(Suits(ctemp,vtemp)){
				Temp=ctemp->cl->Name();
				Temp+="->";
				Temp+=vtemp->vac->Firm();
				Temp+=", ";
				Temp+=vtemp->vac->Job();
				Form8->ListBox1->Items->Add(Temp);
			}
			vtemp=vtemp->next;
		}
		ctemp=ctemp->next;
	}
	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Form9->Show();
	Form9->ListBox1->Items->Clear();
	String Temp;
	struct Arh* atemp=arh;
	while(atemp!=NULL){
		Temp=atemp->cl->cl->Name();
		Temp+="=>";
		Temp+=atemp->vl->vac->Firm();
		Temp+=", ";
		Temp+=atemp->vl->vac->Job();
		Form9->ListBox1->Items->Add(Temp);
		atemp=atemp->next;
	}
	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	if(!OpenDialog1->Execute()){
		return;
	}
	arh=NULL;vlist=NULL;clist=NULL;
	Memo1->Clear();
	Memo1->Lines->LoadFromFile(OpenDialog1->FileName);
	int v=Memo1->Lines->Strings[1].ToInt(), c=Memo1->Lines->Strings[2].ToInt(), a=Memo1->Lines->Strings[3].ToInt(),i=4;
	while(v>0){


		if(vlist==NULL){
		vlist=new struct VList();
		vlist->next=vlist->prev=NULL;
		vlist->vac=new Vacansy(Memo1->Lines->Strings[i],Memo1->Lines->Strings[i+1],Memo1->Lines->Strings[i+2],Memo1->Lines->Strings[i+3],
				Memo1->Lines->Strings[i+4].ToInt(),Memo1->Lines->Strings[i+5].ToInt(),Memo1->Lines->Strings[i+6].ToInt(),Memo1->Lines->Strings[i+7].ToInt(),Memo1->Lines->Strings[i+8].ToInt(),Memo1->Lines->Strings[i+9].ToInt());          i+=10;
	}else{
		struct VList* temp=new struct VList();
		temp->next=vlist;
		temp->prev=NULL;
		vlist->prev=temp;
		temp->vac=new Vacansy(Memo1->Lines->Strings[i],Memo1->Lines->Strings[i+1],Memo1->Lines->Strings[i+2],Memo1->Lines->Strings[i+3],
				Memo1->Lines->Strings[i+4].ToInt(),Memo1->Lines->Strings[i+5].ToInt(),Memo1->Lines->Strings[i+6].ToInt(),Memo1->Lines->Strings[i+7].ToInt(),Memo1->Lines->Strings[i+8].ToInt(),Memo1->Lines->Strings[i+9].ToInt());          i+=10;
		vlist=temp;
	}

	v--;
	}
	while(c>0){


	if(clist==NULL){
		clist=new struct CList();
		clist->next=clist->prev=NULL;
		clist->cl=new Client(Memo1->Lines->Strings[i],Memo1->Lines->Strings[i+1],Memo1->Lines->Strings[i+2],Memo1->Lines->Strings[i+3],
				Memo1->Lines->Strings[i+4].ToInt(),Memo1->Lines->Strings[i+5].ToInt(),Memo1->Lines->Strings[i+6].ToInt(),Memo1->Lines->Strings[i+7].ToInt(),Memo1->Lines->Strings[i+8].ToInt(),Memo1->Lines->Strings[i+9].ToInt());          i+=10;

	}else{
		struct CList* temp=new struct CList();
		temp->prev=NULL;
		temp->next=clist;
		clist->prev=temp;
		temp->cl=new Client(Memo1->Lines->Strings[i],Memo1->Lines->Strings[i+1],Memo1->Lines->Strings[i+2],Memo1->Lines->Strings[i+3],
				Memo1->Lines->Strings[i+4].ToInt(),Memo1->Lines->Strings[i+5].ToInt(),Memo1->Lines->Strings[i+6].ToInt(),Memo1->Lines->Strings[i+7].ToInt(),Memo1->Lines->Strings[i+8].ToInt(),Memo1->Lines->Strings[i+9].ToInt());          i+=10;
		clist=temp;
	}

	c--;
	}
	while(a>0){


	if(arh==NULL){
		arh=new struct Arh();
		arh->cl=new struct CList;
		arh->vl=new struct VList;
		arh->next=arh->prev=NULL;
		arh->cl->cl=new Client(Memo1->Lines->Strings[i],Memo1->Lines->Strings[i+1],Memo1->Lines->Strings[i+2],Memo1->Lines->Strings[i+3],
				Memo1->Lines->Strings[i+4].ToInt(),Memo1->Lines->Strings[i+5].ToInt(),Memo1->Lines->Strings[i+6].ToInt(),Memo1->Lines->Strings[i+7].ToInt(),Memo1->Lines->Strings[i+8].ToInt(),Memo1->Lines->Strings[i+9].ToInt());          i+=10;
		arh->vl->vac=new Vacansy(Memo1->Lines->Strings[i],Memo1->Lines->Strings[i+1],Memo1->Lines->Strings[i+2],Memo1->Lines->Strings[i+3],
				Memo1->Lines->Strings[i+4].ToInt(),Memo1->Lines->Strings[i+5].ToInt(),Memo1->Lines->Strings[i+6].ToInt(),Memo1->Lines->Strings[i+7].ToInt(),Memo1->Lines->Strings[i+8].ToInt(),Memo1->Lines->Strings[i+9].ToInt());          i+=10;

	}else{
		struct Arh* temp=new struct Arh();
		temp->prev=NULL;
		temp->cl=new struct CList;
		temp->vl=new struct VList;
		temp->next=arh;
		arh->prev=temp;
		temp->cl->cl=new Client(Memo1->Lines->Strings[i],Memo1->Lines->Strings[i+1],Memo1->Lines->Strings[i+2],Memo1->Lines->Strings[i+3],
				Memo1->Lines->Strings[i+4].ToInt(),Memo1->Lines->Strings[i+5].ToInt(),Memo1->Lines->Strings[i+6].ToInt(),Memo1->Lines->Strings[i+7].ToInt(),Memo1->Lines->Strings[i+8].ToInt(),Memo1->Lines->Strings[i+9].ToInt());          i+=10;
		temp->vl->vac=new Vacansy(Memo1->Lines->Strings[i],Memo1->Lines->Strings[i+1],Memo1->Lines->Strings[i+2],Memo1->Lines->Strings[i+3],
				Memo1->Lines->Strings[i+4].ToInt(),Memo1->Lines->Strings[i+5].ToInt(),Memo1->Lines->Strings[i+6].ToInt(),Memo1->Lines->Strings[i+7].ToInt(),Memo1->Lines->Strings[i+8].ToInt(),Memo1->Lines->Strings[i+9].ToInt());          i+=10;
		arh=temp;
	}

	a--;
	}
	return;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	if(!SaveDialog1->Execute()){
		return;
	}
	Memo1->Clear();
	int v,c,a,i=4;
	v=c=a=0;
	struct VList* vtemp=vlist;
	struct CList* ctemp=clist;
	struct Arh* atemp=arh;
	Memo1->Lines->Add("");
	Memo1->Lines->Add("");
	Memo1->Lines->Add("");
	Memo1->Lines->Add("");
	while(vtemp!=NULL){
		Memo1->Lines->Add(vtemp->vac->Job());
		Memo1->Lines->Add(vtemp->vac->Firm());
		Memo1->Lines->Add(vtemp->vac->City());
		Memo1->Lines->Add(vtemp->vac->Specialisation());
		Memo1->Lines->Add(IntToStr(vtemp->vac->Age()));
		Memo1->Lines->Add(IntToStr(vtemp->vac->Salary()));
		Memo1->Lines->Add(IntToStr(vtemp->vac->Sex()));
		Memo1->Lines->Add(IntToStr(vtemp->vac->Edu()));
		Memo1->Lines->Add(IntToStr(vtemp->vac->Busyness()));
		Memo1->Lines->Add(IntToStr(vtemp->vac->Family()));
		v++;
		vtemp=vtemp->next;
	}
	Memo1->Lines->Strings[1]=IntToStr(v);
	while(ctemp!=NULL){
		Memo1->Lines->Add(ctemp->cl->Name());
		Memo1->Lines->Add(ctemp->cl->Contacts());
		Memo1->Lines->Add(ctemp->cl->City());
		Memo1->Lines->Add(ctemp->cl->Specialisation());
		Memo1->Lines->Add(IntToStr(ctemp->cl->Age()));
		Memo1->Lines->Add(IntToStr(ctemp->cl->Salary()));
		Memo1->Lines->Add(IntToStr(ctemp->cl->Sex()));
		Memo1->Lines->Add(IntToStr(ctemp->cl->Edu()));
		Memo1->Lines->Add(IntToStr(ctemp->cl->Busyness()));
		Memo1->Lines->Add(IntToStr(ctemp->cl->Family()));
		c++;
		ctemp=ctemp->next;
	}
	Memo1->Lines->Strings[2]=IntToStr(c);
	while(atemp!=NULL){
		Memo1->Lines->Add(atemp->cl->cl->Name());
		Memo1->Lines->Add(atemp->cl->cl->Contacts());
		Memo1->Lines->Add(atemp->cl->cl->City());
		Memo1->Lines->Add(atemp->cl->cl->Specialisation());
		Memo1->Lines->Add(IntToStr(atemp->cl->cl->Age()));
		Memo1->Lines->Add(IntToStr(atemp->cl->cl->Salary()));
		Memo1->Lines->Add(IntToStr(atemp->cl->cl->Sex()));
		Memo1->Lines->Add(IntToStr(atemp->cl->cl->Edu()));
		Memo1->Lines->Add(IntToStr(atemp->cl->cl->Busyness()));
		Memo1->Lines->Add(IntToStr(atemp->cl->cl->Family()));

		Memo1->Lines->Add(atemp->vl->vac->Job());
		Memo1->Lines->Add(atemp->vl->vac->Firm());
		Memo1->Lines->Add(atemp->vl->vac->City());
		Memo1->Lines->Add(atemp->vl->vac->Specialisation());
		Memo1->Lines->Add(IntToStr(atemp->vl->vac->Age()));
		Memo1->Lines->Add(IntToStr(atemp->vl->vac->Salary()));
		Memo1->Lines->Add(IntToStr(atemp->vl->vac->Sex()));
		Memo1->Lines->Add(IntToStr(atemp->vl->vac->Edu()));
		Memo1->Lines->Add(IntToStr(atemp->vl->vac->Busyness()));
		Memo1->Lines->Add(IntToStr(atemp->vl->vac->Family()));
		a++;
		atemp=atemp->next;
	}
	Memo1->Lines->Strings[3]=IntToStr(a);
	Memo1->Lines->SaveToFile(SaveDialog1->FileName);
	return;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

