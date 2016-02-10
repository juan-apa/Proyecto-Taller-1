#include "Valores.h"

//Funciones
Valores Valores_parseValores(String s){
    Valores va= new Nodo; //Tengo que crear un nuevo nodo, porque sin importar el valor de la primer posicion del String s
                          //voy a guardarlo en el primer nodo.

    String_crear(va->valor); //Tengo que crear los String del nodo nuevo, porque sino la funcion String_addChar()
                             //no anda, ya que necesita un String ya inicializado.

    Valores original= va; //Hago una copia de la posicion del primer nodo, porque despues voy a estar moviendome
                          //por la lista y pierdo la primer posicion, por lo tanto, luego de las iteraciones no voy
                          //a tener el comienzo de la lista y no lo voy a poder devolver.

    Valores anterior= va; //Creo un nuevo puntero para llevar una posicion del nodo anterior al que me encuentro parado.
                          //Como el primer nodo no tiene un nodo anterior, lo inicializo como el primero. Una vez dentro del while
                          //a medida que me muevo por los nodos, voy apuntando al nodo en el que estoy antes de moverme al siguiente.
                          //Hago este puntero, para tener en cuenta los signos despues de que pase el '=' en la ecuacion. Asi se si
                          //omitir el '+' cuando tengo "=+1", queda "= 1", asi como los espacios del '-'
                          //cuando tengo "=-1", queda "= -1" en lugar de "= - 1"
    int i= 0;

    while(s[i]!= '\0'){
        if(i==0){ //Si me encuentro en la primer posicion, entonces empiezo a cargar ya tenga un signo o un numero
                  //Cargo sin importar, porque si fuese un signo, crearia un nuevo nodo, quedando asi el primer nodo vacio
            String_addChar(va->valor, s[i]);
        }
        else{ //No es la primer posicion. Si no pongo el else, en la primer posicion se va a ejecutar lo de arriba y las siguientes lineas, lo cual es incorrecto
            if((s[i]>47 && s[i]<58) || s[i]=='x'){ //Caso de que sea un numero o la variable x
                String_addChar(va->valor, s[i]); //Lo guardo en la posicion en la que este de la lista
            }
            else{ //CASO DE QUE EN EL QUE ESTOY NO ES UN NUMERO
                anterior= va; //Guardo la posicion en la que estoy parado y luego me muevo al siguiente
                va->sig= new Nodo; //creo un nuevo nodo
                va= va->sig; //Me muevo a la siguiente posicion
                String_crear(va->valor); //Inicializo valor: String del nuevo nodo.
                //TODO preguntar a bea como hago con el destruir, tengo que destruir el String trimeado?
                //si lo tengo que destruir, entonces tengo que asignarlo a una variable antes de igualar en el if(), y despues destruirlo
                if(String_eq(String_trim(anterior->valor), "=\0")){ //Entra en este if si el nodo anterior es el "="
                    //caso de que el nodo anterior sea signo de igual, no quiero guardar el signo '+', pero si el signo '-'
                    if(s[i]== '-'){
                        String_addChar(va->valor, s[i]); //agrego el caracter en el que estoy al String del nodo en el que estoy parado
                    }
                    //si no es == '-', entonces no guardo, ya que las unicas posibilidades que tengo dentro de este if es que
                    //el nodo anterior es == "=", y ahora estoy posicionado en un '+' o un '-'
                }
                else{ //Si el nodo anterior no es el "=", entonces guardo el caracter normalmente con los espacios
                    String_addChar(va->valor, ' ');
                    String_addChar(va->valor, s[i]); //agrego el caracter en el que estoy al String del nodo en el que estoy parado
                    String_addChar(va->valor, ' ');
                }
                if(s[i]== '=' && s[i+1]!='+' && s[i+1]!='-'){
                    //Si en el que estoy parado es un simbolo de igual, entonces me paso al siguiente nodo
                    //porque no voy a guardar nada mas en ese nodo. En cambio si el siguiente simbolo es un mas o un menos
                    //no voy a insertar un nuevo nodo, porque eso lo va a hacer en la siguiente iteracion. por ejemplo si tengo
                    //2x=-1 quedarian los nodos 1->2x; 2->=; 3->(vacío); 4->-1;
                    anterior= va;
                    va->sig= new Nodo;
                    va= va->sig;
                    String_crear(va->valor);
                }
            }
        }
        i++; //Me muevo al siguiente casillero del String en el que se encuentra la ecuacion
    }
    va->sig= NULL;//Termino la lista apuntando el ultimo nodo a NULL
    return original; //Devuelvo original, porque es la posicion del primer nodo, si devuelvo va, voy a estar devolviendo solo el ultimo nodo
}

void Valores_mostrar(Valores v){
    //No hay que hacer copia del primer puntero, porque estoy pasando por valor, no por referencia, por lo tanto solo trabajo con una copia
    int i= 1;
    while(v!=NULL){
       //printf("%d:", i);
       String_mostrar(v->valor);
       v=v->sig; //Me muevo al siguiente nodo
       //printf("\n");
       i++;
    }
    printf("\nNodos: %d\n\n", i-1);
}
