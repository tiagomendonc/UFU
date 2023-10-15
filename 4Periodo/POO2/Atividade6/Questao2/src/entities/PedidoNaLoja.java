package entities;

public class PedidoNaLoja extends PedidoTemplate {

    @Override
    protected double calcularTotal(int quantidadeItens, double valorPorItem) {
        return quantidadeItens * valorPorItem;
    }

    @Override
    protected boolean verificarEntrega() {
        return false;
    }

    @Override
    protected String escolherFormaPagamento() {
        return "Dinheiro ou Cartão de Débito/Crédito na Loja";
    }
}