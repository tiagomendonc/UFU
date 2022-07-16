#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char nome[30];
    int idade;
    char endereco[30];
}; 
typedef struct Pessoa pessoa;

int main()
{
    // Estático
    pessoa p1;
    printf("Nome:");
    gets(p1.nome);   setbuf(stdin, NULL);
    printf("Idade:");
    scanf("%d", &p1.idade);   setbuf(stdin, NULL);
    printf("Endereco:");
    gets(p1.endereco);   setbuf(stdin, NULL);
    printf("%s %d %s\n\n", p1.nome, p1.idade, p1.endereco);

    // Dinâmico
    pessoa *p2 = (pessoa *) malloc(sizeof(pessoa));
    printf("Nome:");
    gets(p2 -> nome);   setbuf(stdin, NULL);
    printf("Idade:");
    scanf("%d", &p2 -> idade);   setbuf(stdin, NULL);
    printf("Endereco:");
    gets(p2 -> endereco);   setbuf(stdin, NULL);
    printf("%s %d %s\n\n", p2->nome, p2->idade, p2->endereco);

    return 0;
}