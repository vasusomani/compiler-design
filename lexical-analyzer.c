#include <stdio.h>
#include <string.h>

int main()
{
    char input[256];
    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);

    char *token = strtok(input, " ");
    while (token != NULL)
    {
        if (strcmp(token, "float") == 0 || strcmp(token, "int") == 0 || strcmp(token, "char") == 0)
        {
            printf("Keyword: %s\n", token);
        }
        else if (strlen(token) == 1 && (*token == '+' || *token == '=' || *token == '*' || *token == '-' || *token == '/'))
        {
            printf("Operator: %s\n", token);
        }
        else
        {
            printf("Identifier: %s\n", token);
        }
        token = strtok(NULL, " ");
    }

    return 0;
}