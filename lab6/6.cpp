#include <fstream>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <malloc.h>
#include "Unit1.cpp"

struct Tree{char* word; struct Tree* left; struct Tree* right;};

struct Tree* add(struct Tree* head, char* s){
	if(head==NULL){
		head=(struct Tree*)malloc(sizeof(struct Tree));
		head->right=NULL;
		head->left=NULL;
		head->word=(char*)malloc(strlen(s)+1);
		strcpy(head->word,s);
	}else{
		if(compare(s,head->word)==1){
			head->right=add(head->right,s);
		}
		if(compare(s,head->word)==-1){
			head->left=add(head->left,s);
		}
	}
	return head;
}

void generate(struct Tree* head){
	if(head->left!=NULL){
		generate(head->left);
	}
	ofstream out;
	out.open("OUTPUT.txt", ios::app);
	out.write(head->word,strlen(head->word));
	out.put(' ');
	out.close();
	if(head->right!=NULL){
		generate(head->right);
	}
	return;
}

void deleting(struct Tree* head){
	if(head->left!=NULL){
		deleting(head->left);
	}
	if(head->right!=NULL){
		deleting(head->right);
	}
	free(head);
	return;
}

struct Tree* work(char* s, struct Tree* head){
	char buf[100];
	int l=0,i=0;
	while(i<=strlen(s)){
		if((s[i]>-65&&s[i]<0)||(s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)){
			buf[l++]=toupper(s[i]);
		}else{
			buf[l]='\0';
			l=0;
			if (nice(buf)) {
				head=add(head,buf);
			}
		}
		i++;
	}
	return head;
};

int _tmain(int argc, _TCHAR* argv[])
{
   //	freopen("prn", "w", stdout);
	char s[1001];
	ofstream out;
	ifstream in("6.txt");
	SetConsoleOutputCP(1251);
	if(!in.good()){
		std::cout<<"Создайте файл \"6.txt\"";
		getch();
		return 1;
	}
	struct Tree* head=NULL;
	do{
		in.getline(s,1000);
		head=work(s,head);
	}while(s[0]!='\0');
	std::cout<<"Результат в файле \"OUTPUT.TXT\".";
	out.open("OUTPUT.TXT",ios::trunc);
	out.close();
	if(head!=NULL){
		generate(head);
		deleting(head);
	}
   /*	std::cout<<"\nРаспечатать(y/n)?:\n";
	std::cin>>s[0];
	if(toupper(s[0])=='Y'){
			system("print OUTPUT.txt");
	}else{
		std::cout<<"Как хотите";
    }    */
	getch();
	in.close();
	return 0;
}
