// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int vetor[10];

    printf("Informe 10 numeros para o vetor: \n");
    for (int i = 0; i < 10; i++) { 
        scanf("%d", &vetor[i]);
        for (int j = 0; j < i; j++) { 
            if (vetor[i] == vetor[j]) { 
                printf("Esse numero ja esta no vetor, informe outro!\n");
                i--; 
            }
        }
    }

    printf("\n");
    printf("O vetor eh: ");
    for (int i = 0; i < 10; i++) { 
        printf("%d ", vetor[i]);
    }

    return 0;
}