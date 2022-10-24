#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto {
    int x;
    int y;
};
typedef struct ponto Ponto;

int criar(Ponto *p) {
    p->x = 0;
    p->y = 0;

    return 0;
}

int inserir(Ponto *p, int a, int b) {
    p->x = a;
    p->y = b;

    return 0;
}

double calculaDistancia(Ponto p, Ponto p1) {
    double d;
    d = sqrt(pow(p1.x - p.x, 2) + pow(p1.y - p.y, 2));

    return d;
}

int main()
{
    Ponto p;
    criar(&p);

    int x, y;
    printf("Informe as coordenadas X e Y de um ponto: \n");
    printf("X: ");
    scanf("%d", &x);
    printf("\nY: ");
    scanf("%d", &y);

    inserir(&p, x, y);

    printf("Para calcular a distancia entre dois pontos, informe as coordenadas do segundo ponto: \n");
    Ponto p1;
    criar(&p1);
    printf("Informe as coordenadas X e Y do segundo ponto: \n");
    printf("X: ");
    scanf("%d", &x);
    printf("\nY: ");
    scanf("%d", &y);

    inserir(&p1, x, y);

    printf("A distancia entre os dois pontos eh: %f\n", calculaDistancia(p, p1));

    return 0;
}