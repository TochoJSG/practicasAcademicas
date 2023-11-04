#include<iostream>
#include<conio.h>
using namespace std;
typedef int e;
struct persona{
       char nombre[20];
       int edad;
       }p[3];
e main(){
         for(e i=0;i<3;i++){
               fflush(stdin); cout<<"De el nombre "<<i+1<<":";
//               cin.getline(p[i].nombre,20,'\n');
               gets(p[i].nombre);
               cout<<"De la edad "<<i+1<<":";
               /*cin>>p[i].edad;*/ scanf("%d",&p[i].edad); cout<<"\n";
               } getch();
         for(e i=0;i<3;i++){
               cout<<"Nombre "<<i+1<<p[i].nombre<<endl;
               cout<<"Edad "<<i+1<<p[i].edad<<endl;
               }
         getch(); return 0;
         }
