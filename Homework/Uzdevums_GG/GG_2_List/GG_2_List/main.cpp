/********************************************************************
G2. Uzrakstît funkciju, kas salîdzina, vai divi saraksti ir vienâdi.

Realizçt izmantojot STL::list konteineru.

GG2. G2 uzdevuma risinâjumam pievienot exception handling un vienîbtestçðanu.
********************************************************************/

// Autors: Santa Lauva
// Studenta apliecîbas nr.: sl19037
// Datums: 10.05.2020.

// Programmai par pamatu òemts Santas Lauvas izstrâdâtais G2 uzdevuma risinâjums

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

        cout << "Ievadiet pirmâ saraksta elementus (veselus skaitïus). Ievadiet 0, lai beigtu ievadi : ";
        cin >> vertiba;
        // Vçrtîbu ievietoðana sarakstâ.
        while (vertiba!=0)
        {
            virkne1.push_back(vertiba);
            cin >> vertiba;
        }

        cout << "Ievadiet otrâ saraksta elementus (veselus skaitïus). Ievadiet 0, lai beigtu ievadi : ";
        cin >> vertiba;
        // Vçrtîbu ievietoðana sarakstâ.
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
                cout << "... Saraksti ir vienâdi!"<< endl;
            }
            else
            {
                cout << "Pirmais saraksts: ";
                print(virkne1);
                cout << "Otrais saraksts: ";
                print(virkne2);
                cout << "... Saraksti nav vienâdi!" << endl;
            }
        }
        catch (int exp)
        {
            cout << "Izskatâs, ka kâds no sarakstiem ir tukðs" << endl;
        }
        // const char * err tiek izvadîts, ja abi saraksti tukði
        catch (const char * err)
        {
            cout << err << endl;   // "Abi saraksti ir tukði. Tukði saraksti ir vienâdi!"
        }
        catch (...)
        {
            cout << "kïûda" << endl;
        }


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

