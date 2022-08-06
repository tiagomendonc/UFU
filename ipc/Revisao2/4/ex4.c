#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    arq = fopen("C:\\ufu\\ipc\\Revisao2\\arquivos\\ex4.txt", "r");
    if(arq == NULL) {
        printf("Erro ao abrir o arquivo!\n\n");
    }

    int count = 1;

    while(!feof(arq)) {
        if(fgetc(arq) == '\n') {
            count++;
        }
    }

    printf("O arquivo tem %d linhas.\n", count);

    fclose(arq);

    return 0;
}