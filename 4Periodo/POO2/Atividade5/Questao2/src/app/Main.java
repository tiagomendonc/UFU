package app;

import entities.*;
import interfaces.*;

public class Main {
	public static void main(String[] args) {
		AcaoBroker broker = new AcaoBroker();
		
		Acao acao = new Acao("AcaoXYZ", 100.0, broker);
		
		Investidor investidor1 = new InvestidorPessoaFisica("Investidor1", 120.0, 150.0);
		Investidor investidor2 = new InvestidorPessoaFisica("Investidor2", 90.0, 130.0);
		
		acao.adicionarObservador(investidor1);
		acao.adicionarObservador(investidor2);
		
		acao.setPrecoAtual(140.0);
		
		investidor1.comprarAcoes("AcaoXYZ", 5, broker);
		investidor2.comprarAcoes("AcaoXYZ", 3, broker);
	}
}
