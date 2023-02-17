// PiPLa0401.cpp
/*************************************************************
PiPLa0401. Pârveidot uzdevuma PiPLa0301 risinâjumu par projektu ar divâm funkcijâm:
pievienot(first, last, elem) – pievieno sarakstam elementu;
atrast(first, skaitlis) – meklç sarakstâ doto skaitli.
Funkcijâ atrast(first, skaitlis) paredzçt tukða saraksta apstrâdi,
izmetot izòçmumu situâciju ar argumentu “tukðs”.
**************************************************************
PiPLa0301. Sastâdît C++ programmu, kas noskaidro,
vai dotajâ skaitïu virknç ir sastopams lietotâja dots skaitlis.
Skaitïu virkne jârealizç kâ vienvirziena saistîtais saraksts.
**************************************************************/
// Autors: Uldis Straujums (modificçts linkedlist.cpp)
// Radîts: 16.03.2020.

#include <iostream>
#include "lvtocon.h"
#include "funkcijas.h"
using namespace std;

int main ()
{
// first-norâde uz pirmo elementu
// last-norâde uz pçdçjo elementu
// p-palîgnorâde
Node *first=NULL, *last=NULL, *p;
int elem; // lietotâja dots saraksta elements
int sk; // meklçjamais skaitlis
bool ir = false; // true, ja skaitlis sk atrasts sarakstâ

// Saraksta elementu ievadîðanai tiek lietota
// tâda pat shçma kâ teksta failu secîgai lasîðanai
cout << "Ievadiet saraksta elementu, lai beigtu, ievadiet 0:" << endl;
cin >> elem;
// ievadîðana, kamçr nav sastapta 0
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
// meklçjamâ skaitïa dabûðana
cout << "Ievadiet meklçjamo skaitli:"<< endl;
cin >> sk;

// skaitïa sk meklçðana sarakstâ
for (p = first; p!=NULL; p=p->next)
{
if (p->num == sk) {ir = true; break;}
};
// rezultâta paziòoðana
cout << "Meklçjamais skaitlis " << sk << endl;
try
{
cout << (atrast(first, sk)?" ir sarakstâ": " nav sarakstâ") << endl;
}
catch(const char *msg)
{
  cout<<msg<<endl;
}

// saraksta iznîcinâðana
p = first;
while (p!=NULL)
{
first = first->next;
delete p;
p = first;
};
return 0;
}

/**** Testu plâns ********************************************
saraksts      meklçjamais skaitlis   paredzamais rezuultâts
1 2 3 3 2       3                     ir sarakstâ
==============================================================
1 2 3 3 2       4                     nav sarakstâ
==============================================================
tukðs           17                    izdrukâ "tukðs"
**************************************************************/
