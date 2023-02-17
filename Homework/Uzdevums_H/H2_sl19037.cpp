/**************************************************************************************************************************************************
H2.
Dots teksta fails. Saskaitît tekstâ vârdus pçc to garumiem (1-burtîgie, 2-burtîgie utt.).
Programmai statistika pa vârdu garumiem jâsaliek tabulâ, kas realizçta kâ vârdnîca (STL map).
Programmas rezultâtâ iegût failu, kas sastâv no skaitïu pârîðiem, kurâ katram vârdu garumam dots vârdu skaits (piemçram, 1 110, 2 406, 3 632 utt.).
Par vârdiem tiek uzskatîtas simbolu virknes, kas atdalîtas ar tukðumiem un pieturzîmçm.
***************************************************************************************************************************************************/

// Autors: Santa Lauva
// Apliecîbas nr. : sl19037
// Izstrâdes datums: 16.04.2020

// Programmai par pamatu òemts e-studijâs pieejamais koda paraugs word_count.cpp

#include <iostream>
#include <map>
#include <fstream>
#include "lvfriendly.h"
using namespace std;

// Funkcija failaApstrade(fstream &fin, map<int, int> &varduGarumi) nolasa vârdus no faila, saskaita to garumu un iekïau vârdnîcâ.
// Funkcija parametri ir lasîðanas fails un vârdnîca
void failaApstrade (fstream &fin, map<int, int> &varduGarumi)
{
    string s; // No faila nolasîtâ rindiòa
    int i; // analizçjamâ simbola pozîcija nolasîtajâ rindiòâ
    int j; // vârda kârtçjâ simbola pozîcija vârdâ

    // Nolasa pirmo rindiòu
    getline(fin, s);
    while (fin)
    {
     // Apstrâdâ rindiòu
        for(i=0;i<s.size();i++)
        {
            // Atrod simbolu virkni, kas atdalîta ar tukðumiem vai pieturzîmçm
            while(!isalnum(s[i])&& i<s.size()) i++;

            if (i<s.size()) //Stâvoklis: jauna vârda sâkums
            {
                int garums=0;
                for(j=i;j<s.size();j++)
                {
                    if (isalnum(s[j]))
                    {
                        garums++;
                    }
                    else break;  // Stâvoklis: vârda beigas
                }
                // Ievieto nolasîtâ vârda garumu vârdnîcâ varduGarumi
                varduGarumi[garums] += 1;

                i=j; // sagatavojas nâkoðâ vârda meklçðanai
            }
       }
        // Nolasa nâkoðo rindiòu
        getline(fin, s);
    };
}

// Funkcija print(fstream &fout, map<int, int> &varduGarumi) izdrukâ vârdnîcas saturu rakstîðanas failâ.
// Nepiecieðamie parametri: rakstîðanas fails un vârdnîca
void print(fstream &fout, map<int, int> &varduGarumi)
{
    map<int, int>::iterator it;
    for (it=varduGarumi.begin(); it != varduGarumi.end(); ++it)
    {
        fout<< "  " << it->first << '\t' << it->second << endl;
    }
}

int main()
{
    int ok;
    fstream fin1, fin2, fin3; // fails no kura nolasa
    fstream fout1, fout2, fout3; // fails, kurâ tiks ierakstîts rezultâts
    map<int, int> varduGarumi;
    do
    {
        // Pirmais failu komplekts
            fin1.open ("teksta_fails.txt", ios::in);
            if (!fin1){cout << "Nav faila"<< endl; return 13;}

            failaApstrade(fin1, varduGarumi); // Veic teksta_fails.txt faila apstrâdi

            fout1.open ("vardu_statistika.txt", ios::out);
            if (!fout1){cout << "Nav faila"<< endl;}

            print(fout1, varduGarumi);  // Veic izdruku vardu_statistika.txt failâ
            fin1.close();
            fout1.close();

            varduGarumi.clear();  // Iztukðo map konteineru


                // Otrais failu komplekts
                fin2.open ("teksta_fails_2.txt", ios::in);
                if (!fin2){cout << "Nav faila 1"<< endl; return 13;}

                failaApstrade(fin2, varduGarumi);

                fout2.open ("vardu_statistika_2.txt", ios::out);
                if (!fout2){cout << "Nav faila 2"<< endl;}

                print(fout2, varduGarumi);

                fin2.close();
                fout2.close();

                varduGarumi.clear();

                    // Treðais failu komplekts
                    cout << "Treðais fails:" << endl;

                    fin3.open ("fails.txt", ios::in);
                    if (!fin3){cout << "Nav faila!"<< endl; return 13;}

                    failaApstrade(fin3, varduGarumi);

                    fout2.open ("statistika.txt", ios::out);
                    if (!fout3){cout << "Nav faila!"<< endl;}

                    print(fout3, varduGarumi);
                    fin3.close();
                    fout3.close();
                    varduGarumi.clear();


        cout << " Vai turpinât (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}

/************************************** TESTA PLÂNS ***************************************************

         Ievades fails                    Izvades fails                         Rezultâts, redzams izvades failâ
------------------------------------------------------------------------------------------------------------------

                                                                                            1	5
                                                                                            2	25
                                                                                            3	18
                                                                                            4	28
        teksta_fails.txt                vardu_statistika.txt                                5	17
                                                                                            6	8
                                                                                            7	7
                                                                                            8	3
                                                                                            9	2
                                                                                            10	3

------------------------------------------------------------------------------------------------------------------
                                                                                            1	2
                                                                                            2	6
                                                                                            3	1
                                                                                            4	2
                                                                                            5	1
        teksta_fails_2.txt              vardu_statistika_2.txt                              6	2
                                                                                            7	4
                                                                                            8	5
                                                                                            9	3
                                                                                            11	1
                                                                                            12	2
------------------------------------------------------------------------------------------------------------------
                                                                                     Izvade konsolç:
            fails.txt                      statistika.txt                               Nav faila!
*****************************************************************************************************************/
