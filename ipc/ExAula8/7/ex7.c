#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int **a, **b, **c;

    a = (int *) malloc(2*sizeof(int));
    for (int i = 0; i < 2; i++) {
        a[i] = (int *) malloc(3*sizeof(int));
    }

    printf("Informe os numeros da matriz A: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    b = (int *) malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++) {
        b[i] = (int *) malloc(2*sizeof(int));
    }

    printf("Informe os numeros da matriz B: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    c = (int *) malloc(3*sizeof(int));
    for (int i = 0; i < 3; i++) {
        c[i] = (int *) malloc(3*sizeof(int));
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = 0;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];
            }
        }
    }

    printf("A matriz A eh: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", a[i][j]);
        }
    }
    printf("\n");
    printf("A matriz B eh: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", b[i][j]);
        }
    }
    printf("\n");
    printf("A matriz AB eh: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", c[i][j]);
        }
    }
    printf("\n");

    for (int i = 0; i < 2; i++) {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < 3; i++) {
        free(b[i]);
    }
    free(b);

    for (int i = 0; i < 2; i++) {
        free(c[i]);
    }
    free(c);

    return 0;
}