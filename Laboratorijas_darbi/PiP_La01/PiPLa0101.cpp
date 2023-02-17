// PiPLa0101.cpp
/**************************
PiPLa0101. Sastâdît C++ programmu, kas aprçíina,
cik reizes dotajâ teksta failâ in0101.txt sastopams lietotâja dots simbols.
Dati no faila jânolasa pa vienai rindiòai. Nedrîkst dublçt visa faila saturu operatîvajâ atmiòâ.
Izdrukât rezultâtu.
***************************/
// Autors: Uldis Straujums
// Radîts: 2010.02.17.
// Mainîts: 2011.02.07. Pielikts testu plâns
// Mainîts: 2011.10.18. Pielikts latvieðu valodas tekstu izvades nodroðinâjums(Çriks Gopaks, 2011)
// Mainîts: 2012.02.07. Uzlabots latvieðu valodas nodroðinâjums (Çriks Gopaks, 2012)
// Mainîts: 2013.02.09. Pielikta neesoða faila apstrâde
// Mainîts: 10.02.2015. Uzlaboti mainîgo vârdi, testu plânâ pielikta ' ' saskaitîðana

#include <fstream>
#include <iostream>
#include "lvfriendly.h" // latvieðu valodas tekstu izvadei v.4(Çriks Gopaks, 2012)
using namespace std;

int main()
{
fstream fin;
char d; // Lietotâja dotais simbols
string rin; // No faila nolasîtâ kârtçjâ rindiòa
int reizes; // Dotâ simbola reiþu skaits

cout << "Ievadiet simbolu, kura parâdîðanâs reiþu skaitu gribat aprçíinât" << endl;
cin.get(d);
cout << "Uzskaitâmais simbols ir " << '\'' << d << '\'' << endl;

fin.open("in0101.txt", ios::in);
if (!fin){cout << "Nav faila"<< endl; return 13;}

reizes = 0;
// Faila secîgas lasîðanas shçma realizçta rindiòâs 37-43
getline(fin, rin);
while (fin)
{
for(int i=0;i<rin.length();i++)
           if (rin[i]==d) reizes++;
getline(fin, rin);
};
fin.close ();

cout << "Simbols " << '\'' << d << '\'' << " parâdâs " << reizes << " reizes" << endl;


return 0;
}
/**** Testu plâns ************************************
in0101.txt        simbols        paredzamais rezultâts
1 a a b                a                    7
aaab c                 z                    0
a c                   ' '                   5
defa

----------------------------------------------------------------------
in0101b.txt
b c d                 ' '                   2

-----------------------------------------------------------
in0101c.txt
<tukðs fails>           A                   0
-----------------------------------------------------------
neeksistçjoðs fails                nav faila
*****************************************************/
