// PiPLa0401.cpp
/*************************************************************
PiPLa0401. P�rveidot uzdevuma PiPLa0301 risin�jumu par projektu ar div�m funkcij�m:
pievienot(first, last, elem) � pievieno sarakstam elementu;
atrast(first, skaitlis) � mekl� sarakst� doto skaitli.
Funkcij� atrast(first, skaitlis) paredz�t tuk�a saraksta apstr�di,
izmetot iz��mumu situ�ciju ar argumentu �tuk�s�.
**************************************************************
PiPLa0301. Sast�d�t C++ programmu, kas noskaidro,
vai dotaj� skait�u virkn� ir sastopams lietot�ja dots skaitlis.
Skait�u virkne j�realiz� k� vienvirziena saist�tais saraksts.
**************************************************************/
// Autors: Uldis Straujums (modific�ts linkedlist.cpp)
// Rad�ts: 16.03.2020.

#include <iostream>
#include "lvtocon.h"
#include "funkcijas.h"
using namespace std;

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
pievienot(first, last, elem);
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
cout << "Mekl�jamais skaitlis " << sk << endl;
try
{
cout << (atrast(first, sk)?" ir sarakst�": " nav sarakst�") << endl;
}
catch(const char *msg)
{
  cout<<msg<<endl;
}

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
tuk�s           17                    izdruk� "tuk�s"
**************************************************************/
