/*Desarrollado en Dev C++ 5.0.0.4*/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<iostream>
#define MAX 50
using namespace std;
short int opcion;
FILE *f;
char o;
	int i=0;
int cont; string con, con1; float cn;
class Destino{
	  protected:
				int cve;
				string nomDestino;
				string horario;
				float precio;
	  public:
//			 Destino(int,string,string,float);//Constructor
//			 ~Destino();//Destructor
//           Metodos Getters && Setters
			 void setCve(int);
			 int getCve();
			 void setNom(string);
			 string getNom();
			 void setHor(string);
			 string getHor();
			 void setPrice(float);
			 float getPrice();
//		Metodos para polimorfismo
			 virtual void agregar(int,string,string,float);
			 virtual void modificar();
			 virtual void eliminar();
			 virtual void mostrar();
	  };
class Promocion : public Destino{
	  protected:
				int cvep;
				string nomDes;
				string horario;
				float preciop;
      public:
			 void agregar(int,string,string,float);
			 void modificar();
			 void eliminar();
			 void mostrar();
	  };
//Constructor
/*Destino::Destino(int _cve,string nom,string uhr,float price){
					 cve = _cve;
					 nomDestino = nom;
					 horario = uhr;
					 precio = price;
					 }
//~Destino::Destino(){}//Destructor*/
//Metodos ClaseMadre
void Destino::agregar(int a,string b,string c,float d){
//     d[i].setCve(cont); d[i].setNom(con); d[i].setHor(con1); d[i].setPrice(cn);
	 ofstream ag;
	 ag.open("BD.txt",ios::out);
	 ag<<"\nSu clave es->"<<a<<endl;
     ag<<"\nSu destino: "<<b<<endl;
     ag<<"\nSu horario: "<<c<<endl;
     ag<<"\nPrecio: "<<d<<endl;
     //d[i].setCve(cont); d[i].setNom(con); d[i].setHor(con1); d[i].setPrice(cn);
	 ag.close();
	 }
void Destino::modificar(){
	 cout<<"Modificacion de Datos\n";
	 }
void Destino::eliminar(){
	 cout<<"Eliminacion de Datos\n";
	 }
void Destino::mostrar(){
	 cout<<"Estos son los datos registrados\n";
	 cout<<"Clave->"<<getCve()<<endl;
	 cout<<"Destino->"<<getNom()<<endl;
	 cout<<"Horario->"<<getHor()<<endl;
	 cout<<"Precio->"<<getPrice()<<endl;
	 }
//Metodos Clase Hija
void Promocion::agregar(int,string,string,float){
//	 Destino::agregar(int,string,string,float);
	 cout<<"Agregar, con funcion promocion..."<<endl;
	 }
void Promocion::eliminar(){
	 Destino::eliminar();
	 cout<<"Eliminar a traves de funcion promocion..."<<endl;
	 }
void Promocion::modificar(){
	 Destino::modificar();
	 cout<<"Modificacion a traves de funcion promocion..."<<endl;
	 }
void Promocion::mostrar(){
	 Destino::mostrar();
	 cout<<"Muestra con funcion Promocion"<<endl;
	 }
//Getters&&Setters
void Destino::setCve(int _cve){
	 cve = _cve;
	 }
int Destino::getCve(){
	return cve;
	}
void Destino::setNom(string nom){
	 nomDestino = nom;
	 }
string Destino::getNom(){
	   return nomDestino;
	   }
void Destino::setHor(string uhr){
	 horario = uhr;
	 }
string Destino::getHor(){
	   return horario;
	   }
void Destino::setPrice(float price){
	  precio = price;
 	  }
float Destino::getPrice(){
	  return precio;
	  }
//FILE *f;
int main(){
    Destino d[MAX];
	for(;;){
			system("color 0f"); cout<<"Bienvenido, desea realizar operacion? S/N -> "; o = getch();
			if(toupper(o) == 'S'){
								  system("color 70"); /*Destino d;*/ Destino d[MAX];
//								  d = (*Destino) malloc(MAX*sizeof(Destino));
								  cout<<"\n\t     .:Seleccione numero de operacion deseada:.\n\n";
          						  cout<<"\t1.Agregar\n";
          						  cout<<"\t2.Modificar\n";
          						  cout<<"\t3.Eliminar\n";
          						  cout<<"\t4.Mostrar\n";
								  cout<<"Seleccione opcion-> "; cin>>opcion; cout<<endl;
								  switch(opcion){//Menu Basico de 4 Opciones
		  						                 case 1: f = fopen("Almacen.txt","w+"); srand(time(0)); cont = (rand()%999)+1;
			   		  	    				   		   	 cout<<"Su clave de registro es->"<<cont<<endl; //fprintf(f,"Clave->%d",&cont);
							   							 cout<<"Ingrese lugar de destino->"; cin>>con; //fprintf(f,"Destino->%s\n",&con);
									 					 cout<<"Ingrese horario de preferencia->"; cin>>con1; //fprintf(f,"Horario->%s\n",&con1);
													   	 cout<<"Ingrese precio de preferencia->"; cin>>cn; //fprintf(f,"Precio->%.2f",&cn);
													   	 d[i].agregar(cont,con,con1,cn);
  														 //d[i].setCve(cont); d[i].setNom(con); d[i].setHor(con1); d[i].setPrice(cn);
													   	 i++; //fwrite(&d,sizeof(&d),1,f);
													   	 fclose(f);
													   	 break;
												 case 2: cout<<"Modificacion de Datos\n"; d[i].modificar(); getch();
					   		   					 	  	 break;
											     case 3: cout<<"Eliminacion de Datos\n"; d[i].eliminar(); getch();
												 	     break;
												 case 4: /*d[i].setCve(cont); d[i].setNom(con); d[i].setHor(con1); d[i].setPrice(cn);
					   		   					 	  	 cout<<d[i].getCve()<<endl; cout<<d[i].getNom()<<endl;
					 									 cout<<d[i].getHor()<<endl; cout<<d[i].getPrice()<<endl; getch();*/
														 d[i].mostrar(); getch();
												   		 break;
                                                default: cout<<"Opcion Invalida\n"; getch();
												   		 break;
												   		 }system("cls");//Cierra switch
 												   		 }else{
															   exit(1);
															   }
			}//Cierra for
	system("pause"); return 0;
	}
