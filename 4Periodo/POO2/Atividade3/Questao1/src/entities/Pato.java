package entities;

import interfaces.Ave;

public class Pato implements Ave {
    @Override
    public void voar() {
        System.out.println("O pato voa.");
    }

    @Override
    public void emitirSom() {
        System.out.println("O pato grasna.");
    }
}

