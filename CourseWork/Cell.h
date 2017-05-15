#ifndef CellH
#define CellH Cell

class Cell {
	private :

	wchar_t symbol;
	unsigned canh : 2;
	unsigned canv : 2;
	signed cansmf : 4;

	public :

	void clear ( ) {
		cansmf--;
	}

	void Nothing ( ) {
		cansmf++;
	}

	void YH ( );

	void YV ( );

	void NoH ( ) {
		canh++;
	}

	void NoV ( ) {
		canv++;
	}

	void SetSV ( wchar_t s );

	void SetSH ( wchar_t s );

	wchar_t GetS ( ) {
		return symbol;
	}

	bool CanH ( );

	bool CanV ( );

	void Cellinit ( );
};

#endif
