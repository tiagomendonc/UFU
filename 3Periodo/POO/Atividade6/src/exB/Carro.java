package exB;

public class Carro extends Veiculo {

    private String marca;
    private String modelo;
    private String cor;
    private int potencia;

    public Carro(String marca, String modelo, String cor, int potencia) {
        this.marca = marca;
        this.modelo = modelo;
        this.cor = cor;
        this.potencia = potencia;
    }

    @Override
    public String marca() {
        return marca;
    }

    @Override
    public String modelo() {
        return modelo;
    }

    @Override
    public String cor() {
        return cor;
    }

    @Override
    public int potencia() {
        return potencia;
    }
}
