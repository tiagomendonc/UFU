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
    char status[1];
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
            printf("Minutos invalidos! Informe minutos entre 00 e 59:");
        } else {
            return min;
        }
    }
}

void verificaHorarios(Horario *h) {
    int bissexto = 0;
    h->ano = entraAno();
    if (((h->ano) % 400 == 0) || (((h->ano) % 4 == 0) && ((h->ano) % 100 != 0))) {
        bissexto = 1;
    }

    h->mes = entraMes(bissexto);

    if(bissexto == 1 && (h->mes) == 2) {
        h->dia = entraDia(29);
    } else if((h->mes) == 2) {
        h->dia = entraDia(28);
    } else if ((h->mes) == 1 || (h->mes) == 3 || (h->mes) == 1 || (h->mes) == 5 || (h->mes) == 7 || (h->mes) == 8 || (h->mes) == 10 || (h->mes) == 12) {
        h->dia = entraDia(31);
    } else {
        h->dia = entraDia(30);
    }

    h->hora = entraHora();
    h->min = entraMinuto();
}

Horario calculaTempo(Horario hEntrada, Horario hSaida) {
    Horario tempo;

    tempo.ano = hSaida.ano - hEntrada.ano;
    tempo.mes = hSaida.mes - hEntrada.mes;
    if(hSaida.dia < hEntrada.dia) {
        if (hEntrada.mes == 2 && ((hEntrada.ano) % 400 == 0) || (((hEntrada.ano) % 4 == 0) && ((hEntrada.ano) % 100 != 0))) {
            tempo.dia = 29 - hEntrada.dia + hSaida.dia;
        } else if (hEntrada.mes == 2) {
            tempo.dia = 28 - hEntrada.dia + hSaida.dia;
        } else if (hEntrada.mes == 1 || hEntrada.mes == 3 || hEntrada.mes == 5 || hEntrada.mes == 7 || hEntrada.mes == 8 || hEntrada.mes == 10 || hEntrada.mes == 12) {
            tempo.dia = 31 - hEntrada.dia + hSaida.dia;
        } else {
            tempo.dia = 30 - hEntrada.dia + hSaida.dia;
        }
    } else {
        tempo.dia = hSaida.dia - hEntrada.dia;
    }

    tempo.hora = hSaida.hora - hEntrada.hora;
    tempo.min = hSaida.min - hEntrada.min;
    if(tempo.min < 0) {
        tempo.min += 60;
        tempo.hora -= 1;
    }
    if(tempo.hora < 0) {
        tempo.hora += 24;
        tempo.dia -= 1;
    }
    if(tempo.mes < 0) {
        tempo.mes += 12;
        tempo.ano -= 1;
    }

    return tempo;
}

void inserir(FILE *f) {
    struct cadastro v1;
    printf("Informe a placa do carro:\n"); scanf("%s", v1.placa); getchar();
    printf("Informe o modelo do carro:\n"); scanf("%s", v1.modelo); getchar();
    printf("Informe a cor do carro:\n"); scanf("%s", v1.cor); getchar();
    printf("Informacoes sobre o horario de entrada:\n");
    verificaHorarios(&v1.entrada);
    printf("\nAgora, insira informacoes do horario da SAIDA.\n");
    verificaHorarios(&v1.saida);

    v1.status[0] = 'P';

    fseek(f, 0, SEEK_END);

    fwrite(&v1, sizeof(veiculo), 1, f);
}

void alterar(FILE *f) {
    struct cadastro v1;
    char placa[8];
    printf("Informe a placa do veiculo a ser alterado:\n"); scanf("%s",placa); getchar();

    rewind(f);
    while(fread(&v1, sizeof(v1), 1, f) > 0) {
        if(strcmp(v1.placa, placa) == 0 && v1.status[0] == 'P') {
            printf("Registro encontrado!!\n");
            int opcao = -1;
            while(opcao != 0) {
                printf("O que deseja alterar: \n");
                printf(") - Sair\n");
                printf("1 - Placa\n");
                printf("2 - Modelo\n");
                printf("3 - Cor\n");
                printf("4 - Horario entrada\n");
                printf("5 - Horario saida\n");
                scanf("%d", &opcao);

                switch(opcao) {
                    case 1: printf("Informe a nova placa: \n"); scanf("%s", v1.placa); getchar();
                            fseek(f, -1 * sizeof(v1), SEEK_CUR);
                            fwrite(&v1, sizeof(veiculo), 1, f);
                            break;
                    case 2: printf("Informe o novo modelo: \n"); scanf("%s", v1.modelo); getchar();
                            fseek(f, -1 *sizeof(v1), SEEK_CUR);
                            fwrite(&v1, sizeof(veiculo), 1, f);
                            break;
                    case 3: printf("Informe a nova cor: \n"); scanf("%s", v1.cor); getchar();
                            fseek(f, -1 * sizeof(v1), SEEK_CUR);
                            fwrite(&v1, sizeof(veiculo), 1, f);
                            break;
                    case 4: printf("Informe o novo horario de entrada: \n");
                            verificaHorarios(&v1.entrada);
                            fseek(f, -sizeof(v1), SEEK_CUR);
                            fwrite(&v1, sizeof(veiculo), 1, f);
                            break;
                    case 5: printf("Informe o novo horario de saida: \n");
                            verificaHorarios(&v1.saida);
                            fseek(f, -sizeof(v1), SEEK_CUR);
                            fwrite(&v1, sizeof(veiculo), 1, f);
                            break;
                    printf("\n\n\n");
                }
            }
        }
    }
}

void remover(FILE *f) {
    struct cadastro v1;
    char placa[8];
    printf("Informe a placa do veiculo a ser removido:\n"); scanf("%s", placa); getchar();

    rewind(f);
    while(fread(&v1, sizeof(v1), 1, f) > 0) {
        if(strcmp(v1.placa, placa) == 0) {
            v1.status[0] = 'R';
            fseek(f, -1 * sizeof(veiculo), SEEK_CUR);
            fwrite(&v1, sizeof(veiculo), 1, f);
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

            Horario tempoEstacionado = calculaTempo(v1.entrada, v1.saida);
            printf("Tempo estacionado: \n Anos: %d\n Meses: %d\n Dias: %d\n Horas: %d\n Minutos: %d\n", tempoEstacionado.ano, tempoEstacionado.mes, tempoEstacionado.dia, tempoEstacionado.hora, tempoEstacionado.min);
        }
    }
}

void listar(FILE *f) {
    struct cadastro v1;
    printf("Os registros ja incluidos sao:\n");

    rewind(f);
    while(fread(&v1, sizeof(v1), 1, f) > 0) {
        if(v1.status[0] == 'P' || v1.status[0] == 'R') {
            printf("Placa: %s\nModelo: %s\nCor: %s\n", v1.placa, v1.modelo, v1.cor);
            printf("ENTRADA:\n");
            printf("%d/%d/%d - %d:%d\n", v1.entrada.dia, v1.entrada.mes, v1.entrada.ano, v1.entrada.hora, v1.entrada.min);
            printf("SAIDA:\n");
            printf("%d/%d/%d - %d:%d\n", v1.saida.dia, v1.saida.mes, v1.saida.ano, v1.saida.hora, v1.saida.min);

            Horario tempoEstacionado = calculaTempo(v1.entrada, v1.saida);
            printf("Tempo estacionado: \n Anos: %d\n Meses: %d\n Dias: %d\n Horas: %d\n Minutos: %d\n", tempoEstacionado.ano, tempoEstacionado.mes, tempoEstacionado.dia, tempoEstacionado.hora, tempoEstacionado.min);

            printf("\n\n\n");
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