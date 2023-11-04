#include<stdio.h>//funciones de entrada y salida
#include<stdlib.h>//funcion para manipular systema 'system'
#include<time.h>
#define random(num)(rand()%(num))

struct Vals_en_intervalo{
	   float nums_en_intervalo_cerrado[100];
	   float nums_en_intervalo_abierto[100];
	   };
	   
void intervalo_abierto(float&,float&);
void intervalo_cerrado(float&,float&);
void orden(float &,float&);

int j,prueba_inter,intervalo_entero;
float i,_a, _b, frontera_izq,frontera_der;
Vals_en_intervalo x;

int main(){
    printf("\nIngrese A (Presione espacio) Ingrese B::");	scanf("%f %f",&_a,&_b); system("cls");
    orden(_a,_b);
    printf("\n\nX es una variable que puede tomar cualquier valor dentro de un intervalo\n\n");
    intervalo_abierto(_a,_b); printf("\n\n\n");
    intervalo_cerrado(_a,_b); printf("\n");
	system("pause");	return 0;
	}
	
void intervalo_abierto(float &A,float &B){
     printf("Orden-> %f    <    %f \n\n",frontera_izq,frontera_der);
	 printf("-> %.2f	<	X	<	%.2f  ->  'X' son los valores entre \n\n",frontera_izq,frontera_der);
	 srand( (unsigned) time(NULL) );
	 intervalo_entero = random( static_cast <int> (frontera_der));
	 for(i=(frontera_izq+0.001),j=0; i<(frontera_der) ; i+=0.13,j++){
					   x.nums_en_intervalo_abierto[j] = i;
					   while (x.nums_en_intervalo_abierto[j] > frontera_der-0.0001){
                                                        x.nums_en_intervalo_abierto[j] =  x.nums_en_intervalo_abierto[j]/ static_cast <float> (intervalo_entero);
														}
					   }
     printf("\n 'X' puede valer->\n");
     for(i=(frontera_izq+0.001),j=0; i<(frontera_der) ; i+=0.13,j++)
	 				  printf("%.5f %c",x.nums_en_intervalo_abierto[j], j%6==0? '\n':' ');
	 }
void intervalo_cerrado(float &A,float &B){
     printf("Orden-> %f    <    %f \n\n",frontera_izq,frontera_der);
	 printf("-> %.2f	<=	X	<=	%.2f  ->  'X' son los valores entre \n\n",frontera_izq,frontera_der);
	 srand( (unsigned) time(NULL) );
	 intervalo_entero = random( static_cast <int> (frontera_der));
	 for(i=(frontera_izq),j=0; i<=(frontera_der) ; i+=0.10,j++){
					   x.nums_en_intervalo_cerrado[j] = i;
					   while (x.nums_en_intervalo_cerrado[j] > frontera_der){
                                                        x.nums_en_intervalo_cerrado[j] =  x.nums_en_intervalo_cerrado[j]/ static_cast <float> (intervalo_entero);
														}
					   }
     printf("\n 'X' puede valer->\n");
     for(i=(frontera_izq),j=0; i<(frontera_der) ; i+=0.10,j++)
	 				  printf("%.5f %c",x.nums_en_intervalo_cerrado[j], j%8==0? '\n':' ');
	 }
void orden(float &A,float &B){
     	 if(_a<_b){
	 		   frontera_izq = _a;
			   frontera_der = _b;
		  	   }else{
		 	   		 frontera_izq = _b;
				     frontera_der = _a;
				     }
	 }
