// Tiago Oliveira Mendonça
// 121BSI238

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int n;
    float soma = 0, dp = 0, media = 0;

    printf("Informe quantos numeros tera o vetor: \n");
    scanf("%d", &n);

    int vetor[n];

    printf("Informe %d numeros para seu vetor: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        media += vetor[i];
    }

    media = media / n;

    for (int i = 0; i < n; i++) {
        soma += pow(vetor[i] - media, 2);
    }

    dp = sqrt(soma / n);

    printf("A media aritmetica do vetor eh: %.4f\n", media);
    printf("O desvio padrao do vetor eh: %.4f\n", dp);

    return 0;
}