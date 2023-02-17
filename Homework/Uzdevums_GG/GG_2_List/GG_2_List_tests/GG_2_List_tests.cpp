/********************************************************************
G2. Uzrakstît funkciju, kas salîdzina, vai divi saraksti ir vienâdi.

Realizçt izmantojot STL::list konteineru.

GG2. G2 uzdevuma risinâjumam pievienot exception handling un vienîbtestçðanu.
********************************************************************/

// Autors: Santa Lauva
// Studenta apliecîbas nr.: sl19037
// Datums: 10.05.2020.

// Programmai par pamatu òemts Santas Lauvas izstrâdâtais G2 uzdevuma risinâjums

#include <iostream>
#include<list>
#include<algorithm>
#include "../GG_2_List/GG_2_List.cpp"
#include "lvtocon.h"
using namespace std;

// Ar funkciju test1() pârbauda funkcijas isEqual (list<int> a, list<int> b) darbîbu, ja abi saraksti ir tukði
void test1()
{
    list<int> virkne1, virkne2;
    try {
        isEqual(virkne1, virkne2);
    }
    catch (const char * er) {
        cout << 1 << endl;   // Izvadis 1 (true), jo tukði saraksti ir vienâdi
    }
    catch (...) {
       cout << "ERROR" << endl;
    }
}

// Ar funkciju test2() pârbauda funkcijas isEqual (list<int> a, list<int> b) darbîbu, ja abi saraksti ir vienâdi
void test2()
{
    list<int> virkne1, virkne2;
    for (int i=1; i<6; i++)
    {
        virkne1.push_back(i);
        virkne2.push_back(i);
    }

    cout << isEqual(virkne1, virkne2) << endl;   // 1
}

// Ar funkciju test3() pârbauda funkcijas isEqual (list<int> a, list<int> b) darbîbu, ja otrais saraksts ir garâks
void test3()
{
    list<int> virkne1, virkne2;
    for (int i=1; i<6; i++)
    {
        virkne1.push_back(i);
        virkne2.push_back(i);
    }
    for (int i=6; i<9; i++)
        virkne2.push_back(i);

    cout << !isEqual(virkne1, virkne2) << endl;   // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)
}

// Ar funkciju test4() pârbauda funkcijas isEqual (list<int> a, list<int> b) darbîbu, ja pirmais saraksts ir garâks
void test4()
{
    list<int> virkne1, virkne2;
    for (int i=1; i<6; i++)
    {
        virkne1.push_back(i);
        virkne2.push_back(i);
    }
    for (int i=6; i<9; i++)
        virkne1.push_back(i);

    cout << !isEqual(virkne1, virkne2) << endl;  // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)
}

// Ar funkciju test5() pârbauda funkcijas isEqual (list<int> a, list<int> b) darbîbu, ja abos sarakstos atðíiras vçrtîbas
void test5()
{
    list<int> virkne1, virkne2;
    for (int i=1; i<6; i++)
    {
        virkne1.push_back(i);
        virkne2.push_back(i);
    }
    virkne1.front() = 2;
    cout << !isEqual(virkne1, virkne2) << endl;   // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)
}

// Ar funkciju test6() pârbauda funkcijas isEqual (list<int> a, list<int> b) darbîbu, ja otrais saraksts ir tukðs
void test6()
{
    list<int> virkne1, virkne2;
    for (int i=1; i<6; i++)
    {
        virkne1.push_back(i);
    }

    try {
        isEqual(virkne1, virkne2);
    }
    catch (int e) {
        cout << (e==0) << endl;      // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)
    }
}

// Ar funkciju test7() pârbauda funkcijas isEqual (list<int> a, list<int> b) darbîbu, ja pirmais saraksts ir tukðs
void test7()
{
    list<int> virkne1, virkne2;
    for (int i=1; i<6; i++)
    {
        virkne2.push_back(i);
    }

    try {
        isEqual(virkne1, virkne2);
    }
    catch (int ex) {
        cout << (ex == 0) << endl;   // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)
    }
}

int main ()
{
    test1();  // 1
    test2();  // 1
    test3();  // 1
    test4();  // 1
    test5();  // 1
    test6();  // 1
    test7();  // 1
}

/******************************** Testa plâns *******************************

  Pirmais saraksts                Otrais saraksts                Rezultâts

      "Tukðs"                         "Tukðs"                       1
     1 2 3 4 5                       1 2 3 4 5                      1
     1 2 3 4 5                   1 2 3 4 5 6 7 8                    1
  1 2 3 4 5 6 7 8                    1 2 3 4 5                      1
     2 2 3 4 5                       1 2 3 4 5                      1
     1 2 3 4 5                        "Tukðs"                       1
      "Tukðs"                        1 2 3 4 5                      1

*****************************************************************************/
