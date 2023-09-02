package entities;

import interfaces.Pizza;

public class ToppingDecorator implements Pizza {
	private Pizza pizza;
	private String topping;
	
	public ToppingDecorator(Pizza pizza, String topping) {
		this.pizza = pizza;
		this.topping = topping;
	}
	
	@Override
	public String fazerPizza() {
		return pizza.fazerPizza() + ", com " + topping;
	}
}
