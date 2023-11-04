/*		PRACTICA DE PARTIDA DOBLE; VIDEO 2
				 ->Compra-Venta de Mercancia-Bienes     */
#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
using namespace std;
struct Cuentas{
	   float bancos;
	   float inventario;
	   float proveedor;
	   float cliente;
	   float patrimonio;
//	   struct EdoResultados edoResultados;
//	   struct Bancos losBancos;
	   };
struct EdoResultados{
	   struct Cuentas ctas;//Con esto desde La estructura EdoCuantas acceso a elementos de Cuentas
	   float ventas;
	   float costos;
	   float otros_ingresos;
	   float resultadoBruto;
	   float gastos;
	   float resultadoNeto;
	   };
struct Bancos{
	   float dinero_LaEsperanza;
	   float dinero_Maya;
	   float transferencia;
	   };
//Variables globales
struct EdoResultados movimientos;
struct Bancos banco;

char clientes[][23]={"ADMING","X","LA_LIQUIDADORA,S.A.","LA_MAYORISTA,S.A.","MUEBLES_TABLITAS,S.A."};//Cliente, proveedor,acreedor... Usuarios del Banco
char cuenta[30],ope;
bool band = false, aprobacion = false;
float j;
short i,opcion,movimiento;//movimiento=nuestra accion en la empresa
//Funciones
void texto_CompraVenta();
int texto_pago();
void empresa();
void bienesLaPartidaDobleSA(short,float);
void almacenLaPartidaDoble(short,float);
void diarios(short,float);
void edoResultados();
void fecha();

float banco_LaEsperanza(short,float);//Las funciones de banco son independientes a nuestras cuentas contables 'Bancos' 
float banco_Maya(short,float);//Sus Registros-Operaciones no afectan nuestros registros contables 'Cuenta Bancos', como en la realidad, son independientes
bool valida_pago(float &,float);//Funciones de banco contienen funciones basicas que se realizan en bancos

int main(){//Funcion Principal
 	do{
		cout<<"Deposito de apertura para cuenta en banco 'LaEsperanza' :: "; cin>>banco.dinero_LaEsperanza;
		cout<<"\nDeposito de apertura para cuenta en banco 'Maya' :: "; cin>>banco.dinero_Maya;
		cout<<"\nInversion inicial en mercancia (Almacen) :: "; cin>>movimientos.ctas.inventario;
		}while(banco.dinero_LaEsperanza<1000.0 && banco.dinero_Maya < 1000.0 && movimientos.ctas.inventario<10000.0);
		cout<<endl<<endl;
	do{
       fecha(); empresa(); //Somos nosotros
       cout<<"\t::Realizar otra operacion::s|n::"; ope = toupper(ope=getch());
       system("cls");
	   }while(ope=='S');
 	edoResultados();//Al final, luego de toda operacion se realiza el estado de resultados para saber el resultado final
	system("pause"); return 0;
	}
	
