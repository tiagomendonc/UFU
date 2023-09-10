package entities;

import interfaces.Ave;

public class PavaoAzul implements Ave {
    @Override
    public void voar() {
        System.out.println("O pavão azul não voa.");
    }

    @Override
    public void emitirSom() {
        System.out.println("O pavão azul canta.");
    }
}
