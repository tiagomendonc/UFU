#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float e = 0;
    int fat_i = 1;

    printf("Informe um numero: \n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        fat_i = 1;
        for (int j = 1; j <= i; j++) {
            fat_i = fat_i * j;
            fat_i = fat_i * i;
            e = e + 1 / (float) fat_i;
        }
    }

    printf("\n\n E = %f\n\n", e);

    return 0;
}