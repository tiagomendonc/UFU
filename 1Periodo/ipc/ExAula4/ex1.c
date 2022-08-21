// Faça um programa que leia um número inteiro e escreva se ele é par ou impar

// Dica: utilize o operador de resto da divisão para determinar se um número inteiro
// é par ou impar

#include <stdlib.h>
#include <stdio.h>

int main () {
    
    int num;

    printf("Digite um numero:\n");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("O numero eh par\n");
    } else {
        printf("O numero eh impar\n");
    }
    

    return 0;
}