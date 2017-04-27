//---------------------------------------------------------------------------
 #include "Client.cpp"
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
struct CList{struct CList* next; struct CList* prev; class Client* cl;} *clist=NULL;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
	Form4->RadioGroup2->ItemIndex=2;
	Form4->RadioGroup1->ItemIndex=-1;
	Form4->RadioGroup3->ItemIndex=-1;
	Form4->RadioGroup4->ItemIndex=-1;
	Form4->Edit1->Text="���";
	Form4->Edit2->Text="�����";
	Form4->Edit3->Text="�������������";
	Form4->Edit4->Text="��������";
	Form4->Edit5->Text="�������";
	Form4->Edit6->Text="��������";
	Form4->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
	if(Form4->RadioGroup1->ItemIndex==-1){
		ShowMessage("������� ���");
		return;
	}
	if(Form4->RadioGroup3->ItemIndex==-1){
		ShowMessage("������� �����������");
		return;
	}
	if(Form4->RadioGroup4->ItemIndex==-1){
		ShowMessage("������� �������� ���������");
		return;
	}
	if(!ChkInt(Form4->Edit5->Text)){
		ShowMessage("����� ������������ �������. ���������� ������� ����� �����");
		return;
	}
	if(!ChkInt(Form4->Edit6->Text)){
		ShowMessage("������� ������������ ��������. ���������� ������� ����� �����");
		return;
	}
	if(Form4->Edit5->Text.ToInt()<16){
		ShowMessage("������� �������. �� ���");
		return;
	}
	if(clist==NULL){
		clist=new struct CList();
		clist->next=clist->prev=NULL;
		clist->cl=new Client(Form4->Edit1->Text,Form4->Edit4->Text,Form4->Edit2->Text,Form4->Edit3->Text,
						Form4->Edit5->Text.ToInt(),Form4->Edit6->Text.ToInt(),Form4->RadioGroup1->ItemIndex,Form4->RadioGroup3->ItemIndex,Form4->RadioGroup2->ItemIndex,Form4->RadioGroup4->ItemIndex);

	}else{
		struct CList* temp=new struct CList();
		temp->prev=NULL;
		temp->next=clist;
		clist->prev=temp;
		temp->cl=new Client(Form4->Edit1->Text,Form4->Edit4->Text,Form4->Edit2->Text,Form4->Edit3->Text,
						Form4->Edit5->Text.ToInt(),Form4->Edit6->Text.ToInt(),Form4->RadioGroup1->ItemIndex,Form4->RadioGroup3->ItemIndex,Form4->RadioGroup2->ItemIndex,Form4->RadioGroup4->ItemIndex);
		clist=temp;
	}
	Button1Click(Sender);
	return;
}
//---------------------------------------------------------------------------
