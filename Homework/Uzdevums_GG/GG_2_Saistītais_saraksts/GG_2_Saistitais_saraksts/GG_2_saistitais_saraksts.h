/**********************************************************************
G2. Uzrakstît funkciju, kas salîdzina, vai divi saraksti ir vienâdi.

Realizçts kâ vienvirziena saistîtais saraksts.

GG2. Programmâ G2 iekïaut exception handling.
Un veikt vienîbtestçðanu. Programma vienîbtestçðanai atrodama mapç GG_2_Saistitais_saraksts_tests
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliecîbas nr.: sl19037
// Izstrâdes datums: 09.05.2020.

// Programmai par pamatu òemts Santas Lauvas izstrâdâtais G2 uzdevuma atrisinâjums.

struct elem
{
    int num;
    elem *next;
    elem (int n)
    {
        num = n;
        next = NULL;
    }
};

void append(elem *&first, elem *&last, int n);   // Pievienoðana saraksta beigâs
void print(elem *first);    // Funkcija saraksta izprintçðanai
void rem(elem *&first);    // Saraksta izdçðana
// Funkcija divu sarakstu salîdzinâðanai
// 1) pirmais saraksts var but garaks
// 2) saraksts var bût garaks
// 3) abi vienada garuma
bool isEqual (elem *first1, elem *first2);
