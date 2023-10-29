package entities;

import interfaces.FreteStrategy;

public class NormalFrete implements FreteStrategy {
	@Override
    public double calcularFrete() {
        return 5.0;
    }
}
