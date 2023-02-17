/********************************************************************
G2. Uzrakst�t funkciju, kas sal�dzina, vai divi saraksti ir vien�di.

Realiz�t izmantojot STL::list konteineru.

GG2. G2 uzdevuma risin�jumam pievienot exception handling un vien�btest��anu.
********************************************************************/

// Autors: Santa Lauva
// Studenta apliec�bas nr.: sl19037
// Datums: 10.05.2020.

// Programmai par pamatu �emts Santas Lauvas izstr�d�tais G2 uzdevuma risin�jums

#include <iostream>
#include<list>
#include<algorithm>
#include "GG_2_List.h"
#include "lvtocon.h"
using namespace std;

int main()
{
    int ok;
    do
    {

        list<int> virkne1, virkne2;
        int vertiba;

        cout << "Ievadiet pirm� saraksta elementus (veselus skait�us). Ievadiet 0, lai beigtu ievadi : ";
        cin >> vertiba;
        // V�rt�bu ievieto�ana sarakst�.
        while (vertiba!=0)
        {
            virkne1.push_back(vertiba);
            cin >> vertiba;
        }

        cout << "Ievadiet otr� saraksta elementus (veselus skait�us). Ievadiet 0, lai beigtu ievadi : ";
        cin >> vertiba;
        // V�rt�bu ievieto�ana sarakst�.
        while (vertiba!=0)
        {
            virkne2.push_back(vertiba);
            cin >> vertiba;
        }

        try
        {
            if (isEqual(virkne1, virkne2))
            {
                cout << "Pirmais saraksts: ";
                print(virkne1);
                cout << "Otrais saraksts: ";
                print(virkne2);
                cout << "... Saraksti ir vien�di!"<< endl;
            }
            else
            {
                cout << "Pirmais saraksts: ";
                print(virkne1);
                cout << "Otrais saraksts: ";
                print(virkne2);
                cout << "... Saraksti nav vien�di!" << endl;
            }
        }
        catch (int exp)
        {
            cout << "Izskat�s, ka k�ds no sarakstiem ir tuk�s" << endl;
        }
        // const char * err tiek izvad�ts, ja abi saraksti tuk�i
        catch (const char * err)
        {
            cout << err << endl;   // "Abi saraksti ir tuk�i. Tuk�i saraksti ir vien�di!"
        }
        catch (...)
        {
            cout << "k��da" << endl;
        }


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

