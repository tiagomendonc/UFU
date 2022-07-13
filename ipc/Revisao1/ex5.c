#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[10], maior = 0, menor = 0, posicao_maior, posicao_menor;

    printf("Informe 10 numeros para o vetor: \n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
        if (vet[i] == 0) {
            maior = vet[i];
            menor = vet[i];
            posicao_maior = i + 1;
            posicao_menor = i + 1;
        }
        if (maior < vet[i]) {
            maior = vet[i];
            posicao_maior = i + 1;
        }
        if (menor > vet[i]) {
            menor = vet[i];
            posicao_menor = i + 1;
        }
    }

    printf("O maior numero eh %d e esta na posicao %d\n", maior, posicao_maior);
    printf("O menor numero eh %d e esta na posicao %d\n", menor, posicao_menor);

    return 0;
}