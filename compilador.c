#include "TibSimb.c"
#include "Funciones_compilador.c"
//#include "TipCompy1.c"
#include "TipCompl.c"
//#include"TipCompl.c"
#include<stdlib.h>
int main(){
	yyparse();
	imprimir(tabla);
	system("pause"); return 0;
	}
void yyerror(char *s) {
	 printf("%s\n",s);
	 }
