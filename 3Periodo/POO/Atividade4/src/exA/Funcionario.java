package exA;

public class Funcionario {
	private String nome, rg;
	private double salario_base;
	
	public Funcionario(String nome, String rg, double salario_base) {
		this.nome = nome;
		this.rg = rg;
		this.salario_base = salario_base;
	}
	
	public String getNome() {
		return nome;
	}
	
	public double getSalario() {
		return salario_base;
	}
}

class Vendedor extends Funcionario {
	private double total_vendido;
	private double comissao;
	
	public Vendedor(String nome, String rg, double salario_base) {
		super(nome, rg, salario_base);
		this.total_vendido = 0;
	}
	
	public void adicionaVenda(double valor) {
		this.total_vendido += valor;
	}
	
	public void calculaComissao() {
		this.comissao = total_vendido * 0.05;
	}
	
	public void zeraIndicadores() {
		this.total_vendido = 0;
		this.comissao = 0;
	}
	
	public double calculaSalarioFinal() {
		calculaComissao();
		double salario_final = getSalario() + (this.total_vendido + this.comissao); 
		zeraIndicadores();
		return salario_final;
	}
}

class Administrativo extends Funcionario {
	private int horas_extras;
	private double total_horas_extras;
	
	public Administrativo(String nome, String rg, double salario_base) {
		super(nome, rg, salario_base);
		this.horas_extras = 0;
	}
	
	public void adicionaHoraExtra(double hora_extra) {
		this.horas_extras += hora_extra;
	}
	
	public void calculaTotalValorHorasExtras() {
		this.total_horas_extras = (getSalario() / 100) * this.horas_extras;
	}
	
	public void zeraIndicadores() {
		this.horas_extras = 0;
		this.total_horas_extras = 0;
	}
	
	public double calculaSalarioFinal() {
		calculaTotalValorHorasExtras();
		double salario_final = getSalario() + this.total_horas_extras;
		zeraIndicadores();
		return salario_final;
	}
}
