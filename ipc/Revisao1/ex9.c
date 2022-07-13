#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[4][4], soma = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &mat[i][j]);
            if (i < j) {
                soma += mat[i][j];
            }
        }
    }

    printf ("A soma dos numeros acima da diagonal principal: %d\n", soma);

    return 0;
}