package encapsulamento.exA.exC;
import java.util.Scanner;

public class Main {
	public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);
        float a, b, r;
        System.out.println("Informe os valores do ponto do centro do círculo: ");
        a = scan.nextFloat();
        b = scan.nextFloat();
        System.out.println("Informe o raio do círculo: ");
        r = scan.nextFloat();
        
        Circulo c = new Circulo(a, b, r);
        c.exibeDados();
	}
}