/**********************************************************************
G2. Uzrakstît funkciju, kas salîdzina, vai divi saraksti ir vienâdi.

Realizçts kâ vienvirziena saistîtais saraksts.

GG2. Programmâ G2 iekïaut exception handling.
Un veikt vienîbtestçðanu.
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliecîbas nr.: sl19037
// Izstrâdes datums: 09.05.2020.

#include <iostream>
#include "lvtocon.h"
#include "../GG_2_Saistitais_saraksts/GG_2_Saistitais_saraksts.cpp"
using namespace std;

// Ar funkciju test1() pârbauda funkcijas isEqual (elem *first1, elem *first2) darbîbu, ja abi saraksti ir tukði
void test1()
{
    elem *first1=NULL;
    elem *first2=NULL;
    try {
        isEqual(first1, first2);
    }
    catch (const char * er) {
        cout << 1 << endl;   // Izvadis 1 (true), jo tukði saraksti ir vienâdi
    }
    catch (...) {
       cout << "ERROR" << endl;
    }

    // saraksta iznîcinâðana
    rem(first1);
    rem(first2);
}

// Ar funkciju test2() pârbauda funkcijas isEqual (elem *first1, elem *first2) darbîbu, ja abi saraksti ir vienâdi
void test2()
{
    elem *first1=NULL, *last1=NULL;
    elem *first2=NULL, *last2=NULL;
    for (int i=1; i<6; i++)
    {
        append(first1, last1, i);
        append(first2, last2, i);
    }

    cout << isEqual(first1, first2) << endl;   // 1

    // saraksta iznîcinâðana
    rem(first1);
    rem(first2);
}

// Ar funkciju test3() pârbauda funkcijas isEqual (elem *first1, elem *first2) darbîbu, ja otrais saraksts ir garâks
void test3()
{
    elem *first1=NULL, *last1=NULL;
    elem *first2=NULL, *last2=NULL;
    for (int i=1; i<6; i++)
    {
        append(first1, last1, i);
        append(first2, last2, i);
    }
    for (int i=6; i<9; i++)
        append(first2, last2, i);

    cout << !isEqual(first1, first2) << endl;   // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)

    // saraksta iznîcinâðana
    rem(first1);
    rem(first2);
}

// Ar funkciju test4() pârbauda funkcijas isEqual (elem *first1, elem *first2) darbîbu, ja pirmais saraksts ir garâks
void test4()
{
    elem *first1=NULL, *last1=NULL;
    elem *first2=NULL, *last2=NULL;
    for (int i=1; i<6; i++)
    {
        append(first1, last1, i);
        append(first2, last2, i);
    }
    for (int i=6; i<9; i++)
        append(first1, last1, i);

    cout << !isEqual(first1, first2) << endl;  // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)

    // saraksta iznîcinâðana
    rem(first1);
    rem(first2);
}

// Ar funkciju test5() pârbauda funkcijas isEqual (elem *first1, elem *first2) darbîbu, ja abos sarakstos atðíiras vçrtîbas
void test5()
{
    elem *first1=NULL, *last1=NULL;
    elem *first2=NULL, *last2=NULL;
    for (int i=1; i<6; i++)
    {
        append(first1, last1, i);
        append(first2, last2, i);
    }
    first1->num = 2;
    cout << !isEqual(first1, first2) << endl;   // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)

    // saraksta iznîcinâðana
    rem(first1);
    rem(first2);
}

// Ar funkciju test6() pârbauda funkcijas isEqual (elem *first1, elem *first2) darbîbu, ja otrais saraksts ir tukðs
void test6()
{
    elem *first1=NULL, *last1;
    elem *first2=NULL, *last2=NULL;
    for (int i=1; i<6; i++)
    {
        append(first1, last1, i);
    }

    try {
        isEqual(first1, first2);
    }
    catch (int e) {
        cout << (e==0) << endl;      // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)
    }

    // saraksta iznîcinâðana
    rem(first1);
    rem(first2);
}

// Ar funkciju test7() pârbauda funkcijas isEqual (elem *first1, elem *first2) darbîbu, ja pirmais saraksts ir tukðs
void test7()
{
    elem *first1=NULL, *last1=NULL;
    elem *first2=NULL, *last2;
    for (int i=1; i<6; i++)
    {
        append(first2, last2, i);
    }

    try {
        isEqual(first1, first2);
    }
    catch (int ex) {
        cout << (ex == 0) << endl;   // 1 (nozîmç ka funkcija atgrieza rezultâtu, ka saraksti nav vienâdi)
    }

    // saraksta iznîcinâðana
    rem(first1);
    rem(first2);
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
