#include <stdio.h>
#include <stdlib.h>

// A
void imprimeVetor(int vet[10], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
}

// B
int encontraMaior(int vet[10], int n) {
    int maior = 0;
    for(int i = 0; i < n; i++) {
        if(vet[i] > maior) {
            maior = vet[i];
        }
    }
    return maior;
}

// C
void encontraDoisMaiores(int vet[10], int n) {
    int maior, segmaior, aux;
    for(int i = 0; i < 10; i++) {
        if(i == 0) {
            maior = vet[i];
            segmaior = vet[i];
        } else if (vet[i] > maior) {
            aux = maior;
            maior = vet[i];
            segmaior = aux;
        } else if(vet[i] > segmaior) {
            segmaior = vet[i];
        }
    }
    printf("Os dois maiores valores do vetor sao respectivamente: %d e %d\n", maior, segmaior);
}

// D
float media(int vet[10], int n) {
    int soma = 0;
    for(int i = 0; i < n; i++) {
        soma += vet[i];
    }
    float media = soma / n;
    return media;
}

// E
void doisIguais(int vet[10], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(vet[i] == vet[j]) {
                printf("Valor repetido: %d nos indices %d e %d", vet[i], i, j);
                for(int k = j + 1; k < n; k++) {
                    if(vet[i] == vet[k]) {
                        printf(" e %d", k);
                    }
                }
                printf("\n");
            }
        }
    }
}

// F
void imprimeInverso(int vet[10], int n) {
    printf("O vetor na forma inversa eh: ");
    for(int i = n - 1; i >= 0; i--) {
        printf("%d ", vet[i]);
    }
}

// G
int contaImpar(int vet[10], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(vet[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}


int main()
{
    int vet[10];
    
    printf("Informe dez numeros para o vetor: \n");
    for(int i = 0; i < 10; i++) {
        scanf("%d", &vet[i]);
    }

    imprimeVetor(vet, 10);
    printf("\n");

    printf("O maior numero do vetor eh: %d", encontraMaior(vet, 10));
    printf("\n");

    encontraDoisMaiores(vet, 10);

    printf("A media dos numeros do vetor eh: %.2f", media(vet, 10));
    printf("\n");

    doisIguais(vet, 10);

    imprimeInverso(vet, 10);
    printf("\n");

    printf("O vetor tem %d numeros impares.", contaImpar(vet, 10));
    printf("\n");
    
    return 0;
}