package exA;

class Empregado implements Comparable<Empregado> {
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

    @Override
    public int compareTo(Empregado outroEmpregado) {
        if (this.idade > outroEmpregado.getIdade()) {
            return 1;
        } else if (this.idade < outroEmpregado.getIdade()) {
            return -1;
        } else {
            return 0;
        }
    }
}
