/***********************
F2. Doti divi teksta faili. Uzrakst�t programmu,
kura izveido tre�o failu sekojo�i: katras pirm� faila rindi�as gal� ir pierakst�ta atbilsto�a otr� faila rindi�a.
(Ja ieejas failos rindi�u skaits ir at��ir�gs, tad p�d�j�s rindi�as tre�aj� fail� ir t�das pa�as k� fail� ar liel�ko rindi�u skaitu).
***********************/

//Autors: Santa Lauva
//Datums: 22.02.2020.

#include <iostream>
#include <fstream>
#include "lvfriendly.h"
using namespace std;

void Sapludinasana (fstream &fin1, fstream &fin2, fstream &fout) {
    string rinda;  // 1.faila rinda
    string rinda1;  // 2.faila rinda

        // Faila las��ana pa rindai
    getline(fin1, rinda);
    while (fin1)  //Kam�r pirmais fails nav beidzies
    {
        if (!fin2.eof())  // Otr� faila rinda tiek pievienota pirm� faila rindai un jaun� rinda izvad�ta tre�aj� fail�, kam�r otrais fails nav beidzies
        {
            getline(fin2, rinda1);
            fout << rinda << " " << rinda1 << endl;
        }

        if (fin2.eof() && !fin1.eof() ) // Ja pirmais fails bija gar�ks, tad turpin�s t� izvade tre�aj� fail�.
        {
            getline(fin1, rinda);
            while (fin1)
            {
                fout << rinda << endl;
                getline(fin1, rinda);
            }
        }
        if (fin1.eof() && !fin2.eof() )  // Ja otrais fails bija gar�ks, tad turpin�s otr� faila izvade tre�aj� fail�.
        {
            getline(fin2, rinda1);
            while (fin2)
            {
                fout << rinda1 << endl;
                getline(fin2, rinda1);
            }
        }
        getline(fin1, rinda);
    };
}

int main()
{
    int ok;

    fstream fin1;
    fstream fin2;
    fstream fout1; // Fails kur� pirmajam failam pievieno otro failu
    fstream fout2;  // Fails, kur� otrajam failam pievieno pirmo

do {

    fin1.open("fails1.txt", ios::in);
    if (!fin1){cout << "Nav faila"<< endl;}
    fin2.open("fails2.txt", ios::in);
    if (!fin2){cout << "Nav faila"<< endl;}
    fout1.open ("fails3.txt");
    if (!fout1){cout << "Nav faila"<< endl;}
    fout2.open ("fails4.txt");
    if (!fout2){cout << "Nav faila"<< endl;}

    Sapludinasana(fin1, fin2, fout1);
    Sapludinasana(fin2, fin1, fout2);

    fin1.close ();
    fin2.close ();
    fout1.close ();
    fout2.close ();


    cout << " Vai turpin�t (1) vai beigt (0)?" << endl;
    cin >> ok;
} while (ok == 1);
}


/******************************Testa pl�ns******************************

fails1.txt               fails2.txt                   rezult�ts

1_Saule                  2_Zvaigzne              1_Saule 2_Zvaigzne
1_Merkurs                2_Plan�ta               1_Merkurs 2_Plan�ta
1_Venera                 2_Plan�ta               1_Venera 2_Plan�ta
1_Zeme                   2_Plan�ta               1_Zeme 2_Plan�ta
1_Mars                   2_Plan�ta               1_Mars 2_Plan�ta
1_Jupiters               2_Plan�ta               1_Jupiters 2_Plan�ta
1_Saturns                                        1_Saturns
1_Ur�ns                                          1_Ur�ns
1_Nept�ns                                        1_Nept�ns

----------------------------------------------------------------------------------

fails2.txt               fails1.txt                  rezult�ts

2_Zvaigzne               1_Saule                 2_Zvaigzne 1_Saule
2_Plan�ta                1_Merkurs               2_Plan�ta 1_Merkurs
2_Plan�ta                1_Venera                2_Plan�ta 1_Venera
2_Plan�ta                1_Zeme                  2_Plan�ta 1_Zeme
2_Plan�ta                1_Mars                  2_Plan�ta 1_Mars
2_Plan�ta                1_Jupiters              2_Plan�ta 1_Jupiters
                         1_Saturns               1_Saturns
                         1_Ur�ns                 1_Ur�ns
                         1_Nept�ns               1_Nept�ns

----------------------------------------------------------------------------------

Neeksist�jo�s fails                               Nav faila

**********************************************************************************/
