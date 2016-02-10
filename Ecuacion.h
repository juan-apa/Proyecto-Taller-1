#ifndef ECUACION_H_INCLUDED
#define ECUACION_H_INCLUDED

//Inclusion de librerias externas
#include "Valores.h"

//Declaracion Estructura
typedef struct{
    String nombre;
    Valores val;
}Ecuacion;

//Funciones
String Ecuacion_getNombre(Ecuacion ec);

Valores Ecuacion_getValores(Ecuacion ec);



#endif // ECUACION_H_INCLUDED
