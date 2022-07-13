#include <stdio.h>
#include <stdlib.h>

int main () 
{
    float vi, v, t, a;

    printf("Insira a velocidade inicial em m/s\n");
    scanf("%f", &vi);
    printf("Insira a velocidade final em m/s\n");
    scanf("%f", &v);
    printf("Insira o intervalo de tempo em segundos\n");
    scanf("%f", &t);

    a = (v - vi) / t;

    printf("A aceleracao media foi de %f", a);
    printf("m/s");

    return 0;
}