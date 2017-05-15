#include "AllPositions.h"

void Exclude ( struct AllPositions * out ) {
	int am = out -> amount;
	if ( am < 2 ) {
		return;
	}
	int newam = 1;
	for ( int i = 1; i < am; i++ ) {
		bool t = true;
		for ( int j = newam - 1; j >= 0; j-- ) {
			if ( out -> distance[i] == out -> distance[j] ) {
				if ( out -> c[i] == out -> c[j] ) {
					if ( out -> c[i] == 'h' ) {
						if ( out -> x[i] - out -> n[i] == out -> x[j] - out -> n[j] && out -> y[i] == out -> y[j] ) {
							t = false;
							break;
						}
					} else {
						if ( out -> x[i] == out -> x[j] && out -> y[i] + out -> n[i] == out -> y[j] + out -> n[j] ) {
							t = false;
							break;
						}
					}
				}
			}
		}
		if ( t ) {
			out -> x[newam] = out -> x[i];
			out -> y[newam] = out -> y[i];
			out -> n[newam] = out -> n[i];
			out -> c[newam] = out -> c[i];
			out -> distance[newam++] = out -> distance[i];
		}

	}
	out -> amount = newam;
	return;
}

void SetSize ( struct AllPositions * out ) {
		int newsize = out -> amount;
		out -> x = ( int * ) realloc ( out -> x, sizeof ( int ) * newsize );
		out -> y = ( int * ) realloc ( out -> y, sizeof ( int ) * newsize );
		out -> n = ( int * ) realloc ( out -> n, sizeof ( int ) * newsize );
		out -> c = ( char * ) realloc ( out -> c, sizeof ( char ) * newsize );
		out -> distance = ( double * ) realloc ( out -> distance, sizeof ( double ) * newsize );
		return;
}

struct AllPositions * CreateAP ( ) {
	struct AllPositions * out;
	out = ( struct AllPositions * ) malloc ( sizeof ( struct AllPositions ) );
	out -> x = ( int * ) malloc ( sizeof ( int ) * STARTALLPOS );
	out -> amount = 0;
	out -> y = ( int * ) malloc ( sizeof ( int ) * STARTALLPOS );
	out -> n = ( int * ) malloc ( sizeof ( int ) * STARTALLPOS );
	out -> c = ( char * ) malloc ( sizeof ( char ) * STARTALLPOS );
	out -> distance = ( double * ) malloc ( sizeof ( double ) * STARTALLPOS );
	return out;
}

int ReallocateAP ( struct AllPositions * out ) {
	int news = NEWSIZEOFARR;
	out -> x = ( int * ) realloc ( out -> x, sizeof ( int ) * news );
	out -> y = ( int * ) realloc ( out -> y, sizeof ( int ) * news );
	out -> n = ( int * ) realloc ( out -> n, sizeof ( int ) * news );
	out -> c = ( char * ) realloc ( out -> c, sizeof ( char ) * news );
	out -> distance = ( double * ) realloc ( out -> distance, sizeof ( double ) * news );
	return news;
}

bool IsInt ( String s ){
	for (int i = 1; i <= s.Length(); i++) {
		if ( s[i] > '9' || s[i] < '0' ){
			return false;
		}
	}
	return true;
}

void QSort ( struct AllPositions * arr, int beg, int end ) {
		if ( !arr -> amount ) {
			return;
		}
		double x = arr -> distance[beg + ( end - beg ) / 2], temp;
		int i = beg, j = end;
		while ( i <= j ) {
			while ( arr -> distance[i] < x ) {
				i++;
			}
			while ( arr -> distance[j] > x ) {
				j--;
			}
			if ( i <= j ) {
				temp = arr -> x[i];
				arr -> x[i] = arr -> x[j];
				arr -> x[j] = temp;
				temp = arr -> n[i];
				arr -> n[i] = arr -> n[j];
				arr -> n[j] = temp;
				temp = arr -> y[i];
				arr -> y[i] = arr -> y[j];
				arr -> y[j] = temp;
				temp = arr -> distance[i];
				arr -> distance[i] = arr -> distance[j];
				arr -> distance[j] = temp;
				temp = arr -> c[i];
				arr -> c[i++] = arr -> c[j];
				arr -> c[j--] = temp;
			}
		}
		if ( i < end ) {
			QSort ( arr, i, end );
		}
		if ( j > beg ) {
			QSort ( arr, beg, j );
		}
}