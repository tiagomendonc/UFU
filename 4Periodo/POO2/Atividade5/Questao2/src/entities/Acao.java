package entities;

import java.util.ArrayList;
import java.util.List;
import interfaces.Investidor;

public class Acao {
	private String nome;
	private double precoAtual;
	private List<Investidor> observadores = new ArrayList<>();
	private AcaoBroker acaoBroker;
	
	public Acao(String nome, double precoAtual, AcaoBroker acaoBroker) {
		this.nome = nome;
		this.precoAtual = precoAtual;
		this.acaoBroker = acaoBroker;
	}
	
	public void adicionarObservador(Investidor investidor) {
		observadores.add(investidor);
	}
	
	public void removerObservador(Investidor investidor) {
		observadores.remove(investidor);
	}
	
	public AcaoBroker getAcaoBroker() {
		return this.acaoBroker;
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public double getPrecoAtual() {
		return this.precoAtual;
	}
	
	public void setPrecoAtual(double precoAtual) {
		this.precoAtual = precoAtual;
		notificarObservadores();
	}
	
	private void notificarObservadores() {
		for(Investidor investidor : observadores) {
			investidor.atualizar(this);
		}
	}
}
