#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(){ char a[1000]; char b[100]; char c[100];cout<<"Vvedite stroku: "; gets(a);
int m,i,j,k=0; m=0; for (i = 0; i < 100; i++) { b[i]=0; c[i]=0;}
for (i = 0; a[i] != '\0'; i++) if ((a[i]>=49)&&(a[i]<=57))
if(i>0){ if(!((a[i-1]>=48)&&(a[i-1]<=57))) if (i>1){
if(!(((a[i-1]=='.')||(a[i-1]=='.'))&&(a[i-2]>=48)&&(a[i-2]<=57))) { lm:
for (j = i; ((a[j]>=48)&&(a[j]<=57)); j++)
{b[j-i]=a[j];} if(j-i>m) {m=j-i; for (k=0;k<m;k++)c[k]=b[k];}
else if(j-i==m) for (int n=0; n<m;n++) if(b[n]>c[n]){for (k=0;k<m;k++)c[k]=b[k];} i=j; }} else goto lm;} else goto lm;
cout<<"Rezultat: "<<c;
getch();}
