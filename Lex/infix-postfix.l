%{
#include <stdio.h>
#include <stdlib.h>

char stack[100];
int top = 0;

void push(char c) { 
    stack[top++] = c; 
}

char pop() { 
    return stack[--top]; 
}

int priority(char c) { 
    if (c == '+' || c == '-') return 1; 
    if (c == '*' || c == '/') return 2; 
    return 0; 
}
%}

%%

[a-zA-Z] { 
    printf("%c", yytext[0]); // Print operand directly
}

[+\-*/()] { 
    char op = yytext[0];

    if (op == '(') {
        push(op); // Push '(' onto the stack
    } 
    else if (op == ')') {
        // Pop and print operators until '(' is encountered
        while (stack[top - 1] != '(') {
            printf("%c", pop());
        }
        pop(); // Remove '('
    } 
    else {
        // Pop and print operators with higher or equal precedence
        while (top > 0 && priority(stack[top - 1]) >= priority(op)) {
            printf("%c", pop());
        }
        push(op); // Push current operator onto the stack
    }
}

\n { 
    // Pop and print all remaining operators
    while (top > 0) {
        printf("%c", pop());
    }
    printf("\n");
}

%%

int main() { 
    printf("Enter an infix expression:\n");
    yylex();
    return 0; 
}

int yywrap() { 
    return 1; 
}
