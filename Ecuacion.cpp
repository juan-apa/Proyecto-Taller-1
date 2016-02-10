#include "Ecuacion.h"

String Ecuacion_getNombre(Ecuacion ec){
    return ec.nombre;
}
Valores Ecuacion_getValores(Ecuacion ec){
    return ec.val;
}

Ecuacion Ecuacion_crear(Valores v, String s){
    Ecuacion ec;
    ec.val= v;
    ec.nombre= s;
    return ec;
}

