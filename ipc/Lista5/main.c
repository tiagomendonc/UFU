#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct horario {
    int ano, mes, dia, hora, min;
};

struct cadastro {
    char placa[8];
    char modelo[10];
    char cor[10];
    struct horario entrada;
    struct horario saida;
    char status;
};
typedef struct cadastro veiculo;

int anoBissextoEntrada(veiculo v1) {
    int bissexto = 0;
    if((v1.entrada.ano % 400 == 0) || ((v1.entrada.ano % 4 == 0) && (v1.entrada.ano % 100 != 0))) {
        bissexto = 1;
    }
    return bissexto;
}

int anoBissextoSaida(veiculo v1) {
    int bissexto = 0;
    if((v1.saida.ano % 400 == 0) || ((v1.saida.ano % 4 == 0) && (v1.saida.ano % 100 != 0))) {
        bissexto = 1;
    }
    return bissexto;
}

void validaMesEntrada(veiculo v1) {
    for(int i = 0; i < 1; i++) {   
        if(v1.entrada.mes <= 0 || v1.entrada.mes > 12) {
            printf("Mes invalido! Informe um mes de 1 a 12:\n");
            i--;
        }
    }
}

void validaMesSaida(veiculo v1) {
    for(int i = 0; i < 1; i++) {  
        if(v1.saida.mes <= 0 || v1.saida.mes > 12) {
            printf("Mes invalido! Informe um mes de 1 a 12:\n");
            i--;
        }
    }
}

int verificaDiasMesEntrada(veiculo v1) {
    int diasMes = 0;
    if(v1.entrada.mes == 1 || v1.entrada.mes == 3 || v1.entrada.mes == 5 || v1.entrada.mes == 7 || v1.entrada.mes == 8 || v1.entrada.mes == 10 || v1.entrada.mes == 11) {
        diasMes = 1;
    }
    return diasMes;
}

int verificaDiasMesSaida(veiculo v1) {
    int diasMes = 0;
    if(v1.saida.mes == 1 || v1.saida.mes == 3 || v1.saida.mes == 5 || v1.saida.mes == 7 || v1.saida.mes == 8 || v1.saida.mes == 10 || v1.saida.mes == 11) {
        diasMes = 1;
    }
    return diasMes;
}

void verificaDiaEntrada(veiculo v1, int bissexto, int diaMes) { // NÃO FUNCIONA - VERIFICAR!!!!!!
    for(int i = 0; i < 1; i++) {
        if(bissexto == 0) {
            if(v1.entrada.mes == 2) {
                if(v1.entrada.dia <= 0 || v1.entrada.dia > 28) {
                    printf("Dia invalido! Informe um dia entre 1 e 28.\n");
                    i--;
                }
            }
            if(diaMes == 0) {
                if(v1.entrada.dia <= 0 || v1.entrada.dia > 30) {
                    printf("Dia invalido! Informe um dia entre 1 e 30.\n");
                    i--;
                }
            }
            if(diaMes == 1) {
                if(v1.entrada.dia <= 0 || v1.entrada.dia > 31) {
                    printf("Dia invalido! Informe um dia entre 1 e 31.\n");
                    i--;
                }
            }
        }
        if(bissexto == 1) {
            if(v1.entrada.mes == 2) {
                if(v1.entrada.dia <= 0 || v1.entrada.dia > 29) {
                    printf("Dia invalido! Informe um dia entre 1 e 29.\n");
                    i--;
                }
            }
            if(diaMes == 0) {
                if(v1.entrada.dia <= 0 || v1.entrada.dia > 30) {
                    printf("Dia invalido! Informe um dia entre 1 e 30.\n");
                    i--;
                }
            }
            if(diaMes == 1) {
                if(v1.entrada.dia <= 0 || v1.entrada.dia > 31) {
                    printf("Dia invalido! Informe um dia entre 1 e 31.\n");
                    i--;
                }
            }
        }
    }
}

