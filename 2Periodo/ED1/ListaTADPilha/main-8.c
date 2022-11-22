#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

struct pilha{
    int el[MAX];
    int topo;
}; typedef struct pilha Pilha;

void criar(Pilha *p) {
    p->topo = -1;
}

void destruir(Pilha *p) {
    p->topo = -1;
}

bool cheia(Pilha p, int n) {
    if(p.topo == (n - 1)) {
        return true;
    } else {
        return false;
    }
}

bool vazia(Pilha p) {
    if(p.topo == -1) {
        return true;
    } else {
        return false;
    }
}

bool empilhar(Pilha *p, int x, int n) {
    bool deuCerto;
    if(cheia(*p, n) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        p->topo++;
        p->el[p->topo] = x;
        deuCerto = true;
        return deuCerto;
    }
}

bool desempilhar(Pilha *p, int *x) {
    bool deuCerto;
    if(vazia(*p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        *x = p->el[p->topo];
        p->topo--;
        deuCerto = true;
        return deuCerto;
    }
}

int copiaStruct(Pilha *p, Pilha *p2, int n) {
    int x;
    for(int i = 0; i < n; i++) {
        x = p->el[i];
        empilhar(p2, x, n);
    }
    return 0;
}

int main()
{
    Pilha p1;
    Pilha p2;

    int x;
    int n;

    criar(&p1);
    criar(&p2);

    printf("Informe quantos numeros tera sua pilha: \n");
    scanf("%d", &n);

    printf("Informe %d numeros para a pilha: \n", n);
    while(cheia(p1, n) == false) {
        scanf("%d", &x);
        empilhar(&p1, x, n);
    }

    copiaStruct(&p1, &p2, n);
    printf("Struct copiada!\n");

    printf("Pilha 1: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", p1.el[i]);
    }

    printf("\nPilha 2: \n");
    for(int i = 0; i < n; i++) {
        printf("%d ", p2.el[i]);
    }

    return 0;
}