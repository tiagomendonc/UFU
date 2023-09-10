package app;

import interfaces.Ave;
import entities.*;

public class Main {
    public static void main(String[] args) {
        Ave pato = new Pato();
        Ave pavao = new AdaptadorWrapperPavao(new Pavao());
        Ave patoDomestico = new PatoDomestico();
        Ave pavaoAzul = new AdaptadorWrapperPavaoAzul(new PavaoAzul());

        System.out.println("Pato:");
        pato.voar();
        pato.emitirSom();

        System.out.println("\nPavão:");
        pavao.voar();
        pavao.emitirSom();

        System.out.println("\nPato Doméstico:");
        patoDomestico.voar();
        patoDomestico.emitirSom();

        System.out.println("\nPavão Azul:");
        pavaoAzul.voar();
        pavaoAzul.emitirSom();
    }
}

