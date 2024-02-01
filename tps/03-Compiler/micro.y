%{
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

extern char *yytext;
extern int yyleng;
extern int yylex(void);
extern void yyerror(char*);

%}
%union{
   char* cadena;
   int num;
} 
%token ASIGNACION PYCOMA SUMA RESTA PARENIZQUIERDO PARENDERECHO COMA LEER ESCRIBIR INICIO FIN FDT
%token <cadena> ID
%token <num> CONSTANTE

%%
objetivo: programa FDT {printf("El programa es sintacticamente correcto! \n"); exit(0);}
programa: INICIO sentencias FIN 
sentencias:  sentencias sentencia 
|sentencia
;
sentencia: ID {if(yyleng>32) yyerror("la longitud del identificador es mayor que lo permitido");} ASIGNACION expresion PYCOMA
| LEER PARENIZQUIERDO  lista_identificadores PARENDERECHO PYCOMA
| ESCRIBIR PARENIZQUIERDO lista_expresiones PARENDERECHO PYCOMA 
;
lista_expresiones:  expresion COMA lista_expresiones
| expresion
; 
lista_identificadores: ID COMA lista_identificadores
| ID
;
expresion: primaria 
|expresion operadorAditivo primaria
; 
primaria: ID
|CONSTANTE
|PARENIZQUIERDO expresion PARENDERECHO
;
operadorAditivo: SUMA 
| RESTA
;
%%


int main() {
  yyparse();
}
void yyerror (char *s){
  printf ("Hubo un error sintáctico o semántico: %s\n",s);
  exit(1);
}
int yywrap() {
  return 1;  
} 

