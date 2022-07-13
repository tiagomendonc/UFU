#include <stdio.h>
#include <stdlib.h>

float func(float vet[], int *n) {
    float soma = 0;
    for (int i = 0; i < *n; i++) {
        soma += vet[i];
    }
    soma = soma / *n;
    return soma;
}

int main() 
{
    int n;

    printf("Informe quantos numeros tem seu vetor: \n");
    scanf("%d", &n);

    float vet[n];

    printf("Informe os numeros do vetor: \n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &vet[i]);
    }

    printf("A media dos numeros do vetor eh: %.2f\n", func(vet, &n));

    return 0;
}