// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a[2][2];
    int b[2][2];
    int c[2][2];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            a[i][j] = 3 * (i + 1) + 4 * (j + 1);
        }
    }

    printf("A matriz A eh: ");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", a[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            b[i][j] = -4 * (i + 1) - 3 * (j + 1);
        }
    }

    printf ("A matriz B eh: ");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", b[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("C = A + B. A matriz C eh: ");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", c[i][j]);
        }
    }

    return 0;
}