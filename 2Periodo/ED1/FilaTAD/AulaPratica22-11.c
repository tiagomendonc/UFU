#include<stdlib.h>	// malloc, free, exit
#include<stdio.h>	// scanf, printf
#include<stdbool.h>	// true, false

#define  MAX  3	// maximo de elementos permitidos

struct fila {
    char elementos[MAX]; // conjunto de elementos
    int n_elem;		 // numero de elementos
    int primeiro;	 // posicao do primeiro elem
    int final;		 // primeira posicao livre
};

typedef struct fila Fila;

Fila *criar()
{
	Fila *fi;
	
	fi = (Fila *) malloc(sizeof(Fila));
	if (fi != NULL) { // alocou corretamente
		// *deuCerto = true;
		fi->n_elem = 0;
		fi->primeiro = 0;
		fi->final = 0;
	} // else *deuCerto = false;
	
	return fi;
}

void destruir(Fila *fi)
{
    if (fi != NULL) free(fi);
}

bool vazia(Fila *F)
{
    if (F->n_elem == 0) return true;
    else return false;
}

bool cheia(Fila *F)
{
    if (F->n_elem == MAX) return true;
    else return false;
}

bool insere(Fila *F, char X)
{
	bool deuCerto;
	
	if (cheia(F) == true) {
		deuCerto = false;
		return deuCerto;
	}
	
	// senao:
	deuCerto = true;
	F->n_elem = F->n_elem + 1;
	F->elementos[ F->final ] = X;
	
	if (F->final == (MAX-1)) F->final = 0;
	else F->final = F->final + 1;
	
	return deuCerto;
}

bool remover(Fila *F, char *X) {
    bool deuCerto;

    if(vazia(F) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        F->n_elem--;
        *X = F->elementos[F->primeiro];
        if(F->primeiro == (MAX - 1)) {
            F->primeiro = 0;
        } else {
            F->primeiro++;
        }
        deuCerto = true;
        return deuCerto;
    }
}

int main()
{
    Fila *f;
    char caracter;
    
    // primeira coisa: alocar memoria
    /*printf("%lu\n", sizeof(char));
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double));
    printf("%lu\n", sizeof(Fila));*/

    f = criar();    
    if (f == NULL) {
    	printf("ERRO na alocacao da fila\n");
    	exit(1);
    }
    
    while (cheia(f) == false) {
    	scanf(" %c", &caracter);
        insere(f, caracter);
    }

    while(vazia(f) == false) {
        if(remover(f, &caracter) == true) {
            printf("Removido: %c ", caracter);
        }
    }
    
    destruir(f);
 
    return 0;
}
