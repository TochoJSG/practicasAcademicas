#include<iostream>
#inlcude<conio.h>
using namespace std;
const int max_pila  = 5;//Tamnio maximo de pila
class Pila{
      public:
             int pila[max_pila];
             int cant;//Numero de objetos apilados
             void reset();
             void push(int);//Agrega vals al tope
             int pop();//Retorna & elimina tope de Pila
      };

void Pila::reset(){//Vacia pila
     cant = 0;
     }
//Se agrega PUSH valor a tope de estructura
void Pila::push(int v){
//   Comprueba que haya lugar en pila para agegar nuevo val
     if(cant<max_pila){
                       pila[cant++] = v;//Asignamos
                       }
     }
//  Se elimina (POP) ultimo val de Pila y se returna nuevo tope  
int Pila::pop(){
    if(cant>0){
               cout<<"El valor del tope eliminado era:  ";
//             Retorna val del tope que ya fue eliminado
               return (pila[--cant]);
               }else{
                     cout<<"\aNo existen datos para eliminar.  ERROR  ";
                     return 0;
                     }
    }
