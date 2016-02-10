//Inclusion de librerias
#include <stdio.h>
#include "String.h"


int main(){
    String cargado;
    String_crear(cargado);

    printf("%d", String_lar(cargado));
    while(true){
        printf("\nIngrese un String: ");
        String_cargar(cargado);
//        printf("\n");
//        String_mostrar(cargado);
//        String_addChar(cargado, '1');
//        printf("\n");
//        String_mostrar(cargado);
        if(String_isNumeric(cargado))
            printf("true");
        else
            printf("false");
        printf("\nContiene x: ");
        int temp= String_isVariable(cargado, 'x');
        if(temp== -1)
            printf("no");
        else
            printf("%d", temp);
    }



    //test reconocer comando y luego ecuacion
//    int i = 0;
//    char temp;
//    String comando = new char[80];
//    while(cargado[i] != '\0'){
//        temp = cargado[i];
//        if((temp>64 && temp <91) || (temp>96 && temp<123)){ //caso de que la posicion del String en la que estoy parado es un caracter
//                                                            //en mayuscula o minuscula
//            //Aca voy a empezar a guardar los caracteres en un nuevo String. En este String va a quedar el comando.
//            //TODO agregar una funcion que me agregue chars a un String.
//
//        }
//    }
    String_dest(cargado);
    return 0;
}
