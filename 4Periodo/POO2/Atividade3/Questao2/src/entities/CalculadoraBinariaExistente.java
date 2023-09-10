package entities;

import interfaces.CalculadoraBinaria;

public class CalculadoraBinariaExistente implements CalculadoraBinaria {
    @Override
    public String somar(String a, String b) {
        return "Resultado da soma binária: " + a + " + " + b;
    }

    @Override
    public String subtrair(String a, String b) {
        return "Resultado da subtração binária: " + a + " - " + b;
    }
}

