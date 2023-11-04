#include<iostream>
#include<conio.h>
using namespace std;
float prom;
struct promedio{
       float n1;
       float n2;
       float n3;
       };
struct alumno{
       char nombre[20];
       char sexo[10];
       int edad;
       struct promedio notas;
       }alumno;
int main(){
    char a;
    int i=1;
    do{
         cout<<"De nombre "<<i<<":";
         fflush(stdin); cin.getline(alumno.nombre,20,'\n');
         cout<<"Digite su sexo: ";
         fflush(stdin); cin.getline(alumno.sexo,10,'\n');
         cout<<"Digite su edad: ";
         fflush(stdin); cin>>alumno.edad;
         cout<<"\n::Digite las notas de alumno::\n"<<endl;
         cout<<"Calificacion 1: ";
         fflush(stdin); cin>>alumno.notas.n1;
         cout<<"Calificacion 2: ";
         fflush(stdin); cin>>alumno.notas.n2;
         cout<<"Calificacion 3: ";
         fflush(stdin); cin>>alumno.notas.n3;
         prom=(alumno.notas.n1+alumno.notas.n2+alumno.notas.n3)/3;
         cout<<"\nDatos del alumno"<<endl;
                    cout<<"Nombre: "<<alumno.nombre<<endl;
                    cout<<"Sexo: "<<alumno.sexo<<endl;
                    cout<<"Edad: "<<alumno.edad<<endl;
                    cout<<"Promedio: "<<prom<<endl;
         cout<<"Precione 'S' para ingresar otros datos, cualquier otro para salir"<<endl;
         fflush(stdin); cin>>a;
         i++; system("cls");
         }while(a=='S'||a=='s');
//         if(a!='S'){
                  /*  cout<<"\nDatos del alumno"<<endl;
                    cout<<"Nombre: "<<alumno.nombre<<endl;
                    cout<<"Sexo: "<<alumno.sexo<<endl;
                    cout<<"Edad: "<<alumno.edad<<endl;
                    cout<<"Promedio: "<<prom<<endl;*/
//                    }
    getch(); return 0;
    }
