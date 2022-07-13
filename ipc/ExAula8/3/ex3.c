#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float a, *b, **c, ***d;

    printf("Qual o valor de A? \n");
    scanf("%f", &a);
    b = &a;
    *b = *b * 2;
    printf("O valor de *B eh: %f\n", *b);
    c = &b;
    **c = (*b / 2) * 3;
    printf("O valor de **C eh: %f\n", **c);
    d = &c;
    ***d = (**c / 3) * 4;
    printf("O valor de ***D eh: %f\n", ***d);
    
    

    return 0;
}