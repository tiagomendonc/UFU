// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdlib.h>
#include <stdio.h>

int main ()
{
    int n;
    float soma = 0;

    printf("Informe quantos numeros tera seu vetor: \n");
    scanf("%d", &n);

    int vetor[n];

    printf("Informe %d numeros para seu vetor: \n", n);
    for (int i = 0; i < n; i++) { 
        scanf("%d", &vetor[i]);
        soma += (i + 1) / (float)vetor[i]; 
    }

    printf("S = %.4f", soma);

    return 0;
}