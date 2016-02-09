#include "String.h"

void String_crear(String &s)
{
    s=new char[1];
    s[0]='\0';
}

void String_dest(String &s)
{
    delete[] s;
    s=NULL;
}

int String_lar(String s)
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    return i;
}

void String_cop(String &s1, String s2)
{
	int i=0;
	int largo= String_lar(s2)+1;//por el \0
	String_dest(s1);
    s1= new char[largo];
    while(s2[i]!='\0')
    {
        s1[i]=s2[i];
        i++;
	}
	s1[i]='\0';
}

void String_cargar(String &s)//ASUMO QUE EL STRING YA VIENE CREADO.!
{
    char *saux = new char[MAX];
    char aux;
    int i=0;
    scanf("%c", &aux);
    while(aux!='\n' && i<MAX-1)
    {
        saux[i]=aux;
        scanf("%c", &aux);
        i++;
    }
    saux[i]='\0';
    String_cop(s, saux);
    String_dest(saux);
}

void String_mostrar(String s)
{
    for(int i=0; i<String_lar(s); i++)
    {
        printf("%c", s[i]);
    }
}

void String_con(String &s1, String s2)//PONE S2 AL FINAL DE S1. S2 NO SE DESTRUYE.
{
    char* saux= new char[MAX];
    int i=0, j=0;
    for(i=0; i<String_lar(s1); i++)
    {
        saux[i]=s1[i];
    }
    while(i<MAX-1 && s2[j]!='\0')
    {
        saux[i]=s2[j];
        i++;
        j++;
    }
    saux[i]='\0';
    String_cop(s1, saux);
    String_dest(saux);
}

void String_swp(String &s1, String &s2)
{
    /*if(strDin_lar(s1)>strDin_lar(s2))
    {
        String saux= new char[strDin_lar(s1)];
    }
    else
    {
        String saux= new char[strDin_lar(s2)];
    }*/
    String saux;
    String_crear(saux);
    String_cop(saux, s1);
    String_cop(s1, s2);
    String_cop(s2, saux);
    String_dest(saux);
}

bool String_men(String s1, String s2)
{
    int i=0;
    bool menor=false, caso=false;
    while(s1[i]!='\0' && s2[i]!='\0' && caso==false)
    {
        if(s1[i]!=s2[i])
        {
            caso=true;
        }
        i++;
    }
    if(caso==true)
    {
        if(s1[i-1]<s2[i-1])
        {
            menor=true; //s1<s2
        }
        else
        {
            menor=false; //s1>s2
        }
    }
    if(caso==false)
    {
        if(s1[i]=='\0' && s2[i]!='\0') menor=true;
        if(s1[i]!='\0' && s2[i]=='\0') menor=false;
        //if(texto0[i]=='\0' && texto1[i]=='\0') caso=3;
    }
    return menor;
}

bool String_eq(String s1, String s2)
{
    int i=0;
    bool igual=true;
    if(String_lar(s1)==String_lar(s2))
    {
        while(s1[i]!='\0' && igual==true)
        {
            if(s1[i]!=s2[i])
                igual=false;
            i++;
        }
    }
    else
        igual=false;
    return igual;
}

void FILE_levantarString(String &s, FILE* f)
{
    String saux;
    saux= new char[MAX];
    int i= 0;

    /*Inicializa el string*/
    String_crear(s);
    /*borrar esta ^^  linea para cuando el string ya viene inicializado*/

    char caux;
    fread(&saux[i], sizeof(char), 1, f);
    while(saux[i]!='\0')
    {
        i++;
        //saux[i]=caux;
        fread(&saux[i], sizeof(char), 1, f);

    }
    //saux[i]= '\0';
    String_cop(s, saux);
    String_dest(saux);
}

