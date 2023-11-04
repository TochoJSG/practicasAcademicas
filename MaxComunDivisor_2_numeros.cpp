/*
  mcd, numero mas pequeño
*/
#include<stdio.h>
#include<stdlib.h>
int mcd(int m,int n);
int main(){
	int m,n;
	do{
	   printf("\nIntroduzca 2 enteros positivos:	");
	   scanf("%d %d",&m,&n);
		   }while((n<=0)||(m<=0));//repetir si algun valor ingresado es negativo o 0
	printf("\nEl maximo comun divisor es: %d\n\n", mcd(m,n));
	system("pause");	return 0;
	}
int mcd(int m,int n){
	if(n<=m && m%n==0)
	        return n;
	        else if(m<n)
	             return mcd(n,m);
	                    else
	                        return mcd(n, m%n);
	}
