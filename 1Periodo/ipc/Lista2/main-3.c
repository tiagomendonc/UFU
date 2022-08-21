// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int mat[6][6];
    int soma = 0;

    printf("Informe os numeros da matriz: \n");
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (i > j) {
                soma += mat[i][j];
            }
        }
    }

    printf("A soma dos numeros abaixo da diagonal principal eh: %d\n", soma);



    return 0;
}