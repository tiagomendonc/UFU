#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[30];
    printf("Informe um nome: \n");
    fgets(nome, 30, stdin);
    size_t size = strlen(nome);
    for (int i = 0; i < size / 2; i++) {
        char c0 = nome[i];
        nome[i] = nome[size - i - 1];
        nome[size - i - 1] = c0;
    }

    printf("%s", nome);

    return 0;
}