#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct matriz {
    int ** mat;
} Matriz;

Matriz *criar(int l, int c) {
    Matriz * mat = (Matriz *) malloc(sizeof(Matriz));
    mat->mat = (int **) malloc(l * sizeof(int *));
    for(int i = 0; i < l; i++) {
        mat->mat[i] = (int *) malloc(c*sizeof(int)); 
    }

    return mat;
}

void inserir(Matriz *mat1, int i, int j, int x) {
    mat1->mat[i][j] = x;
}

void transposta(Matriz *mat1, Matriz *mat2, int l, int c) {
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            mat2->mat[j][i] = mat1->mat[i][j];
        }
    }
}

int main()
{
    Matriz *mat1;
    int l, c, x;

    printf("Informe o numero de linhas da sua matriz: \n");
    scanf("%d", &l);
    printf("Informe o numero de colunas da sua matriz: \n");
    scanf("%d", &c);

    mat1 = criar(l, c);

    printf("Informe os numeros da matriz: \n");
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%i", &x);
            inserir(mat1, i, j, x);
        }
    }

    Matriz *mat2;
    mat2 = criar(c, l);

    transposta(mat1, mat2, l, c);

    printf("Matriz transposta: \n");
    for(int i = 0; i < c; i++) {
        printf("\n");
        for(int j = 0; j < l; j++) {
            printf("%d ", mat2->mat[i][j]);
        }
    }

    return 0;
}