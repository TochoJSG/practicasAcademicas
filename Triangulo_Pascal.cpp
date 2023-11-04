/*Tarea 3:                          
        "Escribir un programa en C++ que permita visualizar el triangulo de Pascal"
        Desarrollado en Dev-C++ 4.9.9.2 por Jorge Salgado Garcia  */
#include<stdio.h>
#include<stdlib.h>
int facto(long long int num);
int main(){
    int i,j=1,k=1;// i = renglones  ;  j = elementos  ; k = formato
    int n=8; // Determina cantidad de columnas
    long int elemento;
    printf("\t\t      .:TRIANGULO DE PASCAL:. \n");
    printf("--------------------------------------------------------------------------------\n\n");

    for(i=0;i<n;i++){
                     for(j=1;j<n-i;j++)//Col. van disminuyendo
                                        printf("    ");
                     for(k=0;k<=i;k++)          
                                        printf(" %6d ",(facto(i)) / ((facto(k))*(facto(i-k))));
                                        printf("\n\n");
                     }printf("\n\n");
    system("pause"); return 0;
    }
int facto(long long int num){
    int i=num;
    long long fact=1;
    for(i=num;i>1;i--){ fact*=i; }
    return fact;
    }
