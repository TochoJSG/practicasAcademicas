/*
  Estructura tipo PILA:
              */
#include<iostream>
int const TAM_PILA = 5;//Tamnio maximo de pila
using namespace std;
class Pila{
      public:
             class Llena{//Clase excepcion; Overflow-Desbordamiento
                   public:
                          int desborde;
                          Llena(int i):desborde(i){ }
                   }; 
             class Vacia{//Clase excepcion; Underflow-Subdesbordamiento
                   public:
                          Vacia(){ }
                   };
             Pila(){cima = -1;}
             void meter(int item){
                  if(cima < (TAM_PILA-1)) 
                          pila[++cima] = item;
                          else
                              throw Llena(item);
                  }
             int sacar(){
                 if(cima > -1)
                         return pila[cima--];
                         else
                             throw Vacia();
                 }
      private://Atributos Clase Pila
              int pila[TAM_PILA];
              int cima;
      };                   
int main(){
    Pila obj;
    int y = 5, x = 25;
    //Bloque try
    try{
        obj.meter(x);
        obj.meter(y);
        obj.meter(12);
        obj.meter(32);
        obj.meter(4392);
        //Pila se llena con 5; Se fuerza excepcion
        obj.meter(500); //Lanza Pila::Desbordamineto
        }
//      Manejador de excepciones
        catch(Pila::Llena &e){
                          cout<<"La pila se desbordo  tratando de meter Val de: "<<e.desborde<<endl;
                          }    
        catch(Pila::Vacia &e){
                          cout<<"Faltan elementos"<<endl;
                          }
        system("pause"); return 0;                  
        }
    
      
