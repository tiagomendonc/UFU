package ex3;
import java.util.Scanner;

public class Triangulo {
	Scanner scan = new Scanner(System.in);
	
	float l1, l2, l3;
	
	public void insereL1(float l1) {
		System.out.println("Informe o novo valor: ");
		this.l1 = scan.nextFloat();
		System.out.println("Valor alterado!");
	}
	
	public void insereL2(float l2) {
		System.out.println("Informe o novo valor: ");
		this.l2 = scan.nextFloat();
		System.out.println("Valor alterado!");
	}
	
	public void insereL3(float l3) {
		System.out.println("Informe o novo valor: ");
		this.l3 = scan.nextFloat();
		System.out.println("Valor alterado!");
	}
	
	public void tipoTriangulo(float l1, float l2, float l3) {
		if(((l1 - l2) == 0) && ((l2 - l3) == 0)) {
			System.out.println("O triângulo é equilátero.");
		} else if (((l1 - l2) == 0) || ((l2 - l3) == 0) || ((l1 - l3) == 0)) {
			System.out.println("O triângulo é isósceles.");
		} else {
			System.out.println("O triângulo é escaleno.");
		}
	}
	
	public boolean ehEquilatero(float l1, float l2, float l3) {
		if(((l1 - l2) == 0) && ((l2 - l3) == 0)) {
			return true;
		} else {
			return false;
		}
	}
	
	public float perimetro(float l1, float l2, float l3) {
		float perimetro = l1 + l2 + l3;
		return perimetro;
	}
}
