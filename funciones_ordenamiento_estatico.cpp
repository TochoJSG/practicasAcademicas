/*Funciones ordenamientos estructuras estaticas*/
void ordBurbuja(long a[],int n){
     int interruptor = 1;
     int pasada,j;
     for(pasada = 0; pasada < n-1 && interruptor;pasada++)
         interuptor = 0;
         for(j=0,j<n-pasada;j++){
                                 if(a[j]>a[j+1]){
                                      long aux;
                                      a[j] = a[j+1];
                                      a[j+1] = aux;
                                      }
                                 }
     }
void ordBurbuja2(long a[],int n){
     int i,j;
     int indInter;   //   i es ultimo elemento de sublista
     i = n-1;  
     while(i>0){//Proceso continua hasta que no haya cambios
             indInter = 0;
//           Explora sublista a[0] -> a[i]
             for(j=0;j<i;j++)
//           Intercambia pareja & actualiza indInter
             if(a[j+]>a[j]){
                            long aux = a[j];
                            a[j] = a[j+1];
                            a[j+1] = aux;
                            indInter = j;
                            }    
//           i pone al  valor del indice del ultimo intercaMBIO
             i = indInter;  
             }
     }
void ordSelec(double a[],int n){
     int indiceMenor, i, j;
//   ordenar a[0] ... a[n-2]  y  a[n-1]   en cada pasada
     for(i=0;i<n-1;i++){
//                      comienzo de exploracion en indice i    
                        indiceMenor = i;
//                      j explora sublista a[i+1] ... a[n-1]
                        for(j=i+1;j<n;j++)
                        if( a[j] < a[indiceMenor] )//a[j]<a[j-1]?
                            indiceMenor = j;
//                          Situa elemento mas pequenio en a[i]
                            if(i != indiceMenor){//Cambio por j, pues hay que hacer cambio
                                 double aux = a[i];
                                 a[i] = a[indiceMenor];
                                 a[indiceMenor] = aux;
                                 }  
                        }
     }
void ordInsercion(int a[],int n){
     int i, j;
     int aux;
     for(i=1;i<n;i++){
//                    Indice j explora sublista a[i-1]... a[0] buscando posicion correcta d elemento destino, lo asigna a a[j] 
                      j = i;
                      aux = a[i];
//                    Se localiza punto de insercion explorando hacia abajo  
                      while(j>0 && a[j-1]<aux){//a[j-1]<a[j]?
//                              Desplazar elementos hacia arriba para hacer espacio
                                a[j] = a[j-1];
                                j--;  
                                }
                                a[j] = aux;
                      }
     }
//Pasar de param (a,0,n-1)
void quicksort(double a[],int first,int last){
     int i ,j, centro=(first + last)/2;
     double pivote=a[centro];//Cont. numero al centro de matriz
     i = primero;
     j = ultimo;
     do{
//       Obtenemos limite  
         while(a[i] < pivote) i++; //Acortar distancia hasta 'encontrarse'
         while(a[j] > pivote) j--;
         if(i<=j){
                  double tmp;  //Intercambio a[i] con a[j] ; Seleccion de grupos
                  tmp = a[i];
                  a[i] = a[j];
                  a[j] = tmp;
                  i++;//Acortar distancia hasta 'encontrarse'
                  j--;
                  }
                  }while(i <= j);
         if(primero < j)
                    quicksort(a,primero,j);//Mismo proceso con sublista izq
         if(i < ultimo)
                    quicksort(a,i,ultimo);//Mismo proceso con sublista der
     }
