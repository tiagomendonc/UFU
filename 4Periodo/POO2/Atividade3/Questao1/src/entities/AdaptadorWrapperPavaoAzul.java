package entities;

import interfaces.Ave;

public class AdaptadorWrapperPavaoAzul implements Ave {
    private PavaoAzul pavaoAzul;

    public AdaptadorWrapperPavaoAzul(PavaoAzul pavaoAzul) {
        this.pavaoAzul = pavaoAzul;
    }

    @Override
    public void voar() {
        pavaoAzul.voar();
    }

    @Override
    public void emitirSom() {
        pavaoAzul.emitirSom();
    }
}
