// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int **mat, det;

    mat = (int *) malloc(2*sizeof(int));
    for (int i = 0; i < 2; i++) {
        mat[i] = (int *) malloc(2*sizeof(int));
    }

    printf("Informe 4 numeros para a matriz: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    det = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

    printf("A determinante da matriz eh: %d\n", det);

    for (int i = 0; i < 2; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}