#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

struct fila {
    int elem[MAX];
    int num_elem;
    int primeiro;
    int final;
}; typedef struct fila Fila;

Fila *criar() {
    Fila *f;

    f = (Fila *) malloc(sizeof(Fila));
    if(f != NULL) {
        f->num_elem = 0;
        f->primeiro = 0;
        f->final = 0;
    }

    return f;
}

void destruir(Fila *f) {
    if(f != NULL) {
        free(f);
    }
}

bool vazia(Fila *f) {
    if(f->num_elem == 0) {
        return true;
    } else {
        return false;
    }
}

bool cheia(Fila *f, int n) {
    if(f->num_elem == n) {
        return true;
    } else {
        return false;
    }
}

bool inserir(Fila *f, int x, int n) {
    bool deuCerto;

    if(cheia(f, n) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        deuCerto = true;
        f->num_elem++;
        f->elem[f->final] = x;

        if(f->final == (n - 1)) {
            f->final = 0;
        } else {
            f->final++;
        }
    }

    return deuCerto;
}

bool remover(Fila *f, int *x, int n) {
    bool deuCerto;

    if(vazia(f) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        deuCerto = true;
        f->num_elem--;
        *x = f->elem[f->primeiro];

        if(f->primeiro == ((n - 1))) {
            f->primeiro = 0;
        } else {
            f->primeiro++;
        }

        return deuCerto;
    }
}

void concatena(Fila *f1, Fila *f2, int n1, int n2) {
    bool deuCerto;
    int x;
    int n = n1 + n2;

    while(vazia(f2) == false) {
        remover(f2, &x, n2);
        inserir(f1, x, n);
    }    
}

int main()
{
    Fila *f1;
    int x;
    int n1, n2;

    printf("Informe a capacidade da fila: \n");
    scanf("%d", &n1);

    f1 = criar();
    if(f1 == NULL) {
        printf("ERRO na alocacao da fila!\n");
        exit(1);
    }

    printf("Informe os numeros da fila: \n");
    while(cheia(f1, n1) == false) {
        scanf("%d", &x);
        inserir(f1, x, n1);
    }

    Fila *f2;

    printf("Informe a capacidade da segunda fila: \n");
    scanf("%d", &n2);

    f2 = criar();
    if(f2 == NULL) {
        printf("ERRO na alocacao da fila!\n");
        exit(1);
    } 

    printf("Informe os numeros da segunda fila: \n");
    while(cheia(f2, n2) == false) {
        scanf("%d", &x);
        inserir(f2, x, n2);
    }

    concatena(f1, f2, n1, n2);

    printf("Filas concatenadas: \n");
    for(int i = 0; i < (n1 + n2); i++) {
        printf("%d ", f1->elem[i]);
    }

    destruir(f1);
    destruir(f2);

    return 0;
}