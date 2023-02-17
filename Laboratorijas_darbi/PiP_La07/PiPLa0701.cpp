//PiPLa0701.cpp
/******************************************************************************************************
PiPLa0701. Sastâdît C++ programmu, kas ïauj iegût ziòas par dotu preses izdevumu.
Preses izdevuma nosaukums jâòem no standartieejas plûsmas.
Jâizmanto fails ar ziòâm par preses izdevumiem.
Ziòas par preses izdevumiem ir ierakstîtas secîgi binârâ komponenðu failâ (prese.bin).
Faila ieraksta saturs: nosaukums, izdevuma veids (laikraksts, þurnâls, nedçïraksts),
iznâkðanas reiþu skaits mçnesî, valoda, izdevçjs, izdevuma indekss (1-100).
******************************************************************************************************/
// Autors: Straujums Uldis
// Radîts: v.1.0.; 17.04.2019. Izmantots risinâjums no e-kursa PiPLa0501.cpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "lvfriendly.h" // latvieðu valodas tekstu izvadei v.5(Çriks Gopaks, 2012; pielâgota C+14 - U.Straujums, 2018)

using namespace std;
const int NOSGARUMS=20;
const int VEIDGARUMS=11;
const int IZDGARUMS=15;

class Prese
{
 private:
 char nosaukums[NOSGARUMS+1];
 char veids[VEIDGARUMS+1];
 int reizes;
 int valoda; // 1 - latvieðu, 2 - angïu, 3 - vâcu
 char izdevejs[IZDGARUMS+1];
 int indekss;  // 1-100
 public:
 /** Metode fillObject() aizpilda Prese objekta laukus,
     vçrtîbas ievada lietotâjs **/
 void fillObject();
 /** Metode add_izdevums(fname) pievieno Prese objekta vçrtîbu faila fname beigâs **/
 void add_izdevums(const char *fname);
/** Metode print() izdrukâ objekta vçrtîbu **/
 void print();
 /** Metode printfile(fname) izdrukâ faila fname komponentes **/
 void printfile(const char *fname);
 // Metode, kas pielikta risinâjumam PiPLU0503.cpp
 /** Metode select(fname,nosaukums) ieraksta no faila fname ziòas
     par preses izdevumu nosaukums objektâ **/
 bool select(const char* fname, const char* nosaukums);
 };
 int main ()
 {
 Prese izd;
 string fn; // Faila vârds
 string nosaukums; // Meklçjamâ preses izdevuma nosaukums

 fn = "prese.bin";
 // Aizpilda sâkotnçjo failu
 izd.fillObject();
 while(cin)
 {
 izd.add_izdevums(fn.c_str());
 izd.fillObject();
 }
 // Izdrukâ sâkotnçjo failu
 izd.printfile(fn.c_str());
 // Iegûst ziòas par dotu preses izdevumu.
 cin.clear();  // Iespçjo ievadîðanu - jo ar CTRL+Z ir pabeigta ievadîðana
 cout << "Ievadiet meklçjamâ preses izdevuma nosaukumu:" << endl;
 cin >> nosaukums;
 if(izd.select(fn.c_str(),nosaukums.c_str()))
    izd.print();
    else cout << "Nav izdevuma " << nosaukums <<endl;
 }
// Klases Prese metoþu realizâcija
/** Metode fillObject() aizpilda Prese objekta laukus,
     vçrtîbas ievada lietotâjs **/
 void Prese::fillObject()
 {
     string vertiba;

    cout << "Ievadiet informâciju par preses izdevumu: "<< endl;
    cout << "nosaukums izdevuma veids (laikraksts, þurnâls, nedçïraksts)"
         << " iznâkðanas reiþu skaits mçnesî valoda izdevçjs indekss" << endl;
    cout << "(CTRL+Z, lai pabeigtu ievadi)" << endl;
    cin >> vertiba;
    strncpy(nosaukums,vertiba.c_str(),NOSGARUMS);
    nosaukums[NOSGARUMS]='\0';
    cin >> vertiba;
    strncpy(veids,vertiba.c_str(),VEIDGARUMS);
    veids[VEIDGARUMS]='\0';
    cin >> reizes;
    cin >> valoda;
    cin >> vertiba;
    strncpy(izdevejs,vertiba.c_str(),IZDGARUMS);
    izdevejs[IZDGARUMS]='\0';
    cin >> indekss;
    cin.ignore();
 }
 /** Metode add_izdevums(fname) pievieno Prese objekta vçrtîbu
     faila fname beigâs **/
 void Prese::add_izdevums(const char *fname)
 {
     fstream f;

 f.open(fname,ios::app| ios::binary);
 f.write(reinterpret_cast<const char *>(this), sizeof(Prese) );
 // f.write((char*)this, sizeof(Prese));
 f.close();
 }
/** Metode print() izdrukâ objekta vçrtîbu **/
 void Prese::print()
 {
    cout << nosaukums<< ' ';
    cout << veids << ' ';
    cout << reizes << ' ';
    cout << valoda<< ' ';
    cout << izdevejs<< ' ';
    cout << indekss<< endl;
 }
 /** Metode printfile(fname) izdrukâ faila fname komponentes **/
 void Prese::printfile(const char *fname)
 {
     fstream f;

 f.open(fname,ios::in| ios::binary);
 f.read(reinterpret_cast<char *>(this), sizeof(Prese));
//f.read((char*) this, sizeof(Prese));
while (f)
  {
      print();
      f.read(reinterpret_cast<char *>(this), sizeof(Prese));
    //f.read((char*) this, sizeof(Prese));
 }
 cout << endl;
 f.close();
 }
 /** Metode select(fname,nosaukums) ieraksta no faila fname ziòas
     par preses izdevumu nosaukums objektâ **/
 bool Prese::select(const char* fname, const char* nosaukums)
 {
 fstream f;
 bool found=false;

 f.open(fname,ios::in| ios::binary);
 f.read(reinterpret_cast<char *>(this), sizeof(Prese));
//f.read((char*) this, sizeof(Prese));
while (f)
  {
      if(strcmp(this->nosaukums, nosaukums)==0)
      {found=true; break;}
      f.read(reinterpret_cast<char *>(this), sizeof(Prese));
    //f.read((char*) this, sizeof(Prese));
 }
 cout << endl;
 f.close();
 return found;
 }
/**********************Testu plâns**************************
ieeja                                        paredzamais rezultâts
Diena laikraksts 24 1 DienasMediji 25  Diena laikraksts 24 1 DienasMediji 5
Ir þurnâls 4 1 CitsMedijs 1            Ir þurnâls 4 1 CitsMedijs 1
CACM þurnâls 1 2 ACM 12                CACM þurnâls 1 2 ACM 12
CTRL+Z
Diena                                  Diena Diena laikraksts 24 1 DienasMediji 5
                                       Atrasts izdevums
===============================================================================
Diena laikraksts 24 1 DienasMediji 25  Diena laikraksts 24 1 DienasMediji 5
Ir þurnâls 4 1 CitsMedijs 1            Ir þurnâls 4 1 CitsMedijs 1
CACM þurnâls 1 2 ACM 12
CTRL+Z
Nakts                                  Nav izdevuma Nakts
===============================================================================
                                            nav neviena izdevuma
CTRL+Z
***********************************************************/
