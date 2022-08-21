#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n, maior, menor;
    float m = 0;

    printf("Insira 10 numeros: \n");

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &n);
        if (n < 0) {
            printf("Insira somente numeros positivos!!\n");
            i--;
            continue;
        } else {
            m += n;

            if (n == 0) {
                maior = n;
                menor = n;
            }

            if (maior < n) {
                maior = n;
            }

            if (menor > n) {
                menor = n;
            }
        }
    }

    printf("A media entre os numeros eh: %.2f\n", m / 10);
    printf("O maior numero eh: %d\n", maior);
    printf("O menor numero eh: %d\n", menor);
    

    return 0;
}