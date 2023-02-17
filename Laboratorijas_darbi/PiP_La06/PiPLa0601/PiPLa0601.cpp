// PiPLa0601.cpp
/***********************************************************
PiPLa0601. Sast�d�t C++ programmu, kas izdz�� no dot�s skait�u virknes lietot�ja dotu skaitli.
Skait�u virkne j�realiz� k� vienvirziena saist�tais saraksts,
izveidojot klases Node un List
(var izmantot e-kursa piem�ru linked_list_class.cpp).
************************************************************/
// Autors: Uldis Straujums (modific�ts linked_list_class.cpp)
// Rad�ts: 01.04.2019. Izmantots PiPLa0302.cpp, mezgla izdz��ana p�rveidota par metodi deleteNode


#include <iostream>
#include "lvtocon.h" // latvie�u valodas tekstu izvadei projektos v.2.0(�riks Gopaks, 2011)
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
};

int main ()
{
int i;
int sk; // izdz��amais skaitlis
List s;

// Saraksta s elementu ievad��anai tiek lietota
// t�da pat sh�ma k� teksta failu sec�gai las��anai
cout << "Ievadiet saraksta elementu, lai beigtu, ievadiet 0:" << endl;
cin >> i;
// ievad��ana, kam�r nav sastapta 0
while (i != 0)
{
s.add_element(i);
cout << "Ievadiet saraksta elementu, lai beigtu, ievadiet 0:" << endl;
cin >> i;
};
// saraksta izdruka
s.print();

// izdz��am� skait�a dab��ana
cout << "Ievadiet izdz��amo skaitli:"<< endl;
cin >> sk;
// Izdz�� pirmo elementu ar v�rt�bu sk
if(s.deleteNode(sk))
    cout << "Elements "<<sk<< " izdz�sts"<<endl;
  else cout << "Nav elementa " << sk << endl;

/** T� var izdz�st visus elementus ar v�rt�bu sk
while(s.deleteNode(sk))
    cout << "Elements "<<sk<< " izdz�sts"<<endl;
**/
// saraksta izdruka
s.print();

// saraksta izn�cin��ana notiek, izpildot destruktoru
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
/**** Testu pl�ns *******************************************
saraksts      izdz��amais skaitlis        paredzamais rezuult�ts
1 2 3 3 2       3 (nepirmais, nep�d�jais) 1 2 3 2
=============================================================
3 2             3 (pirmais)               2
=============================================================
2 3             3 (p�d�jais)              2
=============================================================
3               3  (vien�gais)            tuk�s
=============================================================
1 2 3 3 2       4  (nav sarakst�)         1 2 3 3 2
=============================================================
2 3 4 2 2       2 (gan pirmais,           3 4
                   gan nepirmais,
                  gan p�d�jais)
=============================================================
tuk�s           17                        tuk�s
************************************************************/
