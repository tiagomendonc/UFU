package entities;

import java.util.ArrayList;
import java.util.List;

import interfaces.*;

public class CarrinhoCompras {
	private List<Item> itens = new ArrayList<>();
    private PagamentoStrategy pagamentoStrategy;
    private FreteStrategy freteStrategy;

    public void adicionaItem(Item item) {
        itens.add(item);
    }

    public void removeItem(Item item) {
        itens.remove(item);
    }

    public void setPagamentoStrategy(PagamentoStrategy pagamentoStrategy) {
        this.pagamentoStrategy = pagamentoStrategy;
    }

    public void setFreteStrategy(FreteStrategy freteStrategy) {
        this.freteStrategy = freteStrategy;
    }

    public void realizaPagamento() {
        double total = calculaTotal();
        double frete = freteStrategy.calcularFrete();
        total += frete;
        pagamentoStrategy.realizarPagamento(total);
    }

    public double calculaTotal() {
        double total = 0.0;
        for (Item item : itens) {
            total += item.getPreco();
        }
        return total;
    }
}
