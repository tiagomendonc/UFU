package entities;

import interfaces.FreteStrategy;

public class SedexFrete implements FreteStrategy {
	@Override
    public double calcularFrete() {
        return 10.0;
    }

}
