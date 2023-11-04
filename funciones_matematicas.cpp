#include<stdlib.h>
#include<stdio.h>
#include<math.h>
//Macros funcion f(x) = e^2x - x
#define fesp(x) (x*x + 2*x -1)//Para Funcion 1X, Macro de codigo 3
#define MEDIA3(x,y,z) ((x) + (y) + (z))/3.0//Para Funcion 1X
#define FUNCION3(x){//para Funcion 1X
					if((x) <-1.0)
					  (-(x)*(x)+3);
					else if((x) <=1)
					     (2*(x)+5);
					     else
					         ((x)*(x)-5)
					}

#define M 15
#define f(x) exp(2*x) - x

int main(){
	system("pause");	return 0;
	}
/*
	|   X^2 - X
	|
f(X)|
	|
	|   -X^2 + 3X
*/
void expresiones_pre(){//Partir de aqui para volver complejo el programa
	 float f,x;
	 printf("\n elige un valor para X: "); scanf("%f",&x);
	 /*		Seleccion del rango en que se encuentra X	*/
	 if(x <= 0.0 )	f = pow(x,2) - x;
	      else f = -pow(x,2) + 3*x;
	 printf("f(%.1f) = %.3f",x,f);
	 }
/*
  Leer dato numerico X, cuyo valor debve ser mayor a 0 para calcular f(X) = X*log(X)
*/
void logaritmo_ejemplo(){
	 float f,x;
	 int x_positivo;
	 x_positivo = 0;
	 while(! x_positivo)
	 {
	  printf("\nValor de X: ");scanf("%f",&x);
	  x_positivo = (x > 0.0);//True(1) si cumple condicion
			   }
	  f = x*log(x);
	  printf(" f(%1f) = %.3e",x,f);
	 }
/*	Imprime 15 valores de funcion f(x)=e^2x - x		*/
void funcion_euler(){
	 int i; double x;
	 for(i=1;i<=M;i++){
					   printf("Valor de X: ");	scanf("%lf",&x);
					   printf("f(%.1lf) = %.4g\n",x,f(x));
						}
	 }
void factorial1(){//    n! = n * (n-1)!, n>0
	 long int n,m,fact;
	 do{
		printf("\nFactorial de numero 'n', entre 2 y 20:	"); scanf("%ld",&n);//Aseguramos valor
		   }while((n<2) || (n>20));
	 for(m=n, fact=1; n>1; fact *= n--) ;//alamcenamos n en m para mostrar, mientras n decrementara
	          printf("%ld ! = %ld ", m,fact);//m jamas cambiara, fact se actializara 10!= 1*10, 10*9, 90*8, 720*7, ... X*1 = 10!
	 }
float evalua_maximo(float x,float y){
	  if(x<y? return y:return x);//Valor se asigna a variable en main o funcion que llama
	  }
double media(double x1,double x2){
	   return (x1+x2)/2;
	   }
void funcion_macros(){//Funcion 1X, para-> Macro 3
	 float x1; double a=2.9;
	 for(x1=0.0; x<=6.5; x+=0.3)
	             printf("\t  f(%.1f) = %6.2f ", x, fesp(x) );//Equivalente  escribir toda la funcion cuadratica de la macro, se sustituye expresion ahi
	 printf("\t %lf ", MEDIA3(a,4.5,7) );
	 printf("\t %lf ", FUNCION3(a) );
	 }
