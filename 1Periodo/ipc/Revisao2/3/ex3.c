#include <stdio.h>
#include <stdlib.h>

void transposta(int **mat) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    printf("Informe os numeros da matriz a ser transposta:\n");

    int **mat = (int **) malloc(5*sizeof(int*));
    for(int i = 0; i < 5; i++) {
        mat[i] = (int *) malloc(5*sizeof(int));
        for(int j = 0; j < 5; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n");

    transposta(mat);

    return 0;
}