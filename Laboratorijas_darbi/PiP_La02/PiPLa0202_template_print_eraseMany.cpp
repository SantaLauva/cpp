// PiPLa0202_template_print.cpp
/**************************
PiPLa0202. Sast�d�t C++ programmu,
kas izdz�� no dot�s skait�u virknes lietot�ja dotu skaitli.
Skait�u virkne j�realiz� divos veidos,
izmantojot STL::list konteineru un izmantojot STL::vector konteineru.
***************************/
// Autors: Uldis Straujums
// Rad�ts: 20.02.2018.
// Main�ts: 25.02.2020 Pielikta funkciju veidne dzesdaudz(konteiners, elements)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#include "lvfriendly.h" // latvie�u valodas tekstu izvadei v.4(�riks Gopaks, 2012)
using namespace std;
// Funkcija dzesvekt(v, x)
// dzesvect(v, x) izdz�� no veselu skait�u vektora v  veselu skaitli x pirmaj� viet�,
// atgrie� true, ja ir izdz�sts, atgrie� false, ja nav izdz�sts
bool dzesvect(vector<int>& v, int x);
// Funkcija dzeslist(l, x) -
// dzeslist(l, x) izdz�� no veselu skait�u saraksta l  veselu skaitli x pirmaj� viet�,
// atgrie� true, ja ir izdz�sts, atgrie� false, ja nav izdz�sts
bool dzeslist(list<int>& l, int x);
// Funkciju veidne print(k) -
// print(k) izdruk� konteinera k elementus
// Funkciju veidne �auj piel�got funkciju konteinera tipam T
template <typename T>
void print(T &k)
{
	for(auto p = k.begin(); p!=k.end(); ++p)
      cout << *p << ' ';
    cout << endl << endl;
	return;
}
// Funkciju veidne dzesDaudz(k, x) -
// dzesDaudz(k, x) izdz�� no konteinera k  elementu x vis�s viet�s,
// atgrie� true, ja izdz�sts, atgrie� false, ja nav izdz�sts
// Funkciju veidne �auj piel�got funkciju gan konteinera tipam T2, gan elementa tipam T
template <class T2, class  T>
bool dzesDaudz(T2 &k, T x)
{
	bool dzests = false;
	bool repeat = true;
	do
    {
	auto  p = find(k.begin(),k.end(),x);
	if (p!=k.end()) {k.erase(p);dzests = true;}
	 else repeat = false;
    }while(repeat);

    return dzests;
}
int main()
{

int sk; // Lietot�ja dotais skaitlis
vector <int> v1 = {1, 2, 3, 2, 3};
list <int> l1 = {1, 2, 3, 2, 3};

sk=4;
cout << dzesvect(v1, sk) << endl;  // 0
print(v1);                            // 1 2 3 2 3
cout << dzesDaudz(v1, 2)<< endl;   // 1
print(v1);                         // 1 3 3
sk=3;
cout << dzesvect(v1, sk) << endl;  // 1
print(v1);                            // 1  3
sk=4;
cout << dzeslist(l1, sk) << endl;  // 0
print(l1);                            // 1 2 3 2 3
cout << dzesDaudz(l1, 2) << endl;  // 1
print(l1);                         // 1 3 3
sk=3;
cout << dzeslist(l1, sk) << endl;  // 1
print(l1);                            // 1 3

return 0;
}
// Funkcija dzesvekt(v, x) -
// dzesvect(v, x) izdz�� no veselu skait�u vektora v  veselu skaitli x,
// atgrie� true, ja ir izdz�sts, atgrie� false, ja nav izdz�sts
bool dzesvect(vector<int>& v, int x)
{
	vector<int>::iterator p = find(v.begin(),v.end(),x);
	if (p!=v.end())
	{v.erase(p); return true;}
	else return false;
}
// Funkcija dzeslist(l, x) -
// dzeslist(l, x) izdz�� no veselu skait�u saraksta l  veselu skaitli x,
// atgrie� true, ja ir izdz�sts, atgrie� false, ja nav izdz�sts
bool dzeslist(list<int>& l, int x)
{
	list<int>::iterator p = find(l.begin(),l.end(),x);
	if (p!=l.end())
	{l.erase(p); return true;}
	else return false;
}

/**** Testu pl�ns ************************************
skatiet koment�rus programm�
*****************************************************/
