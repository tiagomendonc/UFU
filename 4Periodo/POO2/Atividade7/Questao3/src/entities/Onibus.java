package entities;

import interfaces.*;

public class Onibus extends Veiculo {
	int lugares;
    int anoFabricacao;

    public Onibus(int lugares, int anoFabricacao) {
        this.lugares = lugares;
        this.anoFabricacao = anoFabricacao;
    }

    @Override
    void accept(Visitor visitor) {
        visitor.visit(this);
    }
}
