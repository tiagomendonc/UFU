#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n;
    int maior = 0;

    printf("Informe quantos elementos tera seu vetor: \n");
    scanf("%d", &n);

    int vetor[n];

    printf("Digite %d numeros para seu vetor: \n", n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);

        if(vetor[i] == 0) {
            maior = vetor[i];
        }

        if(maior < vetor[i]) {
            maior = vetor[i];
        }
    }

    printf("O maior numero eh: %d", maior);

    return 0;
}