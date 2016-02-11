#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "Ecuacion.h"

//Definicion de la estructura
typedef struct Nodo_B{
    Ecuacion ecuacion;
    Nodo_B* izq;
    Nodo_B* der;
}Nodo_Arbol;

typedef Nodo_Arbol* Arbol;

//Funciones



#endif // ARBOL_H_INCLUDED
