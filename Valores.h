#ifndef VALORES_H_INCLUDED
#define VALORES_H_INCLUDED

//Inclusion de librerias externas
#include "String.h"

//Declaracion de estructura
typedef struct Nodo_A{ //Definicion de los nodos de la lista.
    String valor;
    Nodo_A* sig;
}Nodo;

typedef Nodo* Valores; //Esto es la lista de Strings que contiene los valores.

//Funciones
Valores Valores_parseValores(String s); //Tengo que sacarle los espacios a la ecuacion antes de ingresarla en la funcion, de lo contrario queda mal

void Valores_mostrar(Valores v);
Valores Valores_reducir(Valores v); //Devuelve la forma reducida de v

#endif // VALORES_H_INCLUDED