void FILE_bajarString(String s, FILE* f)
{
    int i= 0;
    while(s[i]!='\0')
    {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite(&s[i], sizeof(char), 1, f);
}
//
//
//
//
//
//Funciones agregadas para el taller 1

int String_parseInt(String s) //De un String que solo contiene numeros sin separaciones, devuelve el valor en int
{
    int i= 0, j= 0;
    int resultado= 0;
    //Averiguo la cantidad de cifras que tiene el numero
    int largo= String_lar(s);
    //Mientras que tenga caracteres sigo en el while

    while(s[i]!= '\0'){
        int valor; //En esta variable se guarda el valor del caracter en el que estoy parado en int

        switch(s[i]){ //El switch carga valor: int con el valor del caracter en el que estoy parado
        case '0':
            valor =0;
            break;
        case '1':
            valor =1;
            break;
        case '2':
            valor =2;
            break;
        case '3':
            valor =3;
            break;
        case '4':
            valor =4;
            break;
        case '5':
            valor =5;
            break;
        case '6':
            valor =6;
            break;
        case '7':
            valor= 7;
            break;
        case '8':
            valor =8;
            break;
        case '9':
            valor= 9;
            break;
        default:
            //Si entra en este caso ocurre un error. Simplemente sigue hasta que llegue al siguiente numero.
            //Comprobar antes con la funcion String_isNumeric() si el String solo contiene numeros
            break;
        }

        int multiplicador= 1; //Incializo en 1 y no en 0, porque sino en el while quedaria multiplicador= 0*10, lo cual es 0
                              //y nunca estaria sumando.
        j= largo;
        while(j>1){ //Decide por cuanto tengo que multiplicar valor, para luego sumarlo
                    //Por ej. si ingreso "123", y estoy parado en el 1, voy a tener que hacer
                    //1*100 + 2*10 + 3*1. Este while decide por cuanto tengo que multiplicar cada cifra
            multiplicador= multiplicador *10;
            j--;
        }
        //Sumo a la variable resultado(inicializada en 0) el valor del casillero del String donde estoy parado * la cifra en la que esta
        resultado= resultado + (multiplicador*valor);
        i++; //Me muevo un casillero mas adelante en el String
        largo--; //Le resto uno al largo, porque me estoy moviendo un casillero mas adelante
    }
    if(s[0] == '-')
        resultado= resultado*(-1);
    return resultado; //Finalmente devuelvo un int con el valor del String
}

String String_valueOf(int n) //De un int, me devuelve un String con el n: int pasado a String
{
    //FIXME puse para que sepa cuantas cifras tiene el numero, pero tengo que poner las cifras en las casillas del String
    int digitos = 0; //variable para almacenar la cantidad de digitos
    if(n< 0)
        digitos= 1;
    while(n){ //tomo para cuando n!= 0 true, si n==0, entonces la condicion es false, tal como en la lectura de archivos
        printf("\n%d", n);
        n = n/10;
        digitos++;

    }
    //FIXME cuando arregle la funcion sacar el return NULL, esta puesto ahora solo temporalmente
    return NULL;
}

bool String_isNumeric(String s){//Devuelve true si el String solo contiene numeros.
    bool isNumeric = true;
    int i = 0;

    while(s[i]!='\0' && isNumeric){
        if(i==0){//Cuando me encuentro en la primer posicion
            if(s[i]== '+' || s[i]=='-' || s[i]== '.'){//Si la primer posicion es un signo o un punto
                if((s[i]== '+' && s[i+1]== '+') || (s[i]== '-' && s[i+1]=='-')) //Si la segunda posicion es un + o un -, entonces esta mal
                    isNumeric= false;
                if(s[i]== '.' && s[i+1]== '.') //caso de que hayan 2 puntos seguidos
                    isNumeric= false;
            }
            else
                if((s[i]<48 || s[i]>57) && (s[i]!= '.' || s[i]!= '-' || s[i]!= '+')) //Si no es letra ni punto ni signo en la primer posc
                    isNumeric= false;
        }
        else{ //Me encuentro en cualquier posicion menos la primera
            if(s[i]== '+' || s[i]== '-'){ //Si tengo un signo en la mitad, entonces esta mal
                isNumeric= false;
            }
            if(s[i]== '.' && s[i+1]== '.') //Caso de que hayan 2 puntos seguidos, esta mal
                isNumeric= false;
            if((s[i]<48 || s[i]>57)) //caso de que no sea letra
                if(s[i]!='.') //caso de que no sea ni letra ni punto
                    isNumeric= false;
        }
        i++;
    }
    return isNumeric;
}



