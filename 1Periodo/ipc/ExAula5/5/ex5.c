#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n;
    int penultimo = 0;
    int ultimo = 1;

    printf("Insira um numero maior que 0: \n");
    scanf("%d", &n);

    printf("%d", penultimo);
    printf(", %d", ultimo);

    if (n <= 0) {
        printf("Insira um numero maior que 0!\n");
    } else {
        for (int i = 0; i < n - 2; i++) {
            int atual = penultimo + ultimo;

            printf(", %d", atual);

            penultimo = ultimo;
            ultimo = atual;
            
        }
    }

    return 0;
}