// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float **mat, num;

    mat = (float *) malloc(5*sizeof(float));
    for (int i = 0; i < 5; i++) {
        mat[i] = (float *) malloc(5*sizeof(float));
    }

    printf("Informe os numeros da matriz: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    while(1) {
        printf("Informe um numero para saber a posicao do mesmo na matriz: \n");
        scanf("%d", &num);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (num == mat[i][j]) {
                    printf("Encontrado na posicao: %d, %d\n", i, j);
                }
            }
        }

        if (num == 0) {
            for (int i = 0; i < 5; i++) {
                free(mat[i]);
            }
            free(mat);

            printf("Isso eh tudo pessoal!!!");
            break;
        }
    }

    return 0;
}