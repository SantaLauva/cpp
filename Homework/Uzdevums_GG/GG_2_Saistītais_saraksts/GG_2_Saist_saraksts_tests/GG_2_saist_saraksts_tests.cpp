/**********************************************************************
G2. Uzrakst�t funkciju, kas sal�dzina, vai divi saraksti ir vien�di.

Realiz�ts k� vienvirziena saist�tais saraksts.

GG2. Programm� G2 iek�aut exception handling.
Un veikt vien�btest��anu.
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliec�bas nr.: sl19037
// Izstr�des datums: 09.05.2020.

#include <iostream>
#include "lvtocon.h"
#include "../GG_2_Saistitais_saraksts/GG_2_Saistitais_saraksts.cpp"
using namespace std;

// Ar funkciju test1() p�rbauda funkcijas isEqual (elem *first1, elem *first2) darb�bu, ja abi saraksti ir tuk�i
void test1()
{
    elem *first1=NULL;
    elem *first2=NULL;
    try {
        isEqual(first1, first2);
    }
    catch (const char * er) {
        cout << 1 << endl;   // Izvadis 1 (true), jo tuk�i saraksti ir vien�di
    }
    catch (...) {
       cout << "ERROR" << endl;
    }

    // saraksta izn�cin��ana
    rem(first1);
    rem(first2);
}

// Ar funkciju test2() p�rbauda funkcijas isEqual (elem *first1, elem *first2) darb�bu, ja abi saraksti ir vien�di
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

    // saraksta izn�cin��ana
    rem(first1);
    rem(first2);
}

// Ar funkciju test3() p�rbauda funkcijas isEqual (elem *first1, elem *first2) darb�bu, ja otrais saraksts ir gar�ks
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

    cout << !isEqual(first1, first2) << endl;   // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)

    // saraksta izn�cin��ana
    rem(first1);
    rem(first2);
}

// Ar funkciju test4() p�rbauda funkcijas isEqual (elem *first1, elem *first2) darb�bu, ja pirmais saraksts ir gar�ks
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

    cout << !isEqual(first1, first2) << endl;  // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)

    // saraksta izn�cin��ana
    rem(first1);
    rem(first2);
}

// Ar funkciju test5() p�rbauda funkcijas isEqual (elem *first1, elem *first2) darb�bu, ja abos sarakstos at��iras v�rt�bas
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
    cout << !isEqual(first1, first2) << endl;   // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)

    // saraksta izn�cin��ana
    rem(first1);
    rem(first2);
}

// Ar funkciju test6() p�rbauda funkcijas isEqual (elem *first1, elem *first2) darb�bu, ja otrais saraksts ir tuk�s
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
        cout << (e==0) << endl;      // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)
    }

    // saraksta izn�cin��ana
    rem(first1);
    rem(first2);
}

// Ar funkciju test7() p�rbauda funkcijas isEqual (elem *first1, elem *first2) darb�bu, ja pirmais saraksts ir tuk�s
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
        cout << (ex == 0) << endl;   // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)
    }

    // saraksta izn�cin��ana
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

/******************************** Testa pl�ns *******************************

  Pirmais saraksts                Otrais saraksts                Rezult�ts

      "Tuk�s"                         "Tuk�s"                       1
     1 2 3 4 5                       1 2 3 4 5                      1
     1 2 3 4 5                   1 2 3 4 5 6 7 8                    1
  1 2 3 4 5 6 7 8                    1 2 3 4 5                      1
     2 2 3 4 5                       1 2 3 4 5                      1
     1 2 3 4 5                        "Tuk�s"                       1
      "Tuk�s"                        1 2 3 4 5                      1

*****************************************************************************/
