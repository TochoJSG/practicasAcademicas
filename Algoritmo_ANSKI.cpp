/*Programa pra ayudar al estudio de cualquier materia; ALGORITMO ANSKI*/
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<string.h>
using namespace std;
int i,cant_question,tiMe;
struct general{
       char question[100];
       char answer_base[100];
       char answer_user[100];
       }general[10];
void comenzar();
int valida();
int main(){
//   Almacenamiento decantidad de preguntas  
     cout<<"Digite cantidad de preguntas para estudiar:   "; scanf("%2i",&cant_question); system("Cls");
     for(i=1;i<=cant_question;i++){
                                   fflush(stdin);
                                   printf("\t*Digite su pregunta [%i]:  ",i); gets(general[i].question);
                                   printf("\nDigite la respuesta a pregunta [%i]:  ",i); gets(general[i].answer_base);
                                   system("Cls");                                   
                                   }
     cout<<"CUANTOS SEGUNDOS DESEA PARA REPASAR HACER MEMORIA:  "; scanf("%d",&tiMe);
//   Cuenta regresiva antes de preguntar  
     for(tiMe=tiMe;tiMe>=0;tiMe--){//cuenta regresiva
                          Sleep(1000);//intervalo d' 1s
                          printf("\rTiempo restante para iniciar[ %i ]",tiMe);
                          if(tiMe==0){comenzar();}
                          }
     getch(); return 0;
     }
void comenzar(){
     for(i=1;i<=cant_question;i++){
                                  system("Cls"); fflush(stdin);//Comenzamos a preguntar
                                  cout<<"Responda pregunta ["<<i<<"]:  "<<general[i].question<<endl;
                                  gets(general[i].answer_user);
                                  if(valida()==1){//Respuesta fue correcta
                                                   cout<<"\nFelicidades, tienes buena memoria"<<endl; getch();
                                                   }else{
                                                         cout<<"\nRespuesta incorrecta, estudia mas"<<endl;
                                                         getch(); comenzar();//FUNCION RECURSIVA, llamar a la funcion
                                                         }
                                  }
     }
int valida(){//return 1=TRUE ; return 0=FALSE
    if(strcmp(general[i].answer_base,general[i].answer_user)==0){
                    return 1;
                    }else{
                          return 0;
                          }
    }
