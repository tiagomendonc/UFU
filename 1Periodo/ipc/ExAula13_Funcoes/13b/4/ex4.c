#include <stdio.h>
#include <stdlib.h>

void func(float numero, int *numeroInteiro, float *numeroQuebrado) {
    *numeroQuebrado = numero - *numeroInteiro;
}

int main()
{
    float num;
    printf("Informe um numero: \n");
    scanf("%f", &num);

    int numInteiro = num;
    float numQuebrado;

    func(num, &numInteiro, &numQuebrado);

    printf("%.2f, %d, %.2f\n", num, numInteiro, numQuebrado);

    return 0;
}