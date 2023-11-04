/*Algoritmo programa Ahorcado, funcion length()*/
#include<iostream>
#include<string.h>//Cadenas de caracteres
#include<conio.h>
using namespace std;
string original_word,word_console;
int vidas;
void mostrar();
void ingresar(char x);
void inicializar();
int main(){
    vidas=5;
    inicializar();
    mostrar();
    while(vidas>0&&word_console!=original_word){
                                                 char x;
                                                 cout<<"Digite una letra:  ";
                                                 fflush(stdin); cin>>x; system("cls"); 
                                                 ingresar(x); mostrar();                            
                                                 }
    if(vidas>0){cout<<"\n\tGanaste!!"<<endl;}else{
                                              cout<<"\n\tHas perdido, la palabra original era "<<original_word<<endl;
                                              }
    getch(); return 0;
    }
void mostrar(){
     cout<<"Vidas: "<<vidas<<endl;
     cout<<word_console<<endl;
     }
void inicializar(){
     int vidas=5;
     original_word="Ahorcado c++";
     for(int i=0;i<original_word.length();i++){
             if(original_word[i]>='A'&&original_word[i]<='Z'){
                                                              original_word[i]+=32;
                                                              }
             }
     for(int i=0;i<original_word.length();i++){
             if(original_word[i]>='a'&&original_word[i]<='z'){
                                                              word_console+='-';
                                                              }else{
                                                                    word_console+=original_word[i];
                                                                    }
             }
//     mostrar();  
     }
void ingresar(char x){
     bool lose_life=true;
     for(int i=0;i<original_word.length();i++){//i tiene que ser menor a numero de caracteres
//     original_word es string, pero se vuelve numero con funcion length()
             if(x==original_word[i]){
                                     lose_life=false;//falso que perdi vidas
                                     word_console[i]=x;
                                     }
             }
//   if conditional is TRUE     
     if(lose_life) vidas--;
     }
