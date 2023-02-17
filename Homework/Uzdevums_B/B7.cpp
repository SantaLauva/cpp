/**************
Autors: Santa Lauva
        sl19037

B7. Dots natur�ls skaitlis n<10.
Atrast visus racion�los skait�us,
kuri atrodas interv�l� [0,1] un
kuriem sauc�js nep�rsniedz n.

Izveidots: 14.10.2019.
***************/

#include <iostream>
#include "lvfriendly.h"
using namespace std;

void Farey(int n)
{
    int a=0;
    int b=1;
    int c=1;
    int d=n;
    int p,q;
    cout << "Fareja skait�i ir: " << endl;
    cout << a << "/" << b << "  = 0" << endl;
    while (p<=n)
    {
        int k=((n+b)/d);
        p=k*c-a;
        q=k*d-b;
        a=c;
        b=d;
        c=p;
        d=q;
        cout << a << "/" << b << " = " << double(a)/b << endl;
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
