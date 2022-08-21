#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592

float vol_c(float altura, float raio) {
    float volume = PI * pow(raio, 2) * altura;
    return volume;
}

int main()
{
    float altura, raio;
    printf("Informe a altura e o raio respectivamente do cilindro: \n");
    scanf("%f %f", &altura, &raio);

    printf("O volume do cilindro eh: %.2f\n", vol_c(altura, raio));

    return 0;
}