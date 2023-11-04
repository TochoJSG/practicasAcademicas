/*
                **SIMULADOR CAJERO AUTOMATICO EN POO**
Descripcion:
            1.Clase "Cuenta", con atributos de nombre tt y cantidad
            2.Contara con los metodos: depositar() ; consultar() ; retirar()
            3.Intereses mensuales de 3%
            
            Desarrollado por Jorge Arturo Salgado Garcia en Dev-C++ 4.9.9.2
*/
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
void menu();
void bienvenida();
void apertura();
struct Usuarios_TDD{
       int id;
       int fecha_reg;
       }usuario[10];
float cash_gral;//Contiene el dinero de la cuenta;
char op;
int cont,c,a;
short int opcion;//Donde cont=contador d' bucle; c=cant.d'apertura; a= ; opciones=num correspondiente a acciones
char tt[100],tt1[100];
class Cuenta{
      private:
              char titular;
              float cant;
              Usuarios_TDD id_of;
      public:
             Cuenta(char,float);//Constructor metodo
             Cuenta(Usuarios_TDD);
             void buscar(int);
             void depositar();
             void consultar();
             void retirar();
      };
Cuenta::Cuenta(char _nomTT,float cantidad){
                      titular = _nomTT;
                      cant = cantidad;
                      }
Cuenta::Cuenta(Usuarios_TDD _id){
                   id_of = _id;
                   }
void Cuenta::depositar(){
     float ci = 0;
     cant = cash_gral;//Asignamos monto de apertura
     cout<<"Buen dia "<<titular<<" su saldo es $"<<cant<<", \n ingrese la cantidad a depositar en su cuenta: "; 
     cin>>ci;
     cant = cant + ci;//A cantidad aniadimos monto ingresado
     cash_gral = cant+ci;//Actualizamos edo gral
     cout<<"Su saldo es->$"<<cash_gral<<endl;
     }
void Cuenta::consultar(){
     cout<<"Buen dia "<<titular<<" su saldo es->$"<<cash_gral;
     }
void Cuenta::retirar(){
     float cr = 0;
     cant = cash_gral;
     cout<<"Buen dia "<<titular<<", su saldo es->$"<<cant<<endl;
     cout<<"\tCuanto desea retirar->"; cin>>cr;
     if(((cash_gral-cr)<=100)&&((cash_gral-cr)>0)){//Monto minimo de 100
           cout<<"\aNo puede retirar esa cantidad, pues deben haber al menos $100 de reserva \n para conservar la cuenta"<<endl; 
           }else if(cash_gral<cr){
                 cout<<"\aError, ese monto excede su capital por $"<<cr-cash_gral<<endl;
                 }else{
                       cash_gral = cant-cr;
                       cout<<"Retire su efectivo"<<endl;
                       }
     cout<<"Su saldo es ahora de->$"<<cash_gral<<endl;
     }
void Cuenta::buscar(Usuarios_TDD id_unico){
     Usuarios_TDD n_u; bool efectivo = false;
     for(int i=0;i<10;i++){
             if(id_unico == n_u[i]){
                         menu(); efectivo = true;   
                         }
                         }
             if(efectivo==false){ cout<<"No se encontro la cuenta \n"<<endl; }
     }
