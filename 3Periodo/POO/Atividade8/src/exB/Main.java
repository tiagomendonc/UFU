package exB;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Map<String, Empregado> empregados = new HashMap<>();

        Scanner scanner = new Scanner(System.in);
        for (int i = 0; i < 5; i++) {
            System.out.println("Digite os dados do empregado " + (i + 1));
            System.out.print("CPF: ");
            String cpf = scanner.nextLine();
            System.out.print("Idade: ");
            int idade = Integer.parseInt(scanner.nextLine());
            System.out.print("Salário: ");
            double salario = Double.parseDouble(scanner.nextLine());

            Empregado empregado = new Empregado(cpf, idade, salario);
            empregados.put(cpf, empregado);
        }

        System.out.print("Digite o CPF do empregado a ser buscado: ");
        String cpfBusca = scanner.nextLine();

        if (empregados.containsKey(cpfBusca)) {
            Empregado empregadoEncontrado = empregados.get(cpfBusca);
            System.out.println("Empregado encontrado:");
            System.out.println("CPF: " + empregadoEncontrado.getCpf());
            System.out.println("Idade: " + empregadoEncontrado.getIdade());
            System.out.println("Salário: " + empregadoEncontrado.getSalario());
        } else {
            System.out.println("CPF não encontrado.");
        }

        double menorSalario = Double.MAX_VALUE;
        double maiorSalario = Double.MIN_VALUE;
        String cpfMenorSalario = "";
        String cpfMaiorSalario = "";

        for (Map.Entry<String, Empregado> entry : empregados.entrySet()) {
            Empregado empregado = entry.getValue();
            double salario = empregado.getSalario();

            if (salario < menorSalario) {
                menorSalario = salario;
                cpfMenorSalario = empregado.getCpf();
            }

            if (salario > maiorSalario) {
                maiorSalario = salario;
                cpfMaiorSalario = empregado.getCpf();
            }
        }

        System.out.println("CPF do empregado com menor salário: " + cpfMenorSalario);
        System.out.println("CPF do empregado com maior salário: " + cpfMaiorSalario);
    }
}
