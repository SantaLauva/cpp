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
#include "GG_2_List.h"
#include "lvtocon.h"
using namespace std;

bool isEqual (list<int> a, list<int> b)
{
    if ((a.empty()) && (b.empty())) throw ("Abi saraksti ir tukði. Tukði saraksti ir vienâdi!");  // Ja abi saraksti ir tukði, tie ir vienâdi
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

