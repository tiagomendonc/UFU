#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **mat, maior = 0, posicao_i, posicao_j;

    mat = (int *) malloc(4*sizeof(int));
    for (int i = 0; i < 4; i++) {
        mat[i] = (int *) malloc(4*sizeof(int));
    }

    printf("Informe 16 numeros para a matriz: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] > maior) {
                maior = mat[i][j];
                posicao_i = i;
                posicao_j = j;
            }
        }
    }

    printf("A matriz eh: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", mat[i][j]);
        }
    }
    printf("\n");

    printf("O maior numero eh %d e esta na posicao [%d][%d]\n", maior, posicao_i, posicao_j);

    for (int i = 0; i < 4; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}