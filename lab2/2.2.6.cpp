//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <iostream>
#include <math.h>
#include <conio.h>

int main()
{
	int n,i;
	long double sum,e,r,x;
	std::cout<<"Type x (radians): ";
	std::cin>>x;
	if(x>2*M_PI){
			  x=x-floor(x/(2*M_PI))*2*M_PI;
			  std::cout<<"x = "<<x<<"\n";
			  }
	if(x<-2*M_PI){
			  x=-(abs(x)-floor(abs(x)/(2*M_PI))*2*M_PI);
			  std::cout<<"x = "<<x<<"\n";
			  }
	std::cout<<"Type e: ";
	std::cin>>e;
	std::cout<<sin(x)<<" = ";
	sum=r=x;
	n=1;
	i=-1;
	if(r<0){
			   std::cout<<"- ";
		   }
	std::cout<<abs(r)<<" ";
	while(abs(sum-sin(x))>=e){
		r=i*r*x*x/((n+1)*(n+2));
		n+=2;
		sum+=r;
		if(r<0){
			   std::cout<<"- ";
			   }
		else std::cout<<"+ ";
		std::cout<<abs(r)<<" ";
		}
	std::cout<<"...\nN = "<<(n+1)/2;
	getch();
	return 0;
}
//---------------------------------------------------------------------------
