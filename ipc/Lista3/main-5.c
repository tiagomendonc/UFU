// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand (time(NULL));

    int ***mat;

    mat = (int *) malloc(6*sizeof(int));
    for (int i = 0; i < 6; i++) {
        mat[i] = (int *) malloc(7*sizeof(int));
        for (int j = 0; j < 7; j++) {
            mat[i][j] = (int *) malloc(5*sizeof(int));
            for (int k = 0; k < 5; k++) {
                mat[i][j][k] = rand()%10 + 1;
            }
        }
    }

    for (int k = 0; k < 5; k++) {
        printf("Matriz %d\n", k + 1);
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                printf("%d\t", mat[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    for (int j = 0; j < 6; j++) {
        for (int k = 0; k < 7; k++) {
            free(mat[j][k]);
        }
    }
    free(mat);

    return 0;
}