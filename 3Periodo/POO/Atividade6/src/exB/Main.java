package exB;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Veiculo[] veiculos = new Veiculo[5];

        for (int i = 0; i < veiculos.length; i++) {
            System.out.println("Insira as informações do veículo " + (i+1) + ":");
            System.out.print("Marca: ");
            String marca = sc.nextLine();
            System.out.print("Modelo: ");
            String modelo = sc.nextLine();
            System.out.print("Cor: ");
            String cor = sc.nextLine();
            System.out.print("Potência: ");
            int potencia = sc.nextInt();
            sc.nextLine(); 
            System.out.println(); 
            if (i < veiculos.length-1) {
                System.out.println("Insira as informações do próximo veículo:");
            }
            veiculos[i] = new Carro(marca, modelo, cor, potencia);
        }

        String marcaMaisPotente = "";
        String marcaMenosPotente = "";
        int potenciaMaisPotente = 0;
        int potenciaMenosPotente = Integer.MAX_VALUE;
        int i = 0;
        while (i < veiculos.length) {
            Veiculo veiculo = veiculos[i];
            if (veiculo.cor().equals("Vermelho")) {
                int potencia = veiculo.potencia();
                if (potencia > potenciaMaisPotente) {
                    potenciaMaisPotente = potencia;
                    marcaMaisPotente = veiculo.marca();
                }
                if (potencia < potenciaMenosPotente) {
                    potenciaMenosPotente = potencia;
                    marcaMenosPotente = veiculo.marca();
                }
            }
            i++;
        }

        System.out.println("Marca mais potente: " + marcaMaisPotente);
        System.out.println("Marca menos potente: " + marcaMenosPotente);
        sc.close();
    }
}
