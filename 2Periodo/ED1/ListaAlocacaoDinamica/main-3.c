#include <stdio.h>
#include <stdlib.h>

struct ponto {
    int x;
    int y;
}; typedef struct ponto Ponto;

int main()
{
    int n;
    printf("Informe quantas posicoes tem seu vetor: \n");
    scanf("%d", &n);

    Ponto *p;
    p = (Ponto*) malloc(n*sizeof(Ponto));

    for(int i = 0; i < n; i++) {
        printf("Informe a coordenada x do ponto %d: \n", i + 1);
        scanf("%d", &p[i].x);
        printf("Informe a coordenada y do ponto %d: \n", i + 1);
        scanf("%d", &p[i].y);
    }

    printf("Pontos digitados:");
    for(int i = 0; i < n; i++) {
        printf(" (%d, %d);", p[i].x, p[i].y);
    }

    free(p);

    return 0;
}