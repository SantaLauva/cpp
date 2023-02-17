// PiPLa0103.cpp
/**************************
PiPLa0103. Sastâdît C++ programmu, kas nokopç datus no
teksta faila in0103.txt failâ out0103.txt,
nepârkopçjot tukðuma simbolus.
Dati no faila jânolasa pa vienai rindiòai.
Nedrîkst dublçt visa faila saturu operatîvajâ atmiòâ.
***************************/
// Autors: Uldis Straujums
// Radîts: 2008.02.10.
// Mainîts: 2010.02.16. Pielikti komentâri atbilstoði
//                      Datorikas fakultâtes prasîbâm, izmainîti failu vârdi
// Mainîts: 2011.02.07. Pielikts testu plâns
// Mainîts: 12.02.2015  Pielikta nesekmîga open apstrâde
// Mainîts: 02.02.2017. No faila lasa pa rindiòai

#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
    fstream fin;
    fstream fout;
    string rin; // No faila nolasîtâ rindiòa kodu tabulâ 1257
    string rinout; // Rezultâta rindiòa ierakstîðanai failâ

    fin.open("in0103.txt", ios::in);
    if (!fin){cout << "Nav faila"<< endl; return 13;}
    fout.open("out0103.txt", ios::out);

    rinout="";
    getline(fin, rin);
    while (fin)
    {
        for(int i=0;i<rin.length();i++)
          if (rin[i]!= ' ') rinout+=rin[i];
        fout << rinout<<endl;
        rinout="";
        getline(fin, rin);
    };

    fin.close ();
    fout.close ();

    return 0;
}
/***** Testu plâns ***************************************
in0103.txt          paredzamais rezultâts out0103.txt
1 a b               1ab
a cc                acc
dedf  d             dedfd

----------------------------------------------------------------------
                    nav faila
*********************************************************/
