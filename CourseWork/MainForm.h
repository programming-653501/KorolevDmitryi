//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH MainForm
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "DynArr.h"
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include "CWShow.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Generate;
	TEdit *WordAmount;
	TLabel *WordLabel;
	TStringGrid *Words;
	TRadioGroup *CWSize;
	TButton *OpenForm2;
	TButton *FileButton;
	TOpenDialog *OpenDialog1;
	TMemo *Memof;
	TButton *ExitBut;
	TButton *StopBut;
	void __fastcall GenerateClick(TObject *Sender);
	void __fastcall OpenForm2Click(TObject *Sender);
	void __fastcall FileButtonClick(TObject *Sender);
	void __fastcall ExitButClick(TObject *Sender);
	void __fastcall StopButClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
