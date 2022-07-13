#include <stdio.h>
#include <stdlib.h>

int main()
{
    float **mat, n;

    mat = (float *) malloc(5*sizeof(float));
    for (int i = 0; i < 5; i++) {
        mat[i] = (float *) malloc(5*sizeof(float));
    }

    printf("Informe os numeros da matriz: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%f", &mat[i][j]);
        }
    }

    while(1) {
        printf("Digite um numero para saber a posicao do mesmo: \n");
        scanf("%f", &n);

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (n == mat[i][j]) {
                    printf("Encontrado na posicao: %d, %d\n", i, j);
                }
            }
        }

        if (n == 0) {
            for (int i = 0; i < 5; i++) {
                free(mat[i]);
            }
            free(mat);

            printf("Isso eh tudo pessoal!!!\n");
            break;
        }
    }

    return 0;
}