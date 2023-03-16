package ex5;

public class Pessoa {
	String nome;
	long cpf;
	int idade;
	long telefone;
	
	public Pessoa(String nome, long cpf, int idade, long telefone) {
		this.nome = nome;
		this.cpf = cpf;
		this.idade = idade;
		this.telefone = telefone;
	}
	
	public void mostraDadosCliente() {
		System.out.println("Nome: " + nome);
		System.out.println("CPF: " + cpf);
		System.out.println("Idade: " + idade);
		System.out.println("Telefone: " + telefone);
	}
}