void verificaDiaSaida(veiculo v1, int bissexto, int diaMes) { // NÃO FUNCIONA - VERIFICAR!!!!!!
    for(int i = 0; i < 1; i++) {
        if(bissexto == 0) {
            if(v1.saida.mes == 2) {
                if(v1.saida.dia <= 0 || v1.saida.dia > 28) {
                    printf("Dia invalido! Informe um dia entre 1 e 28.\n");
                    i--;
                }
            }
            if(diaMes == 0) {
                if(v1.saida.dia <= 0 || v1.saida.dia > 30) {
                    printf("Dia invalido! Informe um dia entre 1 e 30.\n");
                    i--;
                }
            }
            if(diaMes == 1) {
                if(v1.saida.dia <= 0 || v1.saida.dia > 31) {
                    printf("Dia invalido! Informe um dia entre 1 e 31.\n");
                    i--;
                }
            }
        }
        if(bissexto == 1) {
            if(v1.saida.mes == 2) {
                if(v1.saida.dia <= 0 || v1.saida.dia > 29) {
                    printf("Dia invalido! Informe um dia entre 1 e 29.\n");
                    i--;
                }
            }
            if(diaMes == 0) {
                if(v1.saida.dia <= 0 || v1.saida.dia > 30) {
                    printf("Dia invalido! Informe um dia entre 1 e 30.\n");
                    i--;
                }
            }
            if(diaMes == 1) {
                if(v1.saida.dia <= 0 || v1.saida.dia > 31) {
                    printf("Dia invalido! Informe um dia entre 1 e 31.\n");
                    i--;
                }
            }
        }
    }
}

void verificaHoraEntrada(veiculo v1) {
    for(int i = 0; i < 1; i++) { 
        if(v1.entrada.hora <= 0 || v1.entrada.hora > 24) {
            printf("Hora invalida! Informe uma hora entre 1 e 24.\n");
            i--;
        }
    }
}

void verificaHoraSaida(veiculo v1) {
    for(int i = 0; i < 1; i++) {  
        if(v1.saida.hora <= 0 || v1.saida.hora > 24) {
            printf("Hora invalida! Informe uma hora entre 1 e 24.\n");
            i--;
        }
    }
}

void verificaMinutoEntrada(veiculo v1) {
    for(int i = 0; i < 1; i++) {  
        if(v1.entrada.min < 0 || v1.entrada.min > 59) {
            printf("Minutos invalidos! Informe um minuto entre 00 e 59.\n");
            i--;
        }
    }
}

void verificaMinutoSaida(veiculo v1) {
    for(int i = 0; i < 1; i++) {  
        if(v1.saida.min < 0 || v1.saida.min > 59) {
            printf("Minutos invalidos! Informe um minuto entre 00 e 59.\n");
            i--;
        }
    }
}

void inserir(FILE *f) {
    struct cadastro v1;
    printf("Informe a placa do carro:\n"); scanf("%s", v1.placa); getchar();
    printf("Informe o modelo do carro:\n"); scanf("%s", v1.modelo); getchar();
    printf("Informe a cor do carro:\n"); scanf("%s", v1.cor); getchar();
    printf("Informacoes sobre a entrada:\n");
    printf("Ano:\n"); scanf("%d", &v1.entrada.ano);          
    int bissexto = anoBissextoEntrada(v1);
    printf("Mes:\n"); scanf("%d", &v1.entrada.mes);
    validaMesEntrada(v1);
    int diasMes = verificaDiasMesEntrada(v1);
    printf("Dia:\n"); scanf("%d", &v1.entrada.dia);
    verificaDiaEntrada(v1, bissexto, diasMes);
    printf("Horario:\nHora:\n"); scanf("%d", &v1.entrada.hora);
    verificaHoraEntrada(v1);
    printf("Minutos:\n"); scanf("%d", &v1.entrada.min);
    verificaMinutoEntrada(v1);

    printf("\nAgora, insira informacoes da SAIDA.\n");
    printf("Ano:\n"); scanf("%d", &v1.saida.ano);           
    bissexto = anoBissextoSaida(v1);
    printf("Mes:\n"); scanf("%d", &v1.saida.mes);
    validaMesSaida(v1);
    diasMes = verificaDiasMesSaida(v1);
    printf("Dia:\n"); scanf("%d", &v1.saida.dia);
    verificaDiaSaida(v1, bissexto, diasMes);
    printf("Horario:\nHora:\n"); scanf("%d", &v1.saida.hora);
    verificaHoraSaida(v1);
    printf("Minutos:\n"); scanf("%d", &v1.saida.min);
    verificaMinutoSaida(v1);

    v1.status = 'P';

    fseek(f, 0, SEEK_END);

    fwrite(&v1, sizeof(veiculo), 1, f);
}

void alterar(FILE *f) {
    // COMPLETAR
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