package ex4;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner (System.in);
		double a, b;
		System.out.println("Informe os valores do primeiro ponto:");
		a = scan.nextDouble();
		b = scan.nextDouble();
		Ponto p1 = new Ponto(a, b);
		System.out.println("Informe os valores do segundo ponto:");
		a = scan.nextDouble();
		b = scan.nextDouble();
		Ponto p2 = new Ponto(a, b);
		
		System.out.println("A distância entre os pontos é: " + p1.distanciaEuclidiana(p1, p2));
	}
}
