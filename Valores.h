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


#endif // VALORES_H_INCLUDED
