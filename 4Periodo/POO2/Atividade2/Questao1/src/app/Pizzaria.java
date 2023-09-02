package app;

import interfaces.Pizza;
import entities.MassaEspessaPizza;
import entities.MassaFinaPizza;
import entities.ToppingDecorator;

public class Pizzaria {
	public static void main(String[] args) {
		Pizza pizza1 = new ToppingDecorator(new ToppingDecorator(new MassaFinaPizza(), "queijo"), "tomate");
		System.out.println("Pedido 1: " + pizza1.fazerPizza());
		
		Pizza pizza2 = new ToppingDecorator(new ToppingDecorator(new ToppingDecorator(new MassaEspessaPizza(), "queijo"),"ovo"),"tomate");
		System.out.println("Pedido 2: " + pizza2.fazerPizza());
	}
}
