// PiPLa0302.cpp
/***********************************************************
PiPLa0302. Sast�d�t C++ programmu,
kas izdz�� no dot�s skait�u virknes lietot�ja dotu skaitli.
Skait�u virkne j�realiz� k� vienvirziena saist�tais saraksts.
************************************************************/
// Autors: Uldis Straujums (modific�ts linkedlist.cpp)
// Rad�ts: 06.03.2018.
// Main�ts: 05.03.2019. elem p�rsaukts par Node, uzlaboti koment�ri
// Main�ts: 02.03.2020  pielikta izdz��am� elementa saites saglab��ana iek� temp

#include <iostream>
#include "lvfriendly.h" // latvie�u valodas tekstu izvadei v.5(�riks Gopaks, 2012; piel�gota C+14 - U.Straujums, 2018)
using namespace std;

struct Node
{
    int num;
    Node *next;
};

int main ()
{
// first-nor�de uz pirmo elementu
// last-nor�de uz p�d�jo elementu
// p-pal�gnor�de
// prev - nor�de uz iepriek��jo elementu
// temp - izdz��am� elementa saites saglab��anai

Node *first=NULL, *last=NULL, *p;
Node *prev;
Node *temp;
int elem; // lietot�ja dots saraksta elements
int sk; // izdz��amais skaitlis

// Saraksta elementu ievad��anai tiek lietota
// t�da pat sh�ma k� teksta failu sec�gai las��anai
cout << "Ievadiet saraksta elementu, lai beigtu, ievadiet 0:" << endl;
cin >> elem;
// ievad��ana, kam�r nav sastapta 0
while (elem != 0)
{
p = new Node; // izveido elementu
p->num = elem;   // aizpilda ar nolas�to v�rt�bu
p->next = NULL; // nor�de uz n�ko�o - tuk�a!
if (first == NULL) // ja saraksts tuk�s
{
first = last = p;// gan pirmais, gan p�d�jais
                 // nor�da uz jauno elementu
}
else // ja saraksts nav tuk�s
{
last->next = p;    // pieliek gal� beidzamajam
last = last->next; // un jaunais k��st par beidzamo
};
cout << "Ievadiet saraksta elementu, lai beigtu, ievadiet 0:" << endl;
cin >> elem;
};
// saraksta izdruka
cout << "Saraksts:"<< endl;
for (p = first; p!=NULL; p=p->next)
{
cout << p->num << endl;
};
// izdz��am� skait�a dab��ana
cout << "Ievadiet izdz��amo skaitli:"<< endl;
cin >> sk;

// skait�a sk izdz��ana no saraksta
prev=NULL;
temp = new Node;
for (p = first; p!=NULL; p=p->next)
{
 if (p->num == sk)
    {
    if (prev==NULL) // j�dz�� pirmais
    {
    first = p->next;
    if (p==last) last = NULL;
    temp->next=p->next;
    delete p;
    p = temp;
    }
    else
       if (p==last) //j�dz�� p�d�jais
   {
       last = prev;
       prev->next=NULL;
       temp->next=p->next;
       delete p;
       p = temp;
   }
       else // j�dz�� ne pirmais, ne p�d�jais
       {
        prev->next=p->next;
        temp->next=p->next;
        delete p;
        p = temp;
       }
    }
else
    prev=p;
}
;
// saraksta izdruka
cout << "Saraksts:"<< endl;
for (p = first; p!=NULL; p=p->next)
{
cout << p->num << endl;
};

// saraksta izn�cin��ana
p = first;
while (p!=NULL)
{
first = first->next;
delete p;
p = first;
};
delete temp;
return 0;
}
/**** Testu pl�ns *******************************************
saraksts      izdz��amais skaitlis        paredzamais rezuult�ts
1 2 3 3 2       3 (nepirmais, nep�d�jais) 1 2 2
=============================================================
3 2             3 (pirmais)               2
=============================================================
2 3             3 (p�d�jais)              2
=============================================================
3               3  (vien�gais)            tuk�s
=============================================================
1 2 3 3 2       4  (nav sarakst�)         1 2 3 3 2
=============================================================
2 3 4 2 2       2 (gan pirmais,           3 4
                   gan nepirmais,
                  gan p�d�jais)
=============================================================
tuk�s           17                        tuk�s
************************************************************/
