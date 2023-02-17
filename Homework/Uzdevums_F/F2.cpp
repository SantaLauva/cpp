/***********************
F2. Doti divi teksta faili. Uzrakstît programmu,
kura izveido treðo failu sekojoði: katras pirmâ faila rindiòas galâ ir pierakstîta atbilstoða otrâ faila rindiòa.
(Ja ieejas failos rindiòu skaits ir atðíirîgs, tad pçdçjâs rindiòas treðajâ failâ ir tâdas paðas kâ failâ ar lielâko rindiòu skaitu).
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

        // Faila lasîðana pa rindai
    getline(fin1, rinda);
    while (fin1)  //Kamçr pirmais fails nav beidzies
    {
        if (!fin2.eof())  // Otrâ faila rinda tiek pievienota pirmâ faila rindai un jaunâ rinda izvadîta treðajâ failâ, kamçr otrais fails nav beidzies
        {
            getline(fin2, rinda1);
            fout << rinda << " " << rinda1 << endl;
        }

        if (fin2.eof() && !fin1.eof() ) // Ja pirmais fails bija garâks, tad turpinâs tâ izvade treðajâ failâ.
        {
            getline(fin1, rinda);
            while (fin1)
            {
                fout << rinda << endl;
                getline(fin1, rinda);
            }
        }
        if (fin1.eof() && !fin2.eof() )  // Ja otrais fails bija garâks, tad turpinâs otrâ faila izvade treðajâ failâ.
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
    fstream fout1; // Fails kurâ pirmajam failam pievieno otro failu
    fstream fout2;  // Fails, kurâ otrajam failam pievieno pirmo

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


    cout << " Vai turpinât (1) vai beigt (0)?" << endl;
    cin >> ok;
} while (ok == 1);
}


/******************************Testa plâns******************************

fails1.txt               fails2.txt                   rezultâts

1_Saule                  2_Zvaigzne              1_Saule 2_Zvaigzne
1_Merkurs                2_Plançta               1_Merkurs 2_Plançta
1_Venera                 2_Plançta               1_Venera 2_Plançta
1_Zeme                   2_Plançta               1_Zeme 2_Plançta
1_Mars                   2_Plançta               1_Mars 2_Plançta
1_Jupiters               2_Plançta               1_Jupiters 2_Plançta
1_Saturns                                        1_Saturns
1_Urâns                                          1_Urâns
1_Neptûns                                        1_Neptûns

----------------------------------------------------------------------------------

fails2.txt               fails1.txt                  rezultâts

2_Zvaigzne               1_Saule                 2_Zvaigzne 1_Saule
2_Plançta                1_Merkurs               2_Plançta 1_Merkurs
2_Plançta                1_Venera                2_Plançta 1_Venera
2_Plançta                1_Zeme                  2_Plançta 1_Zeme
2_Plançta                1_Mars                  2_Plançta 1_Mars
2_Plançta                1_Jupiters              2_Plançta 1_Jupiters
                         1_Saturns               1_Saturns
                         1_Urâns                 1_Urâns
                         1_Neptûns               1_Neptûns

----------------------------------------------------------------------------------

Neeksistçjoðs fails                               Nav faila

**********************************************************************************/
