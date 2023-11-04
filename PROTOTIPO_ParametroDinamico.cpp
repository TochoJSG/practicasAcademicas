/*Funcion de parametros variables, dinamicos
          1* va_list->stdarg.h ; apuntador para manejar lista de datos pasada a la funcion
          
          2* va_start(va_list puntero,ultimofijo); -> Inicializa a variable puntero, referencia al primer parametro d lista ; 
          Segundo arg es el ultimo argumento fijo de funcion          
          Prototipo->va_start(va_list puntero,ultimo_fijo);
          
          Asi para fun Muestra (int a,...); -> va_start(puntero,a);
          
          3* funcion va_arg obtiene, consecutivamente, los sucesivos argumentos de lista variable
          Prototipo->tipo va_arg(va_list puntero,tipo); (tipo=tipo d arg variable capatado al moment)

          Tipo es tipo d' dato captado al momento && tipo de dato que devolvera va_arg
          Ej:
               int m;
               m=va_arg(puntero,int);
          ultima llamada en funcion de esta calse
          4* va_end(va_list puntero) De modo que ounteron queda preparado para siguientes llamadas
          
*/
#include<stdio.h>
#include<stdarg.h>
void maximo(int n,...);
main(){
       puts("\t\tPRIMERA BUSQUEDA DE MAXIMO\n");
       maximo(6,3.0,4.0,-12.5,1.2,4.5,6.4);
       puts("\n\n\t\tNUEVA BUSQUEDA DE MAXIMO\n");
       maximo(4,5.4,17.8,5.9,-17.99);
       getchar();       return 0;       
       }        
void maximo(int n,...){
     double mx,actual;
     va_list puntero;//Apuntador para manejar lista de datos pasada a la funcion
     int i;                                                 
     va_start(puntero,n);//Inicializa a var puntero, referencia al 1º parametro d lista; Segundo arg es el ultimo argumento fijo de funcion
     mx = actual = va_arg(puntero,double);
     printf("\t\tArgumento actual: %.2lf\n",actual);
     for(i=2;i<=n;i++){
                       actual = va_arg(puntero,double);
                       printf("\t\tArgumento actual: %.2lf\n",actual);
                       if(actual > mx){
                                 mx = actual;
                                 }
                       }
     printf("\t\tMaximo de lista de %d numeros es: %.2lf",n,mx);
     va_end (puntero);
     }
