#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palavra[30];
    char palavra_i[30];

    printf("Informe uma palavra para verificar se eh um palindromo: \n");
    fgets(palavra, 30, stdin);
    strcpy(palavra_i, palavra);
    size_t size = strlen(palavra);
    for (int i = 0; i < size / 2; i++) {
        char c0 = palavra[i];
        palavra[i] = palavra[size - i - 1];
        palavra[size - i - 1] = c0;
    }

    if (strcmp(palavra, palavra_i) == 0) {
        printf("A palavra eh um palindromo!\n");
    } else {
        printf("A palavra nao eh um palindromo.\n");
    }

    return 0;
}