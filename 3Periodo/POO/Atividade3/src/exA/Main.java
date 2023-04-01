package exA;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int deposito;
	        
	    Scanner sc = new Scanner(System.in);
	    System.out.println("--------Systema de Passagens-------");
	    System.out.println("Valor a ser depositado");
	    deposito = sc.nextInt();
	        
	    MaquinaPassagens maquina = new MaquinaPassagens();
	    maquina.Deposito(deposito);
	    maquina.Emissao();
	       
	    sc.close();
	}
}
