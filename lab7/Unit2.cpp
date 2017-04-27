//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

struct VList{struct VList* next; struct VList* prev; class Vacansy* vac;} *vlist=NULL;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	Form2->Edit1->Text="�����";
	Form2->Edit2->Text="�����";
	Form2->Edit3->Text="���������";
	Form2->Edit4->Text="�������������";
	Form2->Edit5->Text="�������";
	Form2->Edit6->Text="��������";
	Form2->RadioGroup1->ItemIndex=3;
	Form2->RadioGroup2->ItemIndex=2;
	Form2->RadioGroup3->ItemIndex=-1;
	Form2->RadioGroup4->ItemIndex=3;
	Form2->Close();
}

bool ChkInt(String S){
	for(int i=1; i<=S.Length(); i++){
		if(S[i]<'0'||S[i]>'9'){
			return false;
		}
	}
	return true;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	if(Form2->RadioGroup3->ItemIndex==-1){
		ShowMessage("������� ���������");
		return;
	}
	if(!ChkInt(Form2->Edit5->Text)){
		ShowMessage("����� ������������ �������. ���������� ������� ����� �����");
		return;
	}
	if(!ChkInt(Form2->Edit6->Text)){
		ShowMessage("������� ������������ ��������. ���������� ������� ����� �����");
		return;
	}
	if(vlist==NULL){
		vlist=new struct VList();
		vlist->next=vlist->prev=NULL;
		vlist->vac=new Vacansy(Edit3->Text,Edit1->Text,Edit2->Text,Edit4->Text,Edit5->Text.ToInt(),Edit6->Text.ToInt(),
								RadioGroup2->ItemIndex, RadioGroup1->ItemIndex,RadioGroup3->ItemIndex,RadioGroup4->ItemIndex);
	}else{
		struct VList* temp=new struct VList();
		temp->next=vlist;
		temp->prev=NULL;
		vlist->prev=temp;
		temp->vac=new Vacansy(Edit3->Text,Edit1->Text,Edit2->Text,Edit4->Text,Edit5->Text.ToInt(),Edit6->Text.ToInt(),
								RadioGroup2->ItemIndex, RadioGroup1->ItemIndex,RadioGroup3->ItemIndex,RadioGroup4->ItemIndex);
		vlist=temp;
	}
	Button2Click(Sender);
	return;
}
//---------------------------------------------------------------------------