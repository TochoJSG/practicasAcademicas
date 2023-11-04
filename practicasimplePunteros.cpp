/*
EJERCICIOI PUNTEROS:
           *PEDIR VALOR PARA CADENA CARACTERES, PARA VARIABLE TIPO ENTERO & FLOTANTE
           *IMPRIMIR VALORES CON PUNTEROS E IMPRIMIR DIRECCIONES DE VALORES DE CADA VALOR
*/
//#include<iostream>
#include<stdio.h>
#include<conio.h>
//using namespace std;
int main(){
    char cadena[100];
    int entera;
    float flotante;
    printf("\nDigite valor a su cadena  ");
    gets(cadena);
    printf("\nDigite valor para entero  ");
    scanf("%i",&entera);
    printf("\nDigite valor para flotante  ");
    scanf("%f",&flotante);
//  Imprimimos vals. de punteros; Variables tipo puntero
    char *p_char;
    int *p_int;
    float *p_float;
//  Asignacion
    p_char = cadena;  
    p_int = &entera;
    p_float = &flotante;
//  Imprimimos con los punteros, no directamente  
    printf("\n\nPuntero para su cadena: %s", p_char);//strings no lleva asterisco
    printf("\n\nPuntero para su cadena: %i", *p_int);
    printf("\n\nPuntero para su cadena: %f", *p_float);
    printf("\n\nDireccion en memoria para:\n\tCadena: %p\n\tEntero: %p\n\tFlotante: %p",&cadena,&entera,&flotante);
    getch(); return 0;  
    }
