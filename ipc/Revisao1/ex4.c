#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[10], qtd_n = 0, soma_p = 0;

    printf("Informe dez numeros para o seu vetor: \n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
        if (vet[i] < 0) {
            qtd_n++;
        }
        if (vet[i] >= 0) {
            soma_p += vet[i];
        }
    }

    printf("Existem %d numeros negativos no seu vetor.\n", qtd_n);
    printf("A soma dos numeros positivos do seu vetor eh: %d\n", soma_p);

    return 0;
}