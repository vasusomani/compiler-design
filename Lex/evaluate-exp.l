%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double stack[100];
int top = -1;

void push(double val) {
    stack[++top] = val;
}

double pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}

void evaluate(char op) {
    double b = pop();
    double a = pop();
    switch (op) {
        case '+': push(a + b); break;
        case '-': push(a - b); break;
        case '*': push(a * b); break;
        case '/': 
            if (b != 0) {
                push(a / b);
            } else {
                printf("Division by zero\n");
                exit(1);
            }
            break;
        default: 
            printf("Invalid operator\n");
            exit(1);
    }
}
%}

%%

[0-9]+(\.[0-9]+)?   { push(atof(yytext)); } // Match numbers (integer or floating-point)
[\+\-\*/]           { evaluate(yytext[0]); } // Match operators and evaluate
[\n]                { printf("Result: %lf\n", pop()); } // Print result at end of expression
[ \t]               ; // Ignore whitespaces
.                   { printf("Invalid character: %s\n", yytext); exit(1); } // Invalid input

%%

int main() {
    printf("Enter an arithmetic expression (e.g., '3 4 + 2 *'):\n");
    yylex();
}

int yywrap() {
    return 1;
}
