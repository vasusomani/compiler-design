%{
int correct=0;
%}

%%

[A-Z][A-Z][A-Z][A-Z][A-Z][0-9][0-9][0-9][0-9][A-Z] {correct=1;}
. ;

%%

int main() {
    yylex();
    if(correct==1)printf("\nVALID\n");
    else printf("\nINVALID\n");
}

int yywrap() {
    return 1;
}
