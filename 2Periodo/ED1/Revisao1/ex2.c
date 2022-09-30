#include <stdio.h>
#include <stdlib.h>

int possivelMultiplicar(int la, int ca, int lb, int cb) {
    if(la == cb && ca == lb) {
        return 0;
    }
}

void multiplicaMatriz(int **ma, int la, int ca, int **mb, int lb, int cb) {
    int mab[la][cb];
    for(int i = 0; i < la; i++) {
        for(int j = 0; j < cb; j++) {
            mab[i][j] == 0;
        }
    }
    if(possivelMultiplicar(la, ca, lb, cb) == 0) {
        for(int i = 0; i < la; i++) {
            for(int j = 0; j < cb; j++) {
                for(int k = 0; k < ca; k++) {
                    mab[i][j] = mab[i][j] + ma[i][k] * mb[k][j];
                }
            }
        }

        printf("O resultado da multiplicacao eh: \n");
        for(int i = 0; i < la; i++) {
            printf("\n");
            for(int j = 0; j < cb; j++) {
                printf("%d ", mab[i][j]);
            }
        }
    } else {
        printf("Nao eh possivel multiplicar essas matrizes. \n");
    }
}

int main()
{
    int la, ca;
    printf("Informe respectivamente o numero de linha e colunas da primeira matriz: \n");
    for(int i = 0; i < 1; i++) {
        scanf("%d %d", &la, &ca);
        if(la > 5 || ca > 5) {
            printf("A matriz deve ter no maximo 5 linhas e 5 colunas! Informe novamente: \n");
            i--;
        }
    }
    int lb, cb;
    printf("Informe respectivamente o numero de linha e colunas da segunda matriz: \n");
    for(int i = 0; i < 1; i++) {
        scanf("%d %d", &lb, &cb);
        if(lb > 5 || cb > 5) {
            printf("A matriz deve ter no maximo 5 linhas e 5 colunas! Informe novamente: \n");
            i--;
        }
    }

    int **ma;
    ma = (int *) malloc(la*sizeof(int));
    for(int i = 0; i < la; i++) {
        ma[i] = (int *) malloc(ca*sizeof(int));
    }
    printf("Informe os numeros da primeira matriz: \n");
    for(int i = 0; i < la; i++) {
        for(int j = 0; j < ca; j++) {
            scanf("%d", &ma[i][j]);
        }
    }

    int **mb;
    mb = (int *) malloc(lb*sizeof(int));
    for(int i = 0; i < lb; i++) {
        mb[i] = (int *) malloc(cb*sizeof(int));
    }
    printf("Informe os numeros da segunda matriz: \n");
    for(int i = 0; i < lb; i++) {
        for(int j = 0; j < cb; j++) {
            scanf("%d", &mb[i][j]);
        }
    }

    multiplicaMatriz(ma, la, ca, mb, lb, cb);

    for(int i = 0; i < la; i++) {
        free(ma[i]);
    }
    free(ma);

    for(int i = 0; i < lb; i++) {
        free(mb[i]);
    }
    free(mb);

    return 0;
}