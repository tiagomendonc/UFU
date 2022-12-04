#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct vetor {
    float *elem;
    int total;
    int max;
};
typedef struct vetor Vetor;

Vetor *criar(int n, bool *deuCerto) {
    Vetor *v;
    v = (Vetor *) malloc(sizeof(Vetor));
    if (v == NULL) *deuCerto = false;
    else {
        v->elem = (float *) malloc(n * sizeof(float));
        if (v->elem == NULL) *deuCerto = false;
        else {
            *deuCerto = true;
            v->total = 0;
            v->max = n;
        }
    }
    return v;
}

void destruir(Vetor *v) {
    free(v->elem);
    free(v);
}

bool inserir(Vetor *v, float x) {
    bool deuCerto;
    if(v->total == v->max) {
        deuCerto = false;
        return deuCerto;
    } else {
        v->elem[v->total] = x;
        v->total++;
        deuCerto = true;
        return deuCerto;
    }
}

int main()
{
    int n;
    float x;
    bool deuCerto;

    printf("Informe a capacidade do vetor: \n");
    scanf("%d", &n);

    Vetor *v;
    v = criar(n, &deuCerto);

    printf("Informe %d numeros para o vetor: \n", n);
    while(v->total != v->max) {
        scanf("%f", &x);
        inserir(v, x);
    }

    if(v->total == v->max) {
        printf("Pilha cheia!\n");
    }

    destruir(v);

    return 0;
}