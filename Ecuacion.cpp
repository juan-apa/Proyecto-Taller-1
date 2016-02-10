#include "Ecuacion.h"


Ecuacion Ecuacion_crear(Valores v, String s){
    Ecuacion ec;
    ec.val= v;
    ec.nombre= s;
    return ec;
}
