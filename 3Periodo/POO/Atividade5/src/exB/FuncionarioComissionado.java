package exB;

public class FuncionarioComissionado extends Funcionario {
	int num_vendas, comissao_por_venda;
	
	public FuncionarioComissionado(String nome, String cpf, int matricula, int idade, double salario_base, int num_vendas, int comissao_por_venda) {
		super(nome, cpf, matricula,idade, salario_base);
		this.num_vendas = num_vendas;
		this.comissao_por_venda = comissao_por_venda;
	}
	
	
}
