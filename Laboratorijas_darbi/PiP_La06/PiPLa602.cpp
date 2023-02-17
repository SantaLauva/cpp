//PiPLa0602.cpp
/*********************************************************
PiPLa0602. Sast�d�t C++ programmu, kas noskaidro,
cik dota veselu skait�u saraksta elementu ir ar v�rt�bu, kas p�rsniedz 17.
Sarakstu realiz�t k� dinamisku vienvirziena sarakstu.
*********************************************************/
// Autors:  Uldis Straujums
// Rad�ts:  v.1.0.; 16.04.2018. Izmantots piem�rs linked_list_class.cpp no
//                          e-kursa "Programmat�ras izstr�des pamati"

#include <iostream>
#include "lvfriendly.h"
using namespace std;
// Klase Node - saraksta mezgls ar
// elementu - vesels skaitlis
class Node
{
public:
int num;
Node* next;
Node (int n) { num = n; next = NULL; };
};
// Klase List - saist�ts vienvirziena saraksts ar
// elementu - vesels skait�is
class List
{
protected:
 Node *first, *last;
public:
 Node *current;
public:
 /** Konstruktora metode List() izveido tuk�u sarakstu **/
 List ();
 /** Metode add_element(n) pievieno elementu n saraksta beig�s **/
 void add_element (int n);
 /** Metode delete_element() izdz�� elementu no saraksta s�kuma **/
 void delete_element ();
 /** Metode is_empty() noskaidro, vai saraksts ir tuk�s **/
 bool is_empty ();
 /** Metode start() uzst�da r�d�t�ju current uz saraksta s�kumu **/
 void start ();
 /** Metode end() noskaidro, vai r�d�t�js current ir non�cis aiz saraksta beig�m **/
 bool end ();
 /** Metode next() uzst�da r�d�t�ju current uz saraksta n�kamo elementu **/
 void next();
// Metodes, kas pieliktas linked_list_class.cpp
/** metode print() izdruk� sarakstu **/
void print();
/** metode ~List() atbr�vo visu mezglu dinamiski piepras�to atmi�u **/
~List();
/** metode deleteNode(i) izdz�� pirmo mezglu ar v�rt�bu i,
     atgrie� false, ja nav atrasts mezgls ar v�rt�bu i **/
 bool deleteNode(int i);
 /** Metode count_Exceeding(limit) noskaidro, cik dota veselu skait�u saraksta elementu ir ar v�rt�bu,
    kas p�rsniedz v�rt�bu limit **/
 int count_Exceeding(const int limit);
};
const int LIMIT = 17;
int main()
{
     List v;

     v.add_element(1);
     v.add_element(18);
     v.add_element(1001);
     v.add_element(7);

    v.print();
    // Apr��ina, cik ir elementu, kas p�rsniedz doto v�rt�bu LIMIT
    cout << "Ir "<< v.count_Exceeding(LIMIT)<<
            " elementi, kas p�rsniedz v�rt�bu " << LIMIT<< endl;;


    return 0;
}
/** Konstruktora metode List() izveido tuk�u sarakstu **/
 List::List () { first = last = current = NULL; };
/** Metode add_element(n) pievieno elementu n saraksta beig�s **/
void List::add_element (int n)
{
 Node *p = new Node (n);
 if (first == NULL) first = last = p;
 else last = last -> next = p;
 current =p; // maina current v�rt�bu, lai r�d�tu uz jauno elementu
};
/** Metode delete_element() izdz�� elementu no saraksta s�kuma **/
void List::delete_element ()
{ // saglab� current v�rt�bu (nomaina uz saraksta jauno s�kumu, ja r�d�ja uz izmetamo)
 Node *p = first;
 if(!is_empty())
 { if (current == first) current = first-> next;
 first = first -> next;
 delete p;
 if(is_empty())last = NULL;
 }
};
/** Metode is_empty() noskaidro, vai saraksts ir tuk�s **/
 bool List::is_empty () { return (first == NULL); };
 /** Metode start() uzst�da r�d�t�ju current uz saraksta s�kumu **/
 void List::start () { current = first; };
 /** Metode end() noskaidro, vai r�d�t�js current ir non�cis aiz saraksta beig�m **/
 bool List::end () { return (current == NULL); };
 /** Metode next() uzst�da r�d�t�ju current uz saraksta n�kamo elementu **/
 void List::next(){if (!end())current = current -> next;};
 /** metode print() izdruk� sarakstu **/
void List::print()
{
   for(start();!end();next())
    cout << current->num<< endl;
   cout << endl;
}
/** metode ~List() atbr�vo visu mezglu dinamiski piepras�to atmi�u **/
List::~List()
{
    while (!is_empty())
 {
   delete_element();
 };
 cout << "Visu mezglu atmi�a ir atbr�vota"<< endl;
};
/** metode deleteNode(i) izdz�� pirmo mezglu ar v�rt�bu i,
     atgrie� false, ja nav atrasts mezgls ar v�rt�bu i **/
bool List::deleteNode(int i)
{
    // skait�a i izdz��ana no saraksta
Node* p;
Node* prev=NULL;
bool ir_izdzests=false;
for (p = first; p!=NULL; p=p->next)
{
if (p->num == i)
    {
    if (prev==NULL) // j�dz�� pirmais
    {
    first = p->next;
    if (p==last) last = NULL;
    delete p;
    ir_izdzests=true;
    return ir_izdzests;
    }
    else
       if (p==last) //j�dz�� p�d�jais
   {
       last = prev;
       prev->next=NULL;
       delete p;
       ir_izdzests=true;
       return ir_izdzests;
   }
       else // j�dz�� ne pirmais, ne p�d�jais
       {
        prev->next=p->next;
        delete p;
        ir_izdzests=true;
        return ir_izdzests;
       }
    }
else
    prev=p;
}
return ir_izdzests;
};
/** Metode count_Exceeding(limit) noskaidro, cik dota veselu skait�u saraksta elementu ir ar v�rt�bu,
    kas p�rsniedz v�rt�bu limit **/
 int List::count_Exceeding(const int limit)
{
 int count=0;
 for (start();!end(); next())
          if (current->num > limit) count++;
 return count;
};
/**********************Testu pl�ns**************************
ieeja         paredzamais rezult�ts
1             2
18
1001
7
===============================================================================
tuk�s        tuk�s
***********************************************************/
