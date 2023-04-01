package exB;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int hora, minuto, segundo;
		
		System.out.println("Informe horas, minutos e segundos respectivamente");
		hora = scan.nextInt();
		minuto = scan.nextInt();
		segundo = scan.nextInt();
		
		Tempo horas = new Tempo(hora, minuto, segundo);
		
		int opcao = -1;
		
		System.out.println("O que deseja?");
		System.out.println("1 - Mostrar hora HHSSMM");
		System.out.println("2 - Mostrar hora HH:SS:MM AM-PM");
		System.out.println("3 - Incrementar minutos");
		System.out.println("4 - Decrementar minutos");
		
		while(opcao != 0) {
			opcao = scan.nextInt();
			
			switch(opcao) {
				case 1:
					horas.mostraTempoHHMMSS();
					break;
				case 2:
					horas.mostraTempoAMPM();
					break;
				case 3:
					int incremento;
					System.out.println("Quantos minutos deseja incrementar?");
					incremento = scan.nextInt();
					horas.incrementaMinuto(incremento);
					System.out.print("Nova Hora:");
					horas.mostraTempoAMPM();
					break;
				case 4:
					int decremento;
					System.out.println("Quantos minutos deseja incrementar?");
					decremento = scan.nextInt();
					horas.decrementaMinuto(decremento);
					System.out.print("Nova Hora:");
					horas.mostraTempoAMPM();
			}
		}
		scan.close();
	}
}
