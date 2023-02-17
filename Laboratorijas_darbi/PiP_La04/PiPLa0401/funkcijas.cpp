#include <iostream>
#include "funkcijas.h"
void pievienot(Node* &first, Node* &last, int elem)
{
 Node* p;
 p = new Node; // izveido elementu
p->num = elem;   // aizpilda ar nolas�to v�rt�bu
p->next = NULL; // nor�de uz n�ko�o - tuk�a!
if (first == NULL) // ja saraksts tuk�s
{
first = last = p;// gan pirmais, gan p�d�jais
                 // nor�da uz jauno elementu
}
else // ja saraksts nav tuk�s
{
last->next = p;    // pieliek gal� beidzamajam
last = last->next; // un jaunais k��st par beidzamo
}
}
bool atrast(Node* first, int sk)
{
 bool ir = false;
 Node* p;
 if (first == NULL) throw("tuk�s");
for (p = first; p!=NULL; p=p->next)
{
if (p->num == sk) {ir = true; break;}
};
return ir;
}
