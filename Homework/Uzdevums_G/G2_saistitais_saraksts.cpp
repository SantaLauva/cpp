/**********************************************************************
G2. Uzrakstît funkciju, kas salîdzina, vai divi saraksti ir vienâdi.

Realizçts kâ vienvirziena saistîtais saraksts.
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliecîbas nr. sl19037
// Datums: 20.03.2020.
// Mainîts 08.05.2020 - Papildinâti komentâri

// Programmai par pamatu òemts prof. Zutera pirmkoda piemçrs saitîtajam sarakstam linkedlist2.cpp

#include <iostream>
#include "lvfriendly.h"
using namespace std;

struct elem
{
    int num;
    elem *next;
    elem (int n)
    {
        num = n;
        next = NULL;
    }
};

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

void ins(elem *first,int m,int n) {  // Elementa pievienoðana aiz konkrçta mezgla
    elem *p = first;
    while(p and p->num!=m)
        p=p->next;
    if (p) {
        elem *q = new elem(n);
        q->next = p->next;
        p->next = q;
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
// 2) otrais saraksts var bût garaks
// 3) abi vienada garuma

bool isEqual (elem *first1, elem *first2)
{
    elem *p = first1;
    elem *q = first2;

    if ((first1 == NULL) && (first2 == NULL)) return true;  // Ja abi saraksti ir tukði, tie ir vienâdi
    else if (first1 == NULL) return false;
    else if (first2 == NULL) return false;

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


int main()
{
    int ok;
    do
    {
        elem *first1=NULL,*last1;  // Pirmajam sarakstam
        elem *first2=NULL,*last2;  // Otrajam sarakstam
        elem *first3=NULL,*last3;  // Treðajam sarakstam
        elem *first4=NULL,*last4;  // Ceturtajam sarakstam

        // Salîdzina tukðus sarakstus
        cout << "Tukði saraksti: ";
        if (isEqual(first1, first2)) cout << " ... Saraksti ir vienâdi!" << endl <<endl;
        else cout << "Saraksti nav vienâdi!" << endl;

        /** Tâlâk tiek izveidotajiem èetriem sarakstiem pievienoti elementi un ðiem elementiem pieðíirtas vçrtîbas
        1. un 2. saraksts ir vienâdi
        3.saraksts ir visgarâkais
        4. saraksts no 1. un 2. saraksta atðíiras ar vienu elementa vçrtîbu
        **/

        for(int i=0;i<5;i++) {
            append(first1,last1,i);
            append(first2,last2,i);
            append(first4,last4,i);
        }
        first4->num = 2;

        for(int i=0;i<9;i++) {
            append(first3,last3,i);
        }

        // Salîdzina sarakstus

        // Saraksti ir vienâda garuma, ar vienâdiem elementiem
        cout << "Pirmais saraksts: ";
        print(first1);
        cout << "Otrais saraksts: ";
        print(first2);
        if (isEqual(first1, first2)) cout << "... Saraksti ir vienâdi!" << endl << endl;  // "Saraksti ir vienâdi"
        else cout << "... Saraksti nav vienâdi!" << endl << endl;

        // Pirmais saraksts îsâks
        cout << "Pirmais saraksts: ";
        print(first1);
        cout << "Treðais saraksts: ";
        print(first3);
        if (isEqual(first1, first3)) cout << "... Saraksti ir vienâdi!" << endl << endl;  // "Saraksti nav vienâdi"
        else cout << "... Saraksti nav vienâdi!" << endl << endl;

        // Otrais saraksts îsâks
        cout << "Treðais saraksts: ";
        print(first3);
        cout << "Pirmais saraksts: ";
        print(first1);
        if (isEqual(first3, first1)) cout << "... Saraksti ir vienâdi!" << endl << endl;  // "Saraksti nav vienâdi"
        else cout << "... Saraksti nav vienâdi!" << endl << endl;

        // Saraksti ir vienâda garuma, bet elementu vçrtîbas atðíiras
        cout << "Pirmais saraksts: ";
        print(first1);
        cout << "Ceturtais saraksts: ";
        print(first4);
        if (isEqual(first1, first4)) cout << "... Saraksti ir vienâdi!" << endl<< endl;  // "Saraksti nav vienâdi"
        else cout << "... Saraksti nav vienâdi!" << endl << endl;

        rem(first1);
        rem(first2);
        rem(first3);
        rem(first4);

        cout << " Vai turpinât (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}


/********************************** Testa plâns *****************************************

  Pirmais saraksts                Otrais saraksts                     Rezultâts

      "Tukðs"                         "Tukðs"                     "Saraksti ir vienâdi"
     0 1 2 3 4                       0 1 2 3 4                    "Saraksti ir vienâdi"
     0 1 2 3 4                   0 1 2 3 4 5 6 7 8                "Saraksti nav vienâdi"
  0 1 2 3 4 5 6 7 8                  0 1 2 3 4                    "Saraksti nav vienâdi"
     2 1 2 3 4                       0 1 2 3 4                    "Saraksti nav vienâdi"

*****************************************************************************************/
