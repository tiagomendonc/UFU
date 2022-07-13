#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n, num;

    printf("Informe um numero impar: \n");
    for (int i = 0; i < 1; i++) {
        scanf("%d", &n);
        if (n % 2 == 0) {
            printf("O numero deve ser impar! Tente novamente!\n");
            i--;
        }
    }

    printf("Informe numeros para saber se sao par ou impar: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num % 2 == 0) {
            printf("Par\n");
        } else {
            printf("Impar\n");
        }
    }

    return 0;
}