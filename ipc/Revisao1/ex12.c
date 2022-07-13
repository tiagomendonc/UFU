#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int vet[10], aux;

    printf("Informe 10 numeros para o vetor: \n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
        if (vet[j] < vet[i]) {
            aux = vet[j];
            vet[j] = vet[i];
            vet[i] = aux;
            }
        }
    }
    
    printf("O vetor ordenado eh: \n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}