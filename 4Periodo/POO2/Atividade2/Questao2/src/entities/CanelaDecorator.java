package entities;

import interfaces.Bebida;

public class CanelaDecorator implements Bebida {
    private Bebida bebida;

    public CanelaDecorator(Bebida bebida) {
        this.bebida = bebida;
    }

    @Override
    public double calculaCusto() {
        return bebida.calculaCusto() + 0.3;
    }

    @Override
    public String getDescricao() {
        return bebida.getDescricao() + ", com canela";
    }
}
