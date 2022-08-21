#include <stdio.h>
#include <stdlib.h>

struct Atleta {
    char nome[20], esporte[20]; int idade; float altura, peso; 
};
typedef struct Atleta atleta;

void leitura(atleta *a) {
    printf("Nome: "); gets(a->nome);           setbuf(stdin,NULL);
    printf("Esporte: "); gets(a->esporte);        setbuf(stdin,NULL);
    printf("Idade: "); scanf("%d", &a->idade);  setbuf(stdin,NULL);
    printf("Altura: "); scanf("%f", &a->altura); setbuf(stdin,NULL);
    printf("Peso: "); scanf("%f", &a->peso);   setbuf(stdin,NULL);
    printf("\n");
}

#define TAM 5

int main() 
{
    atleta atletas[TAM];
    for (int i = 0; i < TAM; i++) {
        leitura(&atletas[i]);
    }
    
    int posicaoMaisAlto = 0, posicaoMaisVelho = 0;
    float MaisAlto = atletas[0].altura;
    int MaiorIdade = atletas[0].idade;
    for (int i = 0; i < TAM; i++) {
        if (MaisAlto < atletas[i].altura) {
            MaisAlto = atletas[i].altura;
            posicaoMaisAlto = i;
        }
        if (MaiorIdade < atletas[i].idade) {
            MaiorIdade = atletas[i].idade;
            posicaoMaisVelho = i;
        }
    }

    printf("\n Mais velho %s %s %d",
           atletas[posicaoMaisVelho].nome,
           atletas[posicaoMaisVelho].esporte,
           atletas[posicaoMaisVelho].idade);
    printf("\n Mais alto %s %s %.2f",
           atletas[posicaoMaisAlto].nome,
           atletas[posicaoMaisAlto].esporte,
           atletas[posicaoMaisAlto].altura);

 

    return 0;
}