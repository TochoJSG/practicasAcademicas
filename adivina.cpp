#include<stdlib.h>
#include<stdio.h>
#include<time.h>//crear numero aleatorio
int main(){
    srand(time(NULL));
    bool c=false;
    int random=1+rand()%((50+1)-1);//Creamos numnero aleatorio y guardamos en valiable Random
    //Variable de almacenamineto dato user
    int adivina;
//    printf("Numero aleatorio es :  %i \n",random);//Mostramos resultado
    do{               
        printf("Digite adivinanza:  "); scanf("%d",&adivina); printf("\n");
        if(random<adivina){//Dar pista
                           printf("\nEl numero es menor al numero que digitaste\n");
                           }else if(random>adivina){
                                 printf("\nEl numero es mayor al que digitaste\n");
                                 }else{
                                       printf("\nHas acertado, programa finalizado\n\n");
                                       c=true;
                                       }
        }while(c==false);
    system("pause"); return 0;
    }
