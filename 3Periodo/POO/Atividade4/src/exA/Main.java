package exA;
import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		
		Vendedor v_vet[] = new Vendedor[5];
		int qtd_v_vet = 0;
		Administrativo a_vet[] = new Administrativo[5];
		int qtd_a_vet = 0;
		
		String nome, rg;
		double salario_base;
		
		int opcao = -1;
		
		while(opcao != 0) {
			System.out.println("Informe qual opcao deseja");
			System.out.println("1 - Criar vendedor");
			System.out.println("2 - Adicionar venda");
			System.out.println("3 - Fechar salário final de vendedor");
			System.out.println("4 - Adicionar administrador");
			System.out.println("5 - Adicionar horas extras");
			System.out.println("6 - Fechar salário final de administrador");
			
			opcao = scan.nextInt();
			
			switch(opcao) {
			case 1:
				System.out.println("Informe o nome do vendedor:");
				nome = scan.next();
				System.out.println("Informe o rg do vendedor:");
				rg = scan.next();
				System.out.println("Informe o salário base do vendedor:");
				salario_base = scan.nextDouble();
				
				v_vet[qtd_v_vet] = new Vendedor(nome, rg, salario_base); 
				
				if(v_vet[qtd_v_vet] != null) {
					qtd_v_vet++;
					System.out.println("Vendedor criado com sucesso!");
					break;
				} else {
					System.out.println("ERRO: Algo não ocorreu como deveria, tente novamente.");
					break;
				}
				
			case 2:
				double valor_venda;
				int escolha;
				
				System.out.println("Informe qual vendedor deseja inserir uma venda:");
				for(int i = 0; i < qtd_v_vet; i++) {
					System.out.println("Vendedor " + (i + 1) + ": " + v_vet[i].getNome());
				}
				escolha = scan.nextInt();
				for(int i = 0; i < qtd_v_vet; i++) {
					if(escolha == (i + 1)) {
						System.out.println("Informe o valor da venda:");
						valor_venda = scan.nextDouble();
						v_vet[i].adicionaVenda(valor_venda);
						System.out.println("Venda adicionada com sucesso");
					}
				}
				break;
				
			case 3:
				System.out.println("Informe qual vendedor deseja fechar o salário:");
				for(int i = 0; i < qtd_v_vet; i++) {
					System.out.println("Vendedor " + (i + 1) + ": " + v_vet[i].getNome());
				}
				escolha = scan.nextInt();
				for(int i = 0; i < qtd_v_vet; i++) {
					if(escolha == (i + 1)) {
						System.out.println("Salário fechado no valor total de R$" + v_vet[i].calculaSalarioFinal());
					}
				}
				break;
				
			case 4:
				System.out.println("Informe o nome do administrativo:");
				nome = scan.next();
				System.out.println("Informe o rg do administrativo:");
				rg = scan.next();
				System.out.println("Informe o salário base do administrativo:");
				salario_base = scan.nextDouble();
				
				a_vet[qtd_a_vet] = new Administrativo(nome, rg, salario_base); 
				
				if(a_vet[qtd_a_vet] != null) {
					qtd_a_vet++;
					System.out.println("Administrativo criado com sucesso!");
					break;
				} else {
					System.out.println("ERRO: Algo não ocorreu como deveria, tente novamente.");
					break;
				}
				
			case 5:
				int hora_extra;
				
				System.out.println("Informe qual administrativo deseja inserir uma hora extra:");
				for(int i = 0; i < qtd_a_vet; i++) {
					System.out.println("Administrativo " + (i + 1) + ": " + a_vet[i].getNome());
				}
				escolha = scan.nextInt();
				for(int i = 0; i < qtd_a_vet; i++) {
					if(escolha == (i + 1)) {
						System.out.println("Informe quantas horas extras:");
						hora_extra = scan.nextInt();
						a_vet[i].adicionaHoraExtra(hora_extra);
						System.out.println("Horas extras adicionadas com sucesso");
					}
				}
				break;
				
			case 6:
				System.out.println("Informe qual administrativo deseja fechar o salário:");
				for(int i = 0; i < qtd_a_vet; i++) {
					System.out.println("Vendedor " + (i + 1) + ": " + a_vet[i].getNome());
				}
				escolha = scan.nextInt();
				for(int i = 0; i < qtd_a_vet; i++) {
					if(escolha == (i + 1)) {
						System.out.println("Salário fechado no valor total de R$" + a_vet[i].calculaSalarioFinal());
					}
				}
				break;
			}
		}
		
		scan.close();
	}
}
