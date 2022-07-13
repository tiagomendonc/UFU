#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int mat[3][3], t[3][3];

    printf("Informe os numeros da matriz: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &mat[i][j]);
            t[j][i] = mat[i][j];
        }
    }

    printf("A matriz transposta eh: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", t[i][j]);
        }
    }

    return 0;
}