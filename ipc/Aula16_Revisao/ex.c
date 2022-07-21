#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void atribuiVetor(int *vet, int tam) {
    srand(time(NULL));
    for (int i = 0; i < tam; i++) {
        vet[i] = rand() % tam;
    }
}

void ordenaVetor(int *vet, int tam) {
    int aux;
    for(int j = tam - 1; j >= 1; j--) {
        for(int i = 0; i < j; i++) {
            if(vet[i] > vet[i + 1]) {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
            }
        }
    }
}

int pesquisaSequencial(int *vet, int tam, int n, int *comparacoes) {
    *comparacoes = 0;
    for(int i = 0; i < tam; i++) {
        *comparacoes = *comparacoes + 1;
        if(n == vet[i]) {
            return i;
        }
    }
    return -1;
}

int pesquisaBinariaI(int *vet, int tam, int n, int *comparacoes) {
    int inicio = 0, fim = tam - 1, meio;
    *comparacoes = 0;
    while(inicio <= fim) {
        meio = (inicio + fim) / 2;
        *comparacoes = *comparacoes + 1;
        if(n == vet[meio]) {
            return meio;
        }
        *comparacoes = *comparacoes + 1;
        if(n < vet[meio]) {
            fim = meio - 1;
            continue;;
        }
        if(n > vet[meio]) {
            inicio = meio + 1;
            continue;
        }
        else {
            return -1;
        }
    }
}

int pesquisaBinariaR(int *vet, int tam, int n) {
    int inicio = 0, fim = tam - 1, meio;
    meio = (inicio + fim) / 2;
    if(vet[meio] == n) {
        return meio;
    }
    if(fim == inicio) {
        return -1;
    }
    if(vet[meio] > n) {
        meio--;
        return pesquisaBinariaR(vet, tam, n);
    }
    else {
        inicio++;
        return pesquisaBinariaR(vet, tam, n);
    }
}

int main()
{
    int tam = 1000;
    int *vet = (int *) malloc(tam*sizeof(int));

    atribuiVetor(vet, tam);
    ordenaVetor(vet, tam);
    for(int i = 0; i < tam; i++) {
        printf("%d, ", vet[i]);
    }

    int n, meio;

    do {
        printf("\nInforme um valor para buscar no vetor: \n");
        scanf("%d", &n);
        int comparacao1, comparacao2, comparacao3;
        printf("Pesquisa Sequencial:\nEncontrado na posicao: %d.", pesquisaSequencial(vet, tam, n, &comparacao1)); printf(" %d comparacoes.\n", comparacao1);
        printf("Pesquisa Binaria:\nEncontrado na posicao: %d.", pesquisaBinariaI(vet, tam, n, &comparacao2)); printf(" %d comparacoes.\n", comparacao2);
        printf("Pesquisa Binaria Recursiva:\nEncontrado na posicao: %d.", pesquisaBinariaR(vet, tam, n));
    } while(n);

    return 0;
}