#include<iostream>
#include<conio.h>
using namespace std;
typedef int tipo;
class Arbol_bin{
                struct Nodo{
                       tipo dato;
                       Nodo *izq;
                       Nodo *der;
                       Nodo *padre;
                       };
       Nodo *nuevo(tipo,Nodo *);
       void add(Nodo *&,tipo,Nodo *);
       void mostrar(Nodo *,int);
       };

Nodo *Arbol = NULL;
int contador = 0;
int main(){
    int j;
    tipo info;
    for(j=0;j<8;j++){
          cout<<"Da numero "<<j+1<<":  "; cin>>info;
          add(Arbol,info,NULL);
          }                    fflush(stdin);
    mostrar(Arbol,contador);
    getch();      return 0;
    }
Nodo Arbol_bin::Nodo *nuevo(tipo num,Nodo *papa){
     Nodo *nuevo_nodo = new Nodo();
     nuevo_nodo->dato = num;
     nuevo_nodo->izq = NULL;
     nuevo_nodo->der = NULL;
     nuevo_nodo->padre = papa;
     return nuevo_nodo;
     }
void Arbol_bin::add(Nodo *&arbol,tipo n,Nodo *pap){
     if(arbol == NULL){
              Nodo *nna = nuevo(n,pap);
              arbol = nuevo(n,pap);
              }else{
                    if(arbol->dato <= n){
                                   add(arbol->izq,n,arbol);
                                   }else{
                                         add(arbol->der,n,arbol);
                                         }
                    }
     }
void Arbol_bin::mostrar(Nodo *arbol,int cont){
     if(arbol == NULL){
              return;
              }else{
                    mostrar(arbol->der,cont+1);
                    for(int i=0;i<cont;i++){
                            cout<<"   ";
                            }
                    cout<<arbol->dato<<endl;
                    mostrar(arbol->izq,cont+1);
                    }
     }
