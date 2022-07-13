#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int num = 0;
    int soma = 0;

    for(num = 0; num < 1000; num++) {
        if (num % 3 == 0 || num % 5 == 0) {
            soma += num;
        }
    }

    printf("A soma dos numeros multiplos de 5 ou 3 eh: %d\n", soma);

    return 0;
}