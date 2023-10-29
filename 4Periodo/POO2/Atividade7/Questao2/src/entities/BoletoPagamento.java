package entities;

import interfaces.PagamentoStrategy;

public class BoletoPagamento implements PagamentoStrategy {
	@Override
    public void realizarPagamento(double valor) {
        System.out.println("Pagamento via Boleto Bancário no valor de R$" + valor);
    }
}
