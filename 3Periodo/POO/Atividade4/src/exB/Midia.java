package exB;

public class Midia {
	String nome, tipo, genero;
	double preco;
	
	public Midia(String nome, String tipo, String genero, double preco) {
		this.nome = nome;
		this.tipo = tipo;
		this.genero = genero;
		this.preco = preco;
	}
	
	public String getNome() {
		return nome;
	}
	
	public String getTipo() {
		return tipo;
	}
	
	public String getGenero() {
		return genero;
	}
	
	public double getPreco() {
		return preco;
	}
}

class Dvd extends Midia {
	String atores, diretor;
	int tempo_de_duracao_min;
	
	public Dvd(String nome, String tipo, String genero, double preco, String atores, String diretor, int tempo_de_duracao_min) {
		super(nome, tipo, genero, preco);
		this.atores = atores;
		this.diretor = diretor;
		this.tempo_de_duracao_min = tempo_de_duracao_min;
	}
}

class Cd extends Midia {
	String cantor;
	int num_faixas;
	
	public Cd(String nome, String tipo, String genero, double preco, String cantor, int num_faixas) {
		super(nome, tipo, genero, preco);
		this.cantor = cantor;
		this.num_faixas = num_faixas;
	}
}

class Vhs extends Midia {
	boolean is_rebobinada;
	
	public Vhs(String nome, String tipo, String genero, double preco, boolean is_rebobinada) {
		super(nome, tipo, genero, preco);
		this.is_rebobinada = is_rebobinada;
	}
}
