%{
#include<stdio.h>
int upper=0;
int lower=0;
%}

%%
[A-Z] {upper++;}
[a-z] {lower++;}
.;
%%

int main(){
    printf("Enter string: ");
    yylex();
    printf("Upper Count: %d\nLower Count: %d",upper,lower);
    return 0;
}

int yywrap(){
    return 1;
}