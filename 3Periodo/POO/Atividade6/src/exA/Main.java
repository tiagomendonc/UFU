package exA;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Funcionario[] funcionarios = new Funcionario[5];
        int i = 0;

        int count_gerentes = 0;
        int count_assistentes = 0;
        int count_vendedores = 0;

        while (i < funcionarios.length) {
            System.out.println("Digite o tipo de funcionário (1 - Gerente, 2 - Assistente, 3 - Vendedor):");
            int tipo = scanner.nextInt();
            scanner.nextLine();

            System.out.println("Digite o nome:");
            String nome = scanner.nextLine();

            System.out.println("Digite a matrícula:");
            String matricula = scanner.nextLine();

            System.out.println("Digite o salário base:");
            double salario_base = scanner.nextDouble();
            scanner.nextLine(); 

            switch (tipo) {
                case 1:
                    funcionarios[i] = new Gerente(nome, matricula, salario_base);
                    count_gerentes++;
                    break;
                case 2:
                    funcionarios[i] = new Assistente(nome, matricula, salario_base);
                    count_assistentes++;
                    break;
                case 3:
                    System.out.println("Digite a comissão:");
                    double comissao = scanner.nextDouble();
                    scanner.nextLine();
                    funcionarios[i] = new Vendedor(nome, matricula, salario_base, comissao);
                    count_vendedores++;
                    break;
                default:
                    System.out.println("Tipo inválido, tente novamente.");
                    continue;
            }

            i++;
        }

        double total_salarios = 0.0;
        double total_salarios_gerentes = 0.0;
        double total_salarios_assistentes = 0.0;
        double total_salarios_vendedores = 0.0;

        i = 0;
        while (i < funcionarios.length) {
            total_salarios += funcionarios[i].calculaSalario();

            switch (funcionarios[i].getClass().getSimpleName()) {
                case "Gerente":
                    total_salarios_gerentes += funcionarios[i].calculaSalario();
                    break;
                case "Assistente":
                    total_salarios_assistentes += funcionarios[i].calculaSalario();
                    break;
                case "Vendedor":
                    total_salarios_vendedores += funcionarios[i].calculaSalario();
                    break;
            }

            i++;
        }

        double media_salarios_gerentes = total_salarios_gerentes / count_gerentes;
        double media_salarios_assistentes = total_salarios_assistentes / count_assistentes;
        double media_salarios_vendedores = total_salarios_vendedores / count_vendedores;

        System.out.println("Folha salarial total: R$" + total_salarios);
        System.out.println("Média salarial dos gerentes: R$" + media_salarios_gerentes);
        System.out.println("Média salarial dos assistentes: R$" + media_salarios_assistentes);
        System.out.println("Média salarial dos vendedores: R$" + media_salarios_vendedores);
    }
}
