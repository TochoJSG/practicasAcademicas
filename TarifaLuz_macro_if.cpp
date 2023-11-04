/*Visualizar tarifa de luz segun gasto de corriente electrica*/
#include<stdio.h>
#include<stdlib.h>
#define TARIFA 1.2
#define TARIFA2 1.0
#define TARIFA3 0.9
int main(){
	float gasto, tasa;
	printf("\n Gasto de corriente:  ");
	scanf("%f",&gasto);
	if(gasto < 1000.0) tasa = TARIFA;
	if(gasto >= 1000.0 && gasto <= 1850.0 ) tasa = TARIFA2;
	if(gasto > 1850.0) tasa = TARIFA3;
	printf("\n Tasa que le corresponde a %.1f KWxH es de %f \n", gasto,tasa);
	system("pause");	return 0;
	}
