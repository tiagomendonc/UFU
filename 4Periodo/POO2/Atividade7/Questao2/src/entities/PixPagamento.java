package entities;

import interfaces.PagamentoStrategy;

public class PixPagamento implements PagamentoStrategy {
	 @Override
    public void realizarPagamento(double valor) {
        System.out.println("Pagamento via Pix no valor de R$" + valor);
    }
}
