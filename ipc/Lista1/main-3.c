// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float vetor[20], aux;

    printf("Informe 20 numeros para o vetor: \n");

    for (int i = 0; i < 20; i++) {
        scanf("%f", &vetor[i]);
    }

    for (int i = 0; i < 20; i++) {
        for (int j = i + 1; j < 20; j++) {
            if (vetor[j] < vetor[i]) {
                aux = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = aux;
                }
            }
    }
    

    printf("Vetor ordenado: ");
    for (int i = 0; i < 20; i++) {
        printf("%.4f ", vetor[i]);
    }

    return 0;
}