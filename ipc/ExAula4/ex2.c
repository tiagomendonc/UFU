// Faça um programa que receba a altura e o sexo de uma pessoa e calcule
// e mostre seu peso ideal, utilizando as seguintes equações (em que “h” corresponde a altura)
// - homem: (72,7 * h) - 58
// - mulher: (62,1 * h) - 44,7

#include <stdio.h>
#include <stdlib.h>

int main () {
    char sexo[1];
    float altura, pesoIdeal;

    printf("Informe o seu sexo: ('M', 'F')\n");
    scanf("%c", &sexo);
    printf("Informe sua altura em metros:\n");
    scanf("%f", &altura);

    if ((sexo == 'M') || (sexo == 'm')) {
        pesoIdeal = (72.7 * altura) - 58;
        printf("Seu peso ideal eh: %f", pesoIdeal);
    } else if ((sexo == "F") || (sexo == "f"))
    {
        pesoIdeal = (62.1 * altura) - 44.7;
        printf("Seu peso ideal eh: %f", pesoIdeal);
    } else {
        printf("Informe um caracter válido\n");

    }
    

    return 0;
}