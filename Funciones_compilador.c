#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TAM_PILA 21
#define TAM_NOMBRE 20
/* El caracter 0 indica el número de posiciones ocupadas en el resto de la cadena */
//Gestion de tipos
typedef char pila_tipo[TAM_PILA];
void crearPila(pila_tipo tipo,char x){
	 tipo[0]=1;
	 tipo[1]=x;
	 tipo[TAM_PILA-1]=0;
	 }
void insertarPila(pila_tipo tipo,char x){
	 if(tipo[0] < TAM_PILA-2) tipo[++tipo[0]]=x;
	 	else printf("Tipo demasiado complejo.\n");
     }
void eliminarPila(pila_tipo tipo){
	 if(tipo[0] > 0) tipo[0]--;
	 }
char cimaPila(pila_tipo tipo) {
	 return tipo[tipo[0]];
	 }
void copiarPila(pila_tipo destino,pila_tipo origen){
	 strcpy(destino,origen);
	 }
void verPila(pila_tipo tipo){
	 unsigned char cont;
	 printf("El tipo es ");
	 for(cont=tipo[0];cont>0;cont--)
	 		  			 		 	switch(tipo[cont]){
													   case('i'): printf("un entero.\n"); break;
													   case('r'): printf("un real.\n"); break;
													   case('b'): printf("un booleano.\n"); break;
													   case('c'): printf("un caracter.\n"); break;
													   case('p'): printf("un puntero a "); break;
													   case('a'): printf("un array de "); break;
													   case('f'): printf("una funcion que devuelve "); break;
													   case('u'): printf("indefinido.\n"); break;
													   }//;
     }
/* Definición de la tabla de símbolos */
typedef struct _simbolo{
	 struct _simbolo * sig;
	 char nombre[TAM_NOMBRE];
	 pila_tipo tipo;
	 }simbolo;
void insertar(simbolo **p_t,char nombre[TAM_NOMBRE],pila_tipo tipo){
	 simbolo *s = (simbolo *) malloc(sizeof(simbolo));
	 		 strcpy(s->nombre, nombre);
	 		 strcpy(s->tipo, tipo);
	 		 s->sig = (*p_t);
	 		 (*p_t) = s;
	 }
simbolo *buscar(simbolo * t,char nombre[TAM_NOMBRE]){
		while ((t != NULL)&&(strcmp(nombre,t->nombre)))
			  	  t = t->sig;
				  return(t);
		};
void imprimir(simbolo *t){
	 while(t != NULL){
	 		 		  printf("%s. ",t->nombre);//arreglo char de 21
					  verPila(t->tipo);
					  t = t->sig;
					  }
    }
int main(){
//    insertar(simbolo ** p_t,char nombre[TAM_NOMBRE],pila_tipo tipo);
    imprimir(simbolo *t);
	system("pause");	return 0;
	}
