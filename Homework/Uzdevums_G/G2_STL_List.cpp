/********************************************************************
G2. Uzrakstît funkciju, kas salîdzina, vai divi saraksti ir vienâdi.

Realizçt izmantojot STL::list konteineru.
********************************************************************/

// Autors: Santa Lauva
// Studenta apliecîbas nr. sl19037
// Datums: 20.03.2020.
// Mainîts 08.05.2020 - Papildinâti komentâri

#include <iostream>
#include<list>
#include<algorithm>
#include "lvfriendly.h"
using namespace std;

bool isEqual (list<int> a, list<int> b)
{
    if ((a.empty()) && (b.empty())) return true;  // Ja abi saraksti ir tukði, tie ir vienâdi
    else if (a.empty()) return false;
    else if (b.empty()) return false;

    if (a.size() != b.size()) return false;
    else
    {
        list<int> :: iterator i;
        list<int> :: iterator j;
        j=b.begin();
        for (i=a.begin(); i!=a.end(); ++i)
        {
            if (*i != *j) return false;
            else ++j;
        }
    }
    return true;
}

void print(list<int> a)
{
    list<int> :: iterator i;
    for (i=a.begin(); i!=a.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

int main()
{
    int ok;

    do
    {

        list<int> virkne1 = {0, 1, 2, 3, 4};
        list<int> virkne2, virkne3, virkne4;

        // Salîdzina tukðus sarakstus
        cout << "Tukði saraksti: ";
        if (isEqual(virkne3, virkne2)) cout << " ... Saraksti ir vienâdi!" << endl <<endl;
        else cout << "Saraksti nav vienâdi!" << endl;

        /** Tâlâk tiek izveidoti trîs saraksti
        2. saraksts vienâds pirmajam
        3.saraksts ir visgarâkais
        4. saraksts no 1. un 2. saraksta atðíiras ar vienu elementa vçrtîbu
        **/

        for (int i=0; i<5; i++)
        {
            virkne2.push_back(i);
            virkne4.push_back(i);
        }
        virkne4.front()=2;

        for (int i=0; i<9; i++)
        {
            virkne3.push_back(i);
        }

        // Salîdzina sarakstus

        // Saraksti ir vienâda garuma, ar vienâdiem elementiem
        cout << "Pirmais saraksts: ";
        print(virkne1);
        cout << "Otrais saraksts: ";
        print(virkne2);
        if (isEqual(virkne1, virkne2)) cout << "... Saraksti ir vienâdi!" << endl << endl;  // "Saraksti ir vienâdi"
        else cout << "... Saraksti nav vienâdi!" << endl << endl;

        // Pirmais saraksts îsâks
        cout << "Pirmais saraksts: ";
        print(virkne1);
        cout << "Treðais saraksts: ";
        print(virkne3);
        if (isEqual(virkne1, virkne3)) cout << "... Saraksti ir vienâdi!" << endl << endl;  // "Saraksti nav vienâdi"
        else cout << "... Saraksti nav vienâdi!" << endl << endl;

        // Otrais saraksts îsâks
        cout << "Treðais saraksts: ";
        print(virkne3);
        cout << "Pirmais saraksts: ";
        print(virkne1);
        if (isEqual(virkne3, virkne1)) cout << "... Saraksti ir vienâdi!" << endl << endl;  // "Saraksti nav vienâdi"
        else cout << "... Saraksti nav vienâdi!" << endl << endl;

        // Saraksti ir vienâda garuma, bet elementu vçrtîbas atðíiras
        cout << "Pirmais saraksts: ";
        print(virkne1);
        cout << "Ceturtais saraksts: ";
        print(virkne4);
        if (isEqual(virkne1, virkne4)) cout << "... Saraksti ir vienâdi!" << endl<< endl;  // "Saraksti nav vienâdi"
        else cout << "... Saraksti nav vienâdi!" << endl << endl;

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
