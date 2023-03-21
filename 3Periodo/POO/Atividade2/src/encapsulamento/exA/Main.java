package encapsulamento.exA;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        float a, b;
        System.out.println("Informe os valores dos ponto:");
        a = scan.nextFloat();
        b = scan.nextFloat();
        Ponto p1 = new Ponto(a,b);
        System.out.println("Informe os valores do segundo ponto:");
        a = scan.nextFloat();
        b = scan.nextFloat();
        Ponto p2 = new Ponto(a,b);
        System.out.println("A distância entre os pontos é: " + p1.Distancia(p1, p2));
    }
}
