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
using namespace std;

bool isEqual (list<int> a, list<int> b);
void print(list<int> a);
