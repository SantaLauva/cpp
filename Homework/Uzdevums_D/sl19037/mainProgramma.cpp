/**************************************************************************************************************************
D6.
Izveidot klasi "Skaitïu rinda" (queue, pa vienu pusi ieliek, pa otru izòem!),
kurâ glabâjas masîvs ar skaitliskâm vçrtîbâm (int) garumâ pieci un rindas elementu skaits.
Klasei izveidot ðâdas metodes:
(1) konstruktors,
(2) destruktors, kurð paziòo par objekta likvidçðanu un likvidçto elementu skaitu (ja likvidçðanas brîdî rinda nav tukða),
(3) metode "enqueue", kas pievieno rindai elementu, ja tâ nav pilna,
(4) metode "dequeue", kas izòem no rindas elementu un atgrieþ tâ vçrtîbu,
(5) metode "Count", kas atgrieþ elementu skaitu rindâ,
(6) metode "IsEmpty", kas noskaidro, vai rinda ir tukða.
Pirms uzdevuma veikðanas precîzi noskaidrot, ko nozîmç jçdziens rinda (queue) kâ datu struktûra.
**************************************************************************************************************************/

#include <iostream>
using namespace std;
#include "SkaitluRinda.h"
#include "lvtocon.h"

int main()
{
        Skaitlu_rinda s;
        cout << "Rinda ir izveidota!" << endl;
        if (s.IsEmpty()) cout << "Rinda ir tukða!" << endl;
        else cout << "Rinda nav tukða!" << endl;  // Rinda ir tukða!
        cout << endl;

        s.enqueue(5);   // 5 _ _ _ _
        cout << "Rindâ ir " << s.Count() << " elementi." << endl;   // Rindâ ir 1 elementi

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tukða, nevar izòemt elementu." << endl;
        else cout << "Izòemtais elements ir: " << s.dequeue() << endl;   // Izòemtais elements ir: 5

        cout << "Rindâ ir " << s.Count() << " elementi." << endl;   // Rindâ ir 0 elementi
        if (s.IsEmpty()) cout << "Rinda ir tukða!" << endl;
        else cout << "Rinda nav tukða!" << endl;  // Rinda ir tukða!
        cout << endl;

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tukða, nevar izòemt elementu." << endl;     // ERROR!!! Rinda ir tukða, nevar izòemt elementu.
        else cout << "Izòemtais elements ir: " << s.dequeue() << endl;
        cout << endl;

        s.enqueue(10);  // 10 _ _ _ _
        s.enqueue(8);   // 10 8 _ _ _
        s.enqueue(5);   // 10 8 5 _ _
        s.enqueue(3);   // 10 8 5 3 _
        s.enqueue(11);  // 10 8 5 3 11
        cout << "Rindâ ir " << s.Count() << " elementi." << endl;  // Rindâ ir 5 elementi
        if (s.IsEmpty()) cout << "Rinda ir tukða!" << endl;
        else cout << "Rinda nav tukða!" << endl;  // Rinda nav tukða!
        cout << endl;

        s.enqueue(-5);   // ERROR!!! Skaitïu rinda ir pilna, nav iespçjams pievienot vçl vienu skaitli!
        cout << "Rindâ ir " << s.Count() << " elementi." << endl;  // Rindâ ir 5 elementi
        cout << endl;

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tukða, nevar izòemt elementu." << endl;
        else cout << "Izòemtais elements ir: " << s.dequeue() << endl;   // Izòemtais elements ir: 10

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tukða, nevar izòemt elementu." << endl;
        else cout << "Izòemtais elements ir: " << s.dequeue() << endl;   // Izòemtais elements ir: 8
        cout << endl;

        cout << "Rindâ ir " << s.Count() << " elementi." << endl;  // Rindâ ir 3 elementi

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tukða, nevar izòemt elementu." << endl;
        else cout << "Izòemtais elements ir: " << s.dequeue() << endl;   // Izòemtais elements ir: 5

        if (s.IsEmpty()) cout << "Rinda ir tukða!" << endl;
        else cout << "Rinda nav tukða!" << endl;  // Rinda nav tukða!
        cout << endl;
}
