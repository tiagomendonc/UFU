#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Informe n: \n");
    scanf("%d", &n);

    int a[n], b[n], d = 0, dif = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        dif = a[i] - b[i];
        if (dif < 0) {
            dif = dif * -1;
        }
        d += dif;
    }

    printf("A distancia de Manhattan eh: %d\n", d);

    return 0;
}