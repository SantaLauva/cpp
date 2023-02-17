/**********************************************************************
G2. Uzrakst�t funkciju, kas sal�dzina, vai divi saraksti ir vien�di.

Realiz�ts k� vienvirziena saist�tais saraksts.

GG2. Programm� G2 iek�aut exception handling.
Un veikt vien�btest��anu. Programma vien�btest��anai atrodama map� GG_2_Saistitais_saraksts_tests
**********************************************************************/

// Autors: Santa Lauva
// Studenta apliec�bas nr.: sl19037
// Izstr�des datums: 09.05.2020.

// Programmai par pamatu �emts Santas Lauvas izstr�d�tais G2 uzdevuma atrisin�jums.

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

void append(elem *&first, elem *&last, int n);   // Pievieno�ana saraksta beig�s
void print(elem *first);    // Funkcija saraksta izprint��anai
void rem(elem *&first);    // Saraksta izd��ana
// Funkcija divu sarakstu sal�dzin��anai
// 1) pirmais saraksts var but garaks
// 2) saraksts var b�t garaks
// 3) abi vienada garuma
bool isEqual (elem *first1, elem *first2);
