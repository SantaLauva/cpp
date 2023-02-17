/***********************************************************
PiPLa0303. Sastâdît C++ programmu,
kas aprçíina vârdu bieþumu vârdu sarakstâ, lietojot STL klasi map.
Vârdu saraksts realizçts kâ konstants STL saraksts.
************************************************************/
// Autors: Jânis Zuters
// Radîts: 04.03.2019
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
/********** Testu plâns ***************
skatiet komentârus programmâ
**************************************/
