#include<stdio.h>//funciones de entrada y salida
#include<stdlib.h>//funcion para manipular systema 'system'
#include<time.h>

struct Vals_en_intervalo{
	   float nums_en_intervalo_cerrado[20];
	   float nums_en_intervalo_abierto[20];
	   };

void tricotomia();
void transitividad();
void monotonia(int&,int&);

int i, a,b,c,mayor,menor,medio,valor_monotomo;//Variables globales necesarias
float _a, _b, frontera_izq, frontera_der;
bool tercera_condicion=false;
Vals_en_intervalo x;

int main(){
    tricotomia(); printf("\n\n");//Mandamos a llamar funcioon y damos 2 saltos de linea
	transitividad(); printf("\n\n");//Mandamos a llamar funcioon y damos 2 saltos de linea
	system("pause");	return 0;
	}
void tricotomia(){
	 printf("Ingrese A (Presione espacio) Ingrese B::"); scanf("%d %d",&a,&b);
     system("cls"); printf(" A=%d	B=%d \n",a,b);//Lipiamos la pantalla de lo anterior y mostramos valores de variables A & B
     if(a<b){
	 		 menor=a;
			 mayor=b;
			 }else{
			 	   menor=b;
				   mayor=a;
				   }// 'A' fue mayor por lo tanto 'B' fue menor  o  'B' fue mayor por lo tanto 'A' fue menor -> 2 condiciones
	 if(a==b? tercera_condicion=true:tercera_condicion=false);//la tercera se cumple si las anteriores no se cumplieron, pero solo hay 3 vias
	 tercera_condicion? printf("\a %d = %d",a,b) : printf("\a %d < %d",menor,mayor);
	 if( !tercera_condicion)//No se cumplio el caso de que fueran igual los valores
	 	 					monotonia(menor,mayor);
	 }
void monotonia(int &m,int &M){
     printf("\nDigite valor constante para monotonia::"); scanf("%d",&valor_monotomo);
     printf("\nMonotoniaSUMA-> %d < %d conserva condicion al sumar %d a ambos lados %d < %d"
	 					 		   	  	   					  	 	   	  ,m,M,valor_monotomo,     m + valor_monotomo,   M + valor_monotomo);
	 if(valor_monotomo > 0) //El valor de monotomia debe ser mayor a 0 (positivo) para conservar la misma condicion (La desigualdad)
     printf("\nMonotoniaPRODUCTO-> %d<%d conserva condicion al multiplicar %d a ambos lados %d<%d"
			  			 			   	  	   			      	  	 	  ,m,M,valor_monotomo,     m * valor_monotomo,   M * valor_monotomo);
						   else//Valor monotomo menor a 0 (negativo) por lo tanto la condicion (desigualdad) se invierte
						       printf("\nMonotonia PRODUCTO-> %d<%d condicion invertida al multiplicar %d a ambos lados %d>%d"
			  			 			   	  	   			      	  	 	  ,m,M,valor_monotomo,     m * valor_monotomo,   M * valor_monotomo);
	 }
void transitividad(){//Transitividad logica
	 printf("\n Introduzca 3 enteros: ");
	 scanf("%d %d %d",&a,&b,&c);
	 if(a > b)//a es mayor a b
		  if(a > c){
		  	   	 	mayor = a;//   ademas de ser 'a' mayor que 'b' es mayor que 'c' por lo tanto a es el mayor (mas a la derecha en la recta que 'b' & 'c') a>b>c
					if(b<c){
							menor=b,medio=c;
							}else{
								  menor=c,medio=b;
								  }
				 }else{
				 	   mayor = c;// 'a' fue mayor que 'b' pero 'c' fue mayor que 'a', por lo tanto 'c' es el mayor, seguido de 'a' ->  c > a > b
					   medio = a;
					   menor = b;
					   }
		 else// a < b a fue menor a b
		     if(b > c){
			 	  	   mayor = b;// 'b' fue mayor que 'a', ademas 'b' es mayor que 'c', por lo tanto 'b' es el mayor
                       if(a<c){
					   		   menor=a,medio=c;
					  		   }else{
							   		 menor=c,medio=a;
									 }
					   }else{
					   		 mayor = c;// 'b' fue mayor que 'a', pero 'c' fue mayor que 'b', por lo tanto 'c' es el mayor, seguido de 'a' ->  c > a > b
                             medio = b;
					   		 menor = a;
							 }
	 printf("\n %d > %d > %d \n", mayor,medio,menor);
	 }
