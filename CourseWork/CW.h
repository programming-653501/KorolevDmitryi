#ifndef CWH
#define CWH CW

#include "Libs.h"

struct CROSSWORD {
	int x, y;
	wchar_t * word;
	char horver;
	~CROSSWORD ( ) {
		delete word;
	}
};

class CW {
	private :

	struct CROSSWORD * crossword;
	int words_now, words_max;
	double Xcent, Ycent;

	public :

	CW ( );

	~CW ( ) {
		delete crossword;
	}

	int GetWordsNow ( ) {
		return words_now;
	}

	struct CROSSWORD * GetCrs ( ) {
		return crossword;
	}

	void DeleteWord ( );

	void AddWord ( int X, int Y, wchar_t * w, char c );

	double Distance ( double X, double Y );

	void GetCoordinates ( int & xl, int & yl, int & xr, int & yr);
};

#endif
