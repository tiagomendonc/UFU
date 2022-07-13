#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int matriz[3] [3];
    int soma = 0;

    printf("Informe os numeros da matriz: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i] [j]);
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma = soma + matriz[i] [j];
        }
    }

    printf("A soma dos valores da matriz eh: %d\n", soma);

    return 0;
}