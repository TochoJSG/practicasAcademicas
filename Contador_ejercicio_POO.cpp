#include<iostream>
#include<conio.h>
using namespace std;
class Contador{
      private:
              unsigned int cuenta;
      public:                                   //  contar
             Contador() { cuenta = 0; }         //  constructor
             void inc_cuenta() {cuenta++;}      //Cuenta
             int leer_cuenta(){return cuenta;}  //Devuelve cuenta
      };
int main(){
     Contador c1,c2;//Define e inicializa
     cout<<"\nC1="<<c1.leer_cuenta();
     cout<<"\nC2="<<c2.leer_cuenta();
     
     c1.inc_cuenta();
     c2.inc_cuenta();
     c2.inc_cuenta();
     c2.inc_cuenta();
     c2.inc_cuenta();
     c2.inc_cuenta();
     
     cout<<"\nC1="<<c1.leer_cuenta();
     cout<<"\nC2="<<c2.leer_cuenta();
     getch(); return 0;
     }
