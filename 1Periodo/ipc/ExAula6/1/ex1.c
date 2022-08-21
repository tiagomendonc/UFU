#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int vetor[10];

    printf("Informe 10 numeros: \n");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    for(int i = 0; i < 10; i++) {
        if(vetor[i] % 2 == 0) {
            printf("%d: par\n", vetor[i]);
        } else {
            printf("%d: impar\n", vetor[i]);
        }
    }

    return 0;
}