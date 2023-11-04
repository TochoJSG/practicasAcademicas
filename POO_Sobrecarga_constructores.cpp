#include<iostream>
#include<stdlib.h>
using namespace std;
class Tiempo{
      private:
              int horas,minutos,segundos;
      public:
             Tiempo(int,int,int);//Cons1
             Tiempo(int);//Cons2
             void mostrarTiempo();
      };
Tiempo::Tiempo(int _horas,int _min,int _segs){
                   horas = _horas;
                   minutos = _min;
                   segundos = _segs;
                   }
Tiempo::Tiempo(int tiempoSegs){
                   horas = tiempoSegs / 3600;//Extraer horas
                   tiempoSegs %= 3600;//Segs sobrantes, que no acompletan una hora 
                   minutos = tiempoSegs / 60;//Extraer minutos
                   segundos = tiempoSegs % 60;//Extraer segundos
                   }
void Tiempo::mostrarTiempo(){
     cout<<"La hora es: "<<horas<<":"<<minutos<<":"<<segundos<<endl;
     }
int main(){
    Tiempo hora(16,26,30);
    Tiempo hora1(16000);
    hora.mostrarTiempo();
    hora1.mostrarTiempo();
    system("pause");        return 0;
    }
