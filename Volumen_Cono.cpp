/*
  Utilizando macros con argumentos es VolCono(), calculo de volumen de la figura geometrica CONO
  [ V = 1/3PI * r^2 * h ]
  
  informática es la ciencia que se centra en el estudio de la información y la forma en cómo se trata, se trasmite y se automatiza.
*/
#include<stdio.h>
#include<stdlib.h>
#define PI 3.141592
#define VOLCONO(radio,altura) ((PI*(radio*radio)*altura)/3.0)

int main(){
	float radio,altura,volumen;
	printf("\nIntroduzca radio del cono: ");
	scanf("%f", &radio);
	printf("Introduzca altura del cono: ");
	scanf("%f", &altura);
	volumen = VOLCONO(radio, altura);
	printf("\nEl volumen del cono es: %.2f",volumen);
	system("pause");	return 0;
	}
