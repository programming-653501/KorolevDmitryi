//---------------------------------------------------------------------------

#pragma hdrstop

#include <tchar.h>
//---------------------------------------------------------------------------
#include <iostream>
#include <math.h>
#include <conio.h>
#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	int m,i,j;
	std::cout<<"Type m(Natural number):";
	std::cin>>m;
	if(m<1){
	std::cout<<"Error.";
	getch();
	return 0;
	}
	i=1;
	while (m>=powl(2,i)-1){
		std::cout<<"N(10)="<<(powl(2,i)-1)<<",\tN(2)=";
		for (j=0; j < i; j++) {
			std::cout<<"1";
		}
		std::cout<<";\n";
		i++;
	}
	getch();
	return 0;
}
//---------------------------------------------------------------------------
