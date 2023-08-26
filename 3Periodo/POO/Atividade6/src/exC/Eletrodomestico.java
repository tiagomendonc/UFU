package exC;

public class Eletrodomestico implements Produto {
    private int idEletro;
    private int anoEletro;
    private int unidadeEletro;
    private String categoriaEletro;
    private double precoEletro;

    public Eletrodomestico(int id, int anoProducao, int unidadeVenda, double preco) {
        this.idEletro = id;
        this.anoEletro = anoProducao;
        this.unidadeEletro = unidadeVenda;
        this.precoEletro = preco;
        this.categoriaEletro = "Eletrodoméstico";
    }

    @Override
    public int getId() {
        return idEletro;
    }

    @Override
    public int getAnoProducao() {
        return anoEletro;
    }

    @Override
    public int getUnidadeVenda() {
        return unidadeEletro;
    }

    @Override
    public String getCategoria() {
        return categoriaEletro;
    }

    @Override
    public double getPreco() {
        return precoEletro;
    }
}