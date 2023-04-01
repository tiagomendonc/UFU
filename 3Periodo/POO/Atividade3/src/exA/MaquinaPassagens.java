package exA;

public class MaquinaPassagens {
	private int preco, quantidadeInserida, total;
    
    public MaquinaPassagens() {
        preco = 2;
        quantidadeInserida = 0;
        total = 0;
    }
    
    public void Deposito(int a) {
        if(a == 1 || a == 2) {
            quantidadeInserida += a;
            total += a;
        } else {
            System.out.println("Nota inválida! Insira apenas notas de R$1,00 ou R$2,00");
        }
    }
    
    public void Emissao() {
        if(quantidadeInserida % preco == 0) {
            quantidadeInserida -= preco ;
            System.out.printf("Foi emitida sua passagen.\n");
        } else {
            System.out.println("Falta R$1,00 para a finalização da compra");
        }
    } 
}
