// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float tabela[4][3] = {{170.00, 151.30, 139.20},
                         {153.00, 136.17, 125.28},
                         {139.23, 123.91, 112.76},
                         {128.09, 117.84, 104.88}};
    int quebrado;
    char tipo;

    printf("\t\tTABELA DE GRAOS\n");
    printf("\t\tInforme o tipo de grao desejado: (A, B, C, D)\n");
    scanf("%c", &tipo);
    printf("\t\tInforme a quantidade de graos quebrados por amostra: (3, 4, 5)\n");
    scanf("%d", &quebrado);

    if (tipo == 'A' && quebrado == 3) {
        printf("Valor por saca eh: R$%.2f", tabela[0][0]);
    } else if (tipo == 'A' && quebrado == 4) {
        printf("Valor por saca eh: R$%.2f", tabela[0][1]);
    } else if (tipo == 'A' && quebrado == 5) {
        printf("Valor por saca eh: R$%.2f", tabela[0][2]);
    } else if (tipo == 'B' && quebrado == 3) {
        printf("Valor por saca eh: R$%.2f", tabela[1][0]);
    } else if (tipo == 'B' && quebrado == 4) {
        printf("Valor por saca eh: R$%.2f", tabela[1][1]);
    } else if (tipo == 'B' && quebrado == 5) {
        printf("Valor por saca eh: R$%.2f", tabela[1][2]);
    } else if (tipo == 'C' && quebrado == 3) {
        printf("Valor por saca eh: R$%.2f", tabela[2][0]);
    } else if (tipo == 'C' && quebrado == 4) {
        printf("Valor por saca eh: R$%.2f", tabela[2][1]);
    } else if (tipo == 'C' && quebrado == 5) {
        printf("Valor por saca eh: R$%.2f", tabela[2][2]);
    } else if (tipo == 'D' && quebrado == 3) {
        printf("Valor por saca eh: R$%.2f", tabela[3][0]);
    } else if (tipo == 'D' && quebrado == 4) {
        printf("Valor por saca eh: R$%.2f", tabela[3][1]);
    } else if (tipo == 'D' && quebrado == 5) {
        printf("Valor por saca eh: R$%.2f", tabela[3][2]);
    } else {
        printf("Insira informacoes validas!!");
    }

    return 0;
}