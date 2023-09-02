package app;

import interfaces.Bebida;
import entities.*;

public class Cafeteria {
	public static void main(String[] args) {
        Bebida bebida1 = new LeiteDecorator(new CanelaDecorator(new Espresso()));
        System.out.println("Pedido 1: " + bebida1.getDescricao() + ", custo: R$" + bebida1.calculaCusto());

        Bebida bebida2 = new LeiteDecorator(new ChocolateDecorator(new Decaf()));
        System.out.println("Pedido 2: " + bebida2.getDescricao() + ", custo: R$" + bebida2.calculaCusto());
    }
}
