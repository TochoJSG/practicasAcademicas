#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
long fibo(int);
int n,i,tope;
int main(){
	printf("Digite extension de secuencia:  ");
	scanf("%i",&tope);
	printf("%i  %i  ",0,1);
	for(i=2;i<tope;i++){
		printf("%ld %c",fibo(i),((i%8==0)? '\n':' '));
		}
	}printf("\n\n");
system("pause"); return 0;
}
long fibo(int n){
	if(n==0||n==1){
		return n;
	}else{
		return fibo(n-2) + fibo(n-1);
	}
}
