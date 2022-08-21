#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n;

    printf("Informe um numero para a medida quadrada da matriz: \n");
    for (int i = 0; i < 1; i++) {
        scanf("%d", &n);
        if (n <= 0) {
            printf("O numero deve ser maior que zero!!\n");
            i--;
        }
    }

    int **mat;

    mat = (int *) malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        mat[i] = (int *) malloc(n*sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                mat[i][j] = 1;
            } else {
                mat[i][j] = 0;
            }
        }
    }

    printf("A matriz final eh: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        free (mat[i]);
        free (mat);
    }

    return 0;
}