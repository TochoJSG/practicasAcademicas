#include<iostream>
#include<fstream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
using namespace std;
typedef char c;
typedef int e;
typedef float f;
typedef string s;
struct Product{
	c cve;
	c name;
	f cost;
	f price;
	}*producto;
struct TochaNetworth{
	f patrimonioNeto;
	f inventario;
	f utilidad;
	f perdida;
	struct Product mercancia;
	}finanzas;
void gotoxy(e y,e x){
     HANDLE hCon;
     COORD dwPos;
     dwPos.X=x;
     dwPos.Y=y;
     hCon=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hCon,dwPos);
     }
f c_t,c_u;
f p_e_u,p_e_c,p_g_u,p_g_c,p_e_u1,p_e_c1,p_g_u1,p_g_c1,investment;
e i,ex,contenido;
s linea;
c name[12],opcion;
//e x=1; 
//c o,opc
void asterisco();
void registro();
void info();
void genera();
void agregar();
void busqueda();
void menu();
void m_info();
void borrar();
void muestra();
void f_borrar();
void relog();
void date();
void IniciaLista();
void muestra_info();
e main(){
         menu();
         getch(); return 0;
         }
void menu(){
     e opcion; system("color 1A");
     gotoxy(1,25); printf("::GESTION MATERIAS PRIMAS::");
     cout<<"Inventario Actual "<<finanzas.inventario<<endl;//Pruebas, quitar luego.... o no...
     cout<<"\t.::|VENTA|::."<<endl;
     printf("\n\n"); cout<<"\t1.Reiniciar/Iniciar "<<endl;
     cout<<"\n\t2.Mostrar LISTA"<<endl;
     cout<<"\n\t3.Agregar"<<endl;
     cout<<"\n\t4.Mostrar INFORMACION"<<endl;
     cout<<"\n\t5.Buscar producto"<<endl;
     cout<<"\n\t6.Modificar producto"<<endl;
     cout<<"\n\t7.Borrar Producto"<<endl;
     cout<<"\n\t8.Agenda/Calendario"<<endl;
     cout<<"\n\t9.Esperanza"<<endl;
     cout<<"\n\t10.Salir"<<endl;
     cout<<"Digite el numero de la opcion deseada:  "; fflush(stdin); cin>>opcion;
     system("Cls");
     switch(opcion){
                            case 1: registro(); break;
                            case 2: genera(); break;
                            case 3: agregar(); break;
                            case 4: m_info(); break;
                            case 5: busqueda(); break;
                            case 7: f_borrar(); break;
                            case 10: exit(1);
                            default: system("Cls"); cout<<"OPCION INVALIDA, PRESIONE UNA TECLA"<<endl; getch(); menu();
                            }
     }
void registro(){
     e x=1; 
     c o,opc;
     cout<<"\t\t\t**INICIO-REINICIO**\n"<<endl;
     cout<<"\tINSTRUCCIONES"<<endl;
     cout<<"1.Leer con atencion lo que se pide"<<endl;
     cout<<"2.Digitar los datos conforme se vayan solicitando"<<endl;
     cout<<"3.Cuidar presionar Enter o cualquier otra tecla no"<<"\n"<<"solicitada, pues la captura quedara errada"<<endl;
     cout<<"-------------------------------------------------"<<endl; 
     cout<<"ADVERTENCIA  ->  Si previamente YA se habia iniciado TODO lo anterior se BORRARA"<<endl;
     cout<<"\tDesea continuar   S / N  "; fflush(stdin); cin>>opcion; 
     if(opcion=='S'||opcion=='s'){
                                  IniciaLista(); system("pause");
                                  }else{
                                        system("Cls"); menu();
                                        } x+=10;
                if(o!='s'||o!='S'){menu();}
     }
void genera(){
     string dato;
     ifstream muestra;
     muestra.open("lista.txt",ios::in);
     if(muestra.fail()){cout<<"[No se pudo obtener la lista]"<<endl;}else{
     while(!muestra.eof()){
                           system("color f0");
                           getline(muestra,dato);
                           cout<<setw(3)<<dato<<endl;
                           }
     }
     muestra.close();
     cout<<"\nPOR FAVOR,presione una tecla para volver al menu..."<<endl;
     getch(); system("Cls"); menu();
     }
