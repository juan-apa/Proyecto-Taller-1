#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "Ecuacion.h"

typedef struct Nodo_B{
    Ecuacion ec;
    Nodo_B* izq;
    Nodo_B* der;
}Nodo_ar;

typedef Nodo_ar* Arbol;



#endif // ARBOL_H_INCLUDED
