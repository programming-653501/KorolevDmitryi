#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

void out(const char c[10]){
	for (int i=0; c[i] != '\0'; i++) {
		std::cout<<c[i];
	}
	return;
}

bool check(int a){
	if (a<0||a>1001) {
		std::cout<<"\n���-�� ����� �� ���.";
		getch();
		return true;
	}
	return false;
}

void delo(int k, const int c){
	if (check(k)) return ;
	const char num[10][6]={"","��","��","��","�����","���","����","���","���","�����"};
	const char sot1[7][5]={"","���","���","���","���","���","���"};
	const char devian[7][10]={"","���������","���������","���������","���������","���������","���������"};
	const char sor[7][7]={"","�����","������","�����","������","������","������"};
	const char sot2[7][6]={"","���","���","���","����","�����","����"};
	const char desp[7][9]={"","�����","�����","�����","�����","������","�����"};
	const char pad[7][10][5]={
	"","��","�","�","�","�","�","�","���","�",
	"","����","��","��","��","�","�","�","���","�",
	"","��","�","�","�","�","�","�","���","�",
	"","����","��","��","��","�","�","�","���","�",
	"","���","���","���","���","��","��","��","����","��",
	"","���","��","��","��","�","�","�","���","�"};
	const char tis[10][20]={"","���� ������","����� ������","���� ������","����� ������","����� �������","����� ������"};
	if (k==1000) {
		std::cout<<tis[c];
		return;
	}
	if(k==100){
		std::cout<<sot1[c];
		return;
	}
	if(k/100==1) {
		out(sot1[c]);
	}
	else{
		if(k/100==2&&((c==1)||(c==3))) {
			out("������");
		}else{
			if(k/100>1){
				out(num[k/100]);
				out(pad[c-1][k/100]);
				if((c==1||c==3)&&k/100<4){
					out("���");
				}else{
					out(sot2[c]);
				}
			}
		}
	}
	if(((k/10)%10>0)&&(k/100>1)){
		out(" ");
	}
	k=k%100;
	if (k==10) {
		out("�����");
		out(pad[c-1][9]);
		return;
	}
	if (k<20&&k>10) {
		out(num[k%10]);
		if (k%10==8) {
			out("��");
		}
		out("��");
		out(desp[c]);
		return;
	}else{
		if (k>=20&&k<40) {
			out(num[k/10]);
			out(pad[0][k/10]);
			out(desp[c]);
		}
		if (k>=40&&k<50) {
			out(sor[c]);
		}
		if (k>49&&k<90) {
			out(num[k/10]);
			out(pad[c-1][k/10]);
			out("�����");
			if(c!=1&&c!=3){
				out(pad[c-1][9]);
			}
		}
		if (k>89) {
			out(devian[c]);
		}
	}
	k=k%10;
	if(k==0){
	return;
	}else{
		out(" ");
	}
	out(num[k]);
	out(pad[c-1][k]);
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char s[30];
	int k=0,i;
	std::cout<<"������� �����(�������), � ����� ������(��� ���������) ����� ������(������):\n";
	gets(s);
	for (i = 0; s[i]!='\0'; i++) {
		if(s[i]>=48&&s[i]<=57) {
			k=k*10+(s[i]-48);
		}
		else {
			switch(s[i]) {
			case '�': delo(k,1); std::cout<<"\n"; break;
			case '�': delo(k,2); std::cout<<"\n"; break;
			case '�': delo(k,3); std::cout<<"\n"; break;
			case '�': delo(k,4); std::cout<<"\n"; break;
			case '�': delo(k,5); std::cout<<"\n"; break;
			case '�': delo(k,6); std::cout<<"\n"; break;
			case '�': delo(k,1); std::cout<<"\n"; break;
			case '�': delo(k,2); std::cout<<"\n"; break;
			case '�': delo(k,3); std::cout<<"\n"; break;
			case '�': delo(k,4); std::cout<<"\n"; break;
			case '�': delo(k,5); std::cout<<"\n"; break;
			case '�': delo(k,6); std::cout<<"\n"; break;
			default: continue;
			}
		}
	}
	getch();
	return 0;
}
