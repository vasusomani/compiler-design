#include <stdio.h>

int main()
{
    FILE *fptr = fopen("hello.txt", "r");

    if (fptr == NULL)
    {
        printf("File not found.\n");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), fptr) != NULL)
    {
        printf("%s", line);
    }

    fclose(fptr);
    return 0;
}
