/*********************************************************
// lvtocon.h
�in� fail� aprakst�ti funkciju un operatoru prototipi, kas �auj
pareizi izvad�t latvie�u tekstu uz DOS konsoles.

Versija: 2.0,  paredz�ta izmanto�anai projektos
Autors: �riks Gopaks.
Datums: 07/12/2011
*********************************************************/

#ifndef TRANSLATOR_H_INCLUDED
#define TRANSLATOR_H_INCLUDED

#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

void Output (const char *s);
ostream & operator << (ostream &, const string &);
ostream & operator << (ostream &, const char *s);

#endif
