// Tiago Oliveira Mendonça
// 12121BSI238

#include <stdio.h>
#include <stdlib.h>

int fiboIterativo(int n) {
    int c, a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int fiboRecursivo(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fiboRecursivo(n - 1) + fiboRecursivo(n - 2);
    }
}

int main()
{
    for(int i = 1; i < 100; i++ ) {
        printf("\ntermo %d: %d", i, fiboIterativo(i));
    }
    for (int i = 1; i < 100; i++) {
        printf("\ntermo %d: %d", i, fiboRecursivo(i));
    }

    return 0;
}

// A função fiboIterativo tem um tempo de execução muito superior a função fiboRecursivo.