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
using namespace std;

bool isEqual (list<int> a, list<int> b);
void print(list<int> a);
