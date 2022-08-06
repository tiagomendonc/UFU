#include <stdio.h>
#include <stdlib.h>

void atribuiString(char str[], int i, int j) {
    if(j < i) {
        int aux;
        aux = i;
        i = j;
        j = aux;
    }

    i--;
    j--;

    int k;
    for(k = i; k <= j; k++) {
        str[k - i] = str[k];
    }
    str[k - i] = '\0';
}

int main()
{
    int i, j;
    char str[20];

    printf("Informe uma palavra ou frase: \n"); scanf("%s", str); getchar();
    printf("Informe duas posicoes: \n"); scanf("%d %d", &i, &j);

    atribuiString(str, i, j);

    printf("O resultado eh: %s\n", str);
    

    return 0;
}