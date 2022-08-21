#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float divs = 1, divd = 1;
    float soma = 0;
    float s;
    
    for (int i = 0; i < 50; i++) {
        s = divd / divs;
        soma += s;
        divs++;
        divd += 2;
    }

    printf("O valor de S eh: %f\n", soma);

    return 0;
}