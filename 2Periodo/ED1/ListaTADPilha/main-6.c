#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 10

struct pilha {
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

bool desempilhar(Pilha *p, int *x, int n) {
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

int verificaMaior(Pilha p, Pilha p1) {
    int mais;
    if(p.topo > p1.topo) {
        mais = p.topo;
        return mais;
    } else {
        mais = p1.topo;
        return mais;
    }
}


int main()
{
    Pilha p;
    int n;
    int x;

    criar(&p);

    printf("Informe quantos numeros tera a primeira pilha: \n");
    scanf("%d", &n);

    printf("Informe os numeros da pilha: \n");
    while(cheia(p, n) == false) {
        scanf("%d", &x);
        empilhar(&p, x, n);
    }
    printf("\n");

    Pilha p1;
    criar(&p1);

    printf("Informe quantos numeros tera a segunda pilha: \n");
    scanf("%d", &n);

    printf("Informe os numeros da pilha: \n");
    while(cheia(p1, n) == false) {
        scanf("%d", &x);
        empilhar(&p1, x, n);
    }
    printf("\n");

    printf("A pilha com mais elementos eh ");
    if(verificaMaior(p, p1) == p.topo) {
        printf("P1.\n");
    } else {
        printf("P2.\n");
    }

    while(vazia(p) == false) {
        desempilhar(&p, &x, n);
    }
    destruir(&p);

    while(vazia(p1) == false) {
        desempilhar(&p1, &x, n);
    }
    destruir(&p1);


    return 0;
}