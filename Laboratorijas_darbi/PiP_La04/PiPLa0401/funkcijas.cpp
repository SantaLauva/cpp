#include <iostream>
#include "funkcijas.h"
void pievienot(Node* &first, Node* &last, int elem)
{
 Node* p;
 p = new Node; // izveido elementu
p->num = elem;   // aizpilda ar nolasîto vçrtîbu
p->next = NULL; // norâde uz nâkoğo - tukğa!
if (first == NULL) // ja saraksts tukğs
{
first = last = p;// gan pirmais, gan pçdçjais
                 // norâda uz jauno elementu
}
else // ja saraksts nav tukğs
{
last->next = p;    // pieliek galâ beidzamajam
last = last->next; // un jaunais kïûst par beidzamo
}
}
bool atrast(Node* first, int sk)
{
 bool ir = false;
 Node* p;
 if (first == NULL) throw("tukğs");
for (p = first; p!=NULL; p=p->next)
{
if (p->num == sk) {ir = true; break;}
};
return ir;
}
