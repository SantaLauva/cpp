/**
Izveidot klasi "Skaitïu rinda"
Klasei izveidot ðâdas metodes:
(1) konstruktors,
(2) destruktors, kurð paziòo par objekta likvidçðanu un likvidçto elementu skaitu (ja likvidçðanas brîdî rinda nav tukða),
(3) metode "enqueue", kas pievieno rindai elementu, ja tâ nav pilna,
(4) metode "dequeue", kas izòem no rindas elementu un atgrieþ tâ vçrtîbu,
(5) metode "Count", kas atgrieþ elementu skaitu rindâ,
(6) metode "IsEmpty", kas noskaidro, vai rinda ir tukða.
**/

class Skaitlu_rinda
{
private:
    int n;
    int first, last;
    int skaits;
    int* rinda;
public:
    Skaitlu_rinda ();
    ~Skaitlu_rinda ();
void enqueue (int x);
int dequeue ();
int Count ();
bool IsEmpty ();
};
