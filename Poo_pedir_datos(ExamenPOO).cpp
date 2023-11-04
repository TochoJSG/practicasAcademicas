#include<iostream>
#include<conio.h>
using namespace std;
class Estetica{
      public:
             int precio,cantidad,gran_total;
             string descripcion;
      public:
             void dar_descripcion(){
                  cout<<"Dar descripcion: "; scanf("%s",descripcion);
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
                  cout<<"Gran total "<<gran_total;
                  }
      };
int main(){
    Estetica obj;
    obj.dar_descripcion();
    cout<<"Ingrese Precio de producto "; cin>>obj.precio;
    cout<<"Ingrese cantidad de producto "; cin>>obj.cantidad;
    cout<<"Gran total = "; obj.cuenta();
    cout<<obj.mostrar();
    getch(); return 0;
    }
