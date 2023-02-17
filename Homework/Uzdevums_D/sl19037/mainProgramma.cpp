/**************************************************************************************************************************
D6.
Izveidot klasi "Skait�u rinda" (queue, pa vienu pusi ieliek, pa otru iz�em!),
kur� glab�jas mas�vs ar skaitlisk�m v�rt�b�m (int) garum� pieci un rindas elementu skaits.
Klasei izveidot ��das metodes:
(1) konstruktors,
(2) destruktors, kur� pazi�o par objekta likvid��anu un likvid�to elementu skaitu (ja likvid��anas br�d� rinda nav tuk�a),
(3) metode "enqueue", kas pievieno rindai elementu, ja t� nav pilna,
(4) metode "dequeue", kas iz�em no rindas elementu un atgrie� t� v�rt�bu,
(5) metode "Count", kas atgrie� elementu skaitu rind�,
(6) metode "IsEmpty", kas noskaidro, vai rinda ir tuk�a.
Pirms uzdevuma veik�anas prec�zi noskaidrot, ko noz�m� j�dziens rinda (queue) k� datu strukt�ra.
**************************************************************************************************************************/

#include <iostream>
using namespace std;
#include "SkaitluRinda.h"
#include "lvtocon.h"

int main()
{
        Skaitlu_rinda s;
        cout << "Rinda ir izveidota!" << endl;
        if (s.IsEmpty()) cout << "Rinda ir tuk�a!" << endl;
        else cout << "Rinda nav tuk�a!" << endl;  // Rinda ir tuk�a!
        cout << endl;

        s.enqueue(5);   // 5 _ _ _ _
        cout << "Rind� ir " << s.Count() << " elementi." << endl;   // Rind� ir 1 elementi

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tuk�a, nevar iz�emt elementu." << endl;
        else cout << "Iz�emtais elements ir: " << s.dequeue() << endl;   // Iz�emtais elements ir: 5

        cout << "Rind� ir " << s.Count() << " elementi." << endl;   // Rind� ir 0 elementi
        if (s.IsEmpty()) cout << "Rinda ir tuk�a!" << endl;
        else cout << "Rinda nav tuk�a!" << endl;  // Rinda ir tuk�a!
        cout << endl;

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tuk�a, nevar iz�emt elementu." << endl;     // ERROR!!! Rinda ir tuk�a, nevar iz�emt elementu.
        else cout << "Iz�emtais elements ir: " << s.dequeue() << endl;
        cout << endl;

        s.enqueue(10);  // 10 _ _ _ _
        s.enqueue(8);   // 10 8 _ _ _
        s.enqueue(5);   // 10 8 5 _ _
        s.enqueue(3);   // 10 8 5 3 _
        s.enqueue(11);  // 10 8 5 3 11
        cout << "Rind� ir " << s.Count() << " elementi." << endl;  // Rind� ir 5 elementi
        if (s.IsEmpty()) cout << "Rinda ir tuk�a!" << endl;
        else cout << "Rinda nav tuk�a!" << endl;  // Rinda nav tuk�a!
        cout << endl;

        s.enqueue(-5);   // ERROR!!! Skait�u rinda ir pilna, nav iesp�jams pievienot v�l vienu skaitli!
        cout << "Rind� ir " << s.Count() << " elementi." << endl;  // Rind� ir 5 elementi
        cout << endl;

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tuk�a, nevar iz�emt elementu." << endl;
        else cout << "Iz�emtais elements ir: " << s.dequeue() << endl;   // Iz�emtais elements ir: 10

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tuk�a, nevar iz�emt elementu." << endl;
        else cout << "Iz�emtais elements ir: " << s.dequeue() << endl;   // Iz�emtais elements ir: 8
        cout << endl;

        cout << "Rind� ir " << s.Count() << " elementi." << endl;  // Rind� ir 3 elementi

        if (s.IsEmpty()) cout << "ERROR!!! Rinda ir tuk�a, nevar iz�emt elementu." << endl;
        else cout << "Iz�emtais elements ir: " << s.dequeue() << endl;   // Iz�emtais elements ir: 5

        if (s.IsEmpty()) cout << "Rinda ir tuk�a!" << endl;
        else cout << "Rinda nav tuk�a!" << endl;  // Rinda nav tuk�a!
        cout << endl;
}
