//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <iostream.h>
#include <windows.h>
#include <winspool.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent *Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void AddPrintDemo()
{
  PRINTER_INFO_2W printerInfo = {0};
  printerInfo.pPortName = L"FILE:";
  printerInfo.pDriverName = L"Microsoft Print To PDF";
  printerInfo.pPrinterName = L"PrintDemon";
  printerInfo.pPrintProcessor = L"WinPrint";
  printerInfo.pDatatype = L"RAW";
  HANDLE hPrinter = AddPrinterW(NULL, 2, (LPBYTE)&printerInfo);

  SetDefaultPrinter("PrintDemon");
}
//---------------------------------------------------------------------------
AnsiString GetPrinters()
{
  DWORD dwFlags = PRINTER_ENUM_FAVORITE | PRINTER_ENUM_LOCAL;
  LPPRINTER_INFO_2 pPrinters;
  DWORD cbPrinters;
  DWORD cReturned, i;
  char buf[100];

  EnumPrinters(dwFlags, NULL, 2, NULL, 0, &cbPrinters, &cReturned);
  pPrinters = (LPPRINTER_INFO_2) LocalAlloc(LPTR, cbPrinters + 4);

  EnumPrinters(dwFlags, NULL, 2, (LPBYTE)pPrinters,
              cbPrinters, &cbPrinters, &cReturned);

  AnsiString str;
  if (cReturned > 0)
   for (i = 0; i < cReturned; i++)
   {
     str = str + "Printer: " +(pPrinters + i)->pPrinterName;
     str = str + ", Port: " + (pPrinters + i)->pPortName;
     str = str + ", Driver: " + (pPrinters + i)->pDriverName;
     str = str + "\r\n";
   }

 LocalFree(LocalHandle(pPrinters));
 return str;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  AnsiString str = GetPrinters();
  Memo1->Lines->Add(str);

  AddPrintDemo();
}

