#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n;
    int j, c = 0;

    printf("Informe um numero de linhas: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            c++;
            printf("%d ", c);
        }
        printf("\n");
    }

    return 0;
}