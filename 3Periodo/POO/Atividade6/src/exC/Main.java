package exC;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        List<Produto> produtos = new ArrayList<>();

        int opcao;
        do {
            System.out.println("Selecione uma opção:");
            System.out.println("1 - Adicionar produto na lista");
            System.out.println("2 - Calcular quantidade e preço total de uma categoria");
            System.out.println("3 - Calcular o total geral dos produtos");
            System.out.println("0 - Sair");
            opcao = scanner.nextInt();

            switch (opcao) {
                case 1:
                    System.out.println("Selecione uma categoria:");
                    System.out.println("1 - Eletrodoméstico");
                    System.out.println("2 - Vinho");
                    System.out.println("3 - Café");
                    int categoria = scanner.nextInt();

                    switch (categoria) {
                        case 1:
                            System.out.println("Digite o ID do eletrodoméstico:");
                            int idEletro = scanner.nextInt();
                            System.out.println("Digite o ano de produção do eletrodoméstico:");
                            int anoEletro = scanner.nextInt(); 
                            System.out.println("Digite a unidade de venda do eletrodoméstico:");
                            int unidadeEletro = scanner.nextInt();
                            System.out.println("Digite o preço do eletrodoméstico:");
                            double precoEletro = scanner.nextDouble();
                            produtos.add(new Eletrodomestico(idEletro, anoEletro, unidadeEletro, precoEletro));
                            break;
                        case 2:
                            System.out.println("Digite o ID do vinho:");
                            int idVinho = scanner.nextInt();
                            System.out.println("Digite o ano de produção do vinho:");
                            int anoVinho = scanner.nextInt();
                            System.out.println("Digite a unidade de venda do vinho:");
                            int unidadeVinho = scanner.nextInt();
                            System.out.println("Digite o preço do vinho:");
                            double precoVinho = scanner.nextDouble();
                            produtos.add(new Vinho(idVinho, anoVinho, unidadeVinho, precoVinho));
                            break;
                        case 3:
                            System.out.println("Digite o ID do café:");
                            int idCafe = scanner.nextInt();
                            System.out.println("Digite o ano de produção do café:");
                            int anoCafe = scanner.nextInt();
                            System.out.println("Digite a unidade de venda do café:");
                            int unidadeCafe = scanner.nextInt();
                            System.out.println("Digite o preço do café:");
                            double precoCafe = scanner.nextDouble();
                            produtos.add(new Cafe(idCafe, anoCafe, unidadeCafe, precoCafe));
                            break;
                        default:
                            System.out.println("Opção inválida!");
                            break;
                    }
                    break;
                case 2:
                	System.out.println("Selecione uma categoria:");
                	System.out.println("1 - Eletrodoméstico");
                	System.out.println("2 - Vinho");
                	System.out.println("3 - Café");
                	categoria = scanner.nextInt();
                	int quantidade = 0;
                	double precoTotal = 0.0;
                    for (Produto produto : produtos) {
                        if (categoria == 1 && produto instanceof Eletrodomestico) {
                            quantidade += produto.getUnidadeVenda();
                            precoTotal += produto.getPreco();
                        } else if (categoria == 2 && produto instanceof Vinho) {
                            quantidade += produto.getUnidadeVenda();
                            precoTotal += produto.getPreco();
                        } else if (categoria == 3 && produto instanceof Cafe) {
                            quantidade += produto.getUnidadeVenda();
                            precoTotal += produto.getPreco();
                        }
                    }

                    System.out.println("Quantidade total de unidades vendidas da categoria selecionada: " + quantidade);
                    System.out.println("Preço total dos produtos da categoria selecionada: R$ " + precoTotal);
                    break;
                case 3:
                    double totalGeral = 0.0;
                    for (Produto produto : produtos) {
                        totalGeral += produto.getPreco() * produto.getUnidadeVenda();
                    }
                    System.out.println("O total geral dos produtos é: R$ " + totalGeral);
                    break;
                case 0:
                    System.out.println("Programa encerrado!");
                    break;
                default:
                    System.out.println("Opção inválida!");
                    break;
            }
        } while (opcao != 0);
    }
}