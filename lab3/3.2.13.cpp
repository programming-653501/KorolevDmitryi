#include <iostream>
#include <conio.h>
using namespace std;

int Min(int a, int b){
	if (a>b) {
		return b;
	}
	else {
		return a;
	}
}

void Bubble(int i, int m, int j, int n,double** arr){
	double temp;
	int ii=i,jj=j;
	for (int l = 0; l < Min(abs(ii-n),abs(jj-m))-1; l++) {
	i=ii;
	j=jj;
		while ((i<n-1-l)&&(j<m-1-l)){
			if (arr[i][j]>arr[i+1][j+1]) {
				temp=arr[i][j];
				arr[i][j]=arr[i+1][j+1];
				arr[i+1][j+1]=temp;
			}
			i++;
			j++;
		}
	}
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,m,min,k,l;
	int i,j;
	double** arr;
	cout<<"Enter the number of rows: ";
	cin>>n;
	cout<<"Enter the number of columns: ";
	cin>>m;
	arr = new double* [n];
	cout<<"Enter the elements:\n";
	for (j = 0; j < n; j++) {
		arr[j]=new double [m];
		for (i = 0; i < m; i++) {
			cin>>arr[j][i];
		}
	}
	for (k = 0; k < n; k++) {
		Bubble(k,m,0,n,arr);
		}
	for (k = 1; k < m; k++) {
		Bubble(0,m,k,n,arr);
	}
	cout<<"Result:";
	for (i = 0; i < n; i++) {
		cout<<"\n";
		for (j = 0; j < m; j++) {
			cout<<arr[i][j]<<"\t";
		}
		delete arr[i];
	}
	delete arr;
	getch();
	return 0;
}
