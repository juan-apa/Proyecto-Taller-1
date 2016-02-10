#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include <stdio.h>

const int MAX = 80;
typedef char *String;

void String_crear(String &s); //CREA UN STRING CON SOLO UNA POSICION, QUE ES UN \0

void String_dest(String &s); //DESTRUYE EL STRING

int String_lar(String s);//DEVUELVE EL LARGO DEL STRING

void String_cop(String &s1, String s2);//COPIA EL  STRING S2 EN S1

void String_cargar(String &s);//ASUMO QUE EL STRING YA VIENE CREADO.!

void String_mostrar(String s);//IMPRIME EL STRING

void String_con(String &s1, String s2);//PONE S2 AL FINAL DE S1. S2 NO SE DESTRUYE.

void String_swp(String &s1, String &s2);//SWAPEA LOS STRINGS

bool String_men(String s1, String s2);//DEVUELVE TRUE SI EL PRIMERO ES MENOR ALFABETICAMENTE, FALSE DE LO CONTRARIO

bool String_eq(String s1, String s2);//DEVUELVE TRUE SI LOS STRINGS SON IGUALES

void FILE_levantarString(String &s, FILE* f); //levanta un string al archivo f

void FILE_bajarString(String s, FILE* f); //Baja un string al archivo f


//Funciones agregadas para el taller 1

int String_parseInt(String s); //De un String que solo contiene numeros sin separaciones, devuelve el valor en int

String String_valueOf(int n); //De un int, me devuelve un String con el n: int pasado a String

bool String_isNumeric(String s); //Devuelve true si el String solo contiene numeros.

void String_addChar(String &s, char c); //Agrega c: char al final del s: String.

int String_isVariable(String s, char var); //Devuelve (-1) si el String s no contiene el char var, de lo contrario, devuelve la posicion en la que se encuentra

String String_trim(String s); //Me deuvelve el String s sin los espacios en blanco

#endif // STRING_H_INCLUDED
