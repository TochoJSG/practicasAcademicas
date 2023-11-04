/*
  Resultados que devuelven funciones matematicas de caracter general
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int exponente;
	double d, y;
	printf("\n ceil(3.7)= %lf \t\t ceil(3.4)= %lf",
			   			  	  	   			  	   ceil(3.7), ceil(3.4) );
	printf("\n ceil(-3.7)= %lf \t\t ceil(-3.4)= %lf",
			   			  	  	   			  	   ceil(-3.7), ceil(-3.4) );
    printf("\n floor(3.7)= %lf \t\t floor(3.4)= %lf",
			   			  	  	   			  	   floor(3.7), floor(3.4) );
	printf("\n floor(-3.7)= %lf \t\t floor(-3.4)= %lf",
			   			  	  	   			  	   floor(-3.7), floor(-3.4) );
    printf("\n fmod(5.6,2.5)= %lf \t\t fmod(-5.6,2.5)= %lf",
			   			  	  	   			  	   fmod(5.6,2.5), fmod(-5.6,2.5) );
	d = frexp(16.0, &exponente);
	
	printf("\n Mantista de 16.0, m= %lf \t\t exponente = %d",
 			   			   		 		d,exponente);
	d = modf(-17.365, &y);
	printf("\n Parte decimal de -17.365 = %lf ", d);
	printf("\n Parte entera de -17.365 = %lf ",y);
	system("pause");	return 0;
	}
