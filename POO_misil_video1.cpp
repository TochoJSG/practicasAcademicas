#include<iostream>//funciones de salida: cout, cin
#include<string.h>//Funciones para manipular cadenas: strcat(), toupper(), strupr()
#include<windows.h>//Funciones para manipular la consola: HANDLE, COORD
#include<stdlib.h>//Funciones system("comandos")
#include<stdio.h>//Funciones de entrada y salida: printf(), scanf()
#include<time.h>//Funciones de tiempo: Sleep(#). Y aleatorias: srand(), time(0)
#include<conio.h>//Funcion getch

#define ALTURA 15
#define BORDE 57

using namespace std;

char opciones; int velocidad; char nombre[10];

class Construccion{
	  int altura;
	  int ancho;
	  int coord_ubicacion;
	  public:
			 Construccion(int _altura,int _ancho,int ubicacion) : ancho(_ancho),altura(_altura),coord_ubicacion(ubicacion){}
			 void construir();
			 void coordenadas_construccion(int,int);
			 int ubicacion();
	  };
void Construccion::construir(){
	 if(altura>80? altura = 77 : altura);
	 if(ancho>10? ancho = 9 : ancho);
     if(coord_ubicacion>68? coord_ubicacion = 67 : coord_ubicacion);
	 for(int i=1;i<ancho;i++){
			 coordenadas_construccion(coord_ubicacion+i,altura); printf("%c",250);
			 }
	 for(int j=1;j<altura+2;j++){
  	 		 coordenadas_construccion(coord_ubicacion,j); printf("%c",186);
             coordenadas_construccion(coord_ubicacion+(ancho-1),j); printf("%c",186);
  			 }
     coordenadas_construccion(coord_ubicacion,altura); printf("%c",201);
	 coordenadas_construccion(coord_ubicacion+ancho,altura); printf("%c",187);
	 }
int Construccion::ubicacion(){
	return coord_ubicacion;
	}
void Construccion::coordenadas_construccion(int calle_x,int calle_y){
	 HANDLE terreno = GetStdHandle(STD_OUTPUT_HANDLE);
	 COORD lote;
	 lote.X = calle_x;
	 lote.Y = calle_y;
	 SetConsoleCursorPosition(terreno,lote);
	 }
class Misil{
	  public:
			int id;
			char _nombre[10];
			int velocidad_requerida;
			int recorrido_al_blanco;
			bool despegue;
			bool detonacion;
      public:
            Misil(char[10],int,bool);
//          ~Misil();
			void despegar(bool,struct Construccion &Edificio);
			void detonar(bool,int);//Recibe: Si o No a la detonacion , y la coordenada en la que va el misil
			void coordenada(int,int);
		   };
Misil::Misil(char nomb[10],int velocidad,bool _despegue){//Funcion contructor
				 int identificador = (rand()%100)+1;
                 do{
		   		 	strcat(strupr(nomb),"*");
		   			}while(strlen(nomb) < 10);
                 _nombre[10] = nomb[10];
                 
				 srand(time(NULL));
				 despegue = _despegue;

				 if(_despegue){
							   id = identificador;
                               if(velocidad > 300)
				                    velocidad_requerida = velocidad;
				                    else
				                        velocidad_requerida = 301;
							   }
				 }
