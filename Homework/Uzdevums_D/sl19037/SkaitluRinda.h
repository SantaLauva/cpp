/**
Izveidot klasi "Skait�u rinda"
Klasei izveidot ��das metodes:
(1) konstruktors,
(2) destruktors, kur� pazi�o par objekta likvid��anu un likvid�to elementu skaitu (ja likvid��anas br�d� rinda nav tuk�a),
(3) metode "enqueue", kas pievieno rindai elementu, ja t� nav pilna,
(4) metode "dequeue", kas iz�em no rindas elementu un atgrie� t� v�rt�bu,
(5) metode "Count", kas atgrie� elementu skaitu rind�,
(6) metode "IsEmpty", kas noskaidro, vai rinda ir tuk�a.
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
