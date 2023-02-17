/***********************************************************
PiPLa0303. Sast�d�t C++ programmu,
kas apr��ina v�rdu bie�umu v�rdu sarakst�, lietojot STL klasi map.
V�rdu saraksts realiz�ts k� konstants STL saraksts.
************************************************************/
// Autors: J�nis Zuters
// Rad�ts: 04.03.2019
/// calculating word frequency statistics for a list of words
#include<iostream>
#include<list>
#include<map>
using namespace std;
int main() {
    list<string> s={"life","is","ok","but","life","is","life"};
    map<string,int> m;
    for(const auto &i: s) {
        m[i]+=1;
    }
    for(const auto &p: m) {
        cout<<p.first<<" "<<p.second<<endl;  // but  1
                                             // is   2
                                             // life 3
                                             // ok   1
    }

}
/********** Testu pl�ns ***************
skatiet koment�rus programm�
**************************************/
