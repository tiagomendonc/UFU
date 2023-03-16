package ex3;
import java.util.Scanner;

public class Main {
	static int MAX = 10;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Triangulo t_vet[] = new Triangulo[MAX];
		for(int i = 0; i < MAX; i++) {
			t_vet[i] = new Triangulo();
		}
		int v_length = 0;
		
		int opcao = -1;
		
		while(opcao != 0) {
			System.out.println("Escolha uma opção:");
			System.out.println("1 - Inserir triângulo");
			System.out.println("2 - Mostrar triângulos cadastrados");
			System.out.println("3 - Mostrar número de triângulos equiláteros");
			System.out.println("4 - Monstrar o triângulo com maior perímetro");
			System.out.print("Opção: ");
			opcao = scan.nextInt();
			System.out.println();
			switch(opcao) {
				case 1:
					if(v_length == (MAX - 1)) {
						System.out.println("Ação impossível, o vetor está cheio.");
						System.out.println();
					} else {
						t_vet[v_length].insereL1(t_vet[v_length].l1);
						t_vet[v_length].insereL2(t_vet[v_length].l2);
						t_vet[v_length].insereL3(t_vet[v_length].l3);
						v_length++;
					}		
					break;
				case 2:
						for(int n = 0; n < v_length; n++) {
							System.out.println("Triângulo " + n + 1 + ":");
							System.out.println("Lados: " + t_vet[n].l1 + " " + t_vet[n].l2 + " " + t_vet[n].l3);
							System.out.println();
						}
						break;
				case 3:
						int count = 0;
						for(int n = 0; n < v_length; n++) {
							if(t_vet[n].ehEquilatero(t_vet[n].l1, t_vet[n].l2, t_vet[n].l3) == true) {
								count++;
							}
						}
						System.out.println("O vetor atualmente tem " + count + " triângulos equiláteros.");
						System.out.println();
						break;
				case 4:
						Triangulo maior = new Triangulo();
						for(int n = 0; n < v_length; n++) {
							if(n == 0) {
								maior = t_vet[0];
							} else if(t_vet[n].perimetro(t_vet[n].l1, t_vet[n].l2, t_vet[n].l3) > maior.perimetro(maior.l1, maior.l2, maior.l3)){
								maior = t_vet[n];
							}
						}
						System.out.println("O maior triângulo tem perímetro de " + maior.perimetro(maior.l1, maior.l2, maior.l3));
						System.out.println();
						break;
					default:
						System.out.println("Encerrando...");
						System.out.println();
						break;
			}
		}
	}
}