package app;

import entities.CarroFacade;

public class Main {
	public static void main(String[] args) {
		CarroFacade carro = new CarroFacade();
		
		// Iniciar uma corrida
		System.out.println("Iniciando corrida!");
		carro.iniciarCorrida();
		
		System.out.println();
		
		//Finalizar a corrida
		System.out.println("Finalizando corrida!");
		carro.finalizarCorrida();
	}
}
