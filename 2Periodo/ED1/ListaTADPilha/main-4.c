#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 3

struct pilha {
    char el[MAX];
    int topo;
};
typedef struct pilha Pilha;

void criar(Pilha *p) {
    p->topo = -1;
}

void destruir(Pilha *p) {
    p->topo = -1;
}

bool vazia(Pilha p) {
    if(p.topo == -1) {
        return true;
    } else {
        return false;
    }
}

bool cheia(Pilha p) {
    if(p.topo == (MAX - 1)) {
        return true;
    } else {
        return false;
    }
}

bool empilhar(Pilha *p, char x) {
    bool deuCerto;
    if(cheia(*p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        p->topo++;
        p->el[p->topo] = x;
        deuCerto = true;
        return deuCerto;
    }
}

bool desempilhar(Pilha *p, char *x) {
    bool deuCerto;
    if(vazia(*p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
       *x = p->el[p->topo];
        p->topo = p->topo - 1;
        deuCerto = true;
        return deuCerto;
    }
}

int main()
{
    bool teste;
    char c;
    Pilha p;

    criar(&p);

    while(cheia(p) == false) {
        scanf(" %c", &c);
        empilhar(&p, c);
    }
    printf("\n");

    while(desempilhar(&p, &c) == true) {
        printf("%c ", c);
    }
    printf("\n");

    if(vazia(p) == true) {
        printf("A pilha estah vazia.\n");
    }

    destruir(&p);

    return 0;
}