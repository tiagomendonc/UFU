package exB;

public abstract class Funcionario {
	String nome, cpf;
	int matricula, idade;
	double salario_base;
	
	public Funcionario(String nome, String cpf, int matricula, int idade, double salario_base) {
		this.nome = nome;
		this.cpf = cpf;
		this.matricula = matricula;
		this.idade = idade;
		this.salario_base = 1200;
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		this.cpf = cpf;
	}

	public int getMatricula() {
		return matricula;
	}

	public void setMatricula(int matricula) {
		this.matricula = matricula;
	}

	public int getIdade() {
		return idade;
	}

	public void setIdade(int idade) {
		this.idade = idade;
	}

	public double getSalario_base() {
		return salario_base;
	}

	public void setSalario_base(double salario_base) {
		this.salario_base = salario_base;
	}
	
	
}
