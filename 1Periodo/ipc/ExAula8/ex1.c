#include <stdlib.h>
#include <stdio.h>

int main ()
{
    int vet[10];

    printf("Informe o conteudo do vetor estatico: \n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
    }

    int *p;
    p = (int *) malloc(10*sizeof(int));
    p = &vet;
    

    for (int i = 0; i < 10; i++) {
        printf("O endereco da posicao %d do vetor eh: %d\n", i, &p[i]);
        printf("O conteudo da posicao %d do vetor eh: %d\n", i, *(p + i));
    }

    return 0;
}