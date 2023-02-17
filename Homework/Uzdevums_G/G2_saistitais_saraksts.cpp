/**********************************************************************
G2. Uzrakst�t funkciju, kas sal�dzina, vai divi saraksti ir vien�di.

Realiz�ts k� vienvirziena saist�tais saraksts.
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliec�bas nr. sl19037
// Datums: 20.03.2020.
// Main�ts 08.05.2020 - Papildin�ti koment�ri

// Programmai par pamatu �emts prof. Zutera pirmkoda piem�rs sait�tajam sarakstam linkedlist2.cpp

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

void ins(elem *first,int m,int n) {  // Elementa pievieno�ana aiz konkr�ta mezgla
    elem *p = first;
    while(p and p->num!=m)
        p=p->next;
    if (p) {
        elem *q = new elem(n);
        q->next = p->next;
        p->next = q;
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
// 2) otrais saraksts var b�t garaks
// 3) abi vienada garuma

bool isEqual (elem *first1, elem *first2)
{
    elem *p = first1;
    elem *q = first2;

    if ((first1 == NULL) && (first2 == NULL)) return true;  // Ja abi saraksti ir tuk�i, tie ir vien�di
    else if (first1 == NULL) return false;
    else if (first2 == NULL) return false;

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


int main()
{
    int ok;
    do
    {
        elem *first1=NULL,*last1;  // Pirmajam sarakstam
        elem *first2=NULL,*last2;  // Otrajam sarakstam
        elem *first3=NULL,*last3;  // Tre�ajam sarakstam
        elem *first4=NULL,*last4;  // Ceturtajam sarakstam

        // Sal�dzina tuk�us sarakstus
        cout << "Tuk�i saraksti: ";
        if (isEqual(first1, first2)) cout << " ... Saraksti ir vien�di!" << endl <<endl;
        else cout << "Saraksti nav vien�di!" << endl;

        /** T�l�k tiek izveidotajiem �etriem sarakstiem pievienoti elementi un �iem elementiem pie��irtas v�rt�bas
        1. un 2. saraksts ir vien�di
        3.saraksts ir visgar�kais
        4. saraksts no 1. un 2. saraksta at��iras ar vienu elementa v�rt�bu
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

        // Sal�dzina sarakstus

        // Saraksti ir vien�da garuma, ar vien�diem elementiem
        cout << "Pirmais saraksts: ";
        print(first1);
        cout << "Otrais saraksts: ";
        print(first2);
        if (isEqual(first1, first2)) cout << "... Saraksti ir vien�di!" << endl << endl;  // "Saraksti ir vien�di"
        else cout << "... Saraksti nav vien�di!" << endl << endl;

        // Pirmais saraksts �s�ks
        cout << "Pirmais saraksts: ";
        print(first1);
        cout << "Tre�ais saraksts: ";
        print(first3);
        if (isEqual(first1, first3)) cout << "... Saraksti ir vien�di!" << endl << endl;  // "Saraksti nav vien�di"
        else cout << "... Saraksti nav vien�di!" << endl << endl;

        // Otrais saraksts �s�ks
        cout << "Tre�ais saraksts: ";
        print(first3);
        cout << "Pirmais saraksts: ";
        print(first1);
        if (isEqual(first3, first1)) cout << "... Saraksti ir vien�di!" << endl << endl;  // "Saraksti nav vien�di"
        else cout << "... Saraksti nav vien�di!" << endl << endl;

        // Saraksti ir vien�da garuma, bet elementu v�rt�bas at��iras
        cout << "Pirmais saraksts: ";
        print(first1);
        cout << "Ceturtais saraksts: ";
        print(first4);
        if (isEqual(first1, first4)) cout << "... Saraksti ir vien�di!" << endl<< endl;  // "Saraksti nav vien�di"
        else cout << "... Saraksti nav vien�di!" << endl << endl;

        rem(first1);
        rem(first2);
        rem(first3);
        rem(first4);

        cout << " Vai turpin�t (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}


/********************************** Testa pl�ns *****************************************

  Pirmais saraksts                Otrais saraksts                     Rezult�ts

      "Tuk�s"                         "Tuk�s"                     "Saraksti ir vien�di"
     0 1 2 3 4                       0 1 2 3 4                    "Saraksti ir vien�di"
     0 1 2 3 4                   0 1 2 3 4 5 6 7 8                "Saraksti nav vien�di"
  0 1 2 3 4 5 6 7 8                  0 1 2 3 4                    "Saraksti nav vien�di"
     2 1 2 3 4                       0 1 2 3 4                    "Saraksti nav vien�di"

*****************************************************************************************/
