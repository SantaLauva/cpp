//PiPLa0701.cpp
/******************************************************************************************************
PiPLa0701. Sast�d�t C++ programmu, kas �auj ieg�t zi�as par dotu preses izdevumu.
Preses izdevuma nosaukums j��em no standartieejas pl�smas.
J�izmanto fails ar zi��m par preses izdevumiem.
Zi�as par preses izdevumiem ir ierakst�tas sec�gi bin�r� komponen�u fail� (prese.bin).
Faila ieraksta saturs: nosaukums, izdevuma veids (laikraksts, �urn�ls, ned��raksts),
izn�k�anas rei�u skaits m�nes�, valoda, izdev�js, izdevuma indekss (1-100).
******************************************************************************************************/
// Autors: Straujums Uldis
// Rad�ts: v.1.0.; 17.04.2019. Izmantots risin�jums no e-kursa PiPLa0501.cpp

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "lvfriendly.h" // latvie�u valodas tekstu izvadei v.5(�riks Gopaks, 2012; piel�gota C+14 - U.Straujums, 2018)

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
 int valoda; // 1 - latvie�u, 2 - ang�u, 3 - v�cu
 char izdevejs[IZDGARUMS+1];
 int indekss;  // 1-100
 public:
 /** Metode fillObject() aizpilda Prese objekta laukus,
     v�rt�bas ievada lietot�js **/
 void fillObject();
 /** Metode add_izdevums(fname) pievieno Prese objekta v�rt�bu faila fname beig�s **/
 void add_izdevums(const char *fname);
/** Metode print() izdruk� objekta v�rt�bu **/
 void print();
 /** Metode printfile(fname) izdruk� faila fname komponentes **/
 void printfile(const char *fname);
 // Metode, kas pielikta risin�jumam PiPLU0503.cpp
 /** Metode select(fname,nosaukums) ieraksta no faila fname zi�as
     par preses izdevumu nosaukums objekt� **/
 bool select(const char* fname, const char* nosaukums);
 };
 int main ()
 {
 Prese izd;
 string fn; // Faila v�rds
 string nosaukums; // Mekl�jam� preses izdevuma nosaukums

 fn = "prese.bin";
 // Aizpilda s�kotn�jo failu
 izd.fillObject();
 while(cin)
 {
 izd.add_izdevums(fn.c_str());
 izd.fillObject();
 }
 // Izdruk� s�kotn�jo failu
 izd.printfile(fn.c_str());
 // Ieg�st zi�as par dotu preses izdevumu.
 cin.clear();  // Iesp�jo ievad��anu - jo ar CTRL+Z ir pabeigta ievad��ana
 cout << "Ievadiet mekl�jam� preses izdevuma nosaukumu:" << endl;
 cin >> nosaukums;
 if(izd.select(fn.c_str(),nosaukums.c_str()))
    izd.print();
    else cout << "Nav izdevuma " << nosaukums <<endl;
 }
// Klases Prese meto�u realiz�cija
/** Metode fillObject() aizpilda Prese objekta laukus,
     v�rt�bas ievada lietot�js **/
 void Prese::fillObject()
 {
     string vertiba;

    cout << "Ievadiet inform�ciju par preses izdevumu: "<< endl;
    cout << "nosaukums izdevuma veids (laikraksts, �urn�ls, ned��raksts)"
         << " izn�k�anas rei�u skaits m�nes� valoda izdev�js indekss" << endl;
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
 /** Metode add_izdevums(fname) pievieno Prese objekta v�rt�bu
     faila fname beig�s **/
 void Prese::add_izdevums(const char *fname)
 {
     fstream f;

 f.open(fname,ios::app| ios::binary);
 f.write(reinterpret_cast<const char *>(this), sizeof(Prese) );
 // f.write((char*)this, sizeof(Prese));
 f.close();
 }
/** Metode print() izdruk� objekta v�rt�bu **/
 void Prese::print()
 {
    cout << nosaukums<< ' ';
    cout << veids << ' ';
    cout << reizes << ' ';
    cout << valoda<< ' ';
    cout << izdevejs<< ' ';
    cout << indekss<< endl;
 }
 /** Metode printfile(fname) izdruk� faila fname komponentes **/
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
 /** Metode select(fname,nosaukums) ieraksta no faila fname zi�as
     par preses izdevumu nosaukums objekt� **/
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
/**********************Testu pl�ns**************************
ieeja                                        paredzamais rezult�ts
Diena laikraksts 24 1 DienasMediji 25  Diena laikraksts 24 1 DienasMediji 5
Ir �urn�ls 4 1 CitsMedijs 1            Ir �urn�ls 4 1 CitsMedijs 1
CACM �urn�ls 1 2 ACM 12                CACM �urn�ls 1 2 ACM 12
CTRL+Z
Diena                                  Diena Diena laikraksts 24 1 DienasMediji 5
                                       Atrasts izdevums
===============================================================================
Diena laikraksts 24 1 DienasMediji 25  Diena laikraksts 24 1 DienasMediji 5
Ir �urn�ls 4 1 CitsMedijs 1            Ir �urn�ls 4 1 CitsMedijs 1
CACM �urn�ls 1 2 ACM 12
CTRL+Z
Nakts                                  Nav izdevuma Nakts
===============================================================================
                                            nav neviena izdevuma
CTRL+Z
***********************************************************/
