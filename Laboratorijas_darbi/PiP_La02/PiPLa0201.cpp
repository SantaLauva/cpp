// PiPLa0201.cpp
/**************************
PiPLa0201. Sastâdît C++ programmu, kas noskaidro,
vai dotajâ skaitïu virknç ir sastopams lietotâja dots skaitlis.
Skaitïu virkne jârealizç divos veidos,
izmantojot STL::list konteineru un izmantojot STL::vector konteineru.
***************************/
// Autors: Uldis Straujums
// Radîts: 20.02.2018.

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include "lvfriendly.h" // latvieðu valodas tekstu izvadei v.4(Çriks Gopaks, 2012)
using namespace std;
// Funkcija fvect(v, x) -
// fvect(v, x) noskaidro, vai veselu skaitïu vektorâ v ir sastopams vesels skaitlis x,
// atgrieþ true, ja ir sastopams, atgrieþ false, ja nav sastopams
bool fvect(vector<int>& v, int x);
// Funkcija fvect(v, x) -
// fvect(v, x) noskaidro, vai peldoðu skaitïu vektorâ v ir sastopams peldoðs skaitlis x,
// atgrieþ true, ja ir sastopams, atgrieþ false, ja nav sastopams
bool fvect(vector<float>& v, float x);
// Funkcija flist(l, x) -
// flist(l, x) noskaidro, vai veselu skaitïu sarakstâ l ir sastopams vesels skaitlis x,
// atgrieþ true, ja ir sastopams, atgrieþ false, ja nav sastopams
bool flist(list<int>& l, int x);
// Funkcija flist(l, x) -
// flist(l, x) noskaidro, vai peldoðu skaitïu sarakstâ l ir sastopams peldoðs skaitlis x,
// atgrieþ true, ja ir sastopams, atgrieþ false, ja nav sastopams
bool flist(list<float>& l, float x);

int main()
{
int sk;    // Lietotâja dotais veselais skaitlis
float skf; // Lietotâja dotais peldoðais skaitlis
vector <int> v1 = {1, 2, 3};  // C+11 konstrukcija
vector <float> v2 = {1.2, 2.3, 3.4};
list <int> l1 = {1, 2, 3};

cout << "Ievadiet veselu skaitli:" << endl;
cin >> sk;                    // 3
cout << fvect(v1, sk)<< endl; // 1
cout << "Ievadiet veselu skaitli:" << endl;
cin >> sk;                    // 4
cout << fvect(v1, sk)<< endl; // 0
cout << "Ievadiet peldoðu skaitli:" << endl;
cin >> skf;                    // 3.4
cout << fvect(v2, skf)<< endl; // 1
cout << "Ievadiet peldoðu skaitli:" << endl;
cin >> skf;                    // 3.5
cout << fvect(v2, skf)<< endl; // 0
cout << "Ievadiet veselu skaitli:" << endl;
cin >> sk;                    // 3
cout << flist(l1, sk)<< endl; // 1
cout << "Ievadiet veselu skaitli:" << endl;
cin >> sk;                    // 4
cout << flist(l1, sk)<< endl; // 0

return 0;
}
// Funkcija fvect(v, x) -
// fvect(v, x) noskaidro, vai veselu skaitïu vektorâ v ir sastopams vesels skaitlis x,
// atgrieþ true, ja ir sastopams, atgrieþ false, ja nav sastopams
bool fvect(vector<int> &v, int x)
{
	vector<int>::iterator p = find(v.begin(),v.end(),x);
	if (p!=v.end())
	return true;
	else return false;
}
// Funkcija fvect(v, x) -
// fvect(v, x) noskaidro, vai peldoðu skaitïu vektorâ v ir sastopams peldoðs skaitlis x,
// atgrieþ true, ja ir sastopams, atgrieþ false, ja nav sastopams
bool fvect(vector<float> &v, float x)
{
	vector<float>::iterator p = find(v.begin(),v.end(),x);
	if (p!=v.end())
	return true;
	else return false;
}
// Funkcija flist(l, x) -
// flist(l, x) noskaidro, vai veselu skaitïu sarakstâ l ir sastopams vesels skaitlis x,
// atgrieþ true, ja ir sastopams, atgrieþ false, ja nav sastopams
bool flist(list<int>& l, int x)
{
	list<int>::iterator p = find(l.begin(),l.end(),x);
	if (p!=l.end())
	return true;
	else return false;
}
// Funkcija flist(l, x) -
// flist(l, x) noskaidro, vai peldoðu skaitïu sarakstâ l ir sastopams peldoðs skaitlis x,
// atgrieþ true, ja ir sastopams, atgrieþ false, ja nav sastopams
bool flist(list<float>& l, float x)
{
	list<float>::iterator p = find(l.begin(),l.end(),x);
	if (p!=l.end())
	return true;
	else return false;
}
/**** Testu plâns ************************************
skatiet komentârus programmâ
*****************************************************/
