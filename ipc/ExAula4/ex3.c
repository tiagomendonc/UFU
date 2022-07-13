#include <stdio.h>
#include <stdlib.h>

int main () 
{
    float salario, salarioReajustado;

    printf("Informe o seu salario atual: \n");
    scanf("%f", &salario);

    if (salario <= 1200.00) {
        salarioReajustado = salario + (salario * 0.075) + 100;
        printf("Seu novo salario eh: %f", salarioReajustado);
    } else {
        salarioReajustado = salario + (salario * 0.075);
        printf("Seu novo salario eh: %f", salarioReajustado);
    }
    
    return 0;
}