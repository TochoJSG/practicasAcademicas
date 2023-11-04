/*
  				CODIGO DEMO para FUNCIONES LINEALES
  				Resuleve funciones lineales, para constantes digitos, del tipo:
					§         X + C
					§        -X - C
					§         NX + C
					§        -NX - C
					*Muestra tabla del Contradominio
					*Sustituye en X valores del 5 al -5
					*Muestra orientacion de la grafica
				  Desarollado en Dev-C++ 5.0.0.4
				  Version completa, Funciones o caracteristicas especiales enviar correo para cotizar a->  jjorgess081@gmail.com
				  Precios desde $100.00 en trabajos y funciones nivel escolar.
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<math.h>
using namespace std;
struct Fx{
	   	  int constante[6];
	   	  int variable[13];//Almacenara val con X para operar versus constante
	   	  char exp[15];
		  int resultado[12];
		  };
//Variables Globales
short int i,j,ic;//Indices para bucle y subindices para arreglo
int auxiliar[12];
char entrada;// Se recibe por medio de getch();
char *p,*s, *s1;//Punteros analizan elementos
bool x=false, xn=false, xnNeg=false, neg = false, neg1=false;
int variables[] = {5,4,3,2,1,0,-1,-2,-3,-4,-5};//Constantes para sustituir
Fx expresion;//Variable tipo struct Fx permite acceso, almacenamiento y manipulacion de elementos del Struct
//Funciones
void gotoxy(int ,int);
void captura();
void formatoGrafica();
void text();
void tabla();
int main(){//Funcion principal
	captura();//Recibe datos y 'analiza'
	cout<<endl;
	gotoxy(4,20);	formatoGrafica();//Imprime comportamiento de grafica
	gotoxy(20,90); system("pause"); return 0;
	}
void captura(){
	 ic = 0; i=0; //bool x=false, xn=false, xnNeg=false, neg = false;
     cout<<"::Digita funcion:: "<<endl;
   	 while(!GetAsyncKeyState(0x1B)){//Mientras No 'Esc'  ->  !'Esc' , Finaliza recepcion y opera al oprimir ESC
	 								fflush(stdin); entrada = getch();
									entrada = toupper(entrada); putchar(entrada); //Recibe letra y vuelve mayuscula, putchar muestra en mayuscula
									expresion.exp[i] = entrada;//Arreglo de caracteres que almacena expresion completa
									p = expresion.exp;		s = expresion.exp;	s1 = expresion.exp;// 'p' busca variables & 's' busca signo
									if(p[0]=='X'? x=true: x=false);
									if(p[1]=='X'? xn=true: xn=false);
									if(p[2]=='X'? xnNeg=true: xnNeg=false);
									if(s[0]=='-'? neg=true: neg=false);
									if((s[0]=='-' )&&(s[2]=='-'||s[3]=='-')? neg1=true: neg1=false);
									if(isdigit(entrada)){//Se detecto digito
	 								 					 expresion.constante[ic] = atoi(&entrada); //Almacenamos en constante valor vuelto int por atoi
														 ic++;//Solo si se encontro digito se incrementa, struct admite max 8 elementos
	 													 } i++;// 'i' cuenta a todos los elemetos de la expresion
									 }//Cierra While entrada datos
     if(x && !neg){// X      Evaluara Variables independientes--------->      X + C      X - C
		  	   	  for(i=0;i<11;i++)	expresion.variable[i] = variables[i];
		 		  }else if(xn && !neg){ // NX    Evaluara variables acompañadas de constante------->    NX + C     NX - C
  		  		  	    for(i=0;i<11;i++)	expresion.variable[i] = variables[i] * expresion.constante[0];
	  	 			    }else if(neg && xnNeg){// -NX         Evaluara variables acompañadas de constante Negativas--------->    -NX + C   ||   -NX - C
   		 			   		  expresion.constante[0] = -expresion.constante[0];
   	  	 	  				  for(i=0;i<11;i++)	expresion.variable[i] = variables[i] * expresion.constante[0];
           		  			  }else if(neg && xn){// -X     Evaluara variables acompañadas de constante Negativa------->     -X + C   ||   -X  - C
              	  			 	    for(i=0;i<11;i++)	expresion.variable[i] = -variables[i];
		            			    }
     for(i=0;i<strlen(expresion.exp);i++){//Recorre la expresion, para evaluarla completa sin hacer el bucle pasadas de mas
	      switch(*s1){//Puntero case busca signo y opera la primera parte variable + la constante independiente
				     case '+': for(j=0;j<11;j++){
					   					 	  	 if((x && !neg) || (neg && xn))//   X   |   -X    .....   (+)
													   	  expresion.resultado[j] = expresion.variable[j] + expresion.constante[0];
														  else if((neg && xnNeg) || (xn && !neg))//   -NX   |   NX   ...   (+)
							 	  					 	 	   expresion.resultado[j] = expresion.variable[j] + expresion.constante[1];
								  						  	   }	break;
				     case '-': for(j=0;j<11;j++){
   					 	  	   					 if((x && !neg) || (neg && xn))//   X   |   -X    .....   (-)
  					  							 	   	  expresion.resultado[j] = expresion.variable[j] - expresion.constante[0];
														  else if((neg && xnNeg) || (xn && !neg))//   -NX   |   NX   ...   (-)
								 	  					 	   expresion.resultado[j] = expresion.variable[j] - expresion.constante[1];
						   						 			   }	break;
				     default:         s1++; 	      break;
         			 }//Cierra Case
						   } cout<<"\n"<<endl;//Ciera for i y da saltos de linea
		 tabla();
     }
void tabla(){//   Imprime tabla
	 for(i=0,j=10; i<11,j>=0; i++,j--){
                   if(x && !neg || xn && !neg || neg1){
     			   		cout<<"X-> "<<setw(3)<<variables[i]<<" -> "<<setw(4)<<expresion.exp<<" = "<<setw(3)<<expresion.resultado[i]<<endl;
						}else{
						      auxiliar[j] = -expresion.resultado[j];
						      cout<<"X-> "<<setw(3)<<variables[i]<<" -> "<<setw(4)<<expresion.exp<<" = "<<setw(3)<<auxiliar[j]<<endl;
							  expresion.resultado[j] = auxiliar[j];
							  }
					   } cout<<endl;
//					   text();
	 }
void formatoGrafica(){
     int x=1,y=26;
     cout<<"f(x)->"<<expresion.exp<<endl;
/*	 for(i=25;i>=0;i--){
						gotoxy(1,y); printf("%i",i);  y++;//Imprime a 'i', inicia en 25 y decrece (Eje vertical Y`s)
						for(j=1;j<=25;j++){
						                   gotoxy(x,40); x++;
										   }	}
	 for(j=1;j<=25;j++){
	                    gotoxy(x,40); cout<<setw(3)<<j;  x++;//Imprime a 'j', inicia en 1 y llega a 25 (Eje horizonal X`s)
						 } printf("\n\n");*/
	 for(i=0;i<12;i++){
					   gotoxy(variables[i]+25, expresion.resultado[i]+45); cout<<setw(5)<<"*"<<endl;//Imprime asterisco en coordenadas correspondientes, X & Y (Dominio y Contra dominio)
						} cout<<endl<<endl;
	 }
void gotoxy(int x,int y){
	 HANDLE mCon = GetStdHandle(STD_OUTPUT_HANDLE);
	 COORD pos;
	 pos.X=x;
	 pos.Y=y;
	 SetConsoleCursorPosition(mCon,pos);
	 }
