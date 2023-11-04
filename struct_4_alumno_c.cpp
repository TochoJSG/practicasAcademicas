#include<stdio.h>
#include<conio.h>
struct alumno{
       char nombre[20];
       int edad;
       float ingles,math,historia;
       }alumno[30];
typedef int e;
e cantidad,i;
e main(){
         printf("De la cantidad de alumnos:  ");
         scanf("%i",&cantidad);
         for(i=0;i<cantidad;i++){
               fflush(stdin);
               printf("\nAlumno[%i] · Digite el nombre:  ",i+1);
               gets(alumno[i].nombre);
               printf("\nAlumno[%i] · Digite la edad:  ",i+1);
               scanf("%i",&alumno[i].edad);
               printf("\nDigite las calificaciones en escala del 1 al 10, con decimales");
               printf("\nAlumno[%i] · Digite calificacion de ingles:  ",i+1);
               fflush(stdin); scanf("%2.2f",&alumno[i].ingles);
               printf("\nAlumno[%i] · Digite calificacion de matematicas:  ",i+1);
               fflush(stdin); scanf("%2.2f",&alumno[i].math);
               printf("\nAlumno[%i] · Digite calificacion de historia:  ",i+1);
               fflush(stdin); scanf("%2.2f",&alumno[i].historia);
               }
    getch();
    for(i=0;i<cantidad;i++){
          printf("\nAlumno[%i] %s de %i anios obtuvo %2.2f en ingles, %2.2f en matematicas y %2.2f en historia",i+1,alumno[i].nombre,alumno[i].edad,alumno[i].ingles,alumno[i].math,alumno[i].historia);
          }
    getch(); return 0;
    }
