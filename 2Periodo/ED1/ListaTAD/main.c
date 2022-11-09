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

/*
 * Cria estrutura de dados Ponto 
*/
int criar(Ponto *p) {
    p->x = 0;
    p->y = 0;

    return 0;
}

/*
 * Insere os valores em x e y de Ponto
 * Entrada: Ponto, int a e int b, coletadas na main informadas pelo usuário
 */
int inserir(Ponto *p, int a, int b) {
    p->x = a;
    p->y = b;

    return 0;
}

/*
 * Calcula a distancia entre dois pontos
 * Entrada: Dois registros Ponto distintos
 * Saída: valor da distancia atribuido a d
 */
double calculaDistancia(Ponto p, Ponto p1) {
    double d;
    d = sqrt(pow(p1.x - p.x, 2) + pow(p1.y - p.y, 2));

    return d;
}

/*
 * Cria estrutura de dados Circulo, utilizando dois registros Ponto
 */
int criarCirculo(Ponto *p, Ponto *p1, Circulo *c) {
    c->centro = p;
    c->raio = p1;

    return 0;
}

/*
 * Insere valores dos pontos do centro do Circulo
 * Entrada: Círculo, int a e int b, coletadas na main informadas pelo usuário
 */
int inserirCentroCirculo(Circulo *c, int a, int b) {
    c->centro->x = a;
    c->centro->y = b;

    return 0;
}

/*
 * Insere valores dos pontos da borda do Circulo
 * Entrada: Círculo, int a e int b, coletadas na main informadas pelo usuário
 */
int inserirBordaCirculo(Circulo *c, int a, int b) {
    c->raio->x = a;
    c->raio->y = b;

    return 0;
}

/*
 * Calcula raio (distancia entre centro e borda) do Circulo
 * Entrada: Circulo
 * Saída: raio (r)
 */
double calculaRaioCirculo(Circulo c) {
    double r;
    r = sqrt(pow(c.raio->x - c.centro->x, 2) + pow(c.raio->y - c.centro->y, 2));

    return r;
}

/*
 * Calcula valor da area do Circulo
 * Entrada: Circulo, area e raio
 * O valor da area é atribuído à variável float area
 */
int calculaAreaCirculo(Circulo c, float *area, double raio) {
    *area = PI * pow(raio, 2);

    return 0;
}

/*
 * Verifica se um Ponto está dentro da área de um Circulo
 * Entrada: Ponto, Circulo, raio
 * Saida: valor booleano de estaDentro
 */
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