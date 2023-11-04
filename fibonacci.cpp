#include<stdio.h>
#include<stdlib.h>
long fibo(int);
void fibonacci();

long int fibo1();


int main(){

	}

void fibonacci(){
    int tope,i;
    printf("DE TAMANIO DE ARREGLO  "); scanf("%d",&tope);
    printf(" %i   %i   ",0,1);
    for(i=2;i<tope;i++){
                        printf("%ld%c",fibo(i),(i%7==0? '\n':' '));
                        }printf("\n\n");
    system("pause");
    }
long fibo(int n){
     if(n==0||n==1?	return n : return fibo(n-2) + fibo(n-1));
     }
     
long int fibo1(){//Al usar static se mantiene valor entre llamadas
	 static int x = 0;
	 static int y = 1;
	 y = y + x;// Y=1+0, y=1+1, y=2+1, y=3+2
	 // Prepara X para siguiente llamado
	 x = y - x;// x=1-0, x=2-1, x=3-1, x=5-2....
	 return y;
	 }
void fibonacci1(){
	 int n,i;
     printf("DE TAMANIO DE ARREGLO  "); scanf("%d",&n);
     printf(" %i   %i   ",0,1);
     for(i=2;i<n;i++)
     				  printf("%ld %c",fibo1(),(i%7==0? '\n':' '));
    system("pause");
	 }

