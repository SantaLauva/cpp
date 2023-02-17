// PiPLa0401test.cpp
/*************************************************************
PiPLa0402. Sastâdît C++ programmu,
kas pârbauda PiPLa0401 risinâjumâ izveidoto funkciju atrast(first, skaitlis) trîs variantos –
atrod doto skaitli, neatrod doto skaitli, saòem tukðu sarakstu.
**************************************************************/
// Autors: Uldis Straujums (modificçts linkedlist.cpp)
// Radîts: 16.03.2020.

#include <iostream>
#include "lvtocon.h"
#include "../PiPLa0401/funkcijas.cpp"
using namespace std;

void test1() {
    Node* first=NULL;
    Node* last=NULL;
    Node* p;
    pievienot(first, last, 1);
    pievienot(first, last, 2);
    cout<<(atrast(first,2)==true)<<endl;
 // saraksta iznîcinâðana
    p = first;
    while (p!=NULL)
    {
    first = first->next;
    delete p;
    p = first;
    };
}
void test2() {
    Node* first=NULL;
    Node* last=NULL;
    Node* p;
    pievienot(first, last, 1);
    pievienot(first, last, 2);
    cout<<(atrast(first,3)==false)<<endl;
// saraksta iznîcinâðana
    p = first;
    while (p!=NULL)
    {
    first = first->next;
    delete p;
    p = first;
    };
}
void test3() {
    Node* first=NULL;
    Node* last=NULL;
    try {
        atrast(first,17);
    }
    catch(const char *s) {
        cout<<1<<endl;
    }
    catch(...) {
        cout<<"Wrong Error thrown OK"<<endl;
    }
}
int main()
{
    test1();
    test2();
    test3();
}
