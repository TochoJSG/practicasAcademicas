/*Herencia de clases(Jerarquia de clases)
        ->Estudiante -> Universitario
Persona
        ->Empleado

Simulacion
*/
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
class Persona{
      private:
              string nombre;
              int edad;
      public:
             Persona(string,int);//Constructor, se llama como la clase
             void mostrarPersona();
      };
class Empleado : public Persona{//Derivado de la clase persona
//    Tiene acceso a nombre y edad por ser heredera de Persona a traves de funcion public
      private:
              float sueldo;
      public:
             Empleado(string,int,float);//primero atributos de clase padre, luego concatenamos el suyo
             void mostrarEmpleado();
      };
class Estudiante : public Persona{
      private:
              float nota;
      public:
             Estudiante(string,int,float);
             void mostrarEstudiante();
      };
class Universitario : public Estudiante{
      private:
              string matricula;
      public:
             Universitario(string,int,float,string);
             void mostrarUniversitario();
      };
//Persona Constructor && Funcion
Persona::Persona(string _nombre,int _edad){//Definicion de que se le pasara por el main (Constructor)
                        nombre = _nombre;
                        edad = _edad;
                        }
void Persona::mostrarPersona(){
     cout<<"Nombre "<<nombre<<endl;
     cout<<"Edad  "<<edad<<endl;
     }
     
//Empleado Constructor && Funcion
Empleado::Empleado(string _nombre,int _edad,float _sueldo) : Persona(_nombre,_edad){
                          sueldo = _sueldo;
                          }
void Empleado::mostrarEmpleado(){
     mostrarPersona();
     cout<<"Sueldo  "<<sueldo<<endl;
     }
     
//Estudiante Constructor && Funcion
Estudiante::Estudiante(string _nombre,int _edad,float _nota) : Persona(_nombre,_edad){
                              nota = _nota;
                              }
void Estudiante::mostrarEstudiante(){
     mostrarPersona();
     cout<<"Nota  "<<nota<<endl;
     }
     
//Universitario Constructor && Funcion
Universitario::Universitario(string _nombre,int _edad,float _nota,string _matricula) : Estudiante(_nombre,_edad,_nota){
                                    matricula = _matricula;
                                    }
void Universitario::mostrarUniversitario(){
     mostrarEstudiante();
     cout<<"Matricula  "<<matricula<<endl;
     }
     
int main(){
    Empleado empleado("Pedro",35,1209);
    cout<<"\t.:EMPLEADO:."<<endl;
    empleado.mostrarEmpleado(); cout<<endl;
    
    Universitario uni("Jorge",20,17.98,"informaaaticoo");
    cout<<"\t .:Estudiante:."<<endl;
    uni.mostrarUniversitario(); cout<<endl;
    getch();                    return 0;
    }
    
