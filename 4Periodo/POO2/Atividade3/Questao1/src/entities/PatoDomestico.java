package entities;

import interfaces.Ave;

public class PatoDomestico implements Ave {
    @Override
    public void voar() {
        System.out.println("O pato doméstico voa.");
    }

    @Override
    public void emitirSom() {
        System.out.println("O pato doméstico grasna.");
    }
}