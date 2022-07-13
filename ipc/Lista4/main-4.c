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

float multiplica(float **matA, int la, int ca, float **matB, int lb, int cb) {
    float **matResultado = aloca(la, cb);
}