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
        scanf("%d", &v1.entrada.mes);   
        if(v1.entrada.mes <= 0 || v1.entrada.mes > 12) {
            printf("Mes invalido! Informe um mes de 1 a 12:\n");
            i--;
        }
    }
}

void validaMesSaida(veiculo v1) {
    for(int i = 0; i < 1; i++) {
        scanf("%d", &v1.saida.mes);   
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
        scanf("%d", &v1.entrada.dia);  
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
        scanf("%d", &v1.saida.dia);  
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
        scanf("%d", &v1.entrada.hora);   
        if(v1.entrada.hora <= 0 || v1.entrada.hora > 24) {
            printf("Hora invalida! Informe uma hora entre 1 e 24.\n");
            i--;
        }
    }
}

void verificaHoraSaida(veiculo v1) {
    for(int i = 0; i < 1; i++) {
        scanf("%d", &v1.saida.hora);   
        if(v1.saida.hora <= 0 || v1.saida.hora > 24) {
            printf("Hora invalida! Informe uma hora entre 1 e 24.\n");
            i--;
        }
    }
}

void verificaMinutoEntrada(veiculo v1) {
    for(int i = 0; i < 1; i++) {
        scanf("%d", &v1.entrada.min);   
        if(v1.entrada.min < 0 || v1.entrada.min > 59) {
            printf("Minutos invalidos! Informe um minuto entre 00 e 59.\n");
            i--;
        }
    }
}

void verificaMinutoSaida(veiculo v1) {
    for(int i = 0; i < 1; i++) {
        scanf("%d", &v1.saida.min);   
        if(v1.saida.min < 0 || v1.saida.min > 59) {
            printf("Minutos invalidos! Informe um minuto entre 00 e 59.\n");
            i--;
        }
    }
}

void inserir(FILE *f) {
    struct cadastro v1;
    printf("Informe a placa do carro:\n"); scanf("%s", v1.placa); getchar();
    fwrite(v1.placa, sizeof(char), strlen(v1.placa), f);
    printf("Informe o modelo do carro:\n"); scanf("%s", v1.modelo); getchar();
    fwrite(v1.modelo, sizeof(char), strlen(v1.modelo), f);
    printf("Informe a cor do carro:\n"); scanf("%s", v1.cor); getchar();
    fwrite(v1.cor, sizeof(char), strlen(v1.cor), f);
    printf("Informacoes sobre a entrada:\n");
    printf("Ano:\n"); scanf("%d", &v1.entrada.ano);          
    int bissexto = anoBissextoEntrada(v1);
    fwrite(&v1.entrada.ano, sizeof(int), 1, f);
    printf("Mes:\n");
    validaMesEntrada(v1);
    int diasMes = verificaDiasMesEntrada(v1);
    fwrite(v1.entrada.mes, sizeof(int), 1, f);
    printf("Dia:\n");
    verificaDiaEntrada(v1, bissexto, diasMes);
    fwrite(&v1.entrada.dia, sizeof(int), 1, f);
    printf("Horário:\nHora:\n");
    verificaHoraEntrada(v1);
    fwrite(&v1.entrada.hora, sizeof(int), 1, f);
    printf("Minutos:\n");
    verificaMinutoEntrada(v1);
    fwrite(&v1.entrada.min, sizeof(int), 1, f);

    printf("Agora, insira informacoes da SAIDA.\n");
    printf("Ano:\n"); scanf("%d", &v1.saida.ano);           
    bissexto = anoBissextoSaida(v1);
    fwrite(&v1.saida.ano, sizeof(int), 1, f);
    printf("Mes:\n");
    validaMesSaida(v1);
    diasMes = verificaDiasMesSaida(v1);
    fwrite(&v1.saida.mes, sizeof(int), 1, f);
    printf("Dia:\n");
    verificaDiaSaida(v1, bissexto, diasMes);
    fwrite(&v1.saida.dia, sizeof(int), 1, f);
    printf("Horario:\nHora:\n");
    verificaHoraSaida(v1);
    fwrite(&v1.saida.hora, sizeof(int), 1, f);
    printf("Minutos:\n");
    verificaMinutoSaida(v1);
    fwrite(&v1.saida.min, sizeof(int), 1, f);

    v1.status = 'P';
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
    struct cadastro v1;
    printf("Os registros ja incluidos sao:\n");

    printf("Placa: ");
    fread(v1.placa, sizeof(v1.placa), 1, f);
    for(int i = 0; i < 7; i++) {
        printf("%c", v1.placa[i]);
    }
    printf("\n");

    printf("Modelo: ");
    fread(v1.modelo, sizeof(v1.modelo), 1, f);
    for(int i = 0; i < 10; i++) {
        printf("%c", v1.modelo[i]);
    }
    printf("\n");

    printf("Cor: ");
    fread(v1.cor, sizeof(v1.cor), 1, f);
    for(int i = 0; i < 10; i++) {
        printf("%c", v1.cor[i]);
    }
    printf("\n");

    printf("ENTRADA:\n");
    printf("Ano: ");
    fread(&v1.entrada.ano, sizeof(int), 1, f);
    printf("%d", v1.entrada.ano);
    printf("\n");

    printf("Mes: ");
    fread(&v1.entrada.mes, sizeof(int), 1, f);
    printf("%d", v1.entrada.mes);
    printf("\n");

    printf("Dia: ");
    fread(&v1.entrada.dia, sizeof(int), 1, f);
    printf("%d", v1.entrada.dia);
    printf("\n");

    printf("Horario: ");
    fread(&v1.entrada.hora, sizeof(int), 1, f);
    fread(&v1.entrada.min, sizeof(int), 1, f);
    printf("%d:%d", v1.entrada.hora, v1.entrada.min);
    printf("\n\n");

    printf("SAIDA:\n");
    printf("Ano: ");
    fread(&v1.saida.ano, sizeof(int), 1, f);
    printf("%d", v1.saida.ano);
    printf("\n");

    printf("Mes: ");
    fread(&v1.saida.mes, sizeof(int), 1, f);
    printf("%d", v1.saida.mes);
    printf("\n");

    printf("Dia: ");
    fread(&v1.saida.dia, sizeof(int), 1, f);
    printf("%d", v1.saida.dia);
    printf("\n");

    printf("Horario: ");
    fread(&v1.saida.hora, sizeof(int), 1, f);
    fread(&v1.saida.min, sizeof(int), 1, f);
    printf("%d:%d", v1.saida.hora, v1.saida.min);
    printf("\n\n");
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