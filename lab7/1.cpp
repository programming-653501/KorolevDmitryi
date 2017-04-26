#include <iostream>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdio.h>
using namespace std;
int main(){ char a[1000]; int k,i,j;
 cout<<"Vvedite stroku: "; gets(a); cout<<"Vvedite k: "; cin>>k;
for (i=k; i>-1; i--) if(a[i]==' ')
{for(j=0;j<i;j++) cout<<a[j]; cout<<endl; for(j=i+1;j<strlen(a);j++) cout<<a[j];break;}
getch();}
