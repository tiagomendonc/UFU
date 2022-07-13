#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 20

int main () 
{
    int a[TAMANHO], b[TAMANHO];

    printf("Informe 20 elementos para o vetor: \n");

    for(int i = 0; i < TAMANHO; i++) {
        scanf("%d", &a[i]);
        b[TAMANHO - 1 - i] = a[i];
    }

    printf("Vetor A: \n");
    for(int i = 0; i < TAMANHO; i++) {
        printf("%d\n", a[i]);
    }

    printf("Vetor B: \n");
    for(int i = 0; i < TAMANHO; i++) {
        printf("%d\n", b[i]);
    }   

    return 0;
}