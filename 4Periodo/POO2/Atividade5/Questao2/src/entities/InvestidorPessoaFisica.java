package entities;

import interfaces.Investidor;

public class InvestidorPessoaFisica implements Investidor {
	private String nome;
	private double precoMinimo;
	private double precoMaximo;
	
	public InvestidorPessoaFisica(String nome, double precoMinimo, double precoMaximo) {
		this.nome = nome;
		this.precoMinimo = precoMinimo;
		this.precoMaximo = precoMaximo;
	}
	
	@Override
	public void atualizar(Acao acao) {
		if(acao.getPrecoAtual() >= precoMaximo) {
            System.out.println(nome + " vendeu suas ações de " + acao.getNome() + " a $" + acao.getPrecoAtual());
            venderAcoes(acao.getNome(), 5, acao.getAcaoBroker());
		}
	}
	
	@Override
	public void comprarAcoes(String nomeAcao, int quantidade, AcaoBroker broker) {
		System.out.println(nome + " comprou " + quantidade + " ações de " + nomeAcao);
		broker.comprarAcoes(this, nomeAcao, quantidade);
	}
	
	@Override
	public void venderAcoes(String nomeAcao, int quantidade, AcaoBroker broker) {
	    System.out.println(nome + " vendeu " + quantidade + " ações de " + nomeAcao);
	    broker.venderAcoes(this, nomeAcao, quantidade);
	}
}
