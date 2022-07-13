#include <stdio.h>
#include <stdlib.h>

void maiorMenor(int vet[], int *n, int *maior, int *menor) {
    *maior = 0;
    *menor = 0;
    for (int i = 0; i < *n; i++) {
        if (i == 0) {
            *maior = vet[i];
            *menor = vet[i];
        }
        if (vet[i] > *maior) {
            *maior = vet[i];
        }
        if (*menor > vet[i]) {
            *menor = vet[i];
        }
    }
}

int main()
{
    int n, maior, menor;
    printf("Informe quantos numeros tera seu vetor: \n");
    scanf("%d", &n);

    int vet[n];
    printf("Informe os numeros do seu vetor: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    maiorMenor(vet, &n, &maior, &menor);

    printf("O maior numero do vetor eh: %d\n", maior);
    printf("O menor numero do vetor eh: %d\n", menor);

    return 0;
}