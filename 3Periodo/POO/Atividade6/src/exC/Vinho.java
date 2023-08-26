package exC;

public class Vinho implements Produto {
    private int id;
    private int anoProducao;
    private int unidadeVenda;
    private String categoria;
    private double preco;

    public Vinho(int id, int anoProducao, int unidadeVenda, double preco) {
        this.id = id;
        this.anoProducao = anoProducao;
        this.unidadeVenda = unidadeVenda;
        this.preco = preco;
        this.categoria = "Vinho";
    }

    @Override
    public int getId() {
        return id;
    }

    @Override
    public int getAnoProducao() {
        return anoProducao;
    }

    @Override
    public int getUnidadeVenda() {
        return unidadeVenda;
    }

    @Override
    public String getCategoria() {
        return categoria;
    }

    @Override
    public double getPreco() {
        return preco;
    }
}
