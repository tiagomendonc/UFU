// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int decrescente(int n) {
    printf("%d ", n);
    if (n <= 0) {
        return 0;
    } else {
        return decrescente(n - 1);
    }
}

int crescente(int n, int aux) {
    printf("%d ", aux);
    if (n > aux) {
        return crescente(n, aux + 1);
    } else {
        return 0;
    }
}

int main() 
{
    int n;
    int aux = 0;
    printf("Informe um numero: \n");
    scanf("%d", &n);

    printf("Decrescente: \n");
    decrescente(n);

    printf("\nCrescente: \n");
    crescente(n, aux);

    return 0;
}