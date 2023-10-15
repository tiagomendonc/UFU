package entities;

public class PedidoCriptomoeda extends PedidoTemplate {

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
        return "Criptomoedas";
    }
}