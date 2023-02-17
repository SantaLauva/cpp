/**************
Autors: Santa Lauva
        sl19037

B7. Dots natur�ls skaitlis n<10.
Atrast visus racion�los skait�us,
kuri atrodas interv�l� [0,1] un
kuriem sauc�js nep�rsniedz n.

Izveidots: 06.10.2019.
***************/

#include <iostream>
#include "lvfriendly.h"
using namespace std;

int LKD (int m, int s)    // Apr��ina liel�ko kop�go dal�t�ju, izmantojot Eikl�da algoritmu.
{
    if (s == 0)
        return m;
    return LKD(s, m % s);
}

void Farey(int n)
{
    int sk, sauc;
    cout << "Fareja skait�i ir: \n" << "0/1  = 0" << endl;
    for (sk=1; sk<=n; sk++)
    {
        for (sauc=n; sauc>=sk; sauc--)
        {
            if (LKD(sk,sauc) != 1) continue;
            cout << sk << "/" << sauc << "  = " << (double)sk/sauc << endl;
        }
    }
}

int main()
{
    int ok;
    int n;
    do
    {
        cout << "L�dzu ievadi natur�li skaitli, kas ir maz�ks par 10" << endl;
        cin >> n;
        while ((n>=10) || (n<0) || (n==0))
        {
            cout << "L�dzu ievadiet skaitli, kas ir liel�ks par 0 un maz�ks par 10" << endl;
            cin >> n;
        }
        Farey(n);

        cout << "Vai turpin�t (1) vai beigt (0)?" << endl;
        cin >> ok;
    } while (ok == 1);
}

/***** Testa pl�ns *********
Ievade            Izvade
  -5           L�dzu ievadi n
   0           L�dzu ievadi n
   3           0; 1/3; 1/2; 2/3; 1
   5           0; 1/5; 1/4; 1/3; 2/5; 1/2; 3/5; 2/3; 3/4; 4/5; 1
***************************/
