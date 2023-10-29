package app;

import entities.*;

public class Main {
	public static void main(String[] args) {
        Veiculo[] veiculos = {
            new Carro("Vermelho", "Toyota", "Camry"),
            new Onibus(40, 2020),
            new Bicicleta("Azul")
        };

        OperacoesVisitor operacoesVisitor = new OperacoesVisitor();

        for (Veiculo veiculo : veiculos) {
            veiculo.accept(operacoesVisitor);
            System.out.println();
        }
    }
}
