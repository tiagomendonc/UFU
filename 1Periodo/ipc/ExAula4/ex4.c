#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int a, b, c, delta, raiz1, raiz2;

    printf("Informe respectivamente as raizes a, b e c da equacao: \n");
    scanf("%d %d %d", &a, &b, &c);

    if (a == 0) {
        printf("Para ser uma equacao de segundo grau o a deve ser maior que 0!\n");
    } else {
        delta = (b * b) - 4 * a * c;
        if (delta < 0)
        {
            printf("Nao existe raiz.\n");
        } else if (delta == 0) {
            printf("Raiz unica.\n");
        } else {
            raiz1 = (-b + sqrt(delta)) / 2 * a;
            raiz2 = (-b - sqrt(delta)) / 2 * a;
            printf("As raizes sao: %d %d\n", raiz1, raiz2);
        }
        
    }

    return 0;
}