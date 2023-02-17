// PiPLa0301.cpp
/*************************************************************
PiPLa0301. Sast�d�t C++ programmu, kas noskaidro,
vai dotaj� skait�u virkn� ir sastopams lietot�ja dots skaitlis.
Skait�u virkne j�realiz� k� vienvirziena saist�tais saraksts.
**************************************************************/
// Autors: Uldis Straujums (modific�ts linkedlist.cpp)
// Rad�ts: 06.03.2018.
// Main�ts: 05.03.2019. elem p�rsaukts par Node, uzlaboti koment�ri

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
Node *first=NULL, *last=NULL, *p;
int elem; // lietot�ja dots saraksta elements
int sk; // mekl�jamais skaitlis
bool ir = false; // true, ja skaitlis sk atrasts sarakst�

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
cout << "Saraksts:" << endl;
for (p = first; p!=NULL; p=p->next)
{
cout << p->num << endl;
};
// mekl�jam� skait�a dab��ana
cout << "Ievadiet mekl�jamo skaitli:"<< endl;
cin >> sk;

// skait�a sk mekl��ana sarakst�
for (p = first; p!=NULL; p=p->next)
{
if (p->num == sk) {ir = true; break;}
};
// rezult�ta pazi�o�ana
cout << "Mekl�jamais skaitlis " << sk;
cout << (ir?" ir sarakst�": " nav sarakst�") << endl;


// saraksta izn�cin��ana
p = first;
while (p!=NULL)
{
first = first->next;
delete p;
p = first;
};
return 0;
}
/**** Testu pl�ns ********************************************
saraksts      mekl�jamais skaitlis   paredzamais rezuult�ts
1 2 3 3 2       3                     ir sarakst�
==============================================================
1 2 3 3 2       4                     nav sarakst�
==============================================================
tuk�s           17                    nav sarakst�
**************************************************************/
