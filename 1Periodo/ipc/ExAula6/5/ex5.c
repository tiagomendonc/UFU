#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n; 
    float soma = 0;

    printf("Informe quantos elementos tera o seu vetor: \n");
    scanf("%d", &n);

    int vetor[n];

    printf("Insira %d numeros para seu vetor: \n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        soma += (i + 1) / (float)vetor[i];
    }

    printf("S = %.4f", soma);

    return 0;
}