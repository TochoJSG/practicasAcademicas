#include<iostream>
#include<stdlib.h>
using namespace std;
class Punto{//Metodos Getters - Setters (Constructores y Modificadores)
	  private:
			  int x,y;
	  public:
//			 Punto();//Constructor
			 void setPunto(int,int);//Metodo Set es 'void'
			 int getPuntoX();//Punto por punto, pues tiene un solo return; int por el atributo
			 int getPuntoY();
	  };
//Punto::Punto()   ~
//				 }
void Punto::setPunto(int _x,int _y){
	 x = _x;
	 y = _y;
	 }
int Punto::getPuntoX(){
	return x;//Que quiero mostrar?...
	}
int Punto::getPuntoY(){
	return y;//Que quiero mostrar?...
	}
class Mamifero{
	  protected:
			  string nombre;
			  int edad;
	  public:
			 Mamifero(string,int);
			 ~Mamifero();
			 void leer();
			 virtual void correr();
			 virtual void mostrar();//Vistual palabra reservada de c para indicar polimosfismo(En metodos de clase padre)
			 virtual void coger();
			 virtual void mamar();
	  };
class Alumno : public Mamifero{
	  private:
			  float nota;
	  public:
			 Alumno(string,int,float);//nombre,edad,nota  (datos heredados)
             ~Alumno();
			 void mostrar();
//			 void correr();
	  };
class Profesor : public Mamifero{
	  private:
			  string asig;
	  public:
			 Profesor(string,int,string);
             ~Profesor();
			 void mostrar();
			 void correr();
	  };
class Valeria : public Mamifero{
	  private:
			  string actividad;
			  string culito;
			  string boquita;
	  public:
			 Valeria(string,int,string,string,string);
             ~Valeria();
			 void valeriar();
			 void correr();
			 void coger();
			 void mamar();
	  };
class Perro : public Mamifero{
	  private:
			  string raza;
	  public:
			 Perro(string,int,string);
			 ~Perro();//Destructor; Nombre de la clase; Elimina objetos de clase no usados, o al terminar vacia; Se crea por default
			 void correr();
			 void jugar();
	  };
//CONSTRUCTOR; Inicializar-Crear-CONSTRUIR atributos de la clase
Mamifero::Mamifero(string _nombre,int _edad){
						nombre = _nombre;
						edad = _edad;
						}
Mamifero::~Mamifero(){}
//Constructor heredado
Alumno::Alumno(string _nombre, int _edad, float _nota) : Mamifero(_nombre,_edad){
					  nota = _nota;
					  }
Alumno::~Alumno(){}
Profesor::Profesor(string _nombre,int _edad, string _asig) : Mamifero(_nombre,_edad){
						  asig = _asig;
						  }
Profesor::~Profesor(){}
Perro::Perro(string _nombre,int _edad, string _raza) : Mamifero(_nombre,_edad){
					raza = _raza;
					}
Perro::~Perro(){}
Valeria::Valeria(string _nombre,int _edad, string act,string qlo,string bok): Mamifero(_nombre,_edad){
					actividad = act;
					culito = qlo;
					boquita = bok;
					}
Valeria::~Valeria(){}
//Metodos polimorfistas
void Mamifero::mostrar(){
	 cout<<"Nombre->"<<nombre<<endl;
	 cout<<"Edad->"<<edad<<endl;
	 }
void Mamifero::coger(){
	 cout<<"Setsearse es natural ";
	 }
void Mamifero::mamar(){
	 cout<<"Son ricas las mamadas ";
	 }
	 
void Alumno::mostrar(){
	 Mamifero::mostrar();//notificamos que ya existe, es metodo polimosfista
	 cout<<"Nota final->"<<nota<<endl;//Aniadimos
	 }
void Profesor::mostrar(){
	 Mamifero::mostrar();
	 cout<<"Imparte->"<<asig<<endl;
	 }
void Mamifero::correr(){
	 cout<<"Hola soy "<<nombre<<" tengo "<<edad<<" y estoy corriendo\n";
	 }
void Perro::correr(){
	 Mamifero::correr();
	 cout<<" y me divierto mucho haciendolo\n";
	 }
void Valeria::correr(){
	 Mamifero::correr();
	 cout<<" y lo hago para ponerme mas rica para Jorge\n";
	 }
void Profesor::correr(){
	 cout<<"los fines de semana para el maraton politecnico";
	 }
void Valeria::coger(){
	 Mamifero::coger();
	 cout<<"y quiero duro hasta el fondo el pito de Jorge\n";
	 }
void Valeria::mamar(){
	 Mamifero::mamar();
	 cout<<"si es la verga de Jorge y si se viene en mi boquita\n";
	 }
//Declaracion metodos exclusivos, no poliformismo
void Mamifero::leer(){
	 cout<<"Hola soy "<<nombre<<" tengo "<<" y estoy leyendo un libro\n";
	 }
void Perro::jugar(){
	 cout<<"Me llamo "<<nombre<<" y juego con una rama\n";
	 }
void Valeria::valeriar(){
	 cout<<"Soy "<<nombre<<" tengo "<<edad<<" ahorita estoy "<<actividad<<" tengo un@ "<<culito<<" en mi culito\n sucio y "<<boquita<<" en mi boquita\n";
	 }
//Funcion principal
int main(){
//  Polimorfismo usa punteros
	Mamifero *vector[2];
	vector[0] = new Alumno("Valeria 'Ricolina' Soto",17,6);
	vector[0]->mostrar();
	Mamifero p("Valeria 'La sabrocita' Soto", 15);
	p.correr();
//  Practica Getter Setter
	Punto p1;
	p1.setPunto(15,17);
	cout<<p1.getPuntoX()<<endl;
	cout<<p1.getPuntoY()<<endl;
 	Valeria vale("Valeria",14,"en cuatro","faldita","Verga");
	vale.valeriar();
	vale.coger();
	vale.mamar();
	vale.correr();
	vector[1] = new Profesor("Coronel",50,"Programacion");
	vector[1]->correr();
	vector[1]->mostrar();
	system("pause"); return 0;
	}

