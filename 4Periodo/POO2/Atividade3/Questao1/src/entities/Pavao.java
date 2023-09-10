package entities;

import interfaces.Ave;

public class Pavao implements Ave {
    @Override
    public void voar() {
        System.out.println("O pavão não voa.");
    }

    @Override
    public void emitirSom() {
        System.out.println("O pavão canta.");
    }
}

