#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int opc;
char ccupon[7]={"verano"},ccupon_user[7];
float add=0.0,add_desc, lista_precios[]={0,50.85,10.89,80.45,0};
//funciones
void menu();
void detalles_compra();
main(){
     menu();
     getchar(); return 0;
     }
void menu(){
     cout<<"1.Monitor\t\t$50.85 USD "<<endl;
     cout<<"2.Teclado\t\t10.89 USD "<<endl;
     cout<<"3.Impresora\t\t80.45 USD "<<endl;
     cout<<"4.finalizar compra  "<<endl;
     do{
     cout<<"Digite numero de articulo: "<<endl; cin>>opc; fflush(stdin);
     add+=lista_precios[opc];
     }while(opc<4);
     if(opc>=4){ detalles_compra();/*cout<<add<<endl;getchar();*/}
     }
void detalles_compra(){
     int cupon;
     cout<<"Cuenta con cupon de descuento? si=1 / no=0"<<endl; fflush(stdin); cin>>cupon; getchar();
     if(cupon==0){
                  cout<<"Su cuenta a pagar es de $"<<add<<endl;
                  }else if(cupon==1){
                        cout<<"Digite cupon de descuento "<<endl;
                        cin.getline(ccupon_user,'\n');
                        if(strcmp(ccupon,ccupon_user)==0){
                                                          add_desc=add*.90;
                                                          cout<<"Descuento aplicado"<<endl;
                                                          cout<<"Monto a pgar es $"<<add_desc<<endl;
                                                          }else{
                                                                cout<<"Cupon invalido, monto a pagar "<<add<<endl;
                                                                }                        
                                                          }
     }
