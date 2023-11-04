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
//Variables
short int i,j;
int mat[27][27], auxiliar[12];
char entrada;// Se recibe por medio de getch();
int ic;
char fun_string[15];//Almacena toda la exoresion, para recorrer y busca Signo (s) & Constante (c)
char *p,*s, *s1;
bool x=false, xn=false, xnNeg=false, neg = false, neg1=false;
int variables[] = {5,4,3,2,1,0,-1,-2,-3,-4,-5};
Fx expresion;
//Funciones
void captura();
void formatoGrafica();
void text();
void gotoxy(int ,int);
void tabla();
int main(){
	captura();
	cout<<endl;
	formatoGrafica();
	cout<<endl;
	gotoxy(20,70); system("pause"); return 0;
	}
void captura(){
	 ic = 0; i=0; ic=0; //bool x=false, xn=false, xnNeg=false, neg = false;
     cout<<"::Digita funcion::Presiona 'Esc' al terminar captura:: "<<endl;
	 while(!GetAsyncKeyState(0x1B)){//Mientras No 'Esc'  ->  !'Esc'
	 								fflush(stdin); entrada = getch();
									entrada = toupper(entrada); putchar(entrada); //Recibe letra y vuelve mayuscula
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
		 if(x && !neg){// X        =       X + C      X - C
		  	   for(i=0;i<11;i++)
               					 expresion.variable[i] = variables[i];
				  }
          else if(xn && !neg){ // NX    =    NX + C     NX - C
		  	   		  for(i=0;i<11;i++)
   		  			  					expresion.variable[i] = variables[i] * expresion.constante[0];
		  					  }
		  else if(neg && xnNeg){// -NX         ----->    -NX + C   ||   -NX - C
                                expresion.constante[0] = -expresion.constante[0];
				   	  		  	for(i=0;i<11;i++)
							 				   	 expresion.variable[i] = variables[i] * expresion.constante[0];
		            }
		else if(neg && xn){// -X     ---->     -X + C   ||   -X  - C
		                   for(i=0;i<11;i++)
                                             expresion.variable[i] = -variables[i];
		            }
          for(i=0;i<11;i++){
	      switch(*s1){
				     case '+': for(j=0;j<11;j++){
   					 	  	   if((x && !neg) || (neg && xn)){// X || -X    ..... +
									 expresion.resultado[j] = expresion.variable[j] + expresion.constante[0];
									 }else if((neg && xnNeg) || (xn && !neg)){ // -NX ||  NX     ... +
								 	  					 	 expresion.resultado[j] = expresion.variable[j] + expresion.constante[1];
		   						 	  						 }//Cierra else if
									  } break;
				     case '-': for(j=0;j<11;j++){
   					 	  	   					 if((x && !neg) || (neg && xn)){// X || -X    .....  -
  					  							 	   	  expresion.resultado[j] = expresion.variable[j] - expresion.constante[0];
														  }else if((neg && xnNeg) || (xn && !neg)){// -NX ||  NX     ...  -
								 	  					 	  expresion.resultado[j] = expresion.variable[j] - expresion.constante[1];
																	 }
						   						 }
							  break;
				     default:         s1++; 	      break;
				           }	} cout<<"\n"<<endl;
		 tabla();
     }
void tabla(){
     //   Imprime tabla
	 for(i=0,j=10; i<11,j>=0; i++,j--){
				   fflush(stdin);
                       if(x && !neg || xn && !neg || neg1){
	     			   		cout<<"X-> "<<setw(3)<<variables[i]<<" -> "<<setw(4)<<expresion.exp<<" = "<<setw(3)<<expresion.resultado[i]<<endl;
							}
							else{
							      auxiliar[j] = -expresion.resultado[j];
							      expresion.resultado[j] = auxiliar[j];
							      cout<<"X-> "<<setw(3)<<variables[i]<<" -> "<<setw(4)<<expresion.exp<<" = "<<setw(3)<<expresion.resultado[j]<<endl;
								  }
					   } cout<<endl;
					   formatoGrafica();
					   text();
	 }
void formatoGrafica(){
     int x=1,y=26;
     cout<<"f(x)->"<<expresion.exp<<endl;
//	 for(i=25;i>=0;i--){
//						gotoxy(1,y); printf("%i",i);  y++;//Imprime a 'i', inicia en 25 y decrece (Eje vertical Y`s)
//						for(j=1;j<=25;j++){
//						                   gotoxy(x,40); x++;
//										   }	}
//	 for(j=1;j<=25;j++){
//	                    gotoxy(x,40); cout<<setw(3)<<j;  x++;//Imprime a 'j', inicia en 1 y llega a 25 (Eje horizonal X`s)
//						 } printf("\n\n");
	 for(i=0;i<12;i++){//  X , Y ...
					   					gotoxy(variables[i]+26, expresion.resultado[i]+26); cout<<setw(3)<<"*"<<endl;
						} cout<<endl<<endl;
	 }
void text(){
	ofstream GRAFICA; GRAFICA.open("Grafica.txt",ios::out);
	int v = -25; int k, l;
    for(i=27,k=0;i>0;--i,k++){
					  for(j=27,l=0;j>0;--j,l++){
                                        if(mat[i][26] = i){
		  	 										   	   mat[j][26] = j;
														   }else
														   if(mat[i][j]==mat[variables[k]][expresion.resultado[l]]){
																  mat[i][j] = 8;
																  }  mat[i][j] = 0;
										  }      }
	for(i=27;i>0;i--){
					  for(j=1;j<27;j++){
										if(mat[i][j] == 0? GRAFICA<<setw(3)<<" " : GRAFICA<<setw(3)<<mat[i][j]);
							            } GRAFICA<<endl;  }
    for(j=-25;j<25;j++){
		  			    GRAFICA<<setw(3)<<j;  //Imprime a 'j', inicia en 1 y llega a 25 (Eje horizonal X`s)
 					    } GRAFICA<<"\n\n";
    GRAFICA.close();
	}
/*
	|   X^2 - X
	|
f(X)|
	|
	|   -X^2 + 3X
*/
void expresiones_pre(){//Partir de aqui para volver complejo el programa
	 float f,x;
	 printf("\n elige un valor para X: "); scanf("%f",&x);
	 /*		Seleccion del rango en que se encuentra X	*/
	 if(x <= 0.0 )	f = pow(x,2) - x;
	      else f = -pow(x,2) + 3*x;
	 printf("f(%.1f) = %.3f",x,f);
	 }
/*		Leer dato numerico X, cuyo valor debve ser mayor a 0 para calcular f(X) = X*log(X)		*/
void logaritmo_ejemplo(){
	 float f,x;
	 int x_positivo;
	 x_positivo = 0;
	 while(! x_positivo){
		  printf("\nValor de X: ");scanf("%f",&x);
		  x_positivo = (x > 0.0);//True(1) si cumple condicion
		}
	  f = x*log(x);
	  printf(" f(%1f) = %.3e",x,f);
	 }
void gotoxy(int x,int y){
	 HANDLE mCon;
	 COORD pos;
	 pos.X=x;
	 pos.Y=y;
	 mCon = GetStdHandle(STD_OUTPUT_HANDLE);
	 SetConsoleCursorPosition(mCon,pos);
	 }
