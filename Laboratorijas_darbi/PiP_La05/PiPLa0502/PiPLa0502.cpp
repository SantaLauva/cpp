//PiPLa0502.cpp
/******************************************************************************************************
PiPLa0502. Sast�d�t C++ programmu, kas izveido failu ar zi��m par preses izdevumiem.
Zi�as par preses izdevumiem j�ieraksta ar tie�o pieeju bin�r� komponen�u fail� (prese.bin).
Atsl�ga � izdevuma indekss.
Faila ieraksta saturs: nosaukums, izdevuma veids (laikraksts, �urn�ls, ned��raksts),
izn�k�anas rei�u skaits m�nes�, valoda, izdev�js, izdevuma indekss (1-100).
Ieejas dati j��em no standartieejas pl�smas.
******************************************************************************************************/
// Autors: Straujums Uldis
// Rad�ts: v.1.0.; 01.04.2019.
// Main�ts: 04.04.2019. uzlabota metode createBlank - tiek izsaukta objektam blank

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include "lvtocon.h" // latvie�u valodas tekstu izvadei projektos, v.2(izmanto�anai projektos), �riks Gopaks, 2011

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
 /** Konstruktora metode aizpilda laukus ar "tuk��m" v�rt�b�m **/
 Prese (const char *n = "", const char *v = "",
         const int r = 0, const int val = 0, const char* izd = "",
         const int ind=0);
 /** Metode createBlank(name, count) izveido failu ar v�rdu name,
  kas satur count tuk�us ierakstus **/
 void createBlank(const char *name, int count);
 /** writeDirect(fname) - ieraksta objekta v�rt�bu faila fname ierakst�
    ar k�rtas numuru, kas sakr�t ar objekta lauka indekss v�rt�bu **/
 void writeDirect(const char *fname);
 };
 int main ()
 {
 Prese izd;
 Prese blank; // konstruktors ar noklus�taj�m v�rt�b�m aizpilda ar null�m
 string fn; // faila v�rds

 fn = "prese.bin";
 // Izveido failu ar 101 tuk�iem ierakstiem
 // (0-tais ieraksts netiek izmantots,jo indeksi ir 1-100)
 blank.createBlank(fn.c_str(), 101); // Raksta ierakstus ar indekss=0
 // Aizpilda failu ar lietot�ja ievad�t�m v�rt�b�m
 izd.fillObject();
 while(cin)
 {
     izd.writeDirect(fn.c_str());
     izd.fillObject();
 }

 // Izdruk� failu
 izd.printfile(fn.c_str());

 return 0;
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
 /** Metode add_izdevums(fname) pievieno Prese objekta v�rt�bu faila fname beig�s **/
 void Prese::add_izdevums(const char *fname)
 {
     fstream f;

 f.open(fname,ios::app| ios::binary);
 f.write(reinterpret_cast<const char *>(this), sizeof(Prese) );
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
 f.read(reinterpret_cast<char *>(this), sizeof(Prese) );
//f.read((char*) this, sizeof(Prese));
while (f)
  {
      print();
      f.read(reinterpret_cast<char *>(this), sizeof(Prese) );
    //f.read((char*) this, sizeof(Prese));
 }
 cout << endl;
 f.close();
 }
/** Konstruktora metode aizpilda laukus ar "tuk��m" v�rt�b�m **/
Prese::Prese(const char *n, const char *v,
         const int r, const int val, const char* izd, const int ind)
{
  strncpy(nosaukums,n,NOSGARUMS); nosaukums[NOSGARUMS]='\0';
  strncpy(veids,v,VEIDGARUMS); veids[VEIDGARUMS]='\0';
  reizes=r; valoda=val;
  strncpy(izdevejs,izd,IZDGARUMS);izdevejs[IZDGARUMS]='\0';
  indekss=ind;
};
/** Metode createBlank(f, name, count) izveido failu f ar v�rdu name,
  kas satur count tuk�us ierakstus **/
void Prese::createBlank(const char *name, int count){
 fstream f;
 f.open(name,ios::out| ios::binary);

 for (int i =0; i<count;i++){
 f.write(reinterpret_cast< const char * >(this), sizeof( Prese ) );
 }
 f.close();
 };
/** writeDirect(fname) - ieraksta objekta v�rt�bu faila fname ierakst�
    ar k�rtas numuru, kas sakr�t ar objekta lauka indekss v�rt�bu **/
 void Prese::writeDirect(const char *fname)
 {
     fstream f;

 f.open(fname,ios::in|ios::out| ios::binary);
 f.seekp(indekss*sizeof(Prese));
 f.write(reinterpret_cast<const char *>(this), sizeof(Prese) );
 f.close();
 }
/**********************Testu pl�ns**************************
ieeja                                        paredzamais rezult�ts
Diena laikraksts 24 1 DienasMediji 5   Ir �urn�ls 4 1 CitsMedijs 1
Ir �urn�ls 4 1 CitsMedijs 1            Diena laikraksts 24 1 DienasMediji 5
CACM �urn�ls 1 2 ACM 12                CACM �urn�ls 1 2 ACM 12
CTRL+Z
===============================================================================
                                            nav neviena izdevuma
CTRL+Z
***********************************************************/
