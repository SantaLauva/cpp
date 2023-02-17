/********************************************************************
G2. Uzrakst�t funkciju, kas sal�dzina, vai divi saraksti ir vien�di.

Realiz�t izmantojot STL::list konteineru.

GG2. G2 uzdevuma risin�jumam pievienot exception handling un vien�btest��anu.
********************************************************************/

// Autors: Santa Lauva
// Studenta apliec�bas nr.: sl19037
// Datums: 10.05.2020.

// Programmai par pamatu �emts Santas Lauvas izstr�d�tais G2 uzdevuma risin�jums

#include <iostream>
#include<list>
#include<algorithm>
#include "../GG_2_List/GG_2_List.cpp"
#include "lvtocon.h"
using namespace std;

// Ar funkciju test1() p�rbauda funkcijas isEqual (list<int> a, list<int> b) darb�bu, ja abi saraksti ir tuk�i
void test1()
{
    list<int> virkne1, virkne2;
    try {
        isEqual(virkne1, virkne2);
    }
    catch (const char * er) {
        cout << 1 << endl;   // Izvadis 1 (true), jo tuk�i saraksti ir vien�di
    }
    catch (...) {
       cout << "ERROR" << endl;
    }
}

// Ar funkciju test2() p�rbauda funkcijas isEqual (list<int> a, list<int> b) darb�bu, ja abi saraksti ir vien�di
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

// Ar funkciju test3() p�rbauda funkcijas isEqual (list<int> a, list<int> b) darb�bu, ja otrais saraksts ir gar�ks
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

    cout << !isEqual(virkne1, virkne2) << endl;   // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)
}

// Ar funkciju test4() p�rbauda funkcijas isEqual (list<int> a, list<int> b) darb�bu, ja pirmais saraksts ir gar�ks
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

    cout << !isEqual(virkne1, virkne2) << endl;  // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)
}

// Ar funkciju test5() p�rbauda funkcijas isEqual (list<int> a, list<int> b) darb�bu, ja abos sarakstos at��iras v�rt�bas
void test5()
{
    list<int> virkne1, virkne2;
    for (int i=1; i<6; i++)
    {
        virkne1.push_back(i);
        virkne2.push_back(i);
    }
    virkne1.front() = 2;
    cout << !isEqual(virkne1, virkne2) << endl;   // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)
}

// Ar funkciju test6() p�rbauda funkcijas isEqual (list<int> a, list<int> b) darb�bu, ja otrais saraksts ir tuk�s
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
        cout << (e==0) << endl;      // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)
    }
}

// Ar funkciju test7() p�rbauda funkcijas isEqual (list<int> a, list<int> b) darb�bu, ja pirmais saraksts ir tuk�s
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
        cout << (ex == 0) << endl;   // 1 (noz�m� ka funkcija atgrieza rezult�tu, ka saraksti nav vien�di)
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
