#include <stdio.h>
#include <stdlib.h>

int matTrans(int **mat, int *l, int *c) {
    int **matT;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            matT[j][i] = mat[i][j];
        }
    }
    return **matT;
}

int main()
{
    int l, c;
    printf("Informe respectivamente o numero de linhas e colunas da sua matriz: \n");
    scanf("%d", &l);
    scanf("%d", &c);

    int **mat, **matT;
    mat = (int *) malloc(l*sizeof(int));
    for (int i = 0; i < l; i++) {
        mat[i] = (int *) malloc(c*sizeof(int));
    }

    matT = (int *) malloc(c*sizeof(int));
    for (int i = 0; i < c; sizeof(int)) {
        matT[i] = (int *) malloc(l*sizeof(int));
    }

    printf("Informe os numeros da matriz: \n");    
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    matT = matTrans(&mat, &l, &c);

    printf("A matriz transposta eh: \n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < l; j++) {
            printf("%d ", matT[i][j]);
        }
    }

    for(int i = 0; i < l; i++) {
        free(mat[i]);
    }
    free(mat);

    for (int i = 0; i < c; i++) {
        free(matT[i]);
    }
    free(mat);

    return 0;
}