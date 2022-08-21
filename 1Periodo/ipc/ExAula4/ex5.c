#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num;

    printf("Insira um numero entre 1 e 7\n");
    scanf("%d", &num);

    switch (num) {
        case 1:
            printf("Domingo");
            break;
        case 2:
            printf("Segunda");
            break;
        case 3:
            printf("Terca");
            break;
        case 4:
            printf("Quarta");
            break;
        case 5:
            printf("Quinta");
            break;
        case 6:
            printf("Sexta");
            break;
        case 7:
            printf("Domingo");
            break;
        default:
            printf("Numero deve ser entre 1 e 7. Sinto muito!\n");
    }

    return 0;
}