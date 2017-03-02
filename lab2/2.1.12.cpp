//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
#include <math.h>
#include <iostream>
#include <conio.h>

bool check(double* s){
	if(s[0]==0||s[1]==0||s[2]==0){
	std::cout<<"Error.";
	return 0;
	}
	return 1;
}
void fill(float* x, float* y, float* z, double* s){
	std::cout<<"Type x1,y1,z1:";
	std::cin>>x[0]>>y[0]>>z[0];
	std::cout<<"Type x2,y2,z2:";
	std::cin>>x[1]>>y[1]>>z[1];
	std::cout<<"Type x3,y3,z3:";
	std::cin>>x[2]>>y[2]>>z[2];
	s[0]=sqrt(pow(x[0]-x[1],2)+pow(y[0]-y[1],2)+pow(z[0]-z[1],2));
	s[1]=sqrt(pow(x[0]-x[2],2)+pow(y[0]-y[2],2)+pow(z[0]-z[2],2));
	s[2]=sqrt(pow(x[2]-x[1],2)+pow(y[2]-y[1],2)+pow(z[2]-z[1],2));
}

void info(){
	std::cout<<"\"Everything u wanted to know about triangles\". v 1.0.5 by Korolev Dima";
	return;
}

void type(double s[3]){
	std::cout<<"Your triangle is ";
	if(s[0]==s[1]&&s[1]==s[2]){
	std::cout<<"equilateral";
	return;
	}
	if(floor((s[0]*s[0]+s[1]*s[1])*1000+0.5)==floor(s[2]*s[2]*1000+0.5)){
	std::cout<<"rectangular ";
	}
	if(floor((s[2]*s[2]+s[1]*s[1])*1000+0.5)==floor(s[0]*s[0]*1000+0.5)){
	std::cout<<"rectangular ";
	}
	if(floor((s[2]*s[2]+s[0]*s[0])*1000+0.5)==floor(s[1]*s[1]*1000+0.5)){
	std::cout<<"rectangular ";
	}
	if(s[0]==s[1]||s[0]==s[2]||s[1]==s[2]){
	std::cout<<"isosceles";
	return;
	}
	std::cout<<"of an arbitrary type";
	return;
}

double perimeter(double s[3]){
	return s[0]+s[1]+s[2];
}

double square(double s[3]){
	double p=perimeter(s)/2;
	return (sqrt(p*(p-s[0])*(p-s[1])*(p-s[2])));
}

void circles(double s[3]){
	double sq=square(s), p=perimeter(s)/2;
	std::cout<<"Radius of incircle is "<<sq/p;
	std::cout<<"\nRadius of circumcircle is "<<s[0]*s[1]*s[2]/(4*sq);
	return;
}

int main()
{   float x[3],y[3],z[3];
	double s[3];
	int n;
	s[0]=s[1]=s[2]=0;
	for(;;){
	std::cout<<"Type:\n1 to enter the coordinats;\n2 to get the type of your triangle;\n3 to get the perimeter;\n4 to get square;\n5 to get the radiuses;\n6 for info;\n7 to exit:  ";
	std::cin>>n;
	switch (n) {
	case 1:{fill(x,y,z,s);
			break;
		   }
	case 2:if(check(s)){
		   type(s);
		   }
		   break;
	case 4:if(check(s)){
		   std::cout<<"Square of your triangle is "<<square(s);
		   }
		   break;
	case 3:if(check(s)){
		   std::cout<<"Perimeter of your triangle is "<<perimeter(s);
		   }
		   break;
	case 5:if(check(s)){
		   circles(s);
		   }
		   break;
	case 6:info();
		   break;
	case 7:return 0;
	default:std::cout<<"Error.";
	}
	getch();
	clrscr();
	}
}
