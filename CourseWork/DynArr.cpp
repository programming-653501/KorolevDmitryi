#include "DynArr.h"

	bool DynArr :: Chosen :: can ( int k ) {
		if ( r & ( 1 << k ) ) {
			return false;
		}
			return true;
	}

	void DynArr :: Chosen :: toone ( int k ) {
		r += ( 1 << k );
		return;
	}

	void DynArr :: Chosen :: tonul ( int k ) {
		r -= ( 1 << k );
		return;
	}

	int DynArr :: Max ( int a, int b ) {
		if ( abs ( a ) > abs ( b ) ) {
			return abs ( a );
		} else {
			return abs ( b );
		}
	}

	void DynArr :: Reallocate ( ) {
		for ( int k = 0; k < 4; k++ ) {
			q[k] = ( class Cell ** ) realloc ( q[k], sizeof ( class Cell * ) * NEWSIZE );
			for ( int i = 0; i < size; i++ ) {
				q[k][i] = ( class Cell * ) realloc ( q[k][i], sizeof ( class Cell ) * NEWSIZE );
				for ( int j = size; j < NEWSIZE; j++ ) {
					q[k][i][j].Cellinit ( );
				}
			}
			for ( int i = size; i < NEWSIZE; i++ ) {
				q[k][i] = ( class Cell * ) malloc ( sizeof ( class Cell ) * NEWSIZE );
				for ( int j = 0; j < NEWSIZE; j++ ) {
					q[k][i][j].Cellinit ( );
				}
			}
		}
		size = NEWSIZE;
	}

	DynArr :: DynArr ( ) {
		size = 4;
		q = ( class Cell *** ) malloc ( sizeof ( class Cell ** ) * 4 );
		for ( int k = 0; k < 4; k++ ) {
			q[k] = ( class Cell ** ) malloc ( sizeof ( class Cell * ) * size );
			for ( int i = 0; i < size; i++ ) {
				q[k][i] = ( class Cell * ) malloc ( sizeof ( class Cell ) * size );
				for ( int j = 0; j < size; j++ ) {
					q[k][i][j].Cellinit ( );
				}
			}
		}
		ChosenWords = NULL;
		crossw = new CW ( );
		return;
	}

	DynArr :: ~DynArr ( ) {
		for ( int i = 0; i < 4; i++ ) {
			for ( int j = 0; j < size; j++ ) {
				free ( q[i][j] );
			}
			free ( q[i] );
		}
		free ( q );
		delete ChosenWords;
		delete crossw;
		return;
	}

	class Cell * DynArr :: cell ( int a, int b ) {
		while ( Max ( a, b ) >= size ) {
			Reallocate ( );
		}
		int index;
		if ( a >= 0 ) {
			if ( b >= 0 ) {
				return &q[0][a][b];
			} else {
				return &q[3][a][ - ( b + 1 ) ];
			}
		} else {
			if ( b >= 0 ) {
				return &q[1][ - ( a + 1 ) ][b];
			} else {
				return &q[2][ - ( a + 1 ) ][ - ( b + 1 ) ];
			}
		}
	}

	void DynArr :: Erase ( int a, int b, wchar_t * w, char c, int n ) { // whereX, whereY, word, h if horizontal, beging symbol
		class Cell * cl;
		int len = wcslen ( w );
		crossw -> DeleteWord ( );
		if ( c == 'h' ) {
			cell ( a - 1 - n, b ) -> clear ( );
			cell ( a + len - n, b ) -> clear ( );
			for ( int i = a - n; i < a + len - n; i++ ) {
				cell ( i, b - 1 ) -> YH ( );
				cell ( i, b ) -> YH ( );
				cell ( i, b + 1 ) -> YH ( );
			}
		} else {
			cell ( a, b + 1 + n ) -> clear ( );
			cell ( a, b - len + n ) -> clear ( );
			for ( int i = b + n; i > b - len + n; i-- ) {
				cell ( a - 1, i ) -> YV ( );
				cell ( a, i ) -> YV ( );
				cell ( a + 1, i ) -> YV ( );
			}
		}
		return;
	}

	void DynArr :: PosWord ( int a, int b, wchar_t * w, char c, int n ) { // whereX, whereY, word, h if horizontal, begining symbol
		class Cell * cl;
		int len = wcslen ( w );
		crossw -> AddWord ( a - ( ( c == 'h' ) ? n : 0 ) , b + ( ( c == 'v' ) ? n : 0 ) , w, c );
		if ( c == 'h' ) {
			for ( int i = a - n; i < a + len - n; i++ ) {
				cell ( i, b - 1 ) -> NoH ( );
				cl = cell ( i, b );
				cl -> SetSH ( w[i - a + n] );
				cell ( i, b + 1 ) -> NoH ( );
			}
			cell ( a - 1 - n, b ) -> Nothing ( );
			cell ( a + len - n, b ) -> Nothing ( );
		} else {
			for ( int i = b + n; i > b - len + n; i-- ) {
				cell ( a - 1, i ) -> NoV ( );
				cl = cell ( a, i );
				cl -> SetSV ( w[b - i + n] );
				cell ( a + 1, i ) -> NoV ( );
			}
			cell ( a, b + 1 + n ) -> Nothing ( );
			cell ( a, b - len + n ) -> Nothing ( );
		}
		return;
	}

	bool DynArr :: CanPos ( int a, int b, wchar_t * w, char c, int n ) { // whereX, whereY, word, h if horizontal, nomer vstavliaemogo simvola
		class Cell * cl;
		int len = wcslen ( w );
		if ( c == 'h' ) {
			for ( int i = a - n; i < a - n + len; i++ ) {
				cl = cell ( i, b );
				if ( ! ( cl -> CanH ( ) && ( cl -> GetS ( ) == '\0' || cl -> GetS ( ) == w[i - a + n] ) ) ) {
					return false;
				}
			}
			if ( cell ( a - n - 1, b ) -> GetS ( ) != '\0' || cell ( a - n + len, b ) -> GetS ( ) != '\0' ) {
				return false;
			}
			return true;
		} else {
			for ( int i = b + n; i > b + n - len; i-- ) {
				cl = cell ( a, i );
				if ( ! ( cl -> CanV ( ) && ( cl -> GetS ( ) == '\0' || cl -> GetS ( ) == w[b + n - i] ) ) ) {
					return false;
				}
			}
			if ( cell ( a, b + n + 1 ) -> GetS ( ) != '\0' || cell ( a, b + n - len ) -> GetS ( ) != '\0' ) {
				return false;
			}
			return true;
		}
		return false;
	}

	struct AllPositions * DynArr :: FindAllPositions ( wchar_t * w, bool param ) { // word, posedwords, amount of posed words, sort or no
		struct AllPositions * out;
		struct CROSSWORD * cw = crossw -> GetCrs ( );
		int num = crossw -> GetWordsNow ( );
		out = CreateAP ( );
		int sizeofarr = STARTALLPOS, len = wcslen ( w );
		for ( int i = 0; i < len; i++ ) {
			for ( int j = 0; j < num; j++ ) {
				for ( int k = 0; k < wcslen ( cw[j].word ); k++ ) {
					if ( cw[j].word[k] == w[i] ) {
						char c;
						if ( cw[j].horver == 'h' ) {
							c = 'v';
						} else {
							c = 'h';
						}
						if ( CanPos ( ( ( c == 'h' ) ? cw[j].x : cw[j].x + k ) , ( ( c == 'h' ) ? cw[j].y - k : cw[j].y ) , w, c, i ) ) {

							if ( out -> amount == sizeofarr ) {
								sizeofarr = ReallocateAP ( out );
							}
							int a = out -> amount;
							out -> x[a] = cw[j].x + k * ( ( c == 'v' ) ? 1 : 0 );
							out -> y[a] = cw[j].y - k * ( ( c == 'v' ) ? 0 : 1 );
							out -> n[a] = i;
							out -> distance[a] = crossw -> Distance ( ( ( c == 'v' ) ? out -> x[a] : ( out -> x[a] - i ) ) , ( ( c == 'v' ) ? ( out -> y[a] + i ) : ( out -> x[a] - i ) ) );
							out -> c[ ( out -> amount ) ++] = c;
						}

					}
				}
			}
		}
		SetSize ( out );
		if ( param ) {
			QSort ( out, 0, out -> amount - 1 );
		}
		Exclude ( out );
		SetSize ( out );
		return out;
	}

	bool DynArr :: AddOneMoreWord ( wchar_t * word, int param ) {
		struct AllPositions * pos = FindAllPositions ( word, ( param == 0 ) ? false : true );
		maxnum++;
		if ( pos -> amount ) {
			if ( param >= 0 ) {
				PosWord ( pos -> x[0], pos -> y[0], word, pos -> c[0], pos -> n[0] );
			} else {
				int ammo = pos -> amount - 1;
				PosWord ( pos -> x[ammo], pos -> y[ammo], word, pos -> c[ammo], pos -> n[ammo] );
			}
			return true;
		}
		return false;
	}

	bool DynArr :: GenerateFirst ( wchar_t ** Arrs, int Maxnum, int Param ) {
		param = Param;
		maxnum = Maxnum;
		arrs = Arrs;
		if ( ChosenWords ) {
			delete ChosenWords;
		}
		ChosenWords = new Chosen[ ( maxnum / 8 + ( ( maxnum % 8 ) ? 1 : 0 ) ) ];
		int minus = 0;
		for ( int i = 0; i < maxnum; i++) {
			if ( wcslen ( arrs[i] ) ) {
				PosWord ( 0, 0, arrs[i], 'h', 0 );
				ChosenWords[i / 8].toone ( i % 8 );
				break;
			}
		}
		for ( int i = 0; i < maxnum; i++) {
			if ( !wcslen ( arrs[i] ) ) {
				ChosenWords[i / 8].toone ( i % 8 );
				minus++;
			}
		}
		if( maxnum == 1 + minus ){
			return true;
		}
		return Generate ( minus + 1 );
	}

	bool DynArr :: Generate ( int curr ) {
		struct AllPositions * pos;
		for ( int j = 0; j < maxnum; j++ ) {
			if ( ChosenWords[j / 8].can ( j % 8 ) ) {
				pos = FindAllPositions ( arrs[j], ( param == 0 ) ? false : true );
				if ( pos -> amount == 0 ) {
					continue;
				}
				if ( ( curr == maxnum - 1 ) && ( param >= 0 ) ) {
					PosWord ( pos -> x[0], pos -> y[0], arrs[j], pos -> c[0], pos -> n[0] );
					return true;
				}
				if ( curr == maxnum - 1 && param < 0 ) {
					int ammo = pos -> amount - 1;
					PosWord ( pos -> x[ammo], pos -> y[ammo], arrs[j], pos -> c[ammo], pos -> n[ammo] );
					return true;
				}
				ChosenWords[j / 8].toone ( j % 8 );
				 if ( param >= 0 ) {
					for ( int i = 0; i < pos -> amount; i++ ) {
						PosWord ( pos -> x[i], pos -> y[i], arrs[j], pos -> c[i], pos -> n[i] );
						if ( Generate ( curr + 1 ) ) {
							return true;
						}
						Erase ( pos -> x[i], pos -> y[i], arrs[j], pos -> c[i], pos -> n[i] );
					}
					ChosenWords[j / 8].tonul ( j % 8 );
				} else {
					for ( int i = pos -> amount - 1; i >= 0; i-- ) {
						PosWord ( pos -> x[i], pos -> y[i], arrs[j], pos -> c[i], pos -> n[i] );
						if ( Generate ( curr + 1 ) ) {
							return true;
						}
						Erase ( pos -> x[i], pos -> y[i], arrs[j], pos -> c[i], pos -> n[i] );
					}
					ChosenWords[j / 8].tonul ( j % 8 );
				}
			}
		}
		return false;
	}

	wchar_t ** DynArr :: Show ( int & rows, int & cols ) {
		int xr, xl, yr, yl;
		crossw -> GetCoordinates ( xl, yl, xr, yr );
		cols = xr - xl + 1;
		rows = yl - yr + 1;
		wchar_t ** out = new wchar_t * [rows];
		for ( int i = yr; i <= yl; i++ ) {
			out[i - yr] = new wchar_t [cols];
			for ( int j = xl; j <= xr; j++ ) {
				out[i - yr][j - xl] = cell( j , i ) -> GetS ( );
            }
		}
		return out;
	}

