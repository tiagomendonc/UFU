#include <stdio.h>
#include <stdlib.h>

void print(int **m, int l, int c) {
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < c; j++) {
            printf("%2d", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void transposta(int **m, int l, int c) {
    int aux;
    for(int i = 0; i < l; i++) {
        for(int j = i + 1; j < c; j++) {
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}

int main()
{
    int l = 3, c = 5, v = 1;
    int **m = (int **) malloc(l*sizeof(int));
    for(int i = 0; i < l; i++) {
        m[i] = (int *) malloc(c*sizeof(int));
        for(int j = 0; j < c; j++) {
            m[i][j] = v++;
        }
    }

    print(m, l, c);
    transposta(m, l, c);
    printf("\n\n");
    print(m, l, c);

    return 0;
}