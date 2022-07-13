#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **mat, x, aux = 1;

    mat = (int *) malloc(5*sizeof(int));
    for (int i = 0; i < 5; i++) {
        mat[i] = (int *) malloc(5*sizeof(int));
    }

    printf("Informe 25 numeros para sua matriz: \n");
    for(int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Busque um numero: \n");
    scanf("%d", &x);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (x == mat[i][j]) {
                printf("Encontrado na posicao: %d %d\n", i, j);
                aux++;
            }
        }
    }

    if (aux == 1) {
        printf("Valor nao encontrado!");
    }

    for (int i = 0; i < 5; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}