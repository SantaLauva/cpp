// PiPLa0103.cpp
/**************************
PiPLa0103. Sast�d�t C++ programmu, kas nokop� datus no
teksta faila in0103.txt fail� out0103.txt,
nep�rkop�jot tuk�uma simbolus.
Dati no faila j�nolasa pa vienai rindi�ai.
Nedr�kst dubl�t visa faila saturu operat�vaj� atmi��.
***************************/
// Autors: Uldis Straujums
// Rad�ts: 2008.02.10.
// Main�ts: 2010.02.16. Pielikti koment�ri atbilsto�i
//                      Datorikas fakult�tes pras�b�m, izmain�ti failu v�rdi
// Main�ts: 2011.02.07. Pielikts testu pl�ns
// Main�ts: 12.02.2015  Pielikta nesekm�ga open apstr�de
// Main�ts: 02.02.2017. No faila lasa pa rindi�ai

#include <fstream>
#include <iostream>
using namespace std;

int main ()
{
    fstream fin;
    fstream fout;
    string rin; // No faila nolas�t� rindi�a kodu tabul� 1257
    string rinout; // Rezult�ta rindi�a ierakst��anai fail�

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
/***** Testu pl�ns ***************************************
in0103.txt          paredzamais rezult�ts out0103.txt
1 a b               1ab
a cc                acc
dedf  d             dedfd

----------------------------------------------------------------------
                    nav faila
*********************************************************/