int main(){
    bienvenida();
    //int cont,c,a;
//    short int opcion;//Donde cont=contador d' bucle; c=cant.d'apertura; a= ; opciones=num correspondiente a acciones
//    char tt[100],tt1[100];
    //cout<<"\a \t .:Bienvenido al cajero AdmIng:.\n"<<endl;
//    cout<<"Para aperturar ingrese nombre: "; cin>>tt; strupr(tt); system("Cls");
//    do{  
//       cout<<"Para validar confirme, confirme su nombre: "; cin>>tt1; strupr(tt1);
//       }while(strcmp(tt,tt1)!=0);
//    cont=0;
//    do{
//       fflush(stdin);
//       cout<<"Debe aperturar con al menos $100, con cuanto desea aperturar::"; cin>>c;
//       if(cont==3){
//                  cout<<"\aExcedio intentos para aperturar, lo sentimos"; getch(); exit(1); 
//                  }cont++; cash_gral = c;
//       }while(c<=100);
//    do{
//                       system("cls"); op='\0';
//                       Cuenta C(tt[100],cash_gral);//Creamos objeto
//                       cout<<"\a\t .:Menu Cajero basico AdmIng:.\n"<<endl;
//                       cout<<"\t1.Deposito.\n\t2.Consulta\n\t3.Retiro"<<endl;
//                       cout<<"Digite numero de opcion deseada->"; cin>>opcion;
//                       switch(opcion){
//                                      case 1: cout<<"\t\t::Depositar:: \n";
//                                              C.depositar(); break;
//                                      case 2: cout<<"\t\t::Consultar:: \n";
//                                              C.consultar(); break;
//                                      case 3: cout<<"\t\t::Retirar:: \n";
//                                              C.retirar(); break;
//                                      default: cout<<"opcion invalida"; 
//                                               break;
//                                      }
//                       cout<<"\n\nDesea realizar otra operacion S / N"; op=getch(); toupper(op);
//                       }while(op='S');
//    int dia=1;
//    dia++;
//    if(dia==30){
//                cash_gral*=1.03;
//                cout<<"Su saldo es de->$"<<cash_gral<<endl;
//                }
    system("pause"); return 0;
    }
void bienvenida(){
    Usuarios_TDD val;
    cout<<"\a \t .:Bienvenido al cajero AdmIng:.\n"<<endl;
    cout<<"Para apertura digite ( 1 )"<<endl;
    cout<<"Si ya tiene cuenta digite (2)"<<endl;
    cin>>opcion;
    switch(opcion){
                   case 1: apertura(); system("cls,pause,pause"); break;
                   case 2: //Cuenta c(val); 
                           cout<<"Ingrese su usuario: "; scanf("%i",val.id); val.fecha_reg = (rand()%1000) +1; Cuenta c(val);
                           c.buscar();
                           system("cls,pause,pause"); break;
                   default: system("cls,pause,pause"); bienvenida();  break;
                   }
     }
void menu(){
         do{
                       system("cls"); op='\0';
                       Cuenta C(tt[100],cash_gral);//Creamos objeto
                       cout<<"\a\t .:Menu Cajero basico AdmIng:.\n"<<endl;
                       cout<<"\t1.Deposito.\n\t2.Consulta\n\t3.Retiro"<<endl;
                       cout<<"Digite numero de opcion deseada->"; cin>>opcion;
                       switch(opcion){
                                      case 1: cout<<"\t\t::Depositar:: \n";
                                              C.depositar(); break;
                                      case 2: cout<<"\t\t::Consultar:: \n";
                                              C.consultar(); break;
                                      case 3: cout<<"\t\t::Retirar:: \n";
                                              C.retirar(); break;
                                      default: cout<<"opcion invalida"; 
                                               break;
                                      }
                       cout<<"\n\nDesea realizar otra operacion S / N"; op=getch(); toupper(op);
                       }while(op='S');
     }
void apertura(){
     cout<<"\a \t .:Bienvenido al cajero AdmIng:.\n"<<endl;
    cout<<"Para aperturar ingrese nombre: "; cin>>tt; strupr(tt); system("Cls");
    do{  
       cout<<"Para validar confirme, confirme su nombre: "; cin>>tt1; strupr(tt1);
       }while(strcmp(tt,tt1)!=0);
    cont=0;
    do{
       fflush(stdin);
       cout<<"Debe aperturar con al menos $100, con cuanto desea aperturar::"; cin>>c;
       if(cont==3){
                  cout<<"\aExcedio intentos para aperturar, lo sentimos"; getch(); exit(1); 
                  }cont++; cash_gral = c;
       }while(c<=100);
     }
