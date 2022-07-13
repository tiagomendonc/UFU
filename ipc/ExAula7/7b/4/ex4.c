#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[5][4];
    int n;

    printf("Informe os numeros da sua matriz: \n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Informe qual linha voce deseja receber: \n");
    scanf("%d", &n);

    switch (n) {
        case 1:
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d ", mat[i][j]);
                }
            }
        break;
        case 2:
            for (int i = 1; i < 2; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d ", mat[i][j]);
                }
            }
        break;
        case 3:
            for (int i = 2; i < 3; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d ", mat[i][j]);
                }
            }
        break;
        case 4:
            for (int i = 3; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d ", mat[i][j]);
                }
            }
        break;
        case 5:
            for (int i = 4; i < 5; i++) {
                for (int j = 0; j < 4; j++) {
                    printf("%d ", mat[i][j]);
                }
            }
        break;
        default:
            printf("Informe um numero entre 1 e 5!\n");
    }   

    return 0;
}