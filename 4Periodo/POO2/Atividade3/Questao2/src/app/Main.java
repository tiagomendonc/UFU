package app;

import interfaces.*;
import entities.*;

public class Main {
    public static void main(String[] args) {
        CalculadoraBinaria calculadoraBinaria = new CalculadoraBinariaExistente();
        Calculadora calculadora = new AdaptadorCalculadoraBinariaParaCalculadora(calculadoraBinaria);

        int decimalA = 10;
        int decimalB = 5;

        System.out.println("Operações Decimais:");
        System.out.println("Soma: " + calculadora.somar(decimalA, decimalB));
        System.out.println("Subtração: " + calculadora.subtrair(decimalA, decimalB));
        System.out.println("Multiplicação: " + calculadora.multiplicar(decimalA, decimalB));
    }
}
