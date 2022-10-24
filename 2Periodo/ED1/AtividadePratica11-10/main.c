#include <stdio.h>
#include <stdbool.h>

#define  MAX  10    // tamanho maximo do vetor
// Note que o vetor pode ter menos de 10 elementos

// Declaracao da estrutura de dados
struct vetor {
    int elem[MAX];  // armazena os dados do vetor
    int tam;        // armazena o tamanho do vetor
};

// Definicao do tipo Vetor a partir da estrutura de dados
typedef struct vetor Vetor;

/*
 * Retorna o maior elemento do vetor
 */
int maior_v1(Vetor vet, int *erro)
{
    int i, m = -1;

    // tratamento de erro
    /* opções:
        2 - usar parametro auxiliar para erro
    */

    if (vet.tam == 0) *erro = 1; 
    else {
        m = vet.elem[0];

        for (i = 1; i < vet.tam; i++)
            if (vet.elem[i] > m) m = vet.elem[i];
    }

    return m;
}

/*
 * Encontra o maior elemento do vetor.
 * O resultado eh retornado na variavel m passada por referencia
 * A funcao retorna um codigo de erro:
 * - 0 se nao houve erro
 * - 1 se houve erro
 */
int maior(Vetor vet, int *m)
{
    int i;

    // tratamento de erro
    /* opções:
        1 - retornar um codigo de erro
            (0 se funcionou, 1 caso contrario)
    */

    if (vet.tam == 0) return 1;
    
    *m = vet.elem[0];
    for (i = 1; i < vet.tam; i++)
   	 if (vet.elem[i] > *m) *m = vet.elem[i];

    return 0;
}

/* Cria um vetor "vazio"
 * Basicamente, atribui 0 ao tamanho dele
 * Como o vetor eh estatico, nao precisa alocar espaço para ele
 */
int criar(Vetor *vet)
{
    vet->tam = 0;

    return 0; // nao tem erro
}

/* Insere o valor x no vetor vet
 * Retorna codigo de erro como na funcao anterior
 */
int inserir(Vetor *vet, int x)
{
    int i;

    if (vet->tam >= MAX) return 1; // erro
    i = vet->tam;
    vet->elem[i] = x;
    vet->tam++;
    return 0; // nao tem erro
    
    
    // alternativamente
    // vet->elem[vet->tam++] = x;
}

/* Busca a posicao z no vetor
 * Retorna numero correspondente a posicao
 * Retorna erro caso z > vet.tam
 */ 
int retornaIesimo(Vetor vet, int *z)
{
    int num;

    if (*z > vet.tam || *z < 0) {
        return 1; // erro
    }

    for(int i = 0; i < vet.tam; i++) {
        if(i == *z) {
            num = vet.elem[i];
        }
    }

    return num;
}


int main()
{
    Vetor vet;
    criar(&vet);

    int n;
    printf("Informe quantas posicoes tera o vetor: \n");
    scanf("%d", &n);
    int x;
    printf("Informe os numeros do vetor: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        inserir(&vet, x);
    }

    int m;
    maior(vet, &m);
    printf("O maior valor do vetor eh: %d\n", m);

    int z;
    printf("Informe uma posicao do vetor para buscar o numero correspondente: \n");
    scanf("%d", &z);
    printf("O numero correspondente eh: %d\n", retornaIesimo(vet, &z));

    return 0;
}