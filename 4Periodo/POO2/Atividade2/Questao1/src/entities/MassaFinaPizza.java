package entities;

import interfaces.Pizza;

public class MassaFinaPizza implements Pizza {
	@Override
	public String fazerPizza() {
		return "Pizza de massa fina";
	}
}
