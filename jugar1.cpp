#include<iostream>
#include<windows.h>
#include<conio.h>
//Def segun codigo ascii; Asociacion segun ascii de tecla izq, der
#define IZQUIERDA 75
#define DERECHA 77
typedef int e;
char avion_l1[]={' ',' ',' ','&',' ',' ',' ',0};   //Dibujo de Avion
char avion_l2[]={' ',' ','#','#','#',' ',' ',0};
char avion_l3[]={' ','#','$','#','$','#',' ',0};

char explosion_l1[]={' ',' ','*','*',' ',' ',' ',0};   //Dibujo de explosion 1 de avion
char explosion_l2[]={' ','*','*','*','*',' ',' ',0};
char explosion_l3[]={' ',' ','*','*',' ',' ',' ',0};

char explosion_r1[]={'*',' ','*','*',' ','*',' ',0};   //Dibujo de explosion 2 avion
char explosion_r2[]={' ','*','*','*','*',' ',' ',0};
char explosion_r3[]={'*',' ','*','*',' ','*',' ',0};

char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};   //Borrar lineas de avion; borramos y luego repintamos avion en posicion
e num_vidas = 3;
e corazones = 3;
//Puede inicializarse cualquier coordenada, en margen de pontalla
e ix = 40, iy = 19; //Def. de coordenadas de Avion, don de se posicionara(H_asta abajo)
e y = 8, x = 12;//Coord d asteroides(solo 4), al llegar a piso se usa mismo asteroide con coord nueva X y se reestablece Y
e yy = 12, xx = 17;//2 aste 
e x1 = 58, y1 = 6;//3 asteroide                                     
e x2 = 70, y2 = 9;//4 asteroide
e i,v;//Control de Bucles
e dd = 0;//Control de coord de bala; decrementaraen Y para que suba
e xb;
bool shoot = false;
e repeticion = 0,nivel = 1;//Variables de rutina de cambio de nivel: Control de cambio de nivel, Indicador en pantalla
bool condicion = false;
//Prototipos
void menu();
void juego();
void gotoxy(int,int);
void vidas(int);
void barra_salud(int);
void explosion();
void jugar();
//   funcion main  
main(){
       menu();
       getch(); return 0;
    }
void juego(){
     system("color 0A");
    vidas(num_vidas);
    barra_salud(corazones);         
    gotoxy(35,1); printf("Nivel %i",nivel);
    gotoxy(ix,iy);   puts(avion_l1);
    gotoxy(ix,iy+1); puts(avion_l2);
    gotoxy(ix,iy+2); puts(avion_l3);
    while(num_vidas>0&&nivel<=6)
                       jugar();           
    gotoxy(40,15); printf("GAME OVER");
    Sleep(200); getch();
                       }
void menu(){
     system("color C0");
     int opcion;
     printf("###############################################################################\n");
     printf("################################### JUEGOS ####################################\n");
     printf("###############################################################################\n\n\n");
     printf("\tSeleccione una opcion\n\n");
     printf("\t1.Jugar\n\t2.Salirn\n");
     printf("\nOpcion  ");scanf("%d",&opcion);
     system("Cls");
     switch(opcion){
                    case 1: juego();
                    case 2: exit(1);
                    }
     }
void gotoxy(int x,int y){//Handle coord en Console
           HANDLE hCon;
           COORD dwPos;
           dwPos.X = x;
           dwPos.Y = y;
           hCon = GetStdHandle(STD_OUTPUT_HANDLE);
           SetConsoleCursorPosition(hCon,dwPos);
           }
void vidas(int vida){
     gotoxy(2,1); ("Vidas %d",vida);//Num_vidas
     }
void barra_salud(int n){ //Pone corazones
     gotoxy(72,1); printf(" ");//Primero borra; Borrra corazon 1
     gotoxy(73,1); printf(" ");//Borra corazon 2
     gotoxy(74,1); printf(" ");//Borra corazon 3
     for(v=0;v<n;v++){
                      gotoxy(72+v,1);//Situamos en posicion: 72+0, 72+1=73, 72+2=73 Fin
                      printf("%c",3);//Codigo ascii de 3 es corazon
                      }
     }
void explosion(){//Simple impresion d simulacion explocion
     gotoxy(ix,iy);   puts(explosion_l1);
     gotoxy(ix,iy+1); puts(explosion_l2);
     gotoxy(ix,iy+2); puts(explosion_l3);
     Sleep(380);//Alentar ejecucion para ver explosion
     gotoxy(ix,iy);   puts(explosion_r1);
     gotoxy(ix,iy+1); puts(explosion_r2);
     gotoxy(ix,iy+2); puts(explosion_r3);
     Sleep(380);
     gotoxy(ix,iy);   puts(avion_l1);//Reconstruye avion
     gotoxy(ix,iy+1); puts(avion_l2);
     gotoxy(ix,iy+2); puts(avion_l3);
     }
