#include <stdio.h>
#include <stdlib.h>

struct Ponto { 
    int x,y; struct Ponto *prox; 
};
typedef struct Ponto ponto;

struct Poligono { 
    ponto pt; 
};
typedef struct Poligono poligono;

int main() {
    poligono triangulo;

    triangulo.pt.x = 5;
    triangulo.pt.y = 3;
    triangulo.pt.prox = (ponto *) malloc(sizeof(ponto));

    triangulo.pt.prox->x = 1;
    triangulo.pt.prox->y = 1;
    triangulo.pt.prox->prox = (ponto *) malloc(sizeof(ponto));

    triangulo.pt.prox->prox->x = 1;
    triangulo.pt.prox->prox->y = 5;
    triangulo.pt.prox->prox->prox = NULL;

    return 0;
}