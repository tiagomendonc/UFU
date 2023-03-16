package ex2;
import java.util.Scanner;

public class SomaDeDoisNumeros {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int num1, num2, soma;
		System.out.println("Informe o primeiro número: ");
		num1 = scan.nextInt();
		System.out.println("Informe o segundo número: ");
		num2 = scan.nextInt();
		soma = num1 + num2;
		System.out.println("A soma é: " + soma);
	}
}
