#ifndef AllPositionsH
#define AllPositionsH AllPositions

#include "Libs.h"

struct AllPositions {
	int * x, * y, * n, amount;
	char * c;
	double * distance;
	~AllPositions ( ) {
		delete x;
		delete y;
		delete c;
		delete distance;
	}
};

void Exclude ( struct AllPositions * out );

void SetSize ( struct AllPositions * out );

struct AllPositions * CreateAP ( );

int ReallocateAP ( struct AllPositions * out );

bool IsInt ( String s );

void QSort ( struct AllPositions * arr, int beg, int end );

#endif
