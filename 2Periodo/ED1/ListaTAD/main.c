#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.14

struct ponto {
    int x;
    int y;
};
typedef struct ponto Ponto;

struct circulo {
    Ponto *centro;
    Ponto *raio;
};
typedef struct circulo Circulo;

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

int criarCirculo(Ponto *p, Ponto *p1, Circulo *c) {
    c->centro = p;
    c->raio = p1;

    return 0;
}

int inserirCentroCirculo(Circulo *c, int a, int b) {
    c->centro->x = a;
    c->centro->y = b;

    return 0;
}

int inserirBordaCirculo(Circulo *c, int a, int b) {
    c->raio->x = a;
    c->raio->y = b;

    return 0;
}

double calculaRaioCirculo(Circulo c) {
    double r;
    r = sqrt(pow(c.raio->x - c.centro->x, 2) + pow(c.raio->y - c.centro->y, 2));

    return r;
}

int calculaAreaCirculo(Circulo c, float *area, double raio) {
    *area = PI * pow(raio, 2);

    return 0;
}

bool verificaPontoC(Ponto p, Circulo c, double raio) {
    bool estaDentro;
    float limitex = raio - c.centro->x;
    float limitey = raio - c.centro->y;

    if((p.x > limitex && p.x < limitex) || (p.y > limitey && p.y < limitey)) {
        estaDentro = false;
    } else {
        estaDentro = true;
    }

    return estaDentro;
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

    Circulo c;
    criarCirculo(&p, &p1, &c);
    printf("Para calcular a area do circulo, informe as coordenadas do ponto do centro: \n");
    printf("X: ");
    scanf("%d", &x);
    printf("\nY: ");
    scanf("%d", &y);

    inserirCentroCirculo(&c, x, y);

    printf("Agora, informe as coordenadas do ponto de borda do circulo: \n");
    printf("X: ");
    scanf("%d", &x);
    printf("\nY: ");
    scanf("%d", &y);

    inserirBordaCirculo(&c, x, y);

    double raio = calculaRaioCirculo(c);

    float area;

    calculaAreaCirculo(c, &area, raio);

    printf("A area do circulo eh: %.2f", area);

    Ponto p2;
    criar(&p2);
    printf("Para verificar se um ponto esta dentro do circulo, informe as coordenadas: \n");
    printf("X: ");
    scanf("%d", &x);
    printf("\nY: ");
    scanf("%d", &y);
    inserir(&p2, x, y);

    if(verificaPontoC(p2, c, raio) == true) {
        printf("O ponto esta dentro do circulo!\n");
    } else {
        printf("O ponto esta fora do circulo!\n");
    }

    return 0;
}