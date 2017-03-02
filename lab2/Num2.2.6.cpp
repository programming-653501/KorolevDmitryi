//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <iostream>
#include <math.h>
#include <conio.h>
#include <time.h>

void final(long double sum, long double e, long double r, int n,long double x){
	if(r<0){
		std::cout<<"+ ";
	}
	else{
		std::cout<<"- ";
	}
	std::cout<<"...";
	if(abs(sum-sin(x))<e){
		std::cout<<" = "<<sum<<"\nN = "<<(n+1)/2;
	}
	else{
		std::cout<<"\nNumber series does not converge.";
	}
	return;
}

void cycle(long double x, long double e){
	long double sum,r;
	int n;
	sum=r=x;
	n=1;
	if(r<0){
			   std::cout<<"- ";
		   }
	std::cout<<abs(r)<<" ";
	while(abs(r)>=e){
		r=(-1)*r*x*x/((n+1)*(n+2));
		n+=2;
		sum+=r;
		if(r<0){
			   std::cout<<"- ";
			   }
		else std::cout<<"+ ";
		std::cout<<abs(r)<<" ";
		}
	final(sum,e,r,n,x);
	return;
}

void recursion(long double x, long double e,long double sum, long double r,int i){
	if(r<0){
			   std::cout<<"- ";
		   }
	std::cout<<abs(r)<<" ";
	if (abs(r)>=e) {
		if(r<0){
			   std::cout<<"+ ";
		}
		recursion(x,e,sum+(-1)*r*x*x/((i+1)*(i+2)),(-1)*r*x*x/((i+1)*(i+2)),i+2);
	}
	else {
	   final(sum,e,r,i,x);
	}
	return;
}

int main()
{
	long double e,x;
	clock_t time1,time2;
	std::cout<<"Type x (radians): ";
	std::cin>>x;
	std::cout<<"Type e: ";
	std::cin>>e;
	std::cout<<"sin(x) = "<<sin(x);
	std::cout<<"\nUsing cycle algorithm:\n";
	time1=clock();
	cycle(x,e);
	time2=clock();
	std::cout<<"\nElapsed time = "<<(time2-time1)/CLOCKS_PER_SEC<<"\n\nRecurrent algorithm:\n";
	time1=clock();
	recursion(x,e,x,x,1);
	time2=clock();
	std::cout<<"\nElapsed time = "<<(time2-time1)/CLOCKS_PER_SEC;
	getch();
}
