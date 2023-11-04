/*Funcion para visualizar triangulo isoceles*/
#include<stdlib.h>
#include<stdio.h>
const int num_lineas=5;//	Renglones/niveles/filas/lieasHorizontales
const char blanco=' ';
const char asterisco='*';
int main(){
	int fila,blancos,cuenta_asteriscos;
	puts(" ");//un espacio de separacion
//  Con un bucle externo dibujamos cada linea
	for(fila=1;fila<=num_lineas;fila++){//valor de fila incrementara sin exceder limite
		putchar('\t');
//      El primer bucle interno escribe los espacios en blanco
		for(blancos=num_lineas-fila; blancos>0; blancos--)//numero de espacios en blanco ira decrementando, es decir se pondran menos en cada pasada: 5-1, 5-2, 5-3,...
									 putchar(blanco);//Cada pasada reduce espacios, pone menos, primero pone 4, 3, 2, 1
		for(cuenta_asteriscos=1; cuenta_asteriscos<2*fila; cuenta_asteriscos++)//cantidad de asteriscos debe aumentar
										putchar(asterisco);// 1<2*1=1<2 ´*´ , 2<2*2 = 2<3 ´***´ , 3 < 2*3 = 3<6 ´*****´
//										Terminar linea
										puts(" ");
//                                      fin de bucle externo
										}
	system("pause");	return 0;
	}
