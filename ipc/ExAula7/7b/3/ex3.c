#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[3][3];
    int soma = 0;

    printf("Informe os numeros da matriz: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
            if (i == j) {
                soma += mat[i][j];
            }
        }
    }

    printf("A soma dos valores da diagonal principal da matriz eh: %d\n", soma);

    return 0;
}