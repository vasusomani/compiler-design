%{
#include<stdio.h>
int count=0;
%}

%%
[a-zA-Z0-9]+[ \n\t] {count++;}
.;
%%

int main(){
    printf("Enter string: ");
    yylex();
    printf("Words Count: %d",count);
}

int yywrap(){
    return 1;
}