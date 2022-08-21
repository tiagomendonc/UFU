#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int ql, qc;

    printf("Informe quantas linhas tera sua matriz: \n");
    scanf("%d", &ql);
    printf("Informe quantas colunas tera sua matriz: \n");
    scanf("%d", &qc);

    int matriz[ql][qc];
    int vetor[qc];
    int resultado[ql];

    printf("Informe os numeros da sua matriz: \n");
    for (int i = 0; i < ql; i++) {
        for (int j = 0; j < qc; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Informe os numeros do seu vetor: \n");
    for (int i = 0; i < qc; i++) {
        scanf("%d", &vetor[i]);
    }

    for (int i = 0; i < ql; i++) {
        resultado[i] = 0;
        for (int j = 0; j < qc; j++) {
            resultado[i] += matriz[i][j] * vetor[j];
        }
    }

    printf("O resultado da multiplicacao entre a sua matriz e seu vetor eh: ");
    for (int i = 0; i < qc; i++) {
        printf("%d ", resultado[i]);
    }

    return 0;
}