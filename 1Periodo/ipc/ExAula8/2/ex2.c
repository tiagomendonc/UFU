#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int vet[5];

    printf("Informe os valores do vetor: \n");
    
    int *p;
    p = &vet;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &p[i]);
    }

    for (int i = 0; i < 5; i++) {
        p[i] = (p[i]) * 2;
        printf("O valor da posicao %d eh: %d\n", i, *(p + i));
    }


    return 0;
}