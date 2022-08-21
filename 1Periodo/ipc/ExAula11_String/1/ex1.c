#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[30];
    char nome_M[30];
    printf("Informe um nome: \n");
    fgets(nome, 30, stdin);
    for (int i = 0; nome[i] != '\0'; i++) {
        nome_M[i] = nome[i] - 32;
    }
    printf("%s", nome_M);

    return 0;
}