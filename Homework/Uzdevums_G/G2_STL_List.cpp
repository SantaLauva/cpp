/********************************************************************
G2. Uzrakst�t funkciju, kas sal�dzina, vai divi saraksti ir vien�di.

Realiz�t izmantojot STL::list konteineru.
********************************************************************/

// Autors: Santa Lauva
// Studenta apliec�bas nr. sl19037
// Datums: 20.03.2020.
// Main�ts 08.05.2020 - Papildin�ti koment�ri

#include <iostream>
#include<list>
#include<algorithm>
#include "lvfriendly.h"
using namespace std;

bool isEqual (list<int> a, list<int> b)
{
    if ((a.empty()) && (b.empty())) return true;  // Ja abi saraksti ir tuk�i, tie ir vien�di
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

        // Sal�dzina tuk�us sarakstus
        cout << "Tuk�i saraksti: ";
        if (isEqual(virkne3, virkne2)) cout << " ... Saraksti ir vien�di!" << endl <<endl;
        else cout << "Saraksti nav vien�di!" << endl;

        /** T�l�k tiek izveidoti tr�s saraksti
        2. saraksts vien�ds pirmajam
        3.saraksts ir visgar�kais
        4. saraksts no 1. un 2. saraksta at��iras ar vienu elementa v�rt�bu
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

        // Sal�dzina sarakstus

        // Saraksti ir vien�da garuma, ar vien�diem elementiem
        cout << "Pirmais saraksts: ";
        print(virkne1);
        cout << "Otrais saraksts: ";
        print(virkne2);
        if (isEqual(virkne1, virkne2)) cout << "... Saraksti ir vien�di!" << endl << endl;  // "Saraksti ir vien�di"
        else cout << "... Saraksti nav vien�di!" << endl << endl;

        // Pirmais saraksts �s�ks
        cout << "Pirmais saraksts: ";
        print(virkne1);
        cout << "Tre�ais saraksts: ";
        print(virkne3);
        if (isEqual(virkne1, virkne3)) cout << "... Saraksti ir vien�di!" << endl << endl;  // "Saraksti nav vien�di"
        else cout << "... Saraksti nav vien�di!" << endl << endl;

        // Otrais saraksts �s�ks
        cout << "Tre�ais saraksts: ";
        print(virkne3);
        cout << "Pirmais saraksts: ";
        print(virkne1);
        if (isEqual(virkne3, virkne1)) cout << "... Saraksti ir vien�di!" << endl << endl;  // "Saraksti nav vien�di"
        else cout << "... Saraksti nav vien�di!" << endl << endl;

        // Saraksti ir vien�da garuma, bet elementu v�rt�bas at��iras
        cout << "Pirmais saraksts: ";
        print(virkne1);
        cout << "Ceturtais saraksts: ";
        print(virkne4);
        if (isEqual(virkne1, virkne4)) cout << "... Saraksti ir vien�di!" << endl<< endl;  // "Saraksti nav vien�di"
        else cout << "... Saraksti nav vien�di!" << endl << endl;

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
