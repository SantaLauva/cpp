//PiPLa0702.cpp
/*********************************************************
PiPLa0702. Sastâdît C++ programmu, kas noskaidro,
cik dota veselu skaitïu saraksta elementu ir ar vçrtîbu, kas pârsniedz 17.
Sarakstu realizçt kâ dinamisku vienvirziena sarakstu,
izmantojot klases ar iespçju precizçt elementu tipu.
Izmantot e-kursa piemçru list_generic.cpp.
*********************************************************/
// Autors:  Uldis Straujums
// Radîts:  v.1.0.; 16.04.2018. Izmantots piemçrs list_generic.cpp no
//                          e-kursa "Programmatûras izstrâdes pamati"

#include <iostream>
#include "lvfriendly.h" // latvieðu valodas tekstu izvadei v.5(Çriks Gopaks, 2012; pielâgota C+14 - U.Straujums, 2018)
using namespace std;
template <typename T>
// Klase Node - saraksta mezgls
class Node
{
public:
T val;
Node<T> *next;
Node (T n) { val = n; next = NULL; };
};
template <typename T>
// Klase List - saistîts vienvirziena saraksts
class List
{
protected:
 Node<T> *first, *last;
public:
 Node<T> *current;
public:
 List (); // konstruktors - izveido tukðu sarakstu
 ~List(); // destruktors - iztukðo sarakstu un atbrîvo atmiòu
void add_element (T n);   // pieliek mezglu saraksta beigâs
void delete_element ();   // izmet mezglu no saraksta sâkuma
bool is_empty();          // noskaidro, vai saraksts ir tukðs
Node<T>* begin ();        // atgrieþ râdîtâju uz saraksta sâkumu
Node<T>* end ();          // atgrieþ râdîtâju uz saraksta beigâm (pçc pçdçjâ elementa)
List& operator++(int i=0);// pabîda râdîtâju current uz nâkoðo elementu (ja tas ir iespçjams)
void print();             // izdrukâ saraksta elementus
// metode, kas pievienota risinâjumam list_generic.cpp
int count_Exceeding(const T limit); // aprçíina, cik ir elementu, kas pârsniedz doto vçrtîbu limit
};

const int LIMIT = 17;
int main()
{
     List<int> v;

     v.add_element(1);
     v.add_element(18);
     v.add_element(1001);
     v.add_element(7);

    cout<<"Saraksts ar veselu skaitïu elementiem - izdruka bez print metodes"<<endl;
    for (v.current=v.begin();v.current!=v.end();v++){
        cout<<v.current->val<<endl;
        }
    // Aprçíina, cik ir elementu, kas pârsniedz doto vçrtîbu LIMIT
    cout << "Ir "<< v.count_Exceeding(LIMIT)<<
            " elementi, kas pârsniedz vçrtîbu " << LIMIT<< endl;;


    return 0;
}
template <typename T>
List<T>::List () // konstruktors - izveido tukðu sarakstu
  {first = last = current = NULL;};
template <typename T>
List<T>::~List() // destruktors - iztukðo sarakstu un atbrîvo atmiòu
 {while(!is_empty()){delete_element ();};}
template <typename T>
void List<T>::add_element (T n) // pieliek mezglu saraksta beigâs
{
 Node<T> *p = new Node<T> (n);
 if (first == NULL) first = last = p;
 else last = last -> next = p;
 current =p; // maina current vçrtîbu, lai râdîtu uz jauno elementu
};
template <typename T>
void List<T>::delete_element () // izmet mezglu no saraksta sâkuma
{
 Node<T> *p = first;
 if(!is_empty())
 { if (current == first) current = first-> next;// saglabâ current vçrtîbu (nomaina uz sâkumu,ja râdîja uz izmetamo)
 first = first -> next;
 delete p;
 if(is_empty())last = NULL;
 }
};
template <typename T>
bool List<T>::is_empty () // noskaidro, vai saraksts ir tukðs
 {return (first == NULL);};
template <typename T>
Node<T>* List<T>::begin () // atgrieþ râdîtâju uz saraksta sâkumu
 {return first;};
template <typename T>
Node<T>* List<T>::end ()  // atgrieþ râdîtâju uz saraksta beigâm (pçc pçdçjâ elementa)
 {return  NULL;};
template <typename T>
List<T>& List<T>::operator++(int i=0)// pabîda râdîtâju current uz nâkoðo elementu (ja tas ir iespçjams)
 { if (current!=NULL)current=current->next;
      return *this;
 };
template <typename T>
void List<T>::print()  // izdrukâ saraksta elementus
 {for (current=begin();current!=end();
        current = (current!=end()?current -> next:current))
         cout<<current->val<<endl;
 };
 template <typename T>
 int List<T>::count_Exceeding(const T limit) // aprçíina, cik ir elementu, kas pârsniedz doto vçrtîbu limit
{
 int count=0;
 for (current=begin();current!=end();
                current = (current!=end()?current -> next:current))
          if (current->val> limit) count++;
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
