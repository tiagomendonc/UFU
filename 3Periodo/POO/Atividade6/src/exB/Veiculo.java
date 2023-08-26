package exB;

public abstract class Veiculo {

    public abstract String marca();
    
    public abstract String modelo();
    
    public abstract String cor();
    
    public abstract int potencia();
    
    public void mostraDados() {
        System.out.println("Marca: " + marca());
        System.out.println("Modelo: " + modelo());
        System.out.println("Cor: " + cor());
        System.out.println("Potência: " + potencia());
    }
}