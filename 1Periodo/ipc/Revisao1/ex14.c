#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[3][3];

    printf("Informe os numeros da matriz: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int vet[3];

    for (int j = 0; j < 3; j++) {
        vet[j] = mat[0][j] + mat[1][j] + mat[2][j];
    }

    printf("O vetor resultante eh: \n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}