package entities;

import interfaces.*;

public class OperacoesVisitor implements Visitor {
	@Override
    public void visit(Carro carro) {
        System.out.println("Dados do Carro: Cor - " + carro.cor + ", Marca - " + carro.marca + ", Modelo - " + carro.modelo);
        System.out.println("Mensagem para o dono: favor atualizar dados do IPVA");
    }

    @Override
    public void visit(Onibus onibus) {
        System.out.println("Dados do Ônibus: Lugares - " + onibus.lugares + ", Ano de Fabricação - " + onibus.anoFabricacao);
        System.out.println("Mensagem para o dono: atenção para atualização das licenças");
    }

    @Override
    public void visit(Bicicleta bicicleta) {
        System.out.println("Dados da Bicicleta: Cor - " + bicicleta.cor);
        System.out.println("Mensagem para o dono: comemore no parque o dia do ciclismo");
    }
}
