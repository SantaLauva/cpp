/**************************************************************************************************************************
Klasei izveidot ��das metodes:
(1) konstruktors,
(2) destruktors, kur� pazi�o par objekta likvid��anu un likvid�to elementu skaitu (ja likvid��anas br�d� rinda nav tuk�a),
(3) metode "enqueue", kas pievieno rindai elementu, ja t� nav pilna,
(4) metode "dequeue", kas iz�em no rindas elementu un atgrie� t� v�rt�bu,
(5) metode "Count", kas atgrie� elementu skaitu rind�,
(6) metode "IsEmpty", kas noskaidro, vai rinda ir tuk�a.
**************************************************************************************************************************/

#include <iostream>
using namespace std;
#include "SkaitluRinda.h"
#include "lvtocon.h"

Skaitlu_rinda::Skaitlu_rinda()
{
    n=5;
    rinda = new int[n];  // Izveido skait�u rindu, garum� n=5.
    first=-1;
    last=-1;
}

Skaitlu_rinda::~Skaitlu_rinda()
{
    cout << "Objekts ir likvid�ts!" << endl;
    if (!IsEmpty()) cout << "Likvid�to elementu skaits ir: " << Count() << endl;
    delete [] rinda;
}

void Skaitlu_rinda::enqueue (int x)
{
    if (IsEmpty()) // Ja rinda ir tuk�a, tad first un last nor�d�s uz rindas pirmo poz�ciju.
    // Ievieto�ana notiek izmantojot indeksu last (no beig�m), bet no s�kuma aizpildot pirmos elementus.
    {
        first = 0;
        last = 0;
        rinda[last] = x;
    }
    else if ((last+1)%n == first) // Ja rinda ir pilna, ievieto�anu nevar veikt.
    // indekss last p�c mod 4 ir par vienu vien�bu maz�ks nek� first.
    {
        cout << "ERROR!!! Skait�u rinda ir pilna, nav iesp�jams pievienot v�l vienu skaitli!" << endl;
    }
    else  // Ja rind� ir elementi, bet t� nav pilna,
    // tad ievietojot elementu no beig�m indekss last pab�d�s par vienu vien�bu tuv�k beig�m.
    {
        last = (last+1)%n;
        rinda[last]=x;
    }
}

int Skaitlu_rinda::dequeue()
{
    int a=first;
    // T� k� j�atgrie� v�rt�ba, tad, ja rinda b�s tuk�a,nekas nenotiks.
    if (!IsEmpty())  // Ja rinda nav tuk�a:
    {
        // Mainam first novietojumu
        if (first==last)    // Ja rind� tikai 1 elements, tad p�c izme�anas rinda b�s tuk�a un t�p�c first un last ir -1.
            {
                first = -1;
                last = -1;
            }
        else
        {
            first = (first+1)%n;     // Ja rind� ir vair�ki elementi, tad first nor�d�s uz n�ko�o ievietoto elementu.
        }

        return rinda[a];   // atgrie�am pirm� (vec�k�) elementa v�rt�bu.
    }
    return 0;
}

int Skaitlu_rinda::Count()
{
    int i=first;   // Skait��anu uzs�kam ar pirmo (vec�ko) ievietoto elementu.
    skaits=0;
    if (IsEmpty()) skaits = 0;
    else
    {
        while (i != last)
        {
            skaits ++;
            i=(i+1)%n;
        }
        skaits++; // Lai pieksiat�tu ar� p�d�jo elementu
    }
    return skaits;
}

bool Skaitlu_rinda::IsEmpty()
{
    if ((first == -1) && (last == -1)) return true;
    else return false;
}
