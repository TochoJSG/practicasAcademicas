#include<iostream>
#include<conio.h>
using namespace std;
int numero;
long int facto(int);
main(){
       cout<<"Digite el numero del que desea obtener el factorial:  ";
       cin>>numero;
       for(int i=1;i<=numero;i++){
       cout<<i<<"*"<<i+1<<" = "<<facto(i)<<endl;
       }
       getch(); return 0;
       }         

/*void factorial(){
int i,numero,n,fact;
cout<<"Digite el numero del que desea obtener el factorial:  ";
cin>>numero;
for(i=0;i<numero;i++){
//                      numero--;
                       n=i;
                       if(n=0){
                                n=1;                
//                                     }else{
                                           fact = n * (n+1);
                                           }
                      }
for(i=0;i<numero;i++){
                      cout<<fact<<"  ";
                      }
}*/
long int facto(int n){
     long int a;
     a = n * n+1;
     return a;    
     }
