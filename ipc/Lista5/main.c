#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct horario {
    int ano, mes, dia, hora, min;
};
typedef struct horario Horario;

struct cadastro {
    char placa[8];
    char modelo[10];
    char cor[10];
    struct horario entrada;
    struct horario saida;
    char status;
};
typedef struct cadastro veiculo;

int entraAno() {
    int ano;
    printf("Ano: \n"); scanf("%d", &ano);
    return ano;
}

int entraMes(int bissexto) {
    int mes;
    while(1) {
        printf("Mes: \n"); scanf("%d", &mes);
        if(mes < 1 || mes > 12) {
            printf("Mes invalido! Informe um mes entre 1 e 12:\n");
        } else {
            return mes;
        }
    }
}

int entraDia(int diasMes) {
    int dia;
    while(1) {
        printf("Dia: \n"); scanf("%d", &dia);
        if(dia < 1 || dia > diasMes) {
            printf("Dia invalido! Informe um dia entre 1 e %d:\n", diasMes);
        } else {
            return dia;
        }
    }
}

int entraHora() {
    int hora;
    while(1) {
        printf("Hora: \n"); scanf("%d", &hora);
        if(hora < 0 || hora > 24) {
            printf("Hora invalida! Informe uma hora entre 01 e 24:\n");
        } else {
            return hora;
        }
    }
}

int entraMinuto() {
    int min;
    while(1) {
        printf("Minuto: \n"); scanf("%d", &min);
        if(min < 0 || min > 59) {
            printf("Minutos invalidos! Informe minutos entre 00 e 59");
        } else {
            return min;
        }
    }
}

void verificaHorarios(Horario h) {
    int bissexto = 0;
    h.ano = entraAno();
    if (((h.ano) % 400 == 0) || (((h.ano) % 4 == 0) && ((h.ano) % 100 != 0))) {
        bissexto = 1;
    }

    h.mes = entraMes(bissexto);

    if(bissexto == 1 && h.mes == 2) {
        h.dia = entraDia(29);
    } else if(h.mes == 2) {
        h.dia = entraDia(28);
    } else if (h.mes == 1 || h.mes == 3 || h.mes == 1 || h.mes == 5 || h.mes == 7 || h.mes == 8 || h.mes == 10 || h.mes == 12) {
        h.dia = entraDia(31);
    } else {
        h.dia = entraDia(30);
    }
}

void inserir(FILE *f) {
    struct cadastro v1;
    printf("Informe a placa do carro:\n"); scanf("%s", v1.placa); getchar();
    printf("Informe o modelo do carro:\n"); scanf("%s", v1.modelo); getchar();
    printf("Informe a cor do carro:\n"); scanf("%s", v1.cor); getchar();
    printf("Informacoes sobre o horario de entrada:\n");
    verificaHorarios(v1.entrada);
    printf("\nAgora, insira informacoes do horario da SAIDA.\n");
    verificaHorarios(v1.saida);

    v1.status = 'P';

    fseek(f, 0, SEEK_END);

    fwrite(&v1, sizeof(veiculo), 1, f);
}

void alterar(FILE *f) {
    struct cadastro v1;
    char placa[8];
    printf("Informe a placa do veiculo a ser alterado:\n"); scanf("%s",placa); getchar();
}

void remover(FILE *f) {
    struct cadastro v1;
    char placa[8];
    printf("Informe a placa do veiculo a ser removido:\n"); scanf("%s", placa); getchar();

    rewind(f);
    while(fread(&v1, sizeof(v1), 1, f) > 0) {
        if(strcmp(v1.placa, placa) == 0) {
            v1.status = 'R';
            fseek(f, -1 * sizeof(v1), SEEK_CUR);
            printf("XXXXXXXXXXXXX VEICULO REMOVIDO XXXXXXXXXXXXX");
            break;
        }
    }
}

void buscar(FILE *f) {
    struct cadastro v1;
    char placa[8];
    printf("Informe a placa do veiculo a ser buscado:\n"); scanf("%s", placa); getchar();

    rewind(f);
    while(fread(&v1, sizeof(v1), 1, f) > 0) {
        if(strcmp(v1.placa, placa) == 0) {
            printf("Placa: %s\nModelo: %s\nCor: %s\n", v1.placa, v1.modelo, v1.cor);
            printf("ENTRADA:\n");
            printf("%d/%d/%d - %d:%d\n", v1.entrada.dia, v1.entrada.mes, v1.entrada.ano, v1.entrada.hora, v1.entrada.min);
            printf("SAIDA:\n");
            printf("%d/%d/%d - %d:%d\n", v1.saida.dia, v1.saida.mes, v1.saida.ano, v1.saida.hora, v1.saida.min);
        }
    }
}

void listar(FILE *f) { // MESMO APOS REMOVIDO ARQUIVO CONTINUAR A SER LISTADO
    struct cadastro v1;
    printf("Os registros ja incluidos sao:\n");

    rewind(f);
    while(fread(&v1, sizeof(v1), 1, f) > 0) {
        if(v1.status == 'P') {
            printf("Placa: %s\nModelo: %s\nCor: %s\n", v1.placa, v1.modelo, v1.cor);
            printf("ENTRADA:\n");
            printf("%d/%d/%d - %d:%d\n", v1.entrada.dia, v1.entrada.mes, v1.entrada.ano, v1.entrada.hora, v1.entrada.min);
            printf("SAIDA:\n");
            printf("%d/%d/%d - %d:%d\n", v1.saida.dia, v1.saida.mes, v1.saida.ano, v1.saida.hora, v1.saida.min);
        }
    }
}

int main()
{
    FILE *f;
    f = fopen("C:\\ufu\\ipc\\Lista5\\arquivos\\dados.txt", "rb+");
    if(f == NULL) {
        f = fopen("C:\\ufu\\ipc\\Lista5\\arquivos\\dados.txt", "wb+");
        if(f == NULL) {
            printf("ERROR: Nao foi possivel abrir o arquivo.\n");
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