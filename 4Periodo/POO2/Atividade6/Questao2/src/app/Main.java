package app;

import entities.*;

/* 
 * O padrão Template (PedidoTemplate) define um esqueleto de algoritmo em uma superclasse,
 * permitindo que as subclasses (PedidoOnline, PedidoNaLoja, PedidoCriptomoedas) implementem partes
 * específicas desse algoritmo. Ele é usado para definir um fluxo de execução fixo.
 * 
 * Por outro lado, o padrão Decorator não é utilizado neste exemplo, mas ele permite adicionar
 * responsabilidades a objetos de forma dinâmica, ou seja, você pode "decorar" um objeto com
 * funcionalidades extras sem alterar sua estrutura principal. O Decorator é usado para adicionar
 * comportamentos adicionais de maneira flexível.
 */

public class Main {

    public static void main(String[] args) {
        System.out.println("Pedido Online:");
        PedidoTemplate pedidoOnline = new PedidoOnline();
        pedidoOnline.processarPedido(5, 20.0);

        System.out.println("\nPedido na Loja:");
        PedidoTemplate pedidoNaLoja = new PedidoNaLoja();
        pedidoNaLoja.processarPedido(3, 15.0);

        System.out.println("\nPedido com Criptomoedas:");
        PedidoTemplate pedidoCriptomoedas = new PedidoCriptomoeda();
        pedidoCriptomoedas.processarPedido(2, 50.0);
    }
}
