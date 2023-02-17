// PiPLa0102.cpp
/**************************
PiPLa0102. P�rveidot programmu txt6get.cpp,
lai tiktu apr��in�ti dotaj� fail� eso�o simbolu bie�umi. Izdruk�t bie�umus.
Dati no faila j�nolasa pa vienai rindi�ai.
Nedr�kst dubl�t visa faila saturu operat�vaj� atmi��.
***************************/
// Autors: Uldis Straujums
// Rad�ts: 2008.02.10.
// Main�ts: 2009.02.16. Pielikti koment�ri atbilsto�i
//                      Datorikas noda�as pras�b�m
// Main�ts: 2011.02.07. Pielikts testu pl�ns
// Main�ts: 2011.10.18. Pielikts latvie�u valodas tekstu izvades nodro�in�jums(�riks Gopaks, 2011)
// Main�ts: 2013.02.11. Pieska�ots risin�jums �.Gopaka uzlabotajam lvfriendly.h saturam
// Main�ts: 02.02.2017. No faila lasa pa rindi�ai

#include <fstream>
#include <iostream>
#include "lvfriendly.h" // latvie�u valodas tekstu izvadei(�riks Gopaks, 2012)

using namespace std;

int main()
{
    fstream fin;
    string rin; // No faila nolas�t� rindi�a kodu tabul� 1257
    int biezumi[256] = {0}; // Simbola ar kodu i bie�ums ir
                            // elementa biezumi[i] v�rt�ba

    fin.open ("txt_in6.txt", ios::in);
    if (!fin){cout << "Nav faila"<< endl; return 13;}

    getline(fin, rin);
    while (fin)
    {
    for(int i=0;i<rin.length();i++)
     biezumi[(unsigned char) rin[i]]++;// Lai indekss b�tu 0-255
    getline(fin, rin);
    };
    fin.close();
    // Rezultatu izvade
    cout << endl << endl;

    cout << "Bie�umi: " << endl;
    for (int i = 0; i < 256; i++)
      if (biezumi[i] != 0)
         cout << (char)i << ' ' << biezumi[i] << endl;


    return 0;
}
/****** Testu pl�ns *************************************
txt_in6.txt          paredzamais rezult�ts
1 a a b ,,               ' '=7 ','=2 1=1 a=4 b=1 c=2 d=3 e=1 f=1
a cc
dedf  ad

----------------------------------------------------------------------
                        visiem simboliem 0
********************************************************/
