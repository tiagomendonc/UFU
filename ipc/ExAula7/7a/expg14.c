#include <stdlib.h>
#include <stdio.h>

int main ()
{
    int A[2][3], B[2][3], S[2][3];

    printf("Insira os numeros da matriz A: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Insira os numeros da matriz B: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            S[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("A matriz resultante da soma de A e B eh: %d\n", S[2][3]);

    return 0;
}