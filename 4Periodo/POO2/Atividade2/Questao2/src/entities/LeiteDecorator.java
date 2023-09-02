package entities;

import interfaces.Bebida;

public class LeiteDecorator implements Bebida {
	private Bebida bebida;
	
	public LeiteDecorator(Bebida bebida) {
		this.bebida = bebida;
	}
	
	@Override
	public double calculaCusto() {
		return bebida.calculaCusto() + 0.5;
	}
	
	@Override
	public String getDescricao() {
		return bebida.getDescricao() + ", com leite";
	}
}
