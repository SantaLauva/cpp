// PiPLa0302.cpp
/***********************************************************
PiPLa0302. Sastâdît C++ programmu,
kas izdzçð no dotâs skaitïu virknes lietotâja dotu skaitli.
Skaitïu virkne jârealizç kâ vienvirziena saistîtais saraksts.
************************************************************/
// Autors: Uldis Straujums (modificçts linkedlist.cpp)
// Radîts: 06.03.2018.
// Mainîts: 05.03.2019. elem pârsaukts par Node, uzlaboti komentâri
// Mainîts: 02.03.2020  pielikta izdzçðamâ elementa saites saglabâðana iekð temp

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
// prev - norâde uz iepriekðçjo elementu
// temp - izdzçðamâ elementa saites saglabâðanai

Node *first=NULL, *last=NULL, *p;
Node *prev;
Node *temp;
int elem; // lietotâja dots saraksta elements
int sk; // izdzçðamais skaitlis

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
cout << "Saraksts:"<< endl;
for (p = first; p!=NULL; p=p->next)
{
cout << p->num << endl;
};
// izdzçðamâ skaitïa dabûðana
cout << "Ievadiet izdzçðamo skaitli:"<< endl;
cin >> sk;

// skaitïa sk izdzçðana no saraksta
prev=NULL;
temp = new Node;
for (p = first; p!=NULL; p=p->next)
{
 if (p->num == sk)
    {
    if (prev==NULL) // jâdzçð pirmais
    {
    first = p->next;
    if (p==last) last = NULL;
    temp->next=p->next;
    delete p;
    p = temp;
    }
    else
       if (p==last) //jâdzçð pçdçjais
   {
       last = prev;
       prev->next=NULL;
       temp->next=p->next;
       delete p;
       p = temp;
   }
       else // jâdzçð ne pirmais, ne pçdçjais
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

// saraksta iznîcinâðana
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
/**** Testu plâns *******************************************
saraksts      izdzçðamais skaitlis        paredzamais rezuultâts
1 2 3 3 2       3 (nepirmais, nepçdçjais) 1 2 2
=============================================================
3 2             3 (pirmais)               2
=============================================================
2 3             3 (pçdçjais)              2
=============================================================
3               3  (vienîgais)            tukðs
=============================================================
1 2 3 3 2       4  (nav sarakstâ)         1 2 3 3 2
=============================================================
2 3 4 2 2       2 (gan pirmais,           3 4
                   gan nepirmais,
                  gan pçdçjais)
=============================================================
tukðs           17                        tukðs
************************************************************/
