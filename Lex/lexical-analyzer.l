%{
#include<stdio.h>
%}

%%
float | 
int | 
double | 
char | 
long  {printf("KEYWORD: %s\n",yytext);}
[a-zA-Z_][a-zA-Z_0-9]* {printf("IDENTIFIER: %s\n",yytext);}
[0-9]+ {printf("NUMBER: %s\n",yytext);}
[\+\-/\*=;] {printf("OPERATOR: %s\n",yytext);}
[ \n\t]+ ;
. {printf("UNKNOWN CHARACTER\n");}
%%

int main(){
    yylex();
}

int yywrap(){
    return 1;
}