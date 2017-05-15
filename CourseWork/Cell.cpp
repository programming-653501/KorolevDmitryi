#include "Cell.h"

	void Cell :: YH ( ) {
		if ( canv != 3 ) {
			symbol = '\0';
		}
		if ( canh == 3 ) {
			canh = 0;
		} else {
			canh--;
		}
	}

	void Cell :: YV ( ) {
		if ( canh != 3 ) {
			symbol = '\0';
		}
		if ( canv == 3 ) {
			canv = 0;
		} else {
			canv--;
		}
	}

	void Cell :: SetSV ( wchar_t s ) {
		symbol = s;
		canv = 3;
	}

	void Cell :: SetSH ( wchar_t s ) {
		symbol = s;
		canh = 3;
	}

	bool Cell :: CanH ( ) {
	if ( ( !canh ) && ( !cansmf ) ) {
		return true;
	}
		return false;
	}

	bool Cell :: CanV ( ) {
	if ( ( !canv ) && ( !cansmf ) ) {
		return true;
	}
		return false;
	}
	void Cell :: Cellinit ( ) {
		canv = canh = cansmf = 0;
		symbol = '\0';
	}
