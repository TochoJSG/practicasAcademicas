#include<iostream>
#include<stdlib.h>
#define NULL 00
using namespace std;
typedef int tipo;
class Rectangulo{
      private:
              tipo largo,ancho;
      public:
             Rectangulo(tipo,tipo);
             tipo perimetro(tipo,tipo);
             tipo area(tipo,tipo);
             /*void perimetro();
             void area();*/
      };
Rectangulo::Rectangulo(tipo _largo,tipo _ancho){
                            largo = _largo;
                            ancho = _ancho;
                            }
tipo Rectangulo::perimetro(tipo _largo,tipo _ancho){
     return ((2*_largo) + (2*_ancho));
     }
tipo Rectangulo::area(tipo _largo, tipo _ancho){
     return (_largo * _ancho);
     }
/*
void Rectangulo::perimetro(){
     tipo peri;
     peri = (2*_largo) + (2*_ancho);
     cout<<"El perimetro es  "<<peri<<endl;
     }
void Rectangulo::area(){
     tipo _area;
     area = _ancho * _largo;
     cout<<"El area del rectangulo  "<<_area<<endl;
     }
*/
int main(){
    Rectangulo figura(00,00);
    cout<<"El area de un rectangulo de 10 * 5 es:   "<<figura.area(10,5)<<endl;
    cout<<"El perimetro de un rectangulo de 10 * 5 es:  "<<figura.perimetro(10,5)<<endl;
    system("pause");   return 0;
    }
