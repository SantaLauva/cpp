//PiPLa0602.cpp
/*********************************************************
PiPLa0602. Sastâdît C++ programmu, kas noskaidro,
cik dota veselu skaitïu saraksta elementu ir ar vçrtîbu, kas pârsniedz 17.
Sarakstu realizçt kâ dinamisku vienvirziena sarakstu.
*********************************************************/
// Autors:  Uldis Straujums
// Radîts:  v.1.0.; 16.04.2018. Izmantots piemçrs linked_list_class.cpp no
//                          e-kursa "Programmatûras izstrâdes pamati"

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
// Klase List - saistîts vienvirziena saraksts ar
// elementu - vesels skaitïis
class List
{
protected:
 Node *first, *last;
public:
 Node *current;
public:
 /** Konstruktora metode List() izveido tukðu sarakstu **/
 List ();
 /** Metode add_element(n) pievieno elementu n saraksta beigâs **/
 void add_element (int n);
 /** Metode delete_element() izdzçð elementu no saraksta sâkuma **/
 void delete_element ();
 /** Metode is_empty() noskaidro, vai saraksts ir tukðs **/
 bool is_empty ();
 /** Metode start() uzstâda râdîtâju current uz saraksta sâkumu **/
 void start ();
 /** Metode end() noskaidro, vai râdîtâjs current ir nonâcis aiz saraksta beigâm **/
 bool end ();
 /** Metode next() uzstâda râdîtâju current uz saraksta nâkamo elementu **/
 void next();
// Metodes, kas pieliktas linked_list_class.cpp
/** metode print() izdrukâ sarakstu **/
void print();
/** metode ~List() atbrîvo visu mezglu dinamiski pieprasîto atmiòu **/
~List();
/** metode deleteNode(i) izdzçð pirmo mezglu ar vçrtîbu i,
     atgrieþ false, ja nav atrasts mezgls ar vçrtîbu i **/
 bool deleteNode(int i);
 /** Metode count_Exceeding(limit) noskaidro, cik dota veselu skaitïu saraksta elementu ir ar vçrtîbu,
    kas pârsniedz vçrtîbu limit **/
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
    // Aprçíina, cik ir elementu, kas pârsniedz doto vçrtîbu LIMIT
    cout << "Ir "<< v.count_Exceeding(LIMIT)<<
            " elementi, kas pârsniedz vçrtîbu " << LIMIT<< endl;;


    return 0;
}
/** Konstruktora metode List() izveido tukðu sarakstu **/
 List::List () { first = last = current = NULL; };
/** Metode add_element(n) pievieno elementu n saraksta beigâs **/
void List::add_element (int n)
{
 Node *p = new Node (n);
 if (first == NULL) first = last = p;
 else last = last -> next = p;
 current =p; // maina current vçrtîbu, lai râdîtu uz jauno elementu
};
/** Metode delete_element() izdzçð elementu no saraksta sâkuma **/
void List::delete_element ()
{ // saglabâ current vçrtîbu (nomaina uz saraksta jauno sâkumu, ja râdîja uz izmetamo)
 Node *p = first;
 if(!is_empty())
 { if (current == first) current = first-> next;
 first = first -> next;
 delete p;
 if(is_empty())last = NULL;
 }
};
/** Metode is_empty() noskaidro, vai saraksts ir tukðs **/
 bool List::is_empty () { return (first == NULL); };
 /** Metode start() uzstâda râdîtâju current uz saraksta sâkumu **/
 void List::start () { current = first; };
 /** Metode end() noskaidro, vai râdîtâjs current ir nonâcis aiz saraksta beigâm **/
 bool List::end () { return (current == NULL); };
 /** Metode next() uzstâda râdîtâju current uz saraksta nâkamo elementu **/
 void List::next(){if (!end())current = current -> next;};
 /** metode print() izdrukâ sarakstu **/
void List::print()
{
   for(start();!end();next())
    cout << current->num<< endl;
   cout << endl;
}
/** metode ~List() atbrîvo visu mezglu dinamiski pieprasîto atmiòu **/
List::~List()
{
    while (!is_empty())
 {
   delete_element();
 };
 cout << "Visu mezglu atmiòa ir atbrîvota"<< endl;
};
/** metode deleteNode(i) izdzçð pirmo mezglu ar vçrtîbu i,
     atgrieþ false, ja nav atrasts mezgls ar vçrtîbu i **/
bool List::deleteNode(int i)
{
    // skaitïa i izdzçðana no saraksta
Node* p;
Node* prev=NULL;
bool ir_izdzests=false;
for (p = first; p!=NULL; p=p->next)
{
if (p->num == i)
    {
    if (prev==NULL) // jâdzçð pirmais
    {
    first = p->next;
    if (p==last) last = NULL;
    delete p;
    ir_izdzests=true;
    return ir_izdzests;
    }
    else
       if (p==last) //jâdzçð pçdçjais
   {
       last = prev;
       prev->next=NULL;
       delete p;
       ir_izdzests=true;
       return ir_izdzests;
   }
       else // jâdzçð ne pirmais, ne pçdçjais
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
/** Metode count_Exceeding(limit) noskaidro, cik dota veselu skaitïu saraksta elementu ir ar vçrtîbu,
    kas pârsniedz vçrtîbu limit **/
 int List::count_Exceeding(const int limit)
{
 int count=0;
 for (start();!end(); next())
          if (current->num > limit) count++;
 return count;
};
/**********************Testu plâns**************************
ieeja         paredzamais rezultâts
1             2
18
1001
7
===============================================================================
tukðs        tukðs
***********************************************************/
