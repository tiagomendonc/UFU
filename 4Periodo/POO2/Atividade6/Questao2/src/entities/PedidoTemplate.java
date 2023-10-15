package entities;

public abstract class PedidoTemplate {

    // Método Template que define o fluxo de processamento do pedido.
    public void processarPedido(int quantidadeItens, double valorPorItem) {
        double total = calcularTotal(quantidadeItens, valorPorItem);
        boolean entrega = verificarEntrega();
        String formaPagamento = escolherFormaPagamento();

        System.out.println("Resumo do Pedido:");
        System.out.println("Quantidade de Itens: " + quantidadeItens);
        System.out.println("Valor por Item: R$" + valorPorItem);
        System.out.println("Total do Pedido: R$" + total);
        System.out.println("Entrega: " + (entrega ? "Sim" : "Não"));
        System.out.println("Forma de Pagamento: " + formaPagamento);
    }

    // Método abstrato para calcular o total do pedido.
    protected abstract double calcularTotal(int quantidadeItens, double valorPorItem);

    // Método abstrato para verificar se há entrega.
    protected abstract boolean verificarEntrega();

    // Método abstrato para escolher a forma de pagamento.
    protected abstract String escolherFormaPagamento();
}
