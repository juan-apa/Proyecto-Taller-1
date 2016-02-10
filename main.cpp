//Inclusion de librerias
#include <stdio.h>
//#include "String.h"
#include<windows.h>
#include "Ecuacion.h"
//TODO hacer modulo del arbol de ecuaciones


//Funciones para primer entrega
void ayuda(){ //TODO preguntar si tengo que hacer sobrecarga o hago un switch case aca adentro segun lo que ingrese
    /*Para poner el texto en un color determinado bajo windows
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Save current attributes
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
    printf("This is some nice COLORFUL text, isn't it?");

    // Restore original attributes
    SetConsoleTextAttribute(hConsole, saved_attributes);
    printf("Back to normal");

    printf("\x1b[31m Hello World \x1b[0m\n");
    printf("\033[22;34mHello, world!\033[0m");*/

    printf("----------\n|Comandos|\n----------\n");

    printf("\ncrear nombreFuncion ax + b= 0  --> Crea la funcion ingresada con el nombre nombreFuncion");

    printf("\nlistar nombreFuncion  --> ");//TODO preguntar a bea, incosistencia en la explicacion de ejemplos y el ejemplo de consola

    printf("\nreducir nombreFuncion nuevoNombreReducida  --> Reduce la ecuacion nombreFuncion y la guarda en nuevoNombreReducida");

    printf("\nresolver nombreFuncion  --> Resuelve la ecuacion nombreFuncion");

    printf("\nsumar nombreFuncionA nombreFuncionB nuevoNombreSumado  -->Suma las funciones nombreFuncionA y nombreFuncionB, y guarda el resultado en NuevoNombreSumado");

    printf("\nguardar nombreFuncion nombreArchivo.dat  -->Guarda la ecuacion NombreFuncion en el archivo nombreArchivo.dat");

    printf(""); //TODO preguntar a bea que onda con el comando recuperar

    printf("\n salir  -->Finaliza la ejecucion del programa");
}


int main(){
    //ayuda();
    String s;
    String_crear(s);

//    printf("%d", String_lar(cargado));
//    while(true){
//        printf("\nIngrese un String: ");
//        String_cargar(cargado);
//        if(String_isNumeric(cargado))
//            printf("true");
//        else
//            printf("false");
//        printf("\nContiene x: ");
//        int temp= String_isVariable(cargado, 'x');
//        if(temp== -1)
//            printf("no");
//        else
//            printf("%d", temp);
//    }



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



//Reconocer ecuacion
    printf("Ingrese una ecuacion: ");
    String_cargar(s);
    Ecuacion ec, original;
    original.val= ec.val; //Hago el original, para no perder la posicion del puntero original, porque despues lo muevo por cualquier lado
    ec.val= new Nodo;
    original.val= ec.val;
    ec.val->sig= new Nodo;
    ec.val->valor= "";
    ec.val->sig->sig= new Nodo;
    ec.val->sig->valor= "";
    ec.val->sig->sig->sig= new Nodo;
    ec.val->sig->sig->valor= "";
    ec.val->sig->sig->sig->valor= "";



    int i= 0;
    while(s[i]!= '\0'){
        if(i==0){ //Me encuentro en la primer posicion, entonces empiezo a cargar aunque tenga signo
            String_addChar(ec.val->valor, s[i]);
        }
        else{ //No es l;a primer posicion
            if((s[i]>47 && s[i]<58) || s[i]=='x'){ //Caso de que sea un numero
                //Lo guardo en la posicion en la que este de la lista
                String_addChar(ec.val->valor, s[i]);
            }
            else{ //caso de que no sea un numero
                ec.val= ec.val->sig; //Me muevo a la siguiente posicion
                String_addChar(ec.val->valor, s[i]); //agrego el caracter en el que estoy al String del nodo en el que estoy parado
                if(s[i]== '=') //Si en el que estoy parado es un simbolo de igual, entonces me paso al siguiente nodo
                              //porque no voy a guardar nada mas en ese nodo.
                    ec.val= ec.val->sig;
            }
        }
        i++;
    }

    printf("\nMostrar por nodos los Strings\n1-> ");
    String_mostrar(original.val->valor);
    printf("\n2-> ");
    String_mostrar(original.val->sig->valor);
    printf("\n3-> ");
    String_mostrar(original.val->sig->sig->valor);
    printf("\n4-> ");
    String_mostrar(original.val->sig->sig->sig->valor);



//    ec.nombre= "pepe\0";
//    String_mostrar(ec.nombre);
//    ec.val->sig= NULL;
//    ec.val->valor= "1x";
//    ec.val->sig= new Nodo;
//    ec.val->sig->valor= "32";
//    String_mostrar(ec.val->valor);
//    String_mostrar(ec.val->sig->valor);



    String_dest(s);
    return 0;
}
