package entities;

import interfaces.Ave;

public class AdaptadorWrapperPavao implements Ave {
    private Pavao pavao;

    public AdaptadorWrapperPavao(Pavao pavao) {
        this.pavao = pavao;
    }

    @Override
    public void voar() {
        pavao.voar();
    }

    @Override
    public void emitirSom() {
        pavao.emitirSom();
    }
}

