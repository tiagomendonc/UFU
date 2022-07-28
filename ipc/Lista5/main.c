#include <stdio.h>
#include <stdlib.h>

struct horario {
    int ano, mes, dia, hora, min;
};

struct cadastro {
    char placa[7];
    char modelo[10];
    char cor[10];
    struct horario entrada;
    struct horario saida;
    char status;
};
typedef struct cadastro veiculo;

int anoBissexto(veiculo v1, int bissexto) {
    if((v1.entrada.ano % 400 == 0) || ((v1.entrada.ano % 4 == 0) && (v1.entrada.ano % 100 != 0))) {
        bissexto = 1;
    }
    return bissexto;
}

void validaMes(veiculo v1) {
    for(int i = 0; i < 1; i++) {
        scanf("%d", &v1.entrada.mes);   setbuf(stdin, NULL);
        if(v1.entrada.mes <= 0 || v1.entrada.mes > 12) {
            printf("Mes invalido! Informe um mes de 1 a 12:\n");
            i--;
        }
    }
}

void inserir(FILE *f) {
    int bissexto = 0;
    int diasMes = 0;
    struct cadastro v1;
    setbuf(stdin, NULL);
    printf("Informe a placa do carro:\n"); gets(v1.placa);   setbuf(stdin, NULL);
    printf("Informe o modelo do carro:\n"); gets(v1.modelo); setbuf(stdin, NULL);
    printf("Informe a cor do carro:\n"); gets(v1.cor);       setbuf(stdin, NULL);
    printf("Informacoes sobre a entrada:\n");
    printf("Ano:\n"); scanf("%d", &v1.entrada.ano);          setbuf(stdin, NULL);
    anoBissexto(v1, bissexto);
    printf("Mes:\n");
    validaMes(v1);

    if(v1.entrada.mes == 1 || v1.entrada.mes == 3 || v1.entrada.mes == 5 || v1.entrada.mes == 7 || v1.entrada.mes == 8 || v1.entrada.mes == 10 || v1.entrada.mes == 11) {
        diasMes = 1;
    }
    printf("Dia:\n");

}

void alterar(FILE *f) {
    // COMPLETAR
}

void remover(FILE *f) {
    // COMPLETAR
}

void buscar(FILE *f) {
    // COMPLETAR
}

void listar(FILE *f) {
    // COMPLETAR
}

int main()
{
    FILE *f;
    f = fopen("C:\\ufu\\ipc\\Lista5\\arquivos\\dados.txt", "rb+");
    if(f == NULL) {
        f = fopen("C:\\ufu\\ipc\\Lista5\\arquivos\\dados.txt", "wb+");
        if(f == NULL) {
            printf("ERROR: Nao foi possivel abrir o arquivo.");
        }
    }

    int opcao = -1;
    while(opcao != 0) {
        printf("\n\n0 - sair\n1 - insere\n2 - altera\n3 - remove\n4 - busca\n5 - lista\n");
        printf("\nOpcao: "); scanf("%d", &opcao);
        switch(opcao) {
            case 1: inserir(f);
                    break;
            case 2: alterar(f);
                    break;
            case 3: remover(f);
                    break;
            case 4: buscar(f);
                    break;
            case 5: listar(f);
                    break;
            printf("\n\n\n");
        }
    }

    fclose(f);

    return 0;
}