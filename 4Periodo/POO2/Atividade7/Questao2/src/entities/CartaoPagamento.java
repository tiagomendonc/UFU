package entities;

import interfaces.PagamentoStrategy;

public class CartaoPagamento implements PagamentoStrategy {
	@Override
    public void realizarPagamento(double valor) {
        System.out.println("Pagamento via Cartão de Crédito no valor de R$" + valor);
    }
}
