#include<iostream>
#include<conio.h>
using namespace std;
struct persona{
       char nombre[20];
       int edad;
       }p1={"Jorge", 20},p2={"Araceli",18};//con la estructura llena, estructura llena
int main(){
    cout<<"Nombre 1: "<<p1.nombre<<endl;//imprime nombre persona 1 (p1)
    cout<<"Edad 1: "<<p2.edad<<endl; //imprime edad persona 2 (p2)
    getch(); return 0;
    }
/*struct persona{
         char nombre[20];
         int edad;
         }persona1;
int main(){
    cout<<"Nombre: ";
    cin.getline(persona1.nombre,20,'\n');
    cout<<Edad: ";
    cin>>persona1.edad;
    
    
    cout<<"Imprimiendo datos de la persona "<<endl;
    cout<<"Nombre: "<<persona1.nombre<<endl;
    cout<<"Edad: "<<persona1.edad<<endl;
    }*/
    
