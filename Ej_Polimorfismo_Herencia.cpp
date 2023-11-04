/*Programa en C++ de jerarquia; 
Uso de Polimorfismo de funcion comer*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class Animal{
      private:
              int edad;
      public:
             Animal(int);
             virtual void comer();
      };
class Humano : public Animal{
      private:
              string nombre;
      public:
             Humano(int,string);
             void comer();
      };
class Perro : public Animal{
      private:
              string nombre,raza;
      public:
             Perro(int,string,string);
             void comer();
      };
Animal::Animal(int _edad){
                   edad = _edad;
                   }
Humano::Humano(int _edad,string _nombre) : Animal(_edad){
                   nombre = _nombre;
                   }
Perro::Perro(int _edad,string _nombre,string _raza) : Animal(_edad){
                 nombre = _nombre;
                 raza = _raza;
                 }
void Animal::comer(){
     cout<<"Yo como ";
     }
void Humano::comer(){
     Animal::comer();
     cout<<" en una mesa, sobre una silla\n";
     }
void Perro::comer(){
     Animal::comer();
     cout<<" en el suelo con su plato\n";
     }
int main(){
    Animal *animales[2];
    animales[0] = new Perro(5,"Boby","Pastor aleman");
    animales[1]  =new Humano(18,"Juan");
    animales[0]->comer();
    animales[1]->comer();
    system("pause");     return 0;
    }
