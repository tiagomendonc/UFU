package entities;

public class PedidoOnline extends PedidoTemplate {

    @Override
    protected double calcularTotal(int quantidadeItens, double valorPorItem) {
        return quantidadeItens * valorPorItem;
    }

    @Override
    protected boolean verificarEntrega() {
        return true;
    }

    @Override
    protected String escolherFormaPagamento() {
        return "Cartão de Crédito Online";
    }
}