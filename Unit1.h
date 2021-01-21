//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
bool InstallDriver(const char *pPrinterUNC);
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TPrinterSetupDialog *PrinterSetupDialog1;
  TPrintDialog *PrintDialog1;
  TMemo *Memo1;
  TButton *Button1;
  void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm1(TComponent* Owner);
  void MyAddPrinter();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
