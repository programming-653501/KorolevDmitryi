#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
using namespace std;
int main(){ char a[1000]; int k,i,j; int b[256][2];
for (i = 0; i < 256; i++) {b[i][0]=0; b[i][1]=0;}
cout<<"Vvedite stroku: "; gets(a); cout<<"Rezultat: ";
for (i = 0; i < strlen(a); i++) {b[int(a[i])][0]++;} k=1;j=1;
for (i = 1; i < 256; i++) {if((b[k][0]<b[i][0])&&(i!=32)) { j++; k=i;
b[i][1]=j;} else {if (b[k][0]==b[i][0]) b[i][1]=j;}}
for (i = 1; i < 256; i++) {if (b[i][1]==j) cout<<char(i)<<" ";}
getch();}
