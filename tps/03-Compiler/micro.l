%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "y.tab.h"
%}


DIGITO [0-9]

LETRA [a-zA-Z]

IDENTIFICADOR {LETRA}({LETRA}|{DIGITO})*

constEntera {DIGITO}({DIGITO})*

%%
"inicio" {return INICIO;}
"fin" {return FIN;}
"leer" {return LEER;}
"escribir" {return ESCRIBIR;}
{IDENTIFICADOR} {return ID;}
{constEntera} {yylval.num=atoi(yytext);return CONSTANTE;}
":=" {return ASIGNACION;}
"," {return COMA;}
";" {return PYCOMA;}
"(" {return PARENIZQUIERDO;}
")" {return PARENDERECHO;}
"+" {return SUMA;}
"-" {return RESTA;}
<<EOF>> {return FDT;}
%%