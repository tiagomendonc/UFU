package ex4;

public class Ponto {
	double x, y;
	
	public Ponto(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
	public double distanciaEuclidiana(Ponto p1, Ponto p2) {
		double distancia;
		distancia = Math.sqrt(Math.pow((p2.x - p1.x), 2) + Math.pow((p2.y - p1.y), 2));
		return distancia;
	}
}
