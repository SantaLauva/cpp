Programmējamais uzdevums Alise
Atmiņa: 4 MB
Laiks: 0.2 second
Ievadfails: alise.in
Izvadfails: alise.out

Apraksts
Alise uzzīmēja uz papīra koku (IT izpratnē), kura mezglos bija ierakstīti unikāli skaitļi (skatīt zīmējumā Drawing on the paper). Pēc brīža Alise atcerējās savus piedzīvojumus Aizspogulijā. Viņai sagribējās uzzināt, kā koks izskatītos “otrpus spoguļa”. Palīdziet Alisei tikt ar šo uzdevumu galā un iegūt koka spoguļattēlu (skatīt Mirror image).

Dators koku saprot, ja tas ir uzdots formā:

1. katra rindiņa satur ierakstu par mezglu, kas nav lapa (iekšējais mezgls);
2. ierakstā pirmais skaitlis ir iekšējā mezgla numurs, tam seko visu bērnu numuri secībā no kreisās puses uz labo.


Ja rindiņu secība nav stingri norādīta, tad zīmējumā dotajam kokam pieraksta formas varētu būt daudzas. Piemēram, varētu būt gan

1 2 3 4 5
3 6 7
5 8
8 9 10 11

gan

5 8
3 6 7
8 9 10 11
1 2 3 4 5

Izejā koks arī tiek pierakstīts norādītajā formā, bet ar nosacījumu, ka iekšējie mezgli ir preorder secībā, t.i. ieraksts par vecāku vienmēr ir pirms ieraksta par bērnu.

Alise ir nolēmusi programmētājam kā pateicību dāvāt bučas (punkti par uzdevumu) atkarībā no paveiktā darba kvalitātes. Ja programma spēj apstrādāt kokus, kas ieejā ir tikai preorder secībā, tad var pretendēt tikai uz 8 bučām. Ja programma patvaļīgi pierakstītus kokus spēj apstrādāt laikā ilgākā par O(nlogn), tad – uz 9 bučām. Bet ja patvaļīgus kokus apstrādā ne ilgāk par O(nlogn), tad – 10 bučām, kur n ir mezglu skaits.

Alise nav pārlieku centīga koku zīmētāja. Līdz ar to kokā nebūs vairāk par 10’000 mezgliem.

Ieeja:
Ieejas failā ir nulle vai daudzas rindas ar koka iekšējo mezglu aprakstiem formā:

Parent Child_1 Child_2 ... Child_n
...
0

  Parent nosaka koka iekšējā mezgla numuru [1..999’999’999]
  Child_i nosaka < Parent > mezgla i-to bērnu (skaitlis [1..999’999’999])
  0 - Ieejas failu vienmēr noslēdz rindiņa, kurā ir tikai skaitlis 0.

Izeja:
Izejas failā jāieraksta dotā koka spoguļattēls. Kokam jābūt pierakstītam formā: iekšējie mezgli ir preorder secībā.

Piemērs 1 (ieejā preorder secība):
Ieejas faila alise.in saturs:

1 2 3 4 5
3 6 7
5 8
8 9 10 11
0

Izejas faila alise.out saturs:

1 5 4 3 2
5 8
8 11 10 9
3 7 6
0

Piemērs 2 (ieejā patvaļīga secība):
Ieejas faila alise.in saturs:

5 8
3 6 7
8 9 10 11
1 2 3 4 5
0

Izejas faila alise.out saturs:

1 5 4 3 2
5 8
8 11 10 9
3 7 6
0
