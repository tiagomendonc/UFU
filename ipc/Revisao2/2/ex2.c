#include <stdlib.h>
#include <stdio.h>

int fatorial(int i) {
    int fat;
    if ( i <= 1 ) {
        return (1);
    }
    else {
       return i * fatorial(i - 1);
    }
}

double neperiano(int n) {
    int e = 0;
    for(int i = 0; i < n; i++) {
        e += 1 / fatorial(i);
    }
}

int main()
{
    int n;
    printf("Informe N:\n");
    scanf("%d", &n);

    printf("Numero neperiano = ");
    printf("%f", neperiano(n));

    return 0;
}