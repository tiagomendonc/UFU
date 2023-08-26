package exB;

class Empregado {
    private String cpf;
    private int idade;
    private double salario;

    public Empregado(String cpf, int idade, double salario) {
        this.cpf = cpf;
        this.idade = idade;
        this.salario = salario;
    }

    public String getCpf() {
        return cpf;
    }

    public int getIdade() {
        return idade;
    }

    public double getSalario() {
        return salario;
    }
}