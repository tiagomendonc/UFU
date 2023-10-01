package interfaces;

import entities.*;

public interface Investidor {
	void atualizar(Acao acao);
	void comprarAcoes(String nomeAcao, int quantidade, AcaoBroker broker);
	void venderAcoes(String nomeAcao, int quantidade, AcaoBroker broker);
}