void empresa(){//Funcion empresa realiza control de Cuentas y Resultados pues concierne a la empresa
	 int opc_banco; system("color 0B");
	 cout<<"\t .:   COMERCIALIZADORA `LA PARTIDA DOBLE, S.A. DE C.V.' :. \n\n"<<endl;
	 cout<<"      Saldo en banco La esperanza $"<<banco.dinero_LaEsperanza<<" / Saldo en banco Maya $"<<banco.dinero_Maya<<endl;
	 cout<<"\nActividades de la empresa:  "<<endl;
	 cout<<"\t1.Compramos Mercancia"<<endl;
	 cout<<"\t2.Compramos Mobiliario/Equipo"<<endl;
	 cout<<"\t3.Vendemos Mercancias"<<endl;
	 cout<<"\t4.Vendemos Mobiliario/Equipo"<<endl;
	 cout<<"\t5.Pagamos Servicio, Imprevisto o cualquier otro gasto"<<endl;
	 cout<<"\nOperacion elegida::"; cin>>movimiento;
	 cout<<"\n\n\tPara usar el banco 'La Esperanza', digite 1    \n\tPara el 'Banco Maya', digite 2"<<endl;
	 cout<<"Que banco usara::"; scanf("%i",&opc_banco);
	 if(opc_banco==1){
				  switch(movimiento){
				 					 case 1: system("cls"); cout<<"\n\t.:Compra de Mercancia:."<<endl;
				 					         texto_CompraVenta();
			 	  	   				 	  	 cout<<"Cuanto transferiremos? "; cin>>banco.transferencia; banco_LaEsperanza(movimiento,banco.transferencia);
										     if(band){
											 		  almacenLaPartidaDoble(movimiento,banco.transferencia/1.16);
													  diarios(movimiento,banco.transferencia/1.16);}
											 break;
									 case 2: system("cls"); cout<<"\n\t.:Compra de Mobiliario/Equipo:."<<endl;
									         texto_CompraVenta();
									 	  	 cout<<"Cuanto transferiremos? "; cin>>banco.transferencia; banco_LaEsperanza(movimiento,banco.transferencia);
											 if(band){
											 		  bienesLaPartidaDobleSA(movimiento,banco.transferencia/1.16);
													  diarios(movimiento,banco.transferencia/1.16);}
											 break;
									 case 3: system("cls"); cout<<"\n\t.:Venta de Mercancias:."<<endl;
									         texto_CompraVenta();
									 	  	 cout<<"Cuanto vendimos, se cobrara con un 70% mas de utilidad "; cin>>banco.transferencia;
									 	  	 banco_LaEsperanza(movimiento,banco.transferencia*1.7);
									 	  	 if(band){
											 		  almacenLaPartidaDoble(movimiento,banco.transferencia);
													  diarios(movimiento,banco.transferencia);}
											 break;
									 case 4: system("cls");cout<<"\n\t.:Venta de Mobiliario/Equipo:."<<endl;
                                             texto_CompraVenta();
									 	  	 cout<<"Cuanto cobraremos? "; cin>>banco.transferencia;
									 	  	 banco_LaEsperanza(movimiento,banco.transferencia);
										     if(band){
											 		  bienesLaPartidaDobleSA(movimiento,banco.transferencia);
													  diarios(movimiento,banco.transferencia/1.16);}
											 break;
									 case 5: system("cls"); cout<<"\n\t.:Gastos / Servicios:."<<endl;
									         texto_CompraVenta();
									 	  	 cout<<"Cuanto gastamos::"; cin>>banco.transferencia; banco_LaEsperanza(movimiento,banco.transferencia);
									 	  	 if(band){
											 		  movimientos.gastos += banco.transferencia;
													  diarios(movimiento,banco.transferencia);}
											 break;
                                     case 6: cout<<"\nLaEsperanza->$"<<banco.dinero_LaEsperanza<<endl;
									 	  	 cout<<"Maya->$"<<banco.dinero_Maya<<endl;
											 break;
									 default: system("cls"); getch(); empresa(); break;       }
          							 }else if(opc_banco==2){
                                                switch(movimiento){
				 					 							   case 1: system("cls"); cout<<"\n\t.:Compra de Mercancia:.\n"<<endl;
				 					 							           texto_CompraVenta();
   		  		 	   		  		 							   		   cout<<"\nCuanto transferiremos? "; cin>>banco.transferencia; banco_Maya(movimiento,banco.transferencia);
																	 	   if(band){
																		   			almacenLaPartidaDoble(movimiento,banco.transferencia/1.16);
																			        diarios(movimiento,banco.transferencia/1.16);}
																		   break;
									 							   case 2: system("cls");cout<<"\n\t.:Compra de Mobiliario/Equipo:.\n"<<endl;
									 							           texto_CompraVenta();
																   		   cout<<"Cuanto transferiremos? "; cin>>banco.transferencia; banco_Maya(movimiento,banco.transferencia);
																		   if(band){
																		   			bienesLaPartidaDobleSA(movimiento,banco.transferencia/1.16);
																		            diarios(movimiento,banco.transferencia/1.16);}
											 					   		   break;
									 							   case 3: system("cls"); cout<<"\n\t.:Venta de Mercancias:.\n"<<endl;
									 							           texto_CompraVenta();
																   		   cout<<"Cuanto vendimos, se cobrara con un 70% mas de utilidad "; cin>>banco.transferencia;
																		   banco_Maya(movimiento,banco.transferencia*1.7);
																		   if(band){
																		   			almacenLaPartidaDoble(movimiento,banco.transferencia);
																		            diarios(movimiento,banco.transferencia);}
																		   break;
							 									   case 4: system("cls"); cout<<"\n\t.:Venta de Mobiliario/Equipo:.\n"<<endl;
							 									           texto_CompraVenta();
																   		   cout<<"Cuanto cobraremos? "; cin>>banco.transferencia; banco_Maya(movimiento,banco.transferencia);
																		   if(band){
																		   			bienesLaPartidaDobleSA(movimiento,banco.transferencia);
																		            diarios(movimiento,banco.transferencia/1.16);}
											 							   break;
							 									   case 5: system("cls"); cout<<"\n\t.:Gastos / Servicios:.\n"<<endl;
							 									           texto_CompraVenta();
																   		   cout<<"Cuanto gastamos::"; cin>>banco.transferencia; banco_Maya(movimiento,banco.transferencia);
							 									           if(band){
																		   			movimientos.gastos += banco.transferencia;
																	                diarios(movimiento,banco.transferencia);}
											 					   		   break;
                                                                   case 6: cout<<"\nlaEsperanza->$"<<banco.dinero_LaEsperanza<<endl;
									 	  	 					   		   cout<<"Maya->$"<<banco.dinero_Maya<<endl;
											 							   break;
							 									   default: system("cls"); getch(); empresa(); break;       }
    													   }else{
				  										   		 empresa(); } //edoResultados();
	 movimientos.ctas.bancos = banco.dinero_LaEsperanza + banco.dinero_Maya;
	 }
