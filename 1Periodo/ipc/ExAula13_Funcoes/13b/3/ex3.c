#include <stdio.h>
#include <stdlib.h>

long long int fatorial(int x) {
    long long int y = 1;
    for (int i = 2; i <= x; i++) {
        y = y * 1;
    }
    return y;
}

long long int combinacao(int n, int s) {
    long long int c = fatorial(n) / (fatorial(s) * (fatorial(n - 2)));
    return c;
}

int main()
{
    int n, s;

    printf("Informe N e S respectivamente: \n");
    scanf("%d %d", &n, &s);

    printf("A combinacao eh: %lld\n", combinacao(n, s));

    return 0;
}