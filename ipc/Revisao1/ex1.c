#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num = 0;

    for (int i = 0; i < 100; i++) {
        num += 1000;
        printf("%d ", num);
    }

    return 0;
}