#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int vet[10];

    printf("Informe 10 numeros diferentes para o vetor: \n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
        for (int j = 0; j <= i - 1; j++) {
            if (vet[i] == vet[j]) {
                printf("O valor %d ja existe! Informe outro valor diferente: \n", vet[i]);
                i--;
            }
        }
    }

    printf("O vetor final eh: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}