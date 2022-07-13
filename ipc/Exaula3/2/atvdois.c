#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float c, f, k;

    printf("Insira a temperatura em graus Celsius: \n");
    scanf("%f", &c);

    k = c + 273.15;
    f = (c * 9 / 5) + 32;

    printf("A temperatura em K eh: %f\n", k);
    printf("A temperatura em F eh: %f\n", f);

    return 0;
}