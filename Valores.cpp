#include "Valores.h"

//Funciones
Valores Valores_parseValores(String s){
    Valores va= new Nodo;
    String_crear(va->valor);
    Valores original= va;
    int i= 0;

    while(s[i]!= '\0'){
        if(i==0){ //Me encuentro en la primer posicion, entonces empiezo a cargar ya tenga un signo o un numero
                  //Cargo sin importar, porque si fuese un signo, crearia un nuevo nodo, quedando asi el primer nodo vacio
            String_addChar(va->valor, s[i]);
        }
        else{ //No es la primer posicion
            if((s[i]>47 && s[i]<58) || s[i]=='x'){ //Caso de que sea un numero o la variable x
                //Lo guardo en la posicion en la que este de la lista
                String_addChar(va->valor, s[i]);
            }
            else{ //caso de que no sea un numero
                va->sig= new Nodo;
                va= va->sig; //Me muevo a la siguiente posicion
                String_crear(va->valor);
                String_addChar(va->valor, s[i]); //agrego el caracter en el que estoy al String del nodo en el que estoy parado
                if(s[i]== '=' && s[i+1]!='+' && s[i+1]!='-'){ //Si en el que estoy parado es un simbolo de igual, entonces me paso al siguiente nodo
                              //porque no voy a guardar nada mas en ese nodo.
                    va->sig= new Nodo;
                    va= va->sig;
                    String_crear(va->valor);
                }
            }
        }
        i++;
    }
    va->sig= NULL;//Termino la lista apuntando el ultimo nodo a NULL
    return original;
}

void Valores_mostrar(Valores v){
    int i= 1;
    while(v!=NULL){
       printf("%d: ", i);
       String_mostrar(v->valor);
       v=v->sig;
       printf("\n");
       i++;
    }
}
