/**********************************************************************
G2. Uzrakstît funkciju, kas salîdzina, vai divi saraksti ir vienâdi.

Realizçts kâ vienvirziena saistîtais saraksts.

GG2. Programmâ G2 iekïaut exception handling.
Un veikt vienîbtestçðanu. Programma vienîbtestçðanai atrodama mapç GG_2_Saistitais_saraksts_tests
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliecîbas nr.: sl19037
// Izstrâdes datums: 09.05.2020.

// Programmai par pamatu òemts Santas Lauvas izstrâdâtais G2 uzdevuma atrisinâjums.

#include <iostream>
#include "GG_2_saistitais_saraksts.h"
#include "lvtocon.h"
using namespace std;

int main()
{
    int ok;
    do
    {
        elem *first1=NULL,*last1;  // Pirmajam sarakstam
        elem *first2=NULL,*last2;  // Otrajam sarakstam

        int vertiba;  // Lietotâja ievadîta vçrtîba

        cout << "Ievadiet pirmâ saraksta elementus (veselus skaitïus). Ievadiet 0, lai beigtu ievadi : ";
        cin >> vertiba;
        // Vçrtîbu ievietoðana sarakstâ.
        while (vertiba!=0)
        {
            append(first1, last1, vertiba);
            cin >> vertiba;
        }

        cout << "Ievadiet otrâ saraksta elementus (veselus skaitïus). Ievadiet 0, lai beigtu ievadi : ";
        cin >> vertiba;
        // Vçrtîbu ievietoðana sarakstâ.
        while (vertiba!=0)
        {
            append(first2, last2, vertiba);
            cin >> vertiba;
        }

        try
        {
            if (isEqual(first1, first2))
            {
                cout << "Pirmais saraksts: ";
                print(first1);
                cout << "Otrais saraksts: ";
                print(first2);
                cout << "... Saraksti ir vienâdi!"<< endl;
            }
            else
            {
                cout << "Pirmais saraksts: ";
                print(first1);
                cout << "Otrais saraksts: ";
                print(first2);
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

        rem(first1);
        rem(first2);


        cout << " Vai turpinât (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}


/********************************************* Testa plâns ******************************************************

  Pirmais saraksts                Otrais saraksts                              Rezultâts

      "Tukðs"                         "Tukðs"               "Abi saraksti ir tukði. Tukði saraksti ir vienâdi!"
     1 2 3 4 5                       1 2 3 4 5                            "Saraksti ir vienâdi"
     1 2 3 4 5                   1 2 3 4 5 6 7 8                          "Saraksti nav vienâdi"
  1 2 3 4 5 6 7 8                    1 2 3 4 5                            "Saraksti nav vienâdi"
     2 2 3 4 5                       1 2 3 4 5                            "Saraksti nav vienâdi"
     1 2 3 4 5                        "Tukðs"                   "Izskatâs, ka kâds no sarakstiem ir tukðs"
      "Tukðs"                        1 2 3 4 5                  "Izskatâs, ka kâds no sarakstiem ir tukðs"

*****************************************************************************************************************/
