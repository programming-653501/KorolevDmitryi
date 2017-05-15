#include "CW.h"
	CW :: CW ( ) {
		crossword = ( struct CROSSWORD * ) malloc ( sizeof ( struct CROSSWORD ) * 4 );
		words_max = 4;
		words_now = 0;
		Xcent = Ycent = 0;
		return;
	}

	void CW :: DeleteWord ( ) {
		words_now--;
		Xcent = ( Xcent * ( words_now + 1 ) - ( crossword[words_now].x ) ) / words_now;
		Ycent = ( Ycent * ( words_now + 1 ) - ( crossword[words_now].y ) ) / words_now;
	}

	void CW :: AddWord ( int X, int Y, wchar_t * w, char c ) {
		if ( words_now == words_max ) {
			crossword = ( struct CROSSWORD * ) realloc ( crossword, sizeof ( struct CROSSWORD ) * NEWWORDSMAX );
			words_max = NEWWORDSMAX;
		}
		crossword[words_now].x = X;
		crossword[words_now].horver = c;
		crossword[words_now].y = Y;
		crossword[words_now].word = w;
		Xcent = ( Xcent * words_now + X ) / ( words_now + 1 );
		Ycent = ( Ycent * words_now + Y ) / ( words_now + 1 );
		words_now++;
		return;
	}

	double CW :: Distance ( double X, double Y ) {
		return pow ( ( ( Xcent - X ) * ( Xcent - X ) + ( Ycent - Y ) * ( Ycent - Y ) ) , 0.5 );
	}

	void CW :: GetCoordinates ( int & xl, int & yl, int & xr, int & yr ) {
		xl = crossword[0].x;
		yl = crossword[0].y;
		xr = xl + wcslen( crossword[0].word ) - 1;
		yr = yl;
		for (int i = 1; i < words_now; i++) {
			struct CROSSWORD c = crossword[i];
			if ( crossword[i].horver == 'h' ) {
				if ( xl > c.x ) xl = c.x;
				if ( yl < c.y ) yl = c.y;
				if ( yr > c.y ) yr = c.y;
				int let = c.x + wcslen ( c.word ) - 1;
				if ( xr < let ) xr = let;
			} else {
				if ( xl > c.x ) xl = c.x;
				if ( yl < c.y ) yl = c.y;
				if ( xr < c.x ) xr = c.x;
				int let = c.y - wcslen ( c.word ) + 1;
				if ( yr > let ) yr = let;
			}
		}
		return;
	}

