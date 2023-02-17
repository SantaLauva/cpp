/**************************************************************************************************************************
Klasei izveidot ðâdas metodes:
(1) konstruktors,
(2) destruktors, kurð paziòo par objekta likvidçðanu un likvidçto elementu skaitu (ja likvidçðanas brîdî rinda nav tukða),
(3) metode "enqueue", kas pievieno rindai elementu, ja tâ nav pilna,
(4) metode "dequeue", kas izòem no rindas elementu un atgrieþ tâ vçrtîbu,
(5) metode "Count", kas atgrieþ elementu skaitu rindâ,
(6) metode "IsEmpty", kas noskaidro, vai rinda ir tukða.
**************************************************************************************************************************/

#include <iostream>
using namespace std;
#include "SkaitluRinda.h"
#include "lvtocon.h"

Skaitlu_rinda::Skaitlu_rinda()
{
    n=5;
    rinda = new int[n];  // Izveido skaitïu rindu, garumâ n=5.
    first=-1;
    last=-1;
}

Skaitlu_rinda::~Skaitlu_rinda()
{
    cout << "Objekts ir likvidçts!" << endl;
    if (!IsEmpty()) cout << "Likvidçto elementu skaits ir: " << Count() << endl;
    delete [] rinda;
}

void Skaitlu_rinda::enqueue (int x)
{
    if (IsEmpty()) // Ja rinda ir tukða, tad first un last norâdîs uz rindas pirmo pozîciju.
    // Ievietoðana notiek izmantojot indeksu last (no beigâm), bet no sâkuma aizpildot pirmos elementus.
    {
        first = 0;
        last = 0;
        rinda[last] = x;
    }
    else if ((last+1)%n == first) // Ja rinda ir pilna, ievietoðanu nevar veikt.
    // indekss last pçc mod 4 ir par vienu vienîbu mazâks nekâ first.
    {
        cout << "ERROR!!! Skaitïu rinda ir pilna, nav iespçjams pievienot vçl vienu skaitli!" << endl;
    }
    else  // Ja rindâ ir elementi, bet tâ nav pilna,
    // tad ievietojot elementu no beigâm indekss last pabîdâs par vienu vienîbu tuvâk beigâm.
    {
        last = (last+1)%n;
        rinda[last]=x;
    }
}

int Skaitlu_rinda::dequeue()
{
    int a=first;
    // Tâ kâ jâatgrieþ vçrtîba, tad, ja rinda bûs tukða,nekas nenotiks.
    if (!IsEmpty())  // Ja rinda nav tukða:
    {
        // Mainam first novietojumu
        if (first==last)    // Ja rindâ tikai 1 elements, tad pçc izmeðanas rinda bûs tukða un tâpçc first un last ir -1.
            {
                first = -1;
                last = -1;
            }
        else
        {
            first = (first+1)%n;     // Ja rindâ ir vairâki elementi, tad first norâdîs uz nâkoðo ievietoto elementu.
        }

        return rinda[a];   // atgrieþam pirmâ (vecâkâ) elementa vçrtîbu.
    }
    return 0;
}

int Skaitlu_rinda::Count()
{
    int i=first;   // Skaitîðanu uzsâkam ar pirmo (vecâko) ievietoto elementu.
    skaits=0;
    if (IsEmpty()) skaits = 0;
    else
    {
        while (i != last)
        {
            skaits ++;
            i=(i+1)%n;
        }
        skaits++; // Lai pieksiatîtu arî pçdçjo elementu
    }
    return skaits;
}

bool Skaitlu_rinda::IsEmpty()
{
    if ((first == -1) && (last == -1)) return true;
    else return false;
}
