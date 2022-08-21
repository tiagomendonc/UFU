#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    float num[10];
    float media, soma, qd = 0;

    printf("Insira os numeros para calcular a media aritmetica:\n");

    for (int i = 0; i < 10; i++)
    {
        scanf ("%f", &num[i]);
        soma += num[i];
    }

    media = soma / 10;

    printf("A media dos numeros eh: %.2f\n", media);

    soma = 0;

    for (int j = 0; j < 10; j++)
    {
        qd = pow(num[j] - media, 2);
        soma += qd;
    }

    float dp = sqrt(media);

    printf("O desvio padrao dos numeros eh: %f", dp);
    
    

    return 0;
}