/*
  Prueba con random
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define randomize (srand(time(NULL))
#define random(num) (rand()%(num))
#define TOPE 1000

#define MAX(x,y) ((x)>(y)?(x):(y))
int main(){
	int mx,i;
	randomize;//Se llama funcion, se escribe todo
	mx = random(TOPE);
	for(i=2;i<=10;i++){
					   int y;
					   y = random(TOPE);
					   mx = MAX(mx,y);
					   }
	printf("\nEl mayor numero aleatorio generado es:  %d", mx);
	system("pause");	return 0;
	}
