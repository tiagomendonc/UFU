#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main ()
{
    int mat[10][10];

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i < j) {
                mat[i][j] = 2*i + 7*j - 2;
            }
            if (i == j) {
                mat[i][j] = pow(3*i, 2) - 1; 
            }
            if (i > j) {
                mat[i][j] = pow(4*i, 3) - pow(5*j, 2) + 1;
            }
        }
    }

    printf("A matriz final eh: \n");
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            printf("%d ", mat[i][j]);
        }
    }

    return 0;
}