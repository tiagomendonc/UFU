#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () 
{
    // Usando int

    // int cat1, cat2, hip;

    // printf("Insira os catetos: \n");
    // scanf("%d %d", &cat1, &cat2);

    // hip = sqrt(cat1 * cat1 + cat2 * cat2);

    // printf("A hipotenusa eh: %d", hip);
    
    // return 0;

   
   // Usando float
    float cat1, cat2, hip;

    printf("Insira os catetos: \n");
    scanf("%f %f", &cat1, &cat2);

    hip = sqrt(cat1 * cat1 + cat2 * cat2);

    printf("A hipotenusa eh: %f", hip);
    
    return 0;
}