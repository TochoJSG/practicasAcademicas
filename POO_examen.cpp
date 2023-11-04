#include<iostream>
#include<conio.h>
using namespace std;
class Estetica{
      public:
             int precio,cantidad,gran_total;
             string descripcion;
      public:
             void dar_descripcion(){
                  cout<<"Dar descripcion: "; scanf("%s",&descripcion); cout<<endl;
                  }
             int cuenta(){
                 int Gran_total;
                 Gran_total = precio * cantidad;
                 gran_total = Gran_total;
                 return Gran_total;
                 }
             void mostrar(){
                  cout<<"Precio "<<precio<<endl;
                  cout<<"Cantidad "<<cantidad<<endl;
                  cout<<"Gran total "<<gran_total<<endl;
                  cout<<"Descripcion "<<descripcion<<endl<<endl;
                  }
      };
int main(){
    Estetica obj;
    obj.dar_descripcion();
    cout<<"Ingrese Precio de producto "; cin>>obj.precio;
    cout<<"Ingrese cantidad de producto "; cin>>obj.cantidad;
    obj.cuenta();
    obj.mostrar();
    getch(); return 0;
    }
