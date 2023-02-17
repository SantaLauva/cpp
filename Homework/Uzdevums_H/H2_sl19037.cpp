/**************************************************************************************************************************************************
H2.
Dots teksta fails. Saskait�t tekst� v�rdus p�c to garumiem (1-burt�gie, 2-burt�gie utt.).
Programmai statistika pa v�rdu garumiem j�saliek tabul�, kas realiz�ta k� v�rdn�ca (STL map).
Programmas rezult�t� ieg�t failu, kas sast�v no skait�u p�r��iem, kur� katram v�rdu garumam dots v�rdu skaits (piem�ram, 1 110, 2 406, 3 632 utt.).
Par v�rdiem tiek uzskat�tas simbolu virknes, kas atdal�tas ar tuk�umiem un pieturz�m�m.
***************************************************************************************************************************************************/

// Autors: Santa Lauva
// Apliec�bas nr. : sl19037
// Izstr�des datums: 16.04.2020

// Programmai par pamatu �emts e-studij�s pieejamais koda paraugs word_count.cpp

#include <iostream>
#include <map>
#include <fstream>
#include "lvfriendly.h"
using namespace std;

// Funkcija failaApstrade(fstream &fin, map<int, int> &varduGarumi) nolasa v�rdus no faila, saskaita to garumu un iek�au v�rdn�c�.
// Funkcija parametri ir las��anas fails un v�rdn�ca
void failaApstrade (fstream &fin, map<int, int> &varduGarumi)
{
    string s; // No faila nolas�t� rindi�a
    int i; // analiz�jam� simbola poz�cija nolas�taj� rindi��
    int j; // v�rda k�rt�j� simbola poz�cija v�rd�

    // Nolasa pirmo rindi�u
    getline(fin, s);
    while (fin)
    {
     // Apstr�d� rindi�u
        for(i=0;i<s.size();i++)
        {
            // Atrod simbolu virkni, kas atdal�ta ar tuk�umiem vai pieturz�m�m
            while(!isalnum(s[i])&& i<s.size()) i++;

            if (i<s.size()) //St�voklis: jauna v�rda s�kums
            {
                int garums=0;
                for(j=i;j<s.size();j++)
                {
                    if (isalnum(s[j]))
                    {
                        garums++;
                    }
                    else break;  // St�voklis: v�rda beigas
                }
                // Ievieto nolas�t� v�rda garumu v�rdn�c� varduGarumi
                varduGarumi[garums] += 1;

                i=j; // sagatavojas n�ko�� v�rda mekl��anai
            }
       }
        // Nolasa n�ko�o rindi�u
        getline(fin, s);
    };
}

// Funkcija print(fstream &fout, map<int, int> &varduGarumi) izdruk� v�rdn�cas saturu rakst��anas fail�.
// Nepiecie�amie parametri: rakst��anas fails un v�rdn�ca
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
    fstream fout1, fout2, fout3; // fails, kur� tiks ierakst�ts rezult�ts
    map<int, int> varduGarumi;
    do
    {
        // Pirmais failu komplekts
            fin1.open ("teksta_fails.txt", ios::in);
            if (!fin1){cout << "Nav faila"<< endl; return 13;}

            failaApstrade(fin1, varduGarumi); // Veic teksta_fails.txt faila apstr�di

            fout1.open ("vardu_statistika.txt", ios::out);
            if (!fout1){cout << "Nav faila"<< endl;}

            print(fout1, varduGarumi);  // Veic izdruku vardu_statistika.txt fail�
            fin1.close();
            fout1.close();

            varduGarumi.clear();  // Iztuk�o map konteineru


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

                    // Tre�ais failu komplekts
                    cout << "Tre�ais fails:" << endl;

                    fin3.open ("fails.txt", ios::in);
                    if (!fin3){cout << "Nav faila!"<< endl; return 13;}

                    failaApstrade(fin3, varduGarumi);

                    fout2.open ("statistika.txt", ios::out);
                    if (!fout3){cout << "Nav faila!"<< endl;}

                    print(fout3, varduGarumi);
                    fin3.close();
                    fout3.close();
                    varduGarumi.clear();


        cout << " Vai turpin�t (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}

/************************************** TESTA PL�NS ***************************************************

         Ievades fails                    Izvades fails                         Rezult�ts, redzams izvades fail�
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
                                                                                     Izvade konsol�:
            fails.txt                      statistika.txt                               Nav faila!
*****************************************************************************************************************/
