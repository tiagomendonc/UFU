#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n, qtd, lido = 0, maior = 0;

    printf("Informe uma quantidade de numeros a serem lidos: \n");
    scanf("%d", &qtd);

    for (int i = 0; i < qtd; i++) {
        printf("Informe um numero: \n");
        scanf("%d", &n);

        if (n == 0 && maior == n) {
            maior = n;
            lido++;
        }

        if (n > maior) {
            lido = 0;
            maior = n;
            lido++;
        }
    }

    printf("O maior numero eh: %d\n", maior);
    printf ("O maior numero foi lido: %d", lido);
    printf(" vezes\n");

    return 0;
}