/**************
Autors: Santa Lauva
        sl19037

C6. Dots naturâls skaitlis n un veseli skaitïi
a(1), a(2), ... a(n). Atrast skaitli, kurð dotajâ
virknç atkârtojas  visvairâk reiþu pçc kârtas.
Cik reizes? Ja tâdi skaitïi ir vairâki, tad izdrukât lielâko.

Izveidots: 06.11.2019.
***************/

#include <iostream>
#include "lvfriendly.h"
using namespace std;

void funkcija (int n, int **atkartojums)
{
    int Lielakais, a, b=0;
    for (int i=0; i<n-1; i++)
    {
        if (atkartojums[1][i] > b)    // noskaidro kurð skaitlis atkârtojas visbieþâk
        {
            b = atkartojums[1][i];
            a = atkartojums[0][i];
            Lielakais = a;
        }
    }

    for (int j=0; j<n-1; j++)   // noskaidro vai ir vairâk kâ viens skaitlis, kas atkârtojas visbieþâk.
    {
        if (b == atkartojums[1][j])
        {

            if (a == atkartojums[0][j]) continue;   // lai neapskatîtu skaitli paðu ar sevi
            else if (a > atkartojums[0][j]) Lielakais = a;
            else Lielakais = atkartojums[0][j];
        }
    }

    cout << "Skaitlis " << Lielakais << " atkârtojas " << b << " reizes pçc kârtas" << endl;
}

void masivs (int n, int *skaitli)
{
    int r, k;
    int **atkartojums=new int *[2];      // deklarç 2D masîvu ar 2 rindâm.
	for (int k=0; k<2; k++) atkartojums[k]=new int[n];

    for (int i=0; i<n-1; i++)     // cikls pirmajam sakitlim
	{
		r=1;
		for (int j=i+1; j<n; j++)     // cikls lai salîdzinâtu ar nâkoðo blakus esoðo skaitli.
		{
			if (skaitli[i]==skaitli[j])
			r++;
			else break;
		}
        atkartojums[0][i]=skaitli[i];         // skaitïi, kuri atkârtojas
        atkartojums[1][i]=r;                  // cik reizes atkârtojas
	}

    for (int i=0; i<n; i++)
    {
        if (atkartojums[1][i] > 1) k=0;
    }

    if (k != 0) cout << "Neviens skaitlis neatkârtojas pçc kârtas!" << endl;
    else funkcija(n, atkartojums);

    for(int i = 0; i < n; i++)  delete[] atkartojums[i];
    delete[] atkartojums;
}

int main()
{
	int ok;
	int n;

	do
	{
		do
		{
			cout << "Ievadi cik skaitïi bûs masîvâ: " << endl;
			cin >> n;
		}while (n<=0);

		int *skaitli = new int [n];

		cout << "Ievadi masîva skaitïus" << endl;
		for (int i=0; i<n; i++)
		cin >> skaitli[i];

		if (n == 1) cout << "Masîvs sastâv no viena skaitïa. Skaitlis neatkârtojas" << endl;
		else masivs(n, skaitli);

		delete [] skaitli;

		cout<<"Vai turpinat (1) vai beigt (0)?"<< endl;
		cin>>ok;
	}while (ok==1);
}
