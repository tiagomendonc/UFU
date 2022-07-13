// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int la, ca, lb, cb;

    printf("Informa a quantidade de linhas da matriz A: \n");
    scanf("%d", &la);
    printf("Informe a quantidade de colunas da matriz A: \n");
    scanf("%d", &ca);

    printf("Informe a quantidade de linhas da matriz B: \n");
    scanf("%d", &lb);
    printf("Informe a quantidade de colunas da coluna B: \n");
    scanf("%d", &cb);

    if (la != cb) {
        printf("A matriz nao eh compativel para multiplicacao!!!\n");
    } else 
    {
    int **a, **b, **ab;

    a = (int *) malloc(la*sizeof(int));
    for (int i = 0; i < la; i++) {
        a[i] = (int *) malloc(ca*sizeof(int));
    }

    printf("Informe %d numeros para a matriz A: \n", la * ca);
    for (int i = 0; i < la; i++) {
        for (int j = 0; j < ca; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    b = (int *) malloc(lb*sizeof(int));
    for (int i = 0; i < lb; i++) {
        b[i] = (int *) malloc(cb*sizeof(int));
    }

    printf("Informe %d numeros para a matriz B: \n", lb * cb);
    for (int i = 0; i < lb; i++) {
        for (int j = 0; j < cb; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    ab = (int *) malloc(la*sizeof(int));
    for (int i = 0; i < la; i++) {
        ab[i] = (int *) malloc(cb*sizeof(int));
    }

    for (int i = 0; i < la; i++) {
        for (int j = 0; j < cb; j++) {
            ab[i][j] = 0;
        }
    }

    for (int i = 0; i < la; i++) {
        for (int j = 0; j < cb; j++) {
            for (int k = 0; k < ca; k++) {
                ab[i][j] = ab[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    printf("A matrz A eh: \n");
    for (int i = 0; i < la; i++) {
        for (int j = 0; j < ca; j++) {
            printf("%d ", a[i][j]);
        }
    }

    printf("\n");

    printf("A matrz B eh: \n");
    for (int i = 0; i < lb; i++) {
        for (int j = 0; j < cb; j++) {
            printf("%d ", b[i][j]);
        }
    }

    printf("\n");

    printf("A matrz AB eh: \n");
    for (int i = 0; i < la; i++) {
        for (int j = 0; j < cb; j++) {
            printf("%d ", ab[i][j]);
        }
    }

    for (int i = 0; i < la; i++) {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < lb; i++) {
        free(b[i]);
    }
    free(b);

    for (int i = 0; i < la; i++) {
        free(ab[i]);
    }
    free(ab);

    }

    
    return 0;
}