void jugar(){//Funcion principal, de aqui se ejecutan las demas
     if(!shoot) xb=ix;
     gotoxy(xb+3,iy+dd); printf("*");
     
     gotoxy(x,y);   printf("%c",2);//Imprimimos asteroides, usando coord definidas
     gotoxy(xx,yy); printf("%c",2);//2
     gotoxy(x1,y1); printf("%c",2);//3
     gotoxy(x2,y2); printf("%c",2);//4
     Sleep(100);
     gotoxy(x,y);   printf(" ");//Borramos asteroides en pos en que estaban
     gotoxy(xx,yy); printf(" ");
     gotoxy(x1,y1); printf(" ");
     gotoxy(x2,y2); printf(" ");
     
     gotoxy(xb+3,iy+dd); printf(" "); //Rutina disparo
     if(shoot == true) dd--;//Cuando sea tru dd decrece
     if(iy + dd < 5){//Si llego a altura de donde salen asteroides
           dd = 0;//Reiniciamos dd y booleano
           shoot = false;//Deja de decrementarse; Se vuelve true con switch
           }
//   Rutina asteroide: Variar posiciones en X; Re-situamos arriba de pantalla cunado Y haya llegado a 20, que es el 'suelo'
     if(y>20||x==xb+3&&iy+dd<=y){
              y=4;
              x=(rand()%70)+6; 
              if(y==4)//Cuenta veces quellego al piso, para cambio de nivel
                       condicion=false;
              }
     if(yy>20||xx==xb+3&&iy+dd<=yy){
               yy=4;
               xx=(rand()%70)+6;
               }
     if(y1>20||x1==xb+3&&iy+dd<=y1){
               y1=4;          
               x1=(rand()%70)+6;
               }
     if(y2>20||x2==xb+3&&iy+dd<=y2){
               y2=4;
               x2=(rand()%70)+6;
               }
               
     if(kbhit()){ //Si se presiona tecla se ejecutara lo que esta en cuerpo de if
                 unsigned char tecla=getch();
                 switch(tecla){//Evalua tecla de acuerdo a Codigo ASCII
                               case IZQUIERDA: 
                                    if(ix>4){//Resituamos coord de avion
                                            gotoxy(ix,iy);   puts(borrar_avion);//al apretar lo borramos
                                            gotoxy(ix,iy+1); puts(borrar_avion);
                                            gotoxy(ix,iy+2); puts(borrar_avion);
                                            ix-=2; //ix=ix-2; Coord actual al ir a izq se decrementa
                                            gotoxy(ix,iy);   puts(avion_l1);//Recoloreamos avion
                                            gotoxy(ix,iy+1); puts(avion_l2);
                                            gotoxy(ix,iy+2); puts(avion_l3);
                                    } break;
                               case DERECHA: 
                                    if(ix<70){
                                             gotoxy(ix,iy);   puts(borrar_avion);
                                             gotoxy(ix,iy+1); puts(borrar_avion);
                                             gotoxy(ix,iy+2); puts(borrar_avion);
                                             ix+=2; //ix=ix+2; Coord actual al ir a der se incrementa
                                             gotoxy(ix,iy);   puts(avion_l1);
                                             gotoxy(ix,iy+1); puts(avion_l2);
                                             gotoxy(ix,iy+2); puts(avion_l3);
                                             } break;
                               case 'd'://char 'd' dispara
                                    shoot=true;
                                      break;
                               }
                 }
//               Rutina de golpes Solo si coordenada de avion es igual a asteroides, cubriendo todo; basta un asteroide  
     if((x>ix && x<ix+6 && y==iy-1)||(xx>ix && xx<ix+6 && yy==iy-1)||(x1>ix && x1<ix+6 && y1==iy-1)||(x2>ix && x2<ix+6 && y2==iy-1)){
              corazones--;//Toco alguna coordenada por lo que decrementa salud
              barra_salud(corazones);//Actualiza barra de salud con el incremento
              printf("\a");//Escape de sonido
              }
//            Por cada vida se tienen 3 corazons  
              gotoxy(ix,iy);   puts(avion_l1);//Reimprimos avion
              gotoxy(ix,iy+1); puts(avion_l2);
              gotoxy(ix,iy+2); puts(avion_l3);
              if(!corazones){//Corazones == 0?
                             num_vidas--;//Decrementamos una vida
                             vidas(num_vidas);//Actualizamos edo al usuario
                             explosion();//Lo explotamos
                             corazones=3;//Reiniciamos corazones 
                             barra_salud(corazones);//Actualizamos edo a usuario
                             }
//   rutina de cambio de nivel
     if(!condicion){
                    repeticion++;
                    condicion = true;//aalentamos incremento en nivel
                    }
     if(repeticion==10){//Asteroide llego 10 veces al piso, por lo tanto hay que subir nivel
                       nivel++;
                       gotoxy(35,1); printf("Nivel %i",nivel);
                       gotoxy(ix,iy);   puts(borrar_avion);
                       gotoxy(ix,iy+1); puts(borrar_avion);
                       gotoxy(ix,iy+2); puts(borrar_avion);
                       iy-=2;//iy=iy-2; Subimos el avion en conola sobre eje Y
                       gotoxy(ix,iy);   puts(avion_l1);
                       gotoxy(ix,iy+1); puts(avion_l2);
                       gotoxy(ix,iy+2); puts(avion_l3);
                       repeticion = 0;
                       }
//   Incrementamos coordenadas Y d asteroides para que cambien de lugar al ser borradas  
     y++;
     yy++;
     y1++;
     y2++;
     }
