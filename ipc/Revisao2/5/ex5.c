#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char busca[100];
    FILE *arq;
    arq = fopen("C:\\ufu\\ipc\\Revisao2\\arquivos\\amor.txt", "r");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
    }

    char str[1000];
    int count = 0;

    printf("Informe a palavra a ser buscada: \n"); scanf("%s", busca); getchar();

    while(!feof(arq)) {
        fgets(str, 1000, arq);
        char *ocorrencia = str;
        do {
            ocorrencia = strstr(ocorrencia, busca);
            if(ocorrencia != NULL) {
                count++;
                ocorrencia++;
            }
        } while(ocorrencia != NULL);
    }
    printf("Encontrou %s %d vezes!", busca, count);

    fclose(arq);

    return 0;
}