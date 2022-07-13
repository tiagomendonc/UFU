#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num, div;
    int soma = 0;

    printf("Insira um numero positivo: \n");
    scanf("%d", &num);

    if (num < 0) {
        printf("Informe um numero positivo!!\n");
    } else {
        printf("Os divisores do numero %d", num);
        printf(" sao: \n");

        for (int i = 1; i < num; i++) {
            div = num % i;

            if (div == 0) {
                printf("%d ", i);
                soma += i;        
            }
        }

        printf("\nA soma dos divisores do numero %d", num);
        printf(" eh: %d\n", soma);
    }

    return 0;
}