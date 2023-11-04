#include<stdio.h>
#include<stdlib.h>
typedef struct _simbolo{
	struct _simbolo *sig;
		  char nombre[20];
		  char tipo;
		  union{
		  		char valor_cad[100];
		  		int valor_int;
		  		}info;
	  }simbolo;
void insertar(simbolo **p_t,simbolo *s){
  s->sig = (*p_t);
  (*p_t) = s;
  }
simbolo *buscar(simbolo *t, char nombre[20]){
while((t != NULL)&&(strcmp(nombre,t->nombre)))
  t = t->sig;
  return (t);
  }
void imprimir(simbolo *t){
	 while(t != NULL){
	 		 		  printf("%s:%c: ", t->nombre, t->tipo);
					  if(t->tipo == 'c') printf("%s\n", t->info.valor_cad);
					  			 else if(t->tipo == 'e') printf("%d\n", t->info.valor_int);
					  			 	  			 else printf("Indefinido\n");
					  t = t->sig;
  					  }
  }
