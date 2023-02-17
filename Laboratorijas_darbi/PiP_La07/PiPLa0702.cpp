//PiPLa0702.cpp
/*********************************************************
PiPLa0702. Sast�d�t C++ programmu, kas noskaidro,
cik dota veselu skait�u saraksta elementu ir ar v�rt�bu, kas p�rsniedz 17.
Sarakstu realiz�t k� dinamisku vienvirziena sarakstu,
izmantojot klases ar iesp�ju preciz�t elementu tipu.
Izmantot e-kursa piem�ru list_generic.cpp.
*********************************************************/
// Autors:  Uldis Straujums
// Rad�ts:  v.1.0.; 16.04.2018. Izmantots piem�rs list_generic.cpp no
//                          e-kursa "Programmat�ras izstr�des pamati"

#include <iostream>
#include "lvfriendly.h" // latvie�u valodas tekstu izvadei v.5(�riks Gopaks, 2012; piel�gota C+14 - U.Straujums, 2018)
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
// Klase List - saist�ts vienvirziena saraksts
class List
{
protected:
 Node<T> *first, *last;
public:
 Node<T> *current;
public:
 List (); // konstruktors - izveido tuk�u sarakstu
 ~List(); // destruktors - iztuk�o sarakstu un atbr�vo atmi�u
void add_element (T n);   // pieliek mezglu saraksta beig�s
void delete_element ();   // izmet mezglu no saraksta s�kuma
bool is_empty();          // noskaidro, vai saraksts ir tuk�s
Node<T>* begin ();        // atgrie� r�d�t�ju uz saraksta s�kumu
Node<T>* end ();          // atgrie� r�d�t�ju uz saraksta beig�m (p�c p�d�j� elementa)
List& operator++(int i=0);// pab�da r�d�t�ju current uz n�ko�o elementu (ja tas ir iesp�jams)
void print();             // izdruk� saraksta elementus
// metode, kas pievienota risin�jumam list_generic.cpp
int count_Exceeding(const T limit); // apr��ina, cik ir elementu, kas p�rsniedz doto v�rt�bu limit
};

const int LIMIT = 17;
int main()
{
     List<int> v;

     v.add_element(1);
     v.add_element(18);
     v.add_element(1001);
     v.add_element(7);

    cout<<"Saraksts ar veselu skait�u elementiem - izdruka bez print metodes"<<endl;
    for (v.current=v.begin();v.current!=v.end();v++){
        cout<<v.current->val<<endl;
        }
    // Apr��ina, cik ir elementu, kas p�rsniedz doto v�rt�bu LIMIT
    cout << "Ir "<< v.count_Exceeding(LIMIT)<<
            " elementi, kas p�rsniedz v�rt�bu " << LIMIT<< endl;;


    return 0;
}
template <typename T>
List<T>::List () // konstruktors - izveido tuk�u sarakstu
  {first = last = current = NULL;};
template <typename T>
List<T>::~List() // destruktors - iztuk�o sarakstu un atbr�vo atmi�u
 {while(!is_empty()){delete_element ();};}
template <typename T>
void List<T>::add_element (T n) // pieliek mezglu saraksta beig�s
{
 Node<T> *p = new Node<T> (n);
 if (first == NULL) first = last = p;
 else last = last -> next = p;
 current =p; // maina current v�rt�bu, lai r�d�tu uz jauno elementu
};
template <typename T>
void List<T>::delete_element () // izmet mezglu no saraksta s�kuma
{
 Node<T> *p = first;
 if(!is_empty())
 { if (current == first) current = first-> next;// saglab� current v�rt�bu (nomaina uz s�kumu,ja r�d�ja uz izmetamo)
 first = first -> next;
 delete p;
 if(is_empty())last = NULL;
 }
};
template <typename T>
bool List<T>::is_empty () // noskaidro, vai saraksts ir tuk�s
 {return (first == NULL);};
template <typename T>
Node<T>* List<T>::begin () // atgrie� r�d�t�ju uz saraksta s�kumu
 {return first;};
template <typename T>
Node<T>* List<T>::end ()  // atgrie� r�d�t�ju uz saraksta beig�m (p�c p�d�j� elementa)
 {return  NULL;};
template <typename T>
List<T>& List<T>::operator++(int i=0)// pab�da r�d�t�ju current uz n�ko�o elementu (ja tas ir iesp�jams)
 { if (current!=NULL)current=current->next;
      return *this;
 };
template <typename T>
void List<T>::print()  // izdruk� saraksta elementus
 {for (current=begin();current!=end();
        current = (current!=end()?current -> next:current))
         cout<<current->val<<endl;
 };
 template <typename T>
 int List<T>::count_Exceeding(const T limit) // apr��ina, cik ir elementu, kas p�rsniedz doto v�rt�bu limit
{
 int count=0;
 for (current=begin();current!=end();
                current = (current!=end()?current -> next:current))
          if (current->val> limit) count++;
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
