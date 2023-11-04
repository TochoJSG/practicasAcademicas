#include<iostream>
#include<stdlib.h>
using namespace std;
class Persona{
	  private://Solo para metodos de esta
		      int edad;
			  string nombre;
	  public:
			 void leer();
			 void correr();
	  };
//CONSTRUCTOR; Inicializar-Crear-CONSTRUIR atributos de la clase
Persona::Persona(int _edad,string _nombre){
					 edad = _edad;
					 nombre = _nombre;
					 }
void Persona::leer(){
	 cout<<"Soy "<<nombre<<" tengo "<<edad<<" y leo un libro\n";
	 }
void Persona::correr(){//indico que persona corre, perro , chango.. tambien corren(Referente a poliformismo)
	 cout<<"Soy "<<nombre<<" tengo "<<edad<<" y estoy corriendo una maraton\n";
	 }
int main(){
	Persona p = Persona(20,"Jorge");
	p.leer();
	Persona p1(19,"Valeria");
	system("pause"); return 0;
	}

