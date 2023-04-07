package exB;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		Dvd dvd_vet[] = new Dvd[5];
		int qtd_dvd_vet = 0;
		Cd cd_vet[] = new Cd[5];
		int qtd_cd_vet = 0;
		Vhs vhs_vet[] = new Vhs[5];
		int qtd_vhs_vet = 0;
		
		String nome, tipo, genero, atores, diretor, cantor;
		double preco;
		int tempo_de_duracao_min, num_faixas;
		boolean is_rebobinada;
		
		int opcao = -1;
		
		while(opcao != 0) {
			System.out.println("Escolha uma opção:");
			System.out.println("1 - Adicionar DVD");
			System.out.println("2 - Fechar locação DVDs");
			System.out.println("3 - Adicionar CD");
			System.out.println("4 - Fechar locação CDs");
			System.out.println("5 - Adicionar VHS");
			System.out.println("6 - Fechar locação VHSs");
			
			opcao = scan.nextInt();
			
			switch(opcao) {
				case 1:
					System.out.println("Informe respectivamente: nome, tipo, genero, atores, diretor, preco, tempo de duração(em min)");
					nome = scan.next();
					tipo = scan.next();
					genero = scan.next();
					atores = scan.next();
					diretor = scan.next();
					preco = scan.nextDouble();
					tempo_de_duracao_min = scan.nextInt();
					
					dvd_vet[qtd_dvd_vet] = new Dvd(nome, tipo, genero, preco, atores, diretor, tempo_de_duracao_min);
					System.out.println("DVD adicionado com sucesso");
					qtd_dvd_vet++;
					break;
					
				case 2:
					double preco_total = 0;
					for(int i = 0; i < qtd_dvd_vet; i++) {
						preco_total += dvd_vet[i].getPreco();
					}
					System.out.println("Valor total: R$" + preco_total);
					break;
					
				case 3:
					System.out.println("Informe respectivamente: nome, tipo, genero, preco, cantor, número de faixas.");
					nome = scan.next();
					tipo = scan.next();
					genero = scan.next();
					cantor = scan.next();
					preco = scan.nextDouble();
					num_faixas = scan.nextInt();
					
					cd_vet[qtd_cd_vet] = new Cd(nome, tipo, genero, preco, cantor, num_faixas);
					System.out.println("CD adicionado com sucesso");
					qtd_cd_vet++;
					break;
					
				case 4:
					double preco_final = 0;
					for(int i = 0; i < qtd_cd_vet; i++) {
						preco_final += cd_vet[i].getPreco();
					}
					System.out.println("Valor total: R$" + preco_final);
					break;
					
				case 5:
					System.out.println("Informe respectivamente: nome, tipo, genero, preco, se é rebobinada");
					nome = scan.next();
					tipo = scan.next();
					genero = scan.next();
					preco = scan.nextDouble();
					is_rebobinada = scan.nextBoolean();
					
					vhs_vet[qtd_vhs_vet] = new Vhs(nome, tipo, genero, preco, is_rebobinada);
					System.out.println("VHS adicionada com sucesso");
					qtd_vhs_vet++;
					break;
					
				case 6:
					double preco_f = 0;
					for(int i = 0; i < qtd_vhs_vet; i++) {
						preco_f += vhs_vet[i].getPreco();
					}
					System.out.println("Valor total: R$" + preco_f);
					break;
			}
		}
		
		scan.close();
	}
}
