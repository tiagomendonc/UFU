#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vet;

    printf("Informe 5 numeros para o vetor: \n");
    vet = (int *) malloc(5*sizeof(int));
    for(int i = 0; i < 5; i++) {
        scanf("%d", &vet[i]);
    }
    printf("\n");

    for(int i = 0; i < 5; i++) {
        printf("%d ", vet[i]);
    }

    free(vet);

    return 0;
}