#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 10//Macro para "Introduccion selectiva"
#define CLAVE -666//Macro para "for_infinto"
void introduccionInfinitaXwhile();
int main(){
    introduccionInfinitaXwhile();
	system("pause");	return 0;
	}
void par_non(){
    int n, d;
	printf("Introduzca 2 enteros: ");
	scanf("%d %d",&n,&d);
 	if(n%d == 0? printf("%d es divisible entre %d \n",n,d) : printf("%d no es divisible entre %d \n",n,d));
	}
void comparacion(){
	 int a,b,c,mayor;
	 printf("\n Introduzca 3 enteros: ");
	 scanf("%d %d %d",&a,&b,&c);
	 if(a > b)//a es mayor a b
		  if(a > c) mayor = a;//   ademas de ser 'a' mayor que 'b' es mayor que 'c' por lo tanto a es el mayor (mas a la derecha en la recta que 'b' & 'c')
		  	   else mayor = c;// 'a' fue mayor que 'b' pero 'c' fue mayor que 'a', por lo tanto 'c' es el mayor, seguido de 'a' ->  c > a > b
		 else// a < b a fue menor a b
		     if(b > c) mayor = b;// 'b' fue mayor que 'a', ademas 'b' es mayor que 'c', por lo tanto 'b' es el mayor
		     	  else mayor = c;// 'b' fue mayor que 'a', pero 'c' fue mayor que 'b', por lo tanto 'c' es el mayor, seguido de 'a' ->  c > a > b
	 printf("El mayor es %d \n", mayor);
	 }
void vocal(char car){
	 char arreglo[15]; int digitos,vocales,blancos;
	 switch(car=getch()){
				 case 'a': case 'A':
				 case 'e': case 'E':
				 case 'i': case 'I':
				 case 'o': case 'O':
				 case 'u': case 'U': vocales++; printf("%c es una vocal",car); break;
                 case '1': case '2':
				 case '3': case '4':
				 case '5': case '6':
				 case '7': case '8':
				 case '9': case '0': digitos++; printf("%c es un digito",car); //strcat(arreglo,car); atoi(arreglo,car); break;
				 case '\n': case '\t': blancos++; break;
				 default: printf("%c no es caracter"); break;
				 }
	 }
void uso_caracter_interr(){
	 int n1, n2;
	 printf("Introduzca 2 numeros enteros cualquiera: ");
	 scanf("%d %d",&n1,&n2);
	 n1 > n2 ? printf(" %d > %d ",n1,n2) : printf(" %d < %d ",n1,n2);
	 }
void introduccionSelectiva(){
	 float muestra[MAX]; int i;
	 printf("Introduzca una lista de %d elementos positivos \n",MAX);
	 for(i=0; i<MAX;   muestra[i]>0? ++i : i)     scanf("%f",&muestra[i]);
	 }
void introduccionInfinitaXwhile(){
	 const int clave = 8912;
	 int entrada;
	 while(scanf("%i",&entrada)){
								 if(entrada==clave) break; //CodOrig =  if entrada != clave IntentarAgain : break, Bienvenida
//								                    else continue;
								  }
	 printf("\nProtocolo de Bienvenida\n");
	 }
void for_infinto(){
	 int num,tope,conta;
	 for(;;){
			 printf("\nIntroducir [%d] para detener bucle",CLAVE);	scanf("%d",&num);
			 if(num == CLAVE)	break;
			  }
	printf("\nIngresa numero tope del bucle:	"); scanf("%d",&tope);
	for(;;){
			if(conta<tope){
						   puts("\nBucle\n"); conta++;
						   }else break;
			}
	 }
void for_variante(){
	 int cont = 0;
	 for(;cont<5;){
				   cont++; printf("\nBucle\n");
					}      printf("Contador = %d",cont);
	 }
void eva_nota(){
	 float nota;
	 printf("Introduzca nota obtenida (0 - 10): ");
	 scanf("%f", &nota); if(nota>=5? printf("Aprobado") : printf("Reprobado") );
	 system("pause");	return 0;
	 }
void bucles(){
	 for(i=1;i<=5;i++){
					   printf(" %d \n",i);
					   for(j=i;j>=1; j-=2){
                                           printf(" %d \n",j);
										}
						}
	 for(i=3;i>0;i--)
	 for(j=1;j<=i;j++)
	 for(k=i;k>=j;k--)
	                  printf("%d %d %d \n",i,j,k);
     for(i=1;i<=30;i++)
	 for(j=1;j<=i;j++){
	 				   for(k=i;k>=j;k--)
										printf("%d %d %d \n",i,j,k);
										putchar('\n');
						}

