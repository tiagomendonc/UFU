#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int a[2][3] = {{15, 52, 29},
                   {47, 34, 85}};
    int b[2][3] = {{5, 13, 11},
                   {8, 7, -10}};
    int c[2][3];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("C = ");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", c[i][j]);
        }
    }

    return 0;
}