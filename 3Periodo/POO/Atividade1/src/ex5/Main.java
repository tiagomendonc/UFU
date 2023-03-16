package ex5;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String nome;
		long cpf;
		int idade;
		long telefone;
		
		System.out.println("Informe os dados do cliente:");
		System.out.print("Nome: ");
		nome = scan.nextLine();
		System.out.println();
		System.out.print("CPF: ");
		cpf = scan.nextLong();
		System.out.println();
		System.out.print("Idade: ");
		idade = scan.nextInt();
		System.out.println();
		System.out.print("Telefone: ");
		telefone = scan.nextLong();
		
		Pessoa p = new Pessoa(nome, cpf, idade, telefone);
		
		p.mostraDadosCliente();
	}
}
