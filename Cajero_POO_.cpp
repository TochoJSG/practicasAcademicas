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
float cash_gral;//Contiene el dinero de la cuenta;
using namespace std;
//float cash_gral;//Contiene el dinero de la cuenta;
class Cuenta{
      private:
              string titular;
              float cant;
      public:
             Cuenta(string,float);//Constructor metodo
             void depositar();
             void consultar();
             void retirar();
      };
Cuenta::Cuenta(string _nomTT,float cantidad){
                      titular = _nomTT;
                      cant = cantidad;
                      }
void Cuenta::depositar(){
     float ci = 0;
     cant = cash_gral;//Asignamos monto de apertura
     cout<<"Buen dia "<<titular<<" su saldo es $"<<cant<<", ingrese la cantidad a ingresar en su cuenta: "; 
     cin>>ci;
//     cant = cant + ci;//A cantidad aniadimos monto ingresado
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
     if((cash_gral-cr)<=100){//Monto minimo de 100
           cout<<"No puede retirar esa cantidad, pues deben haber al menos $100 de reserva para conservar la cuenta"<<endl; 
           }else if(cash_gral<cr){
                 cout<<"Error, ese monto excede su capital por $"<<cr-cash_gral<<endl;
                 }else{
                       cash_gral = cant-cr;
                       }
     cout<<"Su saldo es ahora de->$"<<cash_gral<<endl;
     }
int main(){
    int cont,c,a;
    short int opcion;//Donde cont=contador d' bucle; c=cant.d'apertura; a= ; opciones=num correspondiente a acciones
    string tt,tt1;
    char op;
    cout<<"\a \t .:Bienvenido al cajero AdmIng:.\n"<<endl;
//    do{
       cout<<"Para aperturar ingrese nombre: "; cin>>tt; //strupr(tt); system("Cls");
//       cout<<"Confirme su nombre: "; cin>>tt1; strupr(tt1);
//       }while(strcmp(tt,tt1)!=0);
    cont=0;
    do{
       fflush(stdin);
       cout<<"Debe aperturar con al menos $100, con cuanto desea aperturar::"; cin>>c;
       if(cont==3){
                  cout<<"\aExcedio intentos para aperturar, lo sentimos"; getch(); exit(1); 
                  }cont++; cash_gral = c;
       }while(c<=100);
       
    do{
                       system("cls");
                       Cuenta C(tt,cash_gral);//Creamos objeto
                       cout<<"\a\t .:Menu Cajero basico AdmIng:.\n"<<endl;
                       cout<<"\t1.Deposito.\n\t2.Consulta\n\t3.Retiro"<<endl;
                       cout<<"Digite numero de opcion deseada->"; cin>>opcion;
                       switch(opcion){
                                      case 1: cout<<"Depositar \n";
                                              C.depositar(); break;
                                      case 2: cout<<"Consultar \n";
                                              C.consultar(); break;
                                      case 3: cout<<"Retirar \n";
                                              C.retirar(); break;
                                      default: cout<<"opcion invalida"; 
                                               break;
                                      }
                       cout<<"\n\nDesea realizar otra operacion? S / N "; op=getch();
//                       toupper(op);
                       }while(op='S');
//    int dia=1;
//    dia++;
//    if(dia==30){
//                cash_gral*=1.03;
//                cout<<"Su saldo es de->$"<<cash_gral<<endl;
//                }
    system("pause"); return 0;
    }
