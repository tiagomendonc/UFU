package encapsulamento.exA.exC;
import encapsulamento.exA.Ponto;

public class Circulo {
    private float raio;
    float x, y;
    Ponto centro = new Ponto(x , y);
    
    public Circulo(float x, float y, float raio){
        this.raio = raio;
        this.x = x;
        this.y = y;
    }
    
    public void setRaio(float r) {
        raio = r;
    }
    
    public float getRaio() {
        return raio;
    }
    
    public float Diametro() {
        return (float) this.raio * 2;
    }
    
    public double Area() {
        return Math.pow(this.raio, 2) * 3.14;
    }
    
    public double Perimetro() {
        return 2*3.14*this.raio;
    }
    
    public void exibeDados() {
        System.out.println("Dados do círculo de raio " + getRaio());
        System.out.println("Diâmetro      : " + Diametro());
        System.out.println("Circunferência: " + Perimetro());
        System.out.println("Área          : " + Area());
    }
}
