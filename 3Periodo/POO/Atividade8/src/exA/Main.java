package exA;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Empregado> empregados = new ArrayList<>();

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
            empregados.add(empregado);
        }

        Empregado empregadoMaiorIdade = Collections.max(empregados);

        System.out.println("O empregado de maior idade é:");
        System.out.println("CPF: " + empregadoMaiorIdade.getCpf());
        System.out.println("Idade: " + empregadoMaiorIdade.getIdade());
        System.out.println("Salário: " + empregadoMaiorIdade.getSalario());

        System.out.print("Digite um valor de salário: ");
        double salarioInformado = Double.parseDouble(scanner.nextLine());

        System.out.println("Empregados com salário maior do que " + salarioInformado + ":");
        for (Empregado empregado : empregados) {
            if (empregado.getSalario() > salarioInformado) {
                System.out.println("CPF: " + empregado.getCpf());
                System.out.println("Idade: " + empregado.getIdade());
                System.out.println("Salário: " + empregado.getSalario());
            }
        }

        Collections.sort(empregados, (e1, e2) -> Double.compare(e1.getSalario(), e2.getSalario()));

        System.out.println("Empregados ordenados por salário em ordem crescente:");
        for (Empregado empregado : empregados) {
            System.out.println("CPF: " + empregado.getCpf());
            System.out.println("Idade: " + empregado.getIdade());
            System.out.println("Salário: " + empregado.getSalario());
        }
    }
}
