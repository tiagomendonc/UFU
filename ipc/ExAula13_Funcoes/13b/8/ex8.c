#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int elevaCubo(int n) {
    int num;
    int s = 0;
    for (int i = 0; i < n; i++) {
        num = pow(i + 1, 3);
        s += num;
    }
    return s;
}

int main()
{
    int n;
    printf("Informe um numero: \n");
    scanf("%d", &n);

    int s = elevaCubo(n);

    printf("O resultado de S eh: %d\n", s);

    return 0;
}
