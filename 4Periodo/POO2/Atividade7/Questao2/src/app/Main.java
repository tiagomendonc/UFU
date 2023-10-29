package app;

import entities.*;

public class Main {
	public static void main(String[] args) {
        CarrinhoCompras carrinho = new CarrinhoCompras();
        carrinho.adicionaItem(new Item("Produto 1", 50.0));

        // Definindo estratégia de pagamento via Boleto
        carrinho.setPagamentoStrategy(new BoletoPagamento());
        
        // Definindo estratégia de frete como Sedex
        carrinho.setFreteStrategy(new SedexFrete());

        carrinho.realizaPagamento();

        // Mudando a estratégia de pagamento para Cartão de Crédito
        carrinho.setPagamentoStrategy(new CartaoPagamento());

        // Mudando a estratégia de frete para Normal
        carrinho.setFreteStrategy(new NormalFrete());

        carrinho.realizaPagamento();
    }
}
