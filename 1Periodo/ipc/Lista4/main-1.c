// Tiago Oliveira Mendonça
//12121BSI238

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculaImc(float peso, float altura) {
    float imc = peso / pow(altura, 2);
    return imc;
}

int main()
{
    float peso, altura;
    
    printf("Informe seu peso em kg: \n");
    scanf("%f", &peso);
    printf("Informe sua altura em metros: \n");
    scanf("%f", &altura);

    printf("Seu IMC eh: %.4f\n", calculaImc(peso, altura));

    return 0;
}