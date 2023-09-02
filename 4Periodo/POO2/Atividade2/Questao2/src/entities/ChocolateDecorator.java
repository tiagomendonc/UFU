package entities;

import interfaces.Bebida;

public class ChocolateDecorator implements Bebida {
    private Bebida bebida;

    public ChocolateDecorator(Bebida bebida) {
        this.bebida = bebida;
    }

    @Override
    public double calculaCusto() {
        return bebida.calculaCusto() + 0.7; 
    }

    @Override
    public String getDescricao() {
        return bebida.getDescricao() + ", com chocolate";
    }
}
