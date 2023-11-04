#include<iostream>
#include<stdlib.h>//rand()
#include<conio.h>
#include<sstream>
#include<ctime>
#include<iomanip.h>//setw(#);  std::setw(int__n);
using namespace std;
void matriz();
int main(){
    char option;
    do{
           matriz(); printf("\n");
           cout<<"\t Desea otra matriz? S/N...";
           fflush(stdin); cin>>option; system("Cls");
           }while(option=='s'||option=='S');
    getch(); return 0;
    }
void matriz(){
     int Matriz[10][10], numero, c, co, f, fi;
     bool val=false;
     cout<<"De numero de filas: ";
     cin>>fi;
     cout<<"De numero de columnas: ";
     cin>>co;
     srand(time(0));
     for(f=0; f<fi; f++){
              for(c=0; c<co; c++){
                       Matriz[f][c] = 1 + rand() % 20;          
                       }
                       }
                      for(f=0; f<fi; f++){
                               for(c=0; c<co; c++){
                                        cout<<setw(3)<<Matriz[f][c]<<" ";
//                                        printf("%p");     
                                        }cout<<endl;
                                        }
     cout<<"De un numero a buscar en matriz ";
     fflush(stdin); cin>>numero;
     for(f=0; f<fi; f++){
                               for(c=0; c<co; c++){
                                        if(numero == Matriz[f][c]){
                                                  co=c;
                                                  fi=f;
                                                  val=true;
                                                  }}}
                                        if(val==true){
                                                      cout<<"El valor ha sido encontrado en fila "<<fi+1<<" y columna "<<co+1<<endl; 
                                                      printf("%p", &numero);
                                                      } else{
                                                             cout<<"valor no encontrado"<<endl;
                                                             }
                                                             getch();                                  
     }
