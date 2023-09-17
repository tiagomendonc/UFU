// Classe real que representa um arquivo.

package entities;

import interfaces.Arquivo;

public class ArquivoReal implements Arquivo {
	private String nome;
	
	public ArquivoReal(String nome) {
		this.nome = nome;
	}
	
	@Override
	public void visualizar() {
		System.out.println("Visualizando o arquivo: " + nome);
	}
	
	@Override
	public void baixar() {
		System.out.println("Baixando o arquivo: " + nome);
	}
}
