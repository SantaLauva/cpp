//PiPLa0501.cpp
/******************************************************************************************************
PiPLa0501. Sastâdît C++ programmu,
kas izveido failu ar ziòâm par preses izdevumiem.
Ziòas par preses izdevumiem jâieraksta secîgi binârâ komponenðu failâ (prese.bin).
Faila ieraksta saturs: nosaukums, izdevuma veids (laikraksts, þurnâls, nedçïraksts),
iznâkðanas reiþu skaits mçnesî, valoda, izdevçjs, izdevuma indekss (1-100).
Ieejas dati jâòem no standartieejas plûsmas.
******************************************************************************************************/
// Autors: Straujums Uldis
// Radîts: v.1.0.; 23.05.2017.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "lvtocon.h" // latvieðu valodas tekstu izvadei projektos, v.2(izmantoðanai projektos), Çriks Gopaks, 2011

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
 };
 int main ()
 {
 Prese izd;
 string fn; // faila vârds

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

 return 0;
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
/**********************Testu plâns**************************
ieeja                                        paredzamais rezultâts
Diena laikraksts 24 1 DienasMediji 25  Diena laikraksts 24 1 DienasMediji 5
Ir þurnâls 4 1 CitsMedijs 1            Ir þurnâls 4 1 CitsMedijs 1
CACM þurnâls 1 2 ACM 12                CACM þurnâls 1 2 ACM 12
CTRL+Z
===============================================================================
                                            nav neviena izdevuma
CTRL+Z
***********************************************************/
