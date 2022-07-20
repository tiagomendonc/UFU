#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Ponto {
    int x, y;
};
typedef struct Ponto ponto;

struct Retangulo {
    ponto pse;
    ponto pid;
};
typedef struct Retangulo retangulo;

void leitura (retangulo r) {
    printf("Lado superior:"); scanf("%d", &r.pse.x);   setbuf(stdin, NULL);
    printf("Lado esquerdo:"); scanf("%d", &r.pse.y);   setbuf(stdin, NULL);
    printf("Lado inferior:"); scanf("%d", &r.pid.x);   setbuf(stdin, NULL);
    printf("Lado direito:"); scanf("%d", &r.pid.y);    setbuf(stdin, NULL);
}

int main()
{
    retangulo r;

    leitura(r);

    int area = r.pse.y * r.pid.x;
    int perimetro = (r.pse.y * 2) + (r.pid.x * 2);
    float diagonal = pow(r.pse.y, 2) + pow(r.pid.x, 2);
    diagonal = sqrt(diagonal);

    printf("A area do retangulo eh: %d\n", area);
    printf("O perimetro eh: %d\n", perimetro);
    printf("A diagonal eh: %.2f\n", diagonal);

    return 0;
}