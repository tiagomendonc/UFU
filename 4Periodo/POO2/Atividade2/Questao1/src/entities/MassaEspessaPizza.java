package entities;

import interfaces.Pizza;

public class MassaEspessaPizza implements Pizza {
	@Override
	public String fazerPizza() {
		return "Pizza de massa espessa";
	}
}
