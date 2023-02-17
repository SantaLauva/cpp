// PiPLa0101.cpp
/**************************
PiPLa0101. Sast�d�t C++ programmu, kas apr��ina,
cik reizes dotaj� teksta fail� in0101.txt sastopams lietot�ja dots simbols.
Dati no faila j�nolasa pa vienai rindi�ai. Nedr�kst dubl�t visa faila saturu operat�vaj� atmi��.
Izdruk�t rezult�tu.
***************************/
// Autors: Uldis Straujums
// Rad�ts: 2010.02.17.
// Main�ts: 2011.02.07. Pielikts testu pl�ns
// Main�ts: 2011.10.18. Pielikts latvie�u valodas tekstu izvades nodro�in�jums(�riks Gopaks, 2011)
// Main�ts: 2012.02.07. Uzlabots latvie�u valodas nodro�in�jums (�riks Gopaks, 2012)
// Main�ts: 2013.02.09. Pielikta neeso�a faila apstr�de
// Main�ts: 10.02.2015. Uzlaboti main�go v�rdi, testu pl�n� pielikta ' ' saskait��ana

#include <fstream>
#include <iostream>
#include "lvfriendly.h" // latvie�u valodas tekstu izvadei v.4(�riks Gopaks, 2012)
using namespace std;

int main()
{
fstream fin;
char d; // Lietot�ja dotais simbols
string rin; // No faila nolas�t� k�rt�j� rindi�a
int reizes; // Dot� simbola rei�u skaits

cout << "Ievadiet simbolu, kura par�d��an�s rei�u skaitu gribat apr��in�t" << endl;
cin.get(d);
cout << "Uzskait�mais simbols ir " << '\'' << d << '\'' << endl;

fin.open("in0101.txt", ios::in);
if (!fin){cout << "Nav faila"<< endl; return 13;}

reizes = 0;
// Faila sec�gas las��anas sh�ma realiz�ta rindi��s 37-43
getline(fin, rin);
while (fin)
{
for(int i=0;i<rin.length();i++)
           if (rin[i]==d) reizes++;
getline(fin, rin);
};
fin.close ();

cout << "Simbols " << '\'' << d << '\'' << " par�d�s " << reizes << " reizes" << endl;


return 0;
}
/**** Testu pl�ns ************************************
in0101.txt        simbols        paredzamais rezult�ts
1 a a b                a                    7
aaab c                 z                    0
a c                   ' '                   5
defa

----------------------------------------------------------------------
in0101b.txt
b c d                 ' '                   2

-----------------------------------------------------------
in0101c.txt
<tuk�s fails>           A                   0
-----------------------------------------------------------
neeksist�jo�s fails                nav faila
*****************************************************/
