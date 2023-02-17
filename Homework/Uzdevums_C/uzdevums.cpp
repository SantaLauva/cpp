/**************
Autors: Santa Lauva
        sl19037

C6. Dots natur�ls skaitlis n un veseli skait�i
a(1), a(2), ... a(n). Atrast skaitli, kur� dotaj�
virkn� atk�rtojas  visvair�k rei�u p�c k�rtas.
Cik reizes? Ja t�di skait�i ir vair�ki, tad izdruk�t liel�ko.

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
        if (atkartojums[1][i] > b)    // noskaidro kur� skaitlis atk�rtojas visbie��k
        {
            b = atkartojums[1][i];
            a = atkartojums[0][i];
            Lielakais = a;
        }
    }

    for (int j=0; j<n-1; j++)   // noskaidro vai ir vair�k k� viens skaitlis, kas atk�rtojas visbie��k.
    {
        if (b == atkartojums[1][j])
        {

            if (a == atkartojums[0][j]) continue;   // lai neapskat�tu skaitli pa�u ar sevi
            else if (a > atkartojums[0][j]) Lielakais = a;
            else Lielakais = atkartojums[0][j];
        }
    }

    cout << "Skaitlis " << Lielakais << " atk�rtojas " << b << " reizes p�c k�rtas" << endl;
}

void masivs (int n, int *skaitli)
{
    int r, k;
    int **atkartojums=new int *[2];      // deklar� 2D mas�vu ar 2 rind�m.
	for (int k=0; k<2; k++) atkartojums[k]=new int[n];

    for (int i=0; i<n-1; i++)     // cikls pirmajam sakitlim
	{
		r=1;
		for (int j=i+1; j<n; j++)     // cikls lai sal�dzin�tu ar n�ko�o blakus eso�o skaitli.
		{
			if (skaitli[i]==skaitli[j])
			r++;
			else break;
		}
        atkartojums[0][i]=skaitli[i];         // skait�i, kuri atk�rtojas
        atkartojums[1][i]=r;                  // cik reizes atk�rtojas
	}

    for (int i=0; i<n; i++)
    {
        if (atkartojums[1][i] > 1) k=0;
    }

    if (k != 0) cout << "Neviens skaitlis neatk�rtojas p�c k�rtas!" << endl;
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
			cout << "Ievadi cik skait�i b�s mas�v�: " << endl;
			cin >> n;
		}while (n<=0);

		int *skaitli = new int [n];

		cout << "Ievadi mas�va skait�us" << endl;
		for (int i=0; i<n; i++)
		cin >> skaitli[i];

		if (n == 1) cout << "Mas�vs sast�v no viena skait�a. Skaitlis neatk�rtojas" << endl;
		else masivs(n, skaitli);

		delete [] skaitli;

		cout<<"Vai turpinat (1) vai beigt (0)?"<< endl;
		cin>>ok;
	}while (ok==1);
}
