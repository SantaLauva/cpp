// PiPLa0102.cpp
/**************************
PiPLa0102. Pârveidot programmu txt6get.cpp,
lai tiktu aprçíinâti dotajâ failâ esoðo simbolu bieþumi. Izdrukât bieþumus.
Dati no faila jânolasa pa vienai rindiòai.
Nedrîkst dublçt visa faila saturu operatîvajâ atmiòâ.
***************************/
// Autors: Uldis Straujums
// Radîts: 2008.02.10.
// Mainîts: 2009.02.16. Pielikti komentâri atbilstoði
//                      Datorikas nodaïas prasîbâm
// Mainîts: 2011.02.07. Pielikts testu plâns
// Mainîts: 2011.10.18. Pielikts latvieðu valodas tekstu izvades nodroðinâjums(Çriks Gopaks, 2011)
// Mainîts: 2013.02.11. Pieskaòots risinâjums Ç.Gopaka uzlabotajam lvfriendly.h saturam
// Mainîts: 02.02.2017. No faila lasa pa rindiòai

#include <fstream>
#include <iostream>
#include "lvfriendly.h" // latvieðu valodas tekstu izvadei(Çriks Gopaks, 2012)

using namespace std;

int main()
{
    fstream fin;
    string rin; // No faila nolasîtâ rindiòa kodu tabulâ 1257
    int biezumi[256] = {0}; // Simbola ar kodu i bieþums ir
                            // elementa biezumi[i] vçrtîba

    fin.open ("txt_in6.txt", ios::in);
    if (!fin){cout << "Nav faila"<< endl; return 13;}

    getline(fin, rin);
    while (fin)
    {
    for(int i=0;i<rin.length();i++)
     biezumi[(unsigned char) rin[i]]++;// Lai indekss bûtu 0-255
    getline(fin, rin);
    };
    fin.close();
    // Rezultatu izvade
    cout << endl << endl;

    cout << "Bieþumi: " << endl;
    for (int i = 0; i < 256; i++)
      if (biezumi[i] != 0)
         cout << (char)i << ' ' << biezumi[i] << endl;


    return 0;
}
/****** Testu plâns *************************************
txt_in6.txt          paredzamais rezultâts
1 a a b ,,               ' '=7 ','=2 1=1 a=4 b=1 c=2 d=3 e=1 f=1
a cc
dedf  ad

----------------------------------------------------------------------
                        visiem simboliem 0
********************************************************/
