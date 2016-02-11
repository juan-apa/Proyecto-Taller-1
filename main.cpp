//Inclusion de librerias
#include <stdio.h>
//#include "String.h"
#include<windows.h>
#include "Ecuacion.h"
#include "Arbol.h"
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

    //Reconocer ecuacion
    while(true){
        String_crear(s);
        printf("Ingrese una ecuacion: ");
        String_cargar(s);
        s= String_trim(s);

        Ecuacion ec;
        ec.val= Valores_parseValores(s);
        Valores_mostrar(ec.val);
        String_dest(s);
        printf("\n\n\n");

    }

    //Reconocer comando
    Ecuacion ec;
    String pantalla;
    String comando;

    String_crear(pantalla);
    String_crear(comando);

    printf("\nIngrese un comando: ");
    String_cargar(pantalla);
    int j= 0;
    while(pantalla[j]!=' '){
        String_addChar(comando, pantalla[j]);
        j++;
    }
    if(String_eq(comando, "crear\0"))
    {
        String nombre;
        String equacion;
        String_crear(nombre);
        String_crear(equacion);

        //Leo el nombre
        while(pantalla[j]==' '){//muevo el cursor hasta el siguiente caracter, el cual va a ser el comienzo del nombre
            j++;
        }
        do{
            String_addChar(nombre, pantalla[j]);
            j++;
        }while(pantalla[j]!= ' ');

        //Leo la ecuacion
        while(pantalla[j]== ' '){//Muevo el cursor hasta que aparezca el siguiente caracter
            j++;
        }
        do{
            String_addChar(equacion, pantalla[j]);
            j++;
        }while(pantalla[j]!='\0');

        equacion= String_trim(equacion);
        ec.nombre= nombre;
        ec.val= Valores_parseValores(equacion);
        //Muestro todo cargado en la estructura Ecuacion
        printf("\n\nNombre: ");
        String_mostrar(ec.nombre);
        printf("\nEquacion: \n");
        Valores_mostrar(ec.val);

        j=0; //Reinicio el cursor
    }
    else
    {
        if(String_eq(comando, "ayuda\0")){ //INGRESA AYUDA
            while(pantalla[j]!= ' ' && pantalla[j]!= '\0'){ //Muevo el cursor hasta el siguiente caracter
                j++;
            }
            if(pantalla[j]== '\0'){ //Si no pide ayuda de un comando especifico
                //Muestro todos los comandos
            }
            else{ //Si pide ayuda de un comando especifico
                String ayudaComando;
                String_crear(ayudaComando);
                do{
                    String_addChar(ayudaComando, pantalla[j]);
                    j++;
                }while(pantalla[j]!= '\0');
                //Ahora ayudaComando tiene el comando del que quiero la ayuda
            }
        }
        else
        {
//            if() //INGRESA
//            {
//
//            }
        }
    }
    return 0;
}