void agregar(){
     e x=1; system("color 70");
     c o,opc;
     ofstream BD;
     ofstream info;
     info.open("Info.txt",ios::app);
     BD.open("Lista.txt",ios::app);
     if(BD.fail()){ cout<<"[No se puede agregar producto en este momento] "<<endl;}else{
     do{
        cout<<"Cual es el nombre del producto:  "; fflush(stdin); 
        cin.getline(name,12); strupr(name); printf("\n"); BD<<name<<"  ->  ";
        cout<<"Cual fue el costo por Caja/Bulto/Otro:  "; fflush(stdin); 
        cin>>c_t; printf("\n"); BD<<c_t<<"  ->  ";
        cout<<"Cuantas Unidades/kilos/Otros contiene Caja/Bulto/Otro:  "; fflush(stdin); 
        cin>>contenido; printf("\n"); BD<<contenido<<"  ->  "; 
        c_u=c_t/contenido;//posible error *conv. de tipos, checar*/           
        cout<<"Cuantas Caja(s)/Bulto(s)/Otro(s) se compraron:  "; fflush(stdin); cin>>ex; 
        printf("\n"); BD<<ex<<"  ->  "; finanzas.inventario += investment=c_t*ex; //posible error *conv. de tipos, checar
        BD<<"\n\n";
        time_t tiempo=time(NULL);//variables donde guardo el valor de la funcion time.
        struct tm *tlocal=localtime(&tiempo); //estructura donde obtengo el tiempo
        char output[11]; //array donde guardo la fecha
        strftime(output,11,"%d/%m/%y",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
        info<<"\t\t\t"<<" :: "<<output<<"  ->  "<<name<<" ::"<<endl;
        info<<"\tSe hizo una inversion de Total de:   $"<<investment<<"\n"<<endl;
        info<<"\tDonde el Costo unitario es de:   $"<<c_u<<"\n"<<endl;
        info<<"\tSe recomienda un Precio Unitario entre $"<<c_u*1.2<<" y $"<<c_u*1.3<<"\n"<<endl;
        info<<"\tPor Caja/Bulto/Otro de entre   $"<<c_t+5<<" y  $"<<c_t+10<<"\n"<<endl;
        info<<"\tPor vta. unitaria se esperaria ganancia entre $"<<c_t*.2<<" y  $"<<c_t*.3<<"\n"<<endl;
        system("cls"); cout<<"Desea ver AHORA la Informacion generada?  S/N "<<endl; fflush(stdin); opc=getch(); system("cls");
        if(opc=='s'||opc=='S'){muestra_info();}
        cout<<"Desea introducir otro producto?   S/N  "<<endl; o=getch(); system("cls");
        }while(o=='s'||o=='S');
    x+=10; BD.close(); info.close();
    if(o!='s'||o!='S'){menu();}
    	}//else
     }
void m_info(){
     ifstream val;
     string valor;
     val.open("Info.txt",ios::in);
     if(val.fail()){system("Cls");cout<<"No se pudo abrir la informacion"<<endl;}
     while(!val.eof()){
                       system("color f0");
                       getline(val,valor);
                       cout<<setw(3)<<valor<<endl;
                       }
     asterisco();
     val.close();
     cout<<"\nPOR FAVOR, presione una tecla para volver al menu..."<<endl;
     getch(); system("cls"); menu();
     }
void busqueda(){
      FILE *Fd;
      c palabra[30],texto[500],vale;
      e i,tmp1,tmp2,konta; system("color 30"); 
      do{
      konta=0;
      cout<<"\nDigite Producto a buscar: ";
      cin>>palabra; strupr(palabra); 
      Fd=fopen("Info.txt", "r");
      if(Fd==NULL){cout<<" [ Error ] "<<endl;}
      while(feof(Fd)==0){
            fgets(texto,500,Fd);
            for(
            i=0;i<strlen(texto);i++){                            
               if(palabra[0]==texto[i]){
                  tmp1=0; tmp2=i;
                  while((palabra[tmp1]==texto[tmp2])&&(tmp2<strlen(texto))&&(tmp1!=strlen(palabra))){
                        tmp1++; tmp2++;
                        if(tmp1==strlen(palabra))
                           konta++; } } } }
                           if(konta>1){
                                       printf("\n\tHay %d Productos registradas con ese nombre\n",konta);
                                       getch();
                                       }else if(konta==0){
                                       printf("\n\tNO existe registro de ese Producto\n"); getch();
                                       }else if(konta==1){
                                             cout<<"\n\tHay un Producto registrado con ese nombre\n"<<endl; getch();
                                             }
      system("Cls");
      cout<<"\nDesea buscar otro producto? S/N\n"; fflush(stdin); vale=getch();
      system("Cls");
      }while(vale=='S'||vale=='s'); cout<<"Digite una tecla para volver a menu..."<<endl; getch();
      menu(); 
}
void borrar(){
        ifstream archivo("Info.txt");
        ofstream nuevo;
        nuevo.open("temporal.txt", ios::out);
        e cont=0,ln,i=0,n;
        muestra();
        cout<<"Escribe un numero: ";
        fflush(stdin);
        cin>>ln;
        n=ln+11;
        while(getline(archivo, linea)){                              
                if( (ln==cont) && (ln<n-1) ){ // si condicion es true, se encontro la linea 
                            cout<<" borrado "<<endl; // encontro linea solicitada 
                            ln++;
                            }else{
                            	nuevo<<linea<<endl;
							}
                cont++; // Contador aumenta en caso de NO ser igual a linea deseada con el contador de lineas 
                }
        archivo.close();
        nuevo.close();
        remove("Info.txt");                 
        rename("temporal.txt", "Info.txt");				
            }
void muestra(){
        ifstream file1("Info.txt");
        e j=0,cont1=1,i=1,line=1; 
        while(getline(file1,linea)){                               
                if((line==cont1)){ // si condicion es true, se encontro la linea 
                            cout<<"Digite  ["<<j<<"]  para borrar la informacion de usuario "<<i<<endl; 
                            cout<<"PRODUCTO "<<i<<setw(3)<<" -> "<<linea<<"\n"<<endl;
                            line=line+11; i++;/*cuenta elementos de lista a borrar*/ j=j+11;/*numero de linea en que esta*/
                            }
                cont1++;     
                }
        file1.close(); printf("\n\n");
        }
void f_borrar(){ 
     c d;
     do{ 
                borrar(); cout<<"\n";
                cout<<"Desea eliminar otro elemento?  "; fflush(stdin); d=getch();
                system("Cls");
                }while(d=='s'||d=='S');
     }
void asterisco(){
    unsigned int x=10,y=6;
    gotoxy(x,y); printf("*");
    while(!(GetAsyncKeyState(VK_LSHIFT))){//while(1)==bucle infinito, esperamos a que teclasea presionada
             Sleep(100);//intervalo-pausa para que bucle no corra demasiado rapido
//                                      Left(-);Right(+)  
    if(GetAsyncKeyState(0x28)){//if DOWN, codigo predefinido
                                        gotoxy(x,y); printf(" ");//borramos anterior posicion de *, si if==true  
                                        x++;//modif. posicion eje Y
                                        gotoxy(x,y); printf("*");//pasamos nueva posicion
                                        }
    if(GetAsyncKeyState(0x26)){//if UP, codigo predefinido
                                        gotoxy(x,y); printf(" ");//borramos anterior posicion de *, si if==true  
                                        x--;//modif. posicion eje Y
                                        gotoxy(x,y); printf("*");//pasamos nueva posicion
                                        }
             }
    }                                                                    
void relog(){
    SYSTEMTIME stBuffer;
    c buffer[9];
    while(1){
    GetLocalTime(&stBuffer);
    GetTimeFormat(LOCALE_SYSTEM_DEFAULT,TIME_FORCE24HOURFORMAT,&stBuffer,"hh':'mm':'ss",buffer,sizeof(buffer));
    printf("\r%s",buffer);}
	}
void date(){
    time_t tiempo = time(NULL);//variables donde guardo el valor de la funcion time. 
    struct tm *tlocal = localtime(&tiempo); //estructura donde obtengo el tiempo 
    c output[11]; //array donde guardo la fecha
    strftime(output,11,"%d/%m/%y",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
    printf("%s",output);
    }
void IniciaLista(){
     system("color 70"); ofstream bd;
     ofstream informacion; 
     informacion.open("Info.txt",ios::out);//create data file .txt
     bd.open("Lista.txt",ios::out);
     if(bd.fail()){ cout<<"[No se puede agregar producto en este momento]"<<endl;}else{
     do{
                cout<<"\nCual es el nombre del producto:  "; fflush(stdin); 
                cin.getline(name,12); strupr(name); printf("\n"); bd<<name<<" ";
                cout<<"Cual fue el costo por Caja/Bulto/Otro:   "; fflush(stdin); 
                cin>>c_t; printf("\n"); bd<<c_t<<"  ->  ";
                cout<<"Cuantas Unidades/kilos/Otros contiene Caja/Bulto/Otro:  ";
                fflush(stdin); cin>>contenido; printf("\n"); bd<<contenido<<"  ->  "; 
                c_u=c_t/contenido;//posible error *conv. de tipos, checar           
                cout<<"Cuantas Caja(s)/Bulto(s)/Otro(s) se compraron:  ";
                fflush(stdin); cin>>ex; printf("\n"); bd<<ex<<"  ->  "; 
                finanzas.inventario += investment=c_t*ex; //posible error *conv. de tipos, checar
                bd<<"\n\n";
                time_t tiempo=time(NULL);//variables donde guardo valor de la funcion time
                struct tm *tlocal=localtime(&tiempo); //estructura de donde obtengo el tiempo
     /*Se crea variablepara almacenar*/
                c output[11]; //array donde guardo fecha
     /*FuncionParaHora(Variable,ext,YaEstablecido)*/
                strftime(output,11,"%d/%m/%y",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
                informacion<<"\t\t"<<" :: "<<output<<"  ->  "<<name<<" ::"<<endl;
                informacion<<"\tSe hizo una inversion de Total de:   $"<<investment<<"\n"<<endl;
                informacion<<"\tDonde el Costo unitario es de:   $"<<c_u<<"\n"<<endl;
                informacion<<"\tSe recomienda un Precio Unitario entre $"<<c_u*1.2<<" y $"<<c_u*1.3<<"\n"<<endl;
                informacion<<"\tPor Caja/Bulto/Otro de entre  $"<<c_t+5<<" y  $"<<c_t+10<<"\n"<<endl;
                informacion<<"\tPor vta. unitaria se esperaria ganancia de entre $"<<c_t*.2<<" y $"<<c_t*.3<<"\n"<<endl;
                system("cls"); cout<<"Desea ver AHORA la Informacion generada?  S/N "<<endl; fflush(stdin); opcion=getch(); system("cls");
                if(opcion=='s'||opcion=='S'){muestra_info();}
                cout<<"Desea introducir otro producto?   S/N  "<<endl; fflush(stdin); opcion=getch(); 
                system("cls"); fflush(stdin);
                }while(opcion=='s'||opcion=='S');
                bd.close(); informacion.close();
                }
     }
void muestra_info(){
     cout<<"Se genero la siguiente informacion, se recomienda considerarla"<<endl;
     cout<<"y seguirla al pie de la letra \n"<<endl;
     cout<<"\t\t"<<name<<endl;
     cout<<"\tSe hizo una inversion de Total de:   $"<<investment<<"\n"<<endl;
     cout<<"\tDonde el Costo unitario es de:   $"<<c_u<<"\n"<<endl;
     printf("\tSe recomienda un Precio Unitario entre  $%.2f y   $%.2f\n\n",c_u*1.2,c_u*1.3);
     cout<<"\tPor Caja/Bulto/Otro de entre   $"<<c_t+5<<" y   $"<<c_t+10<<"\n"<<endl;
     printf("\tPor venta individual se esperaria ganancia de entre  $%.2f y  $%.2f\n\n",c_t*.2,c_t*.3);
     cout<<"Presione una tecla para continuar..."<<endl;
     getch(); system("cls");
     }
