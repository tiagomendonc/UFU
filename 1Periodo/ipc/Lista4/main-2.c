// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calculaSoma(n) {
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        soma += pow(i, i);
    }
    return soma;
}

int main()
{
    int n;
    
    printf("Informe um numero: \n");
    scanf("%d", &n);

    printf("A soma dos primeiros %d numeros elevados a si proprios eh: %d\n", n, calculaSoma(n));

    return 0;
}