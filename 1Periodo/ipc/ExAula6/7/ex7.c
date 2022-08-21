#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int n;
    float soma = 0;
    float media = 0;
    float dp, somadp = 0;

    printf("Informe quantos numeros tera seu vetor: \n");
    scanf("%d", &n);

    int vetor[n];

    printf("Informe %d numeros para seu vetor: \n", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    media = soma / n;

    for (int i = 0; i < n; i++) {
        dp = pow((float)vetor[i] - media, 2);
        somadp += dp;
    }

    dp = sqrt(somadp / n);

    printf("A media aritmetica do vetor eh: %.4f\n", media);
    printf("O desvio padrao do vetor eh: %.4f\n", dp);

    return 0;
}