#include <stdio.h>
#include <stdlib.h>

void trocaValor(int*a, int*b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    printf("Valor trocado de A: %d\n", *a);
    printf("Valor trocado de B: %d\n", *b);
}

int main ()
{
    int a, b;
    printf("Informe os valores de A e B: \n");
    scanf("%d %d", &a, &b);

    trocaValor(&a, &b);

    return 0;
}