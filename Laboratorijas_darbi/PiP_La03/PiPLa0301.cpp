// PiPLa0301.cpp
/*************************************************************
PiPLa0301. Sastâdît C++ programmu, kas noskaidro,
vai dotajâ skaitïu virknç ir sastopams lietotâja dots skaitlis.
Skaitïu virkne jârealizç kâ vienvirziena saistîtais saraksts.
**************************************************************/
// Autors: Uldis Straujums (modificçts linkedlist.cpp)
// Radîts: 06.03.2018.
// Mainîts: 05.03.2019. elem pârsaukts par Node, uzlaboti komentâri

#include <iostream>
#include "lvfriendly.h" // latvieðu valodas tekstu izvadei v.5(Çriks Gopaks, 2012; pielâgota C+14 - U.Straujums, 2018)
using namespace std;

struct Node
{
    int num;
    Node *next;
};

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
p = new Node; // izveido elementu
p->num = elem;   // aizpilda ar nolasîto vçrtîbu
p->next = NULL; // norâde uz nâkoðo - tukða!
if (first == NULL) // ja saraksts tukðs
{
first = last = p;// gan pirmais, gan pçdçjais
                 // norâda uz jauno elementu
}
else // ja saraksts nav tukðs
{
last->next = p;    // pieliek galâ beidzamajam
last = last->next; // un jaunais kïûst par beidzamo
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
// meklçjamâ skaitïa dabûðana
cout << "Ievadiet meklçjamo skaitli:"<< endl;
cin >> sk;

// skaitïa sk meklçðana sarakstâ
for (p = first; p!=NULL; p=p->next)
{
if (p->num == sk) {ir = true; break;}
};
// rezultâta paziòoðana
cout << "Meklçjamais skaitlis " << sk;
cout << (ir?" ir sarakstâ": " nav sarakstâ") << endl;


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
tukðs           17                    nav sarakstâ
**************************************************************/