void Misil::despegar(bool _despegue,struct Construccion &Edificio){
	 int i; char resp;
	 if(_despegue){//Se lanzo de inmediato
                   cout<<"\n\n\aMisil ::"<<id<<":: lanzado, presione Cualquier tecla para detonar antes\n"<<endl;
				   for(i=0;i<=BORDE;i++){
                                 Sleep(velocidad_requerida);
                                 system("cls");
			                     coordenada(i,ALTURA);   printf("    !%__________  ");
						         coordenada(i,ALTURA+1); printf(">>>>@  %s  /",_nombre);
					   	         coordenada(i,ALTURA+2); printf("    ¡/----------/ ");
					   	         if(kbhit()||Edificio.ubicacion() == i){//Apretar tecla detona antes o estar en la misma coordenada del edificio
									 		 recorrido_al_blanco = i;//No se completo el trayecto, recorrido parcial se vuelve el recorrido total
											 break;//Rompemos el bucle
											 }
								 }//Cierra for
						 recorrido_al_blanco = i;//Recorrido al blanco es igual al borde, pues 'i' llego al limite
						 Edificio.construir();
						 Misil::detonar(true,recorrido_al_blanco);
				   }else{//solo se creo el misil, y se esta en espera de lanzar
						 system("cls");
						 coordenada(7,ALTURA-3); cout<<"\n\aMisil ::"<<id<<":: creado y listo para lanzar"<<endl;
                         coordenada(7,ALTURA);   printf("    !%__________  ");                        //Imprimimos misil pero queda estatico
       					 coordenada(7,ALTURA+1); printf(">>>>@  %s  /",_nombre);
   	         			 coordenada(7,ALTURA+2); printf("    ¡/----------/ ");
   	         			 coordenada(7,ALTURA+4); cout<<"\nLanzar el misil::S::N";  resp = toupper(resp=getch()); system("cls");
   	         			 if(resp=='S'){//Se lanzo
                                       cout<<"\n\nPresione Cualquier tecla para detonar antes\n"<<endl;
                                       for(i=0;i<=BORDE;i++){
									   				 Sleep(velocidad_requerida);
									   				 system("cls");
								                     coordenada(i,ALTURA);   cout<<"    !%%________  "<<endl;
									   		         coordenada(i,ALTURA+1); cout<<">>>>@"<<_nombre<<"."<<endl;
									   	   	         coordenada(i,ALTURA+2); cout<<"    ¡/---------/ "<<endl;
									   	   	         if(kbhit()||Edificio.ubicacion()==i){//Cualq. tecla detona antes o llegar a la ubicacion del edificio
									   					 		 recorrido_al_blanco=i;//No se hizo todo el trayecto: recorrido_total=distancia_recorrida
									   							 break;//Rompemos el bucle
									   							 }
									   				}//Cierra for
						 			   recorrido_al_blanco = i;
						 			   Edificio.construir();
						 			   Misil::detonar(true,recorrido_al_blanco);
									   }//If de Si, en lanzamiento posterior
						 }//Ciera else, misil no fue lanzado directamente
	 }
void Misil::detonar(bool _detonar,int recorrido_al_blanco){
	 if(_detonar){
                  coordenada(recorrido_al_blanco,ALTURA);   cout<<"\a   *     *     *   "<<endl;
			      coordenada(recorrido_al_blanco,ALTURA+1); cout<<"\a     *   *   *     "<<endl;
			      coordenada(recorrido_al_blanco,ALTURA+2); cout<<"\a       * * *       "<<endl;
			      coordenada(recorrido_al_blanco,ALTURA+3); cout<<"\a-* * * * * * * * *-"<<endl;
			      coordenada(recorrido_al_blanco,ALTURA+4); cout<<"\a       * * *       "<<endl;
			      coordenada(recorrido_al_blanco,ALTURA+5); cout<<"\a     *   *   *     "<<endl;
			      coordenada(recorrido_al_blanco,ALTURA+6); cout<<"\a   *     *     *   "<<endl;
				  system("pause");
				  }
	 system("cls");
	 }
void Misil::coordenada(int x,int y){
	 HANDLE espacio_aereo = GetStdHandle(STD_OUTPUT_HANDLE);
	 COORD posicion;
	 posicion.X=x;
	 posicion.Y=y;
	 SetConsoleCursorPosition(espacio_aereo,posicion);
	 }
int main(){
	do{
		cout<<"De un nombre para el misil, maximo 10 caracteres::"; cin>>nombre; strupr(nombre);
	    cout<<"\nDigite la velocidad para misil::"<<nombre<<":: "; cin>>velocidad;
		cout<<"\nUnicamente obtener misil::S::N?"; opciones = toupper(opciones=getch());

		Misil objeto = Misil(nombre,velocidad,false);
		Construccion edificio = Construccion(30,5,67);//Parametros para construir el edificio
		if(opciones=='S')
						 objeto.despegar(false,edificio);
						 else
						 	 objeto.despegar(true,edificio);
		fflush(stdin); system("cls");
		cout<<"\n Crear otro misil::S::N::?"; opciones = toupper(opciones=getch());
		system("cls");
		}while(opciones=='S');
	system("pause");	return 0;
	}
