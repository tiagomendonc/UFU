#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num, div;

    printf("Insira um numero positivo: \n");
    scanf("%d", &num);

    if (num < 0) {
        printf("Informe um numero positivo!!\n");
    } else {
        printf("Os divisores do numero %d", num);
        printf(" sao: \n");

        for (int i = 1; i <= num; i++) {
            div = num % i;

            if (div == 0) {
                printf("%d ", i);        
            }
        }
    }

    return 0;
}