void almacenLaPartidaDoble(short mov,float valor){//La compra de nuestra mercancia para vender o producir, si es el caso de una fabrica
	 //Un cargo a almacen es por compra de mercancia, esa mercancia proviene de alguien que la esta 'perdiendo'
	 //A cambio de aumentar valor de almacen, ocurre algo inverso('perdida') en el capital para invertir
	 //Las actualizaciones al valor de bancos es en nuestros registros contables, el capital en bancos se actualiza por los bancos a parte
	 if(mov==1){//Compra
				movimientos.ctas.bancos = movimientos.ctas.bancos-(valor*1.16);// Actualizacion de saldo en bancos descuenta el pago
				movimientos.ctas.inventario += valor;//Sumamos la compra de mercancia al inventario
				movimientos.costos+=valor;//Sumamos a costo de ventas
				 }else if(mov==3){//Venta
					   movimientos.ctas.bancos += valor*1.7;
					   movimientos.ctas.inventario -= valor;
					   movimientos.ventas += valor*1.7;//Para saber el importe ganado por ventas al final
					   movimientos.costos += valor;
					   }
	 }
void bienesLaPartidaDobleSA(short mov,float otro){//Muebles, maquinaria, electronicos... Toda compra para la empresa, que no sea mercancia
	 if(mov==2){
	 			movimientos.ctas.patrimonio+=otro;
  	            movimientos.ctas.bancos=movimientos.ctas.bancos-(otro*1.16);}// + valor del patrimonio
				else if(mov==4){
					 			movimientos.ctas.patrimonio = movimientos.ctas.patrimonio-otro;
	   			                movimientos.ctas.bancos = movimientos.ctas.bancos+(otro*1.16); }//Disminuimos valor del patrimonio
     }
void diarios(short opcion,float cargo){
	 short opc_pago; float credito;
	 switch(opcion){
					case 1: opc_pago=texto_pago();
					        if(opc_pago==1){//Compra a credito donde se abono algo de enganche
											cout<<"Valor de la Total de la mercancia::"; cin>>credito;
                                            cout<<"\nAlmacen->"<<credito<<endl;//Cargamos el valor Sin iva de la Nota/Factura
						    	 			cout<<"      Iva->"<<credito*.16<<endl;//Iva sobre valor total de mercancia
						    				cout<<"Proveedor->\t\t"<<credito*1.16<<endl;//Cargamos el total a pagar de la Nota/Factura
//                                          Asiento que afecta a los diarios si se dio adelanto o una parte
											cout<<"   \nProveedor->"<<cargo<<endl;
  	 								  		cout<<"           Iva->"<<cargo*.16<<endl;
   									  		cout<<"Abono a Bancos->\t\t"<<cargo*1.16<<endl;
											}else if(opc_pago==2){//Se compro a credito sin abonar nada a la cuenta
												  				  cout<<"       Almacen->"<<cargo<<endl;
						    	 								  cout<<"           Iva->"<<cargo*.16<<endl;
						    									  cout<<"Abono a Bancos->\t\t"<<cargo*1.16<<endl;
																  }
									break;
                    case 2: opc_pago=texto_pago();
					        if(opc_pago==1){
											cout<<"Valor de la mercancia::"; cin>>credito;
                                            cout<<"  Bienes->"<<credito<<endl;//Cargamos el valor Sin iva de la Nota/Factura
						    	 			cout<<"     Iva->"<<credito*.16<<endl;//Iva sobre valor total de mercancia
						    				cout<<"Acreedor-> \t  "<<credito*1.16<<endl;//Cargamos el total a pagar de la Nota/Factura
//                                          Asiento que afecta a los diarios si se dio adelanto o una parte
											cout<<"        Acreedor->"<<cargo<<endl;
  	 								  		cout<<"           Iva->"<<cargo*.16<<endl;
   									  		cout<<"Abono a Bancos-> \t  "<<cargo*1.16<<endl;
											}else if(opc_pago==2){
												  				  cout<<"        Bienes->"<<cargo<<endl;
						    	 								  cout<<"           Iva->"<<cargo*.16<<endl;
						    									  cout<<"Abono a Bancos-> \t  "<<cargo*1.16<<endl;
																  }
									break;
					case 3: opc_pago=texto_pago();
					        if(opc_pago==1){
											cout<<"Valor de la mercancia::"; cin>>credito;
                                            cout<<"Clientes->"<<credito/1.16<<endl;//Cargamos el valor Sin iva de la Nota/Factura
						    	 			cout<<"     Iva->"<<credito*.16<<endl;//Iva sobre valor total de mercancia
						    				cout<<"Ventas-> \t  "<<credito/1.16<<endl;//Cargamos el total a pagar de la Nota/Factura
                                            cout<<"   Iva-> \t  "<<credito*.16<<endl;
//                                          Asiento que afecta a los diarios si se dio adelanto o una parte
											cout<<"          Bancos->"<<cargo/1.16<<endl;
  	 								  		cout<<"             Iva->"<<cargo*.16<<endl;
   									  		cout<<"Abono a Clientes-> \t  "<<cargo<<endl;
											}else if(opc_pago==2){
												  				  cout<<"          Bancos->"<<cargo/1.16<<endl;
						    	 								  cout<<"             Iva->"<<cargo*.16<<endl;
						    									  cout<<"Abono a Clientes-> \t  "<<cargo<<endl;
																  }
  						    break;
				    case 4: opc_pago=texto_pago();
					        if(opc_pago==1){
											cout<<"Valor del bien::"; cin>>credito;
											
                                            cout<<"\nDeudores diversos->"<<credito/1.16<<endl;//Cargamos el valor Sin iva de la Nota/Factura
						    	 			cout<<"     	     Iva->"<<credito*.16<<endl;//Iva sobre valor total de mercancia
						    				cout<<"    Bienes/Equipo->\t\t"<<credito/1.16<<endl;//Cargamos el total a pagar de la Nota/Factura
                                            cout<<"              Iva->\t\t"<<credito*.16<<endl;
//                                          Asiento que afecta a los diarios si se dio adelanto o una parte
											cout<<"         \nBancos->"<<cargo/1.16<<endl;
  	 								  		cout<<"              Iva->"<<cargo*.16<<endl;
   									  		cout<<"Deudores diversos-> \t  "<<cargo<<endl;
   									  		movimientos.otros_ingresos += cargo;
											}else if(opc_pago==2){
												  				  cout<<" \n       Bancos->"<<cargo/1.16<<endl;
						    	 								  cout<<"             Iva->"<<cargo*.16<<endl;
						    									  cout<<"Abono a Bienes/Equipo-> \t  "<<cargo<<endl;
                                                                  movimientos.otros_ingresos += cargo;
																  }
  						    break;
					case 5: cout<<"        Gastos->"<<cargo<<endl;
  	 					 	cout<<"           Iva->"<<cargo*.16<<endl;
   							cout<<"Abono a Bancos->\t"<<cargo*1.16<<endl;
							break;
					default: empresa(); break;
				    }

	 }
void edoResultados(){
	 movimientos.resultadoBruto = movimientos.ventas - movimientos.costos;
	 movimientos.resultadoNeto = movimientos.resultadoBruto - movimientos.gastos;
     cout<<"\n \t.:Estado de resultados al momento:."<<endl;
     cout<<"Ventas------------------------>\t"<<setw(5)<<movimientos.ventas<<endl;
     cout<<"(-) Costo de ventas----------->\t"<<setw(5)<<movimientos.costos<<endl;
     cout<<"(+) Ingresos No operacionales->\t"<<setw(5)<<movimientos.otros_ingresos<<endl;
     cout<<"(=) Perdida/Ganancia Bruta---->\t"<<setw(5)<<movimientos.resultadoBruto<<endl;
     cout<<"(-) Gastos-------------------->\t"<<setw(5)<<movimientos.gastos<<endl;
     cout<<"(=) Perdida/Ganancia Neta----->\t"<<setw(5)<<movimientos.resultadoNeto<<endl;
     cout<<"\nInventario = "<<movimientos.ctas.inventario<<endl;
     cout<<"\nBancos = "<<movimientos.ctas.bancos<<endl;
     cout<<"\nPatrimonio = "<<movimientos.ctas.patrimonio<<endl<<endl;
	 }
	 
void fecha(){//Obtiene la hora de ordenador y la coloca en el programa
	time_t tiempo = time(NULL);//variables donde guardo el valor de la funcion time.
    struct tm *tlocal = localtime(&tiempo);//estructura donde obtengo el tiempo
    char output[11]; //array donde guardo la fecha
    strftime(output,11,"%d/%m/%y",tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
    printf("%s\n",output);
	}
//Bancos son sistemas y entidades externos, por lo que las siguientes funciones son simples y tienen fin unico de apoyo a las anteriores
float banco_LaEsperanza(short operacion,float transf){//Funcion de los Bancos, independiente de nuestra empresa
	  cout<<"Bienvenido al sitio de Banco la Esperanza\n"<<endl; fflush(stdin); band = false; aprobacion = false;
	  switch(operacion){
						case 1:case 2: case 5: cout<<"Escriba el nombre del beneficiario::"; cin>>cuenta; strupr(cuenta);//Nosotros pagamos
					  	   	   cout<<"Monto de transferencia::$"<<transf<<"MxN para "<<cuenta<<endl;
					  		   for(i=0;i<3;i++){
							   					if(strcmp(clientes[i],cuenta)==0) band=true; }//for busca cuentas
					  		   if(band){//Se hayo al cliente
							   			if(valida_pago(banco.dinero_LaEsperanza,transf)){ aprobacion = true;}
										}else{ cout<<"\aEsa cuanta no existe"<<endl; }
							   if(aprobacion){ cout<<"\n\a\tSu nuevo saldo es->$"<<banco.dinero_LaEsperanza<<endl;}
							 	  break;
						case 3:case 4: srand(time(NULL)); i=rand()%3;
			 				      cout<<"Se recibio pago por::$"<<transf<<"MxN"<<" de "<<clientes[i][30]<<endl;
						          band=true; banco.dinero_LaEsperanza+=banco.transferencia;//Actualiza el dinero
							 	  break;
						default: empresa(); break;
				        }
	  }
float banco_Maya(short operacion,float transf){//Funcion de los Bancos, independiente de nuestra empresa
      cout<<"Bienvenido a Banco Maya\n"<<endl; fflush(stdin); band = false; aprobacion = false;
	  switch(operacion){
						case 1:case 2:case 5: cout<<"Escriba el nombre del beneficiario::"; cin>>cuenta; strupr(cuenta);//Nosotros pagamos
							   cout<<"Monto de transferencia::$"<<transf<<"MxN para "<<cuenta<<endl;
							   for(i=0;i<3;i++){
							   					if(strcmp(clientes[i],cuenta)==0) band=true; }//for busca usuarios
						       if(band){
							   			if(valida_pago(banco.dinero_Maya,transf)){ aprobacion=true; }
							   			}else{ cout<<"\aEsa cuanta no existe"<<endl; }
                               if(aprobacion){cout<<"\n\a\tSu nuevo saldo es->$"<<banco.dinero_Maya<<endl;}
							   break;
						case 3:case 4: srand(time(NULL)); cout<<"Se recibio pago por::$"<<transf<<"MxN"<<" de "<<clientes[rand()%3][30]<<endl;
						       band=true; banco.dinero_Maya+=banco.transferencia;//Actualiza el dinero
							   break;
						default: empresa(); break;
				        }
	  }
bool valida_pago(float &capital,float transf){//Funcion de los Bancos, independiente de nuestra empresa
	 if(capital>transf){
	 					cout<<"\aPago aprobado"<<endl; capital=capital-transf;
						return true;
						}else{
							  cout<<"\aSaldo insufieciente, se transferira lo disponible"<<endl; capital=capital-(banco.transferencia-(banco.transferencia-capital));
							  return false;
							  }
     }
void texto_CompraVenta(){
     cout<<"SI ES A CREDITO, y no se pagara nada(abono) digite 0,\n";
	 cout<<"SI ES A CREDITO, y se abonara algo a la deuda, digite lo que se descontara"<<endl;
	 cout<<"Si sera de contado simplemente digite el monto del pago..."<<endl;
	 }
int texto_pago(){
	 int pago;
     cout<<"\a\n\tFue a credito o de Contado"<<endl;
     cout<<"\t\t1.Credito"<<endl;
	 cout<<"\t\t2.Contado"<<endl; cin>>pago;
	 return pago;
	 }
