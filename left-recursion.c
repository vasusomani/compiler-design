#include <stdio.h>
#include <string.h>

/*
E->Eα|β

E->αE'
E'->βE'
E'->ε
*/

void LeftRecursive(char *prod)
{
    char start = prod[0];
    if (prod[3] != start)
    {
        printf("%s", prod);
        return;
    }

    char alpha[100], beta[100];
    int i = 4;
    int j = 0;
    while (prod[i] != '|')
    {
        alpha[j++] = prod[i++];
    }
    i++;
    j = 0;
    while (prod[i] != '\0')
    {
        beta[j++] = prod[i++];
    }
    i++;

    printf("%c->%s%c'\n", start, alpha, start);
    printf("%c'->%s%c'\n", start, beta, start);
    printf("%c'->ep\n", start);
}

int main()
{
    char prod[100];
    printf("Enter the prod (e.g., E->E+E|T): ");
    scanf("%s", prod);

    LeftRecursive(prod);

    return 0;
}
