#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

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

bool verificaIgualdade(Pilha p, Pilha p2) {
    bool saoIguais;
    if(p.topo == p2.topo) {
        for(int i = 0; i < p.topo; i++) {
            if(p.el[i] == p2.el[i]) {
                saoIguais = true;
            } else {
                saoIguais = false;
                return saoIguais;
            }
        }
    } else {
        saoIguais = false;
    }
    return saoIguais;
}

int main()
{
    Pilha p;
    Pilha p2;
    
    criar(&p);
    criar(&p2);

    int n;
    int n2;
    int x;

    printf("Informe quantos elementos tera sua pilha: \n");
    scanf("%d", &n);

    printf("Informe %d numeros para sua pilha: \n");
    while(cheia(p, n) == false) {
        scanf(" %d", &x);
        empilhar(&p, x, n);
    }

    printf("Agora, informe quantos elementos tera sua segunda pilha: \n");
    scanf("%d", &n2);

    printf("Informe %d numeros para sua pilha: \n");
    while(cheia(p2, n2) == false) {
        scanf(" %d", &x);
        empilhar(&p2, x, n2);
    }

    if(verificaIgualdade(p, p2) == true) {
        printf("As pilhas sao iguais!\n");
    } else {
        printf("As pilhas sao diferentes.\n");
    }

    while(vazia(p) == false) {
        desempilhar(&p, &x, n);
    }

    while(vazia(p2) == false) {
        desempilhar(&p2, &x, n2);
    }

    destruir(&p);
    destruir(&p2);

    return 0;
}