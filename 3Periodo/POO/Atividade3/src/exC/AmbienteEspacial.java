package exC;
import java.util.Scanner;
import java.util.Random;

public class AmbienteEspacial {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		Random rand = new Random();
		
		NaveEspacial n_v[] = new NaveEspacial[5];
		int vet_length = 0;
		String nomeNave;
		int velocidadeNave;
		
		int opcao = -1;
		
		while(opcao != 0) {
			System.out.println("Informe qual opcao deseja:");
            System.out.println("1 - Criar nova nave espacial.");
            System.out.println("2 - Exibir naves registradas.");
            System.out.println("3 - Parar nave.");
            System.out.println("4 - Ligar nave.");
            System.out.println("5 - Comparar naves.");
            opcao = scan.nextInt();
            
            switch(opcao) {
            case 1:
            	System.out.println("Informe o nome da nave espacial:");
            	nomeNave = scan.next();
            	velocidadeNave = rand.nextInt((10 - 5) + 1) + 5;         
            	n_v[vet_length] = new NaveEspacial(nomeNave, velocidadeNave);
            	vet_length++;
            	break;
            case 2:
            	if(vet_length == 0) {
            		System.out.println("Não há nenhuma nave registrada.");
            		break;
            	} else {
            		System.out.println("Naves registradas:");
                	for(int i = 0; i < vet_length; i++) {
                		n_v[i].mostrarNave();
                	}
                	break;
            	}
            case 3:
            	int count = 0;
            	int nave;
            	System.out.println("Naves em movimento:");
            	for(int i = 0; i < vet_length; i++) {
            		if(n_v[i].velocidade > 0) {
            			System.out.println("Nave " + (i + 1) + ":");
            			n_v[i].mostrarNave();
            			count++;
            		}
            	}
            	if(count == 0) {
            		System.out.println("Não há nenhuma nave ligada");
            		break;
            	}
            	System.out.println("Qual nave deseja parar?");
            	nave = scan.nextInt();
            	for(int i = 0; i < count; i++) {
            		if(nave == (i + 1)) {
            			n_v[i].paraNave();
            			System.out.println("Nave " + n_v[i].nome + " parada");
            		}
            	}
            	break;
            case 4:
            	int cont = 0;
            	int velocidade;
            	System.out.println("Naves paradas:");
            	for(int i = 0; i < vet_length; i++) {
            		if(n_v[i].velocidade == 0) {
            			System.out.println("Nave " + (i + 1) + ":");
            			n_v[i].mostrarNave();
            			cont++;
            		}
            	}
            	if(cont == 0) {
            		System.out.println("Não há nenhuma nave parada");
            		break;
            	}
            	if(cont >= 3) {
            		System.out.println("Superpopulação de Naves");
            		break;
            	} else {
            		System.out.println("Qual nave deseja ligar?");
                	nave = scan.nextInt();
                	System.out.println("Qual a velocidade?");
                	velocidade = scan.nextInt();
                	for(int i = 0; i < cont; i++) {
                		if(nave == (i + 1)) {
                			n_v[i].ligaNave(velocidade);
                			System.out.println("Nave " + n_v[i].nome + " ligada");
                		}
                	}
            	}
            	break;
            case 5:
            	if(vet_length == 0) {
            		System.out.println("Não há nenhuma nave registrada.");
            		break;
            	} else {
            		System.out.println("Naves registradas:");
                	for(int i = 0; i < vet_length; i++) {
                		System.out.println("Nave " + (i + 1) + ":");
                		n_v[i].mostrarNave();
                	}
                	System.out.println("Quais naves deseja comparar?");
                	int choise1 = scan.nextInt();
                	int choise2 = scan.nextInt();
                	for(int i = 0; i < vet_length; i++) {
                		if(choise1 == (i + 1)) {
                			n_v[i].naveMaisRapida(n_v[choise2 - 1]);
                			break;
                		}
                	}
            	}
            }
		}
		scan.close();
	}
}
