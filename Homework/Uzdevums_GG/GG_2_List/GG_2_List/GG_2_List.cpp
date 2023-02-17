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
#include "GG_2_List.h"
#include "lvtocon.h"
using namespace std;

bool isEqual (list<int> a, list<int> b)
{
    if ((a.empty()) && (b.empty())) throw ("Abi saraksti ir tuk�i. Tuk�i saraksti ir vien�di!");  // Ja abi saraksti ir tuk�i, tie ir vien�di
    else if (a.empty()) throw 0;
    else if (b.empty()) throw 0;

    if (a.size() != b.size()) return false;
    else
    {
        list<int> :: iterator i;
        list<int> :: iterator j;
        j=b.begin();
        for (i=a.begin(); i!=a.end(); ++i)
        {
            if (*i != *j) return false;
            else ++j;
        }
    }
    return true;
}

void print(list<int> a)
{
    list<int> :: iterator i;
    for (i=a.begin(); i!=a.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

