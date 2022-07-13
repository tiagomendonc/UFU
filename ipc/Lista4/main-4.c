// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

float aloca(int l, int c) {
    float **mat;
    mat = (float *) malloc(l*sizeof(float));
    for (int i = 0; i < l; i++) {
        mat[i] = (float *) malloc(c*sizeof(float));
    }
    return **mat;
}

void leitura(float **mat, int l, int c) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

float multiplica(float **matA, int la, int ca, float **matB, int lb, int cb, float **matResultado) {
    **matResultado = aloca(la, cb);
    for (int i = 0; i < la; i++) {
        for (int j = 0; j < cb; j++) {
            for (int k = 0; k < ca; k++) {
                matResultado[i][j] = matA[i][k] * matB[k][j];
            }
        }
    }
    return **matResultado;
}

void imprime(float **mat, int l, int c) {
    for(int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat);
        }
    }
}

void desaloca(float **mat, int l) {
    for(int i = 0; i < l; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main()
{
    int la, ca, lb, cb;
    printf("Informe o numero de linhas da matriz A: \n");
    scanf("%d", &la);
    printf("Informe o numero de colunas da matriz A: \n");
    scanf("%d", &ca);
    cb = la;
    lb = ca;

    float matA = aloca(la, ca);
    printf("Informe %d numeros para a matriz A: \n", la * ca);
    leitura(&matA, la, ca);

    float matB = aloca(lb, cb);
    printf("Informe %d numeros para a matriz B: \n", lb * cb);
    leitura(&matB, lb, cb);

    float matAxB = aloca(la, cb);
    matAxB = multiplica(&matA, la, ca, &matB, lb, cb, &matAxB);

    printf("A matriz A eh: \n");
    imprime(&matA, la, ca);
    printf("A matriz B eh: \n");
    imprime(&matB, lb, cb);
    printf("O resultado da multiplicacao dessas matrizes eh: \n");
    imprime(&matAxB, la, cb);

    desaloca(&matA, la);
    desaloca(&matB, lb);
    desaloca(&matAxB, la);

    return 0;
}