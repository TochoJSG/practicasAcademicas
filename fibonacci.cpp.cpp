#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
long fibo(int);
int n,i,tope;
int main(){
	cout<<"Digite extension de secuencia:  ";
	cin>>tope;
	cout<<"0  1";
	for(i=2;i<tope;i++){
//		printf("%ld %c",fibo(i),((i%8==0)? '\n':' '));
		cout<<setw(4)<<fibo(i)<<(i%8==0)? '\n':' ';
		}cout<<"\n"<<endl;
system("pause"); return 0;
}
long fibo(int n){
	if(n==0||n==1){
		return n;
	}else{
		return fibo(n-2) + fibo(n-1);
	}
}
