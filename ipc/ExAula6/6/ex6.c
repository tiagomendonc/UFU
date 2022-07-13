#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int n;
    float soma = 0, media = 0, dp = 0;

    printf("Informe quantos elementos tera seu vetor: \n");
    scanf("%d", &n);

    printf("Informe %d numeros para o vetor: \n", n);

    int vetor[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        media += vetor[i];
    }

    media = media / n;

    for (int i = 0; i < n; i++) {
        soma += pow(vetor[i] - media, 2);
    }

    dp = sqrt(soma / n);

    printf("A media aritmetica eh: %f\n", media);
    printf("O desvio padrao do vetor eh: %.4f\n", dp);

    return 0;
}