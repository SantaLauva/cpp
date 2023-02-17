/**********************************************************************
G2. Uzrakstît funkciju, kas salîdzina, vai divi saraksti ir vienâdi.

Realizçts kâ vienvirziena saistîtais saraksts.

GG2. Programmâ G2 iekïaut exception handling.
Un veikt vienîbtestçðanu. Programma vienîbtestçðanai atrodama mapç GG_2_Saistitais_saraksts_tests
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliecîbas nr.: sl19037
// Izstrâdes datums: 09.05.2020.

// Programmai par pamatu òemts Santas Lauvas izstrâdâtais G2 uzdevuma atrisinâjums.

#include <iostream>
#include "GG_2_saistitais_saraksts.h"
using namespace std;

void append(elem *&first, elem *&last, int n) // Pievienoðana saraksta beigâs
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

void print(elem *first)  // Funkcija saraksta izprintçðanai
{
    elem *p = first;
    while(p)
    {
        cout << p->num << " ";
        p = p->next;
    }
    cout << endl;
}


void rem(elem *&first) {  // Saraksta izdçðana
    while(first) {
        elem *p = first->next;
        delete first;
        first=p;
    }
}

// Funkcija divu sarakstu salîdzinâðanai
// 1) pirmais saraksts var but garaks
// 2) saraksts var bût garaks
// 3) abi vienada garuma

bool isEqual (elem *first1, elem *first2)
{
    elem *p = first1;
    elem *q = first2;

    if ((first1 == NULL) && (first2 == NULL)) throw ("Abi saraksti ir tukði. Tukði saraksti ir vienâdi!");
    else if (first1 == NULL)  throw 0;
    else if (first2 == NULL)  throw 0;

    while(p)
    {
        // Pârbauda vai abos sarakstos, i-tajâ pozîcijâs ir vienâdas vçrtîbas
        if (p->num != q->num) return false;
        else { // Vçrtîbas vienâdas, ejam uz sarakstu nâkoðajiem mezgliem
            p = p->next;
            q = q->next;
        }

        if ((!q) && (!p)) return true; // Ja abi saraksti vienâda garuma un visas iepriekðçjâs vçrtîbas sakrita
        if (!q) return false;  // Ja q saraksts ir îsâks
    }

    if (q) return false;   // Ja q saraksts ir garâks
}
