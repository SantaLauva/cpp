/**********************************************************************
G2. Uzrakst�t funkciju, kas sal�dzina, vai divi saraksti ir vien�di.

Realiz�ts k� vienvirziena saist�tais saraksts.

GG2. Programm� G2 iek�aut exception handling.
Un veikt vien�btest��anu. Programma vien�btest��anai atrodama map� GG_2_Saistitais_saraksts_tests
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliec�bas nr.: sl19037
// Izstr�des datums: 09.05.2020.

// Programmai par pamatu �emts Santas Lauvas izstr�d�tais G2 uzdevuma atrisin�jums.

#include <iostream>
#include "GG_2_saistitais_saraksts.h"
using namespace std;

void append(elem *&first, elem *&last, int n) // Pievieno�ana saraksta beig�s
{
    elem *p = new elem(n);
    if (first == NULL)
        first = last = p;
    else
    {
        last->next = p;
        last = p;
    }
}

void print(elem *first)  // Funkcija saraksta izprint��anai
{
    elem *p = first;
    while(p)
    {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
}


void rem(elem *&first) {  // Saraksta izd��ana
    while(first) {
        elem *p = first->next;
        delete first;
        first=p;
    }
}

// Funkcija divu sarakstu sal�dzin��anai
// 1) pirmais saraksts var but garaks
// 2) saraksts var b�t garaks
// 3) abi vienada garuma

bool isEqual (elem *first1, elem *first2)
{
    elem *p = first1;
    elem *q = first2;

    if ((first1 == NULL) && (first2 == NULL)) throw ("Abi saraksti ir tuk�i. Tuk�i saraksti ir vien�di!");
    else if (first1 == NULL)  throw 0;
    else if (first2 == NULL)  throw 0;

    while(p)
    {
        // P�rbauda vai abos sarakstos, i-taj� poz�cij�s ir vien�das v�rt�bas
        if (p->num != q->num) return false;
        else { // V�rt�bas vien�das, ejam uz sarakstu n�ko�ajiem mezgliem
            p = p->next;
            q = q->next;
        }

        if ((!q) && (!p)) return true; // Ja abi saraksti vien�da garuma un visas iepriek��j�s v�rt�bas sakrita
        if (!q) return false;  // Ja q saraksts ir �s�ks
    }

    if (q) return false;   // Ja q saraksts ir gar�ks
}
