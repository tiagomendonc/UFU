#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vet;
    int n;
    int countPar = 0;
    int countImpar = 0;

    printf("Informe quantos numeros irah inserir: \n");
    scanf("%d", &n);

    vet = (int *) malloc(n*sizeof(int));

    printf("Informe %d numeros para o vetor: \n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
        if(vet[i] % 2 == 0) {
            countPar++;
        } else {
            countImpar++;
        }
    }

    printf("Sao pares: %d dos %d inteiros lidos: \n", countPar, n);
    printf("Sao impares: %d dos %d inteiros lidos: \n", countImpar, n);

    free(vet);


    return 0;
}