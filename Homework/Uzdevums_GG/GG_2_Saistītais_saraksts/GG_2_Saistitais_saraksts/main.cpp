/**********************************************************************
G2. Uzrakst�t funkciju, kas sal�dzina, vai divi saraksti ir vien�di.

Realiz�ts k� vienvirziena saist�tais saraksts.

GG2. Programm� G2 iek�aut exception handling.
Un veikt vien�btest��anu. Programma vien�btest��anai atrodama map� GG_2_Saistitais_saraksts_tests
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliec�bas nr.: sl19037
// Izstr�des datums: 09.05.2020.

// Programmai par pamatu �emts Santas Lauvas izstr�d�tais G2 uzdevuma atrisin�jums.

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

        int vertiba;  // Lietot�ja ievad�ta v�rt�ba

        cout << "Ievadiet pirm� saraksta elementus (veselus skait�us). Ievadiet 0, lai beigtu ievadi : ";
        cin >> vertiba;
        // V�rt�bu ievieto�ana sarakst�.
        while (vertiba!=0)
        {
            append(first1, last1, vertiba);
            cin >> vertiba;
        }

        cout << "Ievadiet otr� saraksta elementus (veselus skait�us). Ievadiet 0, lai beigtu ievadi : ";
        cin >> vertiba;
        // V�rt�bu ievieto�ana sarakst�.
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
                cout << "... Saraksti ir vien�di!"<< endl;
            }
            else
            {
                cout << "Pirmais saraksts: ";
                print(first1);
                cout << "Otrais saraksts: ";
                print(first2);
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

        rem(first1);
        rem(first2);


        cout << " Vai turpin�t (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}


/********************************************* Testa pl�ns ******************************************************

  Pirmais saraksts                Otrais saraksts                              Rezult�ts

      "Tuk�s"                         "Tuk�s"               "Abi saraksti ir tuk�i. Tuk�i saraksti ir vien�di!"
     1 2 3 4 5                       1 2 3 4 5                            "Saraksti ir vien�di"
     1 2 3 4 5                   1 2 3 4 5 6 7 8                          "Saraksti nav vien�di"
  1 2 3 4 5 6 7 8                    1 2 3 4 5                            "Saraksti nav vien�di"
     2 2 3 4 5                       1 2 3 4 5                            "Saraksti nav vien�di"
     1 2 3 4 5                        "Tuk�s"                   "Izskat�s, ka k�ds no sarakstiem ir tuk�s"
      "Tuk�s"                        1 2 3 4 5                  "Izskat�s, ka k�ds no sarakstiem ir tuk�s"

*****************************************************************************************************************/
