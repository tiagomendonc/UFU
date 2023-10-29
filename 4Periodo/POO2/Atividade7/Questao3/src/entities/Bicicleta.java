package entities;

import interfaces.*;

public class Bicicleta extends Veiculo {
	String cor;

    public Bicicleta(String cor) {
        this.cor = cor;
    }

    @Override
    void accept(Visitor visitor) {
        visitor.visit(this);
    }
}
