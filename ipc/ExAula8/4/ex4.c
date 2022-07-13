#include <stdio.h>
#include <stdlib.h>

int main ()
{
    printf("char: %d\n", sizeof(char));
    printf("char: %d\n", sizeof(char*));
    printf("char: %d\n", sizeof(char**));
    printf("char: %d\n\n", sizeof(char***));

    printf("int: %d\n", sizeof(int));
    printf("int: %d\n", sizeof(int*));
    printf("int: %d\n", sizeof(int**));
    printf("int: %d\n\n", sizeof(int***));

    printf("float: %d\n", sizeof(float));
    printf("float: %d\n", sizeof(float*));
    printf("float: %d\n", sizeof(float**));
    printf("float: %d\n\n", sizeof(float***));

    printf("double: %d\n", sizeof(double));
    printf("double: %d\n", sizeof(double*));
    printf("double: %d\n", sizeof(double**));
    printf("double: %d\n\n", sizeof(double***));

    printf("long double: %d\n", sizeof(long));
    printf("long double: %d\n", sizeof(long*));
    printf("long double: %d\n", sizeof(long**));
    printf("long double: %d\n", sizeof(long***));

    return 0;
}