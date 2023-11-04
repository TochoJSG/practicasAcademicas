#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
//Funciones
void menu();
int depositar(int cantidad);
void retirar(int cantidad);
int saldo_actual=100, cantidad;
int main(){
    char opcion;
    do{
     menu();
     printf("\n\n");
     cout<<"\tDesea efectuar otra operacion  S/N"; opcion=getch();
     system("Cls");
     }while(opcion=='S'||opcion=='s');
     getch();return 0;
     }
void menu(){
     int opc;
     cout<<"1. Consultar saldo"<<endl;
     cout<<"2. Depositar"<<endl;
     cout<<"3. Retirar"<<endl;
     cout<<"4. Salir"<<endl;
     cout<<"\nDigite su opcion"<<endl;
     fflush(stdin); cin>>opc;
     switch(opc){
                 case 1: cout<<"Tu saldo actual es de:  "<<saldo_actual<<endl;
                         break;
                 case 2: cout<<"Cuanto dinero desea depositar:  "; cin>>cantidad;
                         cout<<"Has depositado exitosamente $"<<cantidad<<", tu saldo actual es de $"<<depositar(cantidad); 
                         break;
                 case 3: cout<<"Cuanto deseas retirar:  "; cin>>cantidad;
                         retirar(cantidad); 
                         break;
                 case 4: exit(1); break;
                 default: cout<<"Opcion invalida"<<endl; system("cls,pause"); menu(); break;
                 }
     }
int depositar(int cant){
     int saldo_final;
     saldo_final = saldo_actual + cant;
     saldo_actual = saldo_final;
     return saldo_final;
     }
void retirar(int cant){
     int sal_final,minimo;
     minimo = saldo_actual - cant;
     if((cant<saldo_actual)&&(minimo>100)){
                                sal_final = saldo_actual - cant;
                                saldo_actual = sal_final;
                                cout<<"Ha retirado exitosamente $"<<cantidad<<" su saldo es $"<<saldo_actual<<endl;
                                }else if((minimo<101)&&(cant<saldo_actual)){
                                      cout<<"\n\aSe requieren al menos 100 para mantener activa la cuenta"<<endl; 
                                      cout<<"Su saldo es "<<saldo_actual<<", maximo posible es "<<saldo_actual-100<<endl;
                                      getch(); system("cls,pause"); menu();
                                      }else{
                                           cout<<"\a\nNo cuentas con suficiente dinero para efectuar la operacion"<<endl;
                                           cout<<"Su saldo es "<<saldo_actual<<", maximo posible es "<<saldo_actual-100<<endl;
                                           getch(); system("cls,pause"); menu();
                                           }
     }
