package entities;

import interfaces.Bebida;

public class Espresso implements Bebida {
	@Override
	public double calculaCusto() {
		return 2.0;
	}
	
	@Override 
	public String getDescricao() {
		return "Espresso";
	}
}
