package exC;

public class NaveEspacial {
	String nome;
	int velocidade;
	
	public NaveEspacial(String nome, int velocidade) {
		this.nome = nome;
		this.velocidade = velocidade;
	}
	
	public void mostrarNave() {
		if(velocidade > 0) {
			System.out.println("Nave: " + nome);
			System.out.println("Velocidade: " + velocidade + " km/h");
		} else {
			System.out.println("Nave inoperante");
		}
	}
	
	public void paraNave() {
		velocidade = 0;
	}
	
	public void ligaNave(int velocidade) {
		this.velocidade = velocidade;
	}
	
	public void naveMaisRapida(NaveEspacial n) {
		if(this.velocidade < n.velocidade) {
			System.out.println("A nave mais rápida é a " + n.nome + " com " + n.velocidade + " km/h");
		} else {
			System.out.println("A nave mais rápida é a " + this.nome + " com " + this.velocidade + " km/h");
		}
	}
}
