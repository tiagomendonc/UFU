package entities;

import java.util.HashMap;
import java.util.Map;
import interfaces.Investidor;

public class AcaoBroker {
	private Map<String, Double> precosAcoes = new HashMap<>();
	
	public void comprarAcoes(Investidor investidor, String nomeAcao, int quantidade) {
		double precoAtual = precosAcoes.getOrDefault(nomeAcao, 0.0);
		double valorTotal = precoAtual * quantidade;
		
		System.out.println(investidor + " comprou " + quantidade + " ações de " + nomeAcao + " por $" + valorTotal);
	}
	
	public void venderAcoes(Investidor investidor, String nomeAcao, int quantidade) {
		double precoAtual = precosAcoes.getOrDefault(nomeAcao, 0.0);
		double valorTotal = precoAtual * quantidade;
		
        System.out.println(investidor + " vendeu " + quantidade + " ações de " + nomeAcao + " por $" + valorTotal);
	}
	
	 public void atualizarPrecoAcao(String nomeAcao, double novoPreco) {
	        precosAcoes.put(nomeAcao, novoPreco);
	        System.out.println("Preço da ação " + nomeAcao + " atualizado para $" + novoPreco);
	    }
}
