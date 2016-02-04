//Inclusion de librerias
#include <stdio.h>
#include "String.h"


int main()
{
    //Que me de el numero ascii de un caracter ingresado
//    printf("ingrese un caracter: ");
//    char car;
//    scanf("%c", &car);
//    fflush(stdin);
//    printf("\nEl numero ascii del caracter ingresado es: %d", car);


    String cargado;
    String_crear(cargado);
    printf("Ingrese un String: ");
    String_cargar(cargado);
    if(String_isNumeric(cargado))
        printf("true");
    else
        printf("false");

//    printf("El String ingresado es: ");
//    String_mostrar(cargado);
//    printf("valor numerico es: %d", String_parseInt(cargado));

    printf("\nIngrese un numero: ");
    int num=0;
    scanf("%d", &num);
    String_valueOf(123);


    String_dest(cargado);


    //test reconocer comando y luego ecuacion
    int i = 0;
    char temp;
    String comando = new char[80];
    while(cargado[i] != '\0'){
        temp = cargado[i];
        if((temp>64 && temp <91) || (temp>96 && temp<123)){ //caso de que la posicion del String en la que estoy parado es un caracter
                                                            //en mayuscula o minuscula
            //Aca voy a empezar a guardar los caracteres en un nuevo String. En este String va a quedar el comando.
            //TODO agregar una funcion que me agregue chars a un String.

        }
    }
}
