// PiPLa0202_template_print.cpp
/**************************
PiPLa0202. Sastâdît C++ programmu,
kas izdzçð no dotâs skaitïu virknes lietotâja dotu skaitli.
Skaitïu virkne jârealizç divos veidos,
izmantojot STL::list konteineru un izmantojot STL::vector konteineru.
***************************/
// Autors: Uldis Straujums
// Radîts: 20.02.2018.
// Mainîts: 25.02.2020 Pielikta funkciju veidne dzesdaudz(konteiners, elements)

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#include "lvfriendly.h" // latvieðu valodas tekstu izvadei v.4(Çriks Gopaks, 2012)
using namespace std;
// Funkcija dzesvekt(v, x)
// dzesvect(v, x) izdzçð no veselu skaitïu vektora v  veselu skaitli x pirmajâ vietâ,
// atgrieþ true, ja ir izdzçsts, atgrieþ false, ja nav izdzçsts
bool dzesvect(vector<int>& v, int x);
// Funkcija dzeslist(l, x) -
// dzeslist(l, x) izdzçð no veselu skaitïu saraksta l  veselu skaitli x pirmajâ vietâ,
// atgrieþ true, ja ir izdzçsts, atgrieþ false, ja nav izdzçsts
bool dzeslist(list<int>& l, int x);
// Funkciju veidne print(k) -
// print(k) izdrukâ konteinera k elementus
// Funkciju veidne ïauj pielâgot funkciju konteinera tipam T
template <typename T>
void print(T &k)
{
	for(auto p = k.begin(); p!=k.end(); ++p)
      cout << *p << ' ';
    cout << endl << endl;
	return;
}
// Funkciju veidne dzesDaudz(k, x) -
// dzesDaudz(k, x) izdzçð no konteinera k  elementu x visâs vietâs,
// atgrieþ true, ja izdzçsts, atgrieþ false, ja nav izdzçsts
// Funkciju veidne ïauj pielâgot funkciju gan konteinera tipam T2, gan elementa tipam T
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

int sk; // Lietotâja dotais skaitlis
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
// dzesvect(v, x) izdzçð no veselu skaitïu vektora v  veselu skaitli x,
// atgrieþ true, ja ir izdzçsts, atgrieþ false, ja nav izdzçsts
bool dzesvect(vector<int>& v, int x)
{
	vector<int>::iterator p = find(v.begin(),v.end(),x);
	if (p!=v.end())
	{v.erase(p); return true;}
	else return false;
}
// Funkcija dzeslist(l, x) -
// dzeslist(l, x) izdzçð no veselu skaitïu saraksta l  veselu skaitli x,
// atgrieþ true, ja ir izdzçsts, atgrieþ false, ja nav izdzçsts
bool dzeslist(list<int>& l, int x)
{
	list<int>::iterator p = find(l.begin(),l.end(),x);
	if (p!=l.end())
	{l.erase(p); return true;}
	else return false;
}

/**** Testu plâns ************************************
skatiet komentârus programmâ
*****************************************************/
