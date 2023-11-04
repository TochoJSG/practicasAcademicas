/*Programa Grupo Tocha/Materias Primas fisico
	Control de costos:
		*Registro de costos y promedio

*/
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
FILE *f;
struct Product{
	char cve;
	char name[17];
	float cost;
	float price;
	};
struct Product p1;
void storageProductNew();
int main(){
	storageProductNew();
	system("pause");return 0;
	}
void storageProductNew(){
	char productsFile[]="products.txt";
	cout<<"ingresa precio del producto";cin>>p1.cost;
	f=fopen(productsFile,"r");
	if(f=='\0'){
		f=fopen(productsFile,"wt");
		fprint(f,"%s",p1.cost);
		}
	cout<<p1.cost;
	}
