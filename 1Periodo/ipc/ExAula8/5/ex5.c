#include <stdio.h>
#include <stdlib.h>

int main () 
{
    int n;

    printf("Informe N numeros para posicoes do vetor: \n");
    for (int i = 0; i < 1; i++) {
        scanf("%d", &n);
        if (n <= 0) {
            printf("Informe um numero maior que 0!!\n");
            i--;
        }
    }

    int vet[n], *p;
    p = (int *) malloc(n*sizeof(int));
    p = &vet;

    for (int i = 0; i < n; i++) {
        printf("Informe o %d numero do vetor: \n", i + 1);
        scanf("%d", &p[i]);
        if (p[i] < 2) {
            printf("O valor deve ser maior ou igual a 2!!\n");
            i--;
        }
    }

    printf("O vetor eh: \n");
    for (int i = 0; i < n; i++) {
        printf("%d \n", *(p + i));
    }
    
    return 0;
}