#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX 5

struct pilha {
    int el[MAX];
    int topo;
}; typedef struct pilha Pilha;

struct fila {
    int el[MAX];
    int n_elem;
    int primeiro;
    int final;
}; typedef struct fila Fila;

Pilha *criarPilha() {
    Pilha *p;
    p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = -1;
    return p;
}

Fila *criarFila() {
    Fila *f;
    f = (Fila *) malloc(sizeof(Fila));
    if(f != NULL) {
        f->n_elem = 0;
        f->primeiro = 0;
        f->final = 0;
    }

    return f;
}

void destruirPilha(Pilha *p) {
    free(p);
}

void destruirFila(Fila *f) {
    if(f != NULL) {
        free(f);
    }
}

bool vaziaPilha(Pilha *p) {
    if(p->topo == -1) {
        return true;
    } else {
        return false;
    }
}

bool vaziaFila(Fila *f) {
    if(f->n_elem == 0) {
        return true;
    } else {
        return false;
    }
}

bool cheiaPilha(Pilha *p) {
    if(p->topo == (MAX - 1)) {
        return true;
    } else {
        return false;
    }
}

bool cheiaFila(Fila *f) {
    if(f->n_elem == MAX) {
        return true;
    } else {
        return false;
    }
}

bool push(Pilha *p, int x) {
    bool deuCerto;
    if(cheiaPilha(p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        deuCerto = true;
        p->topo++;
        p->el[p->topo] = x;
        return deuCerto;
    }
}

bool pop(Pilha *p, int *x) {
    bool deuCerto;
    if(vaziaPilha(p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        deuCerto = true;
        *x = p->el[p->topo];
        p->topo--;
        return deuCerto;
    }
}

bool enqueue(Fila *f, int x) {
    bool deuCerto;
    if(cheiaFila(f) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        deuCerto = true;
        f->n_elem++;
        f->el[f->final] = x;
        if(f->final == (MAX - 1)) {
            f->final = 0;
        } else {
            f->final++;
        }

        return deuCerto;
    }
}

bool dequeue(Fila *f, int *x) {
    bool deuCerto;
    if(vaziaFila(f) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        deuCerto = true;
        f->n_elem--;
        x = f->el[f->primeiro];
        if(f->primeiro == (MAX - 1)) {
            f->primeiro = 0;
        } else {
            f->primeiro++;
        }

        return deuCerto;
    }
}

void inverteFila(Fila *f, Pilha *p, int *x) {
    while(vaziaFila(f) == false) {
        dequeue(f, x);
        push(p, x);
    }

    while(cheiaFila(p) == false) {
        pop(p, x);
        enqueue(f, x);
    }
}

int main()
{
    Pilha *p;
    Fila *f;
    int x;

    f = criarFila();
    if (f == NULL) {
    	printf("ERRO na alocacao da fila!!\n");
    	exit(1);
    }
    p = criarPilha();

    printf("Informe os numeros da fila: \n");
    while(cheiaFila(f) == false) {
        scanf("%d", &x);
        enqueue(f, x);
    }

    inverteFila(f, p, &x);

    printf("Fila invertida: \n");
    while(vaziaFila(f) == false) {
        dequeue(f, &x);
        printf("%d ", x);
    }

    destruirFila(f);
    destruirPilha(p);

    return 0;
}