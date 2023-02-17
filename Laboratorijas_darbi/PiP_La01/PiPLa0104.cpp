// PiPLa0104.cpp
// Laboratorijas darbs 18.
// Standarta �ablonu bibliot�kas klases vector pielieto�ana (autors J�nis Zuters).
// U.Straujuma 04.02.2020 modific�ts risin�jums lab18a.cpp

#include <iostream>
#include <vector>
using namespace std;

void print1 (const vector<int> &arr)
{
    for (int i=0; i<arr.size(); i++) cout << arr[i] << " ";
    cout << endl;
};

void print2 (vector<int> &arr)
{
    vector<int>::iterator it;
    for (it=arr.begin(); it!=arr.end(); it++) cout << *it << " ";
    cout << endl;
};

int main()
{
    vector<int> arr;
    arr.push_back (11);
    arr.push_back (22);
    arr.push_back (33);
    arr.push_back (44);
    print1 (arr);
    arr.resize (arr.size()-1);
    print2 (arr);
    return 0;
}
/****************** Testu pl�ns **************
 Paredzamais rezult�ts
11 22 33 44
11 22 33
*********************************************/
