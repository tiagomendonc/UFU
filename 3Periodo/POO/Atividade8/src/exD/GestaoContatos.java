package exD;
import java.util.List;
import java.util.ArrayList;
import java.io.*;

class GestaoContatos implements Serializable {
    private List<Contato> familia;
    private List<Contato> amigos;
    private List<Contato> profissional;

    public List<Contato> getFamilia() {
		return familia;
	}

	public void setFamilia(List<Contato> familia) {
		this.familia = familia;
	}

	public List<Contato> getAmigos() {
		return amigos;
	}

	public void setAmigos(List<Contato> amigos) {
		this.amigos = amigos;
	}

	public List<Contato> getProfissional() {
		return profissional;
	}

	public void setProfissional(List<Contato> profissional) {
		this.profissional = profissional;
	}

	public GestaoContatos() {
        familia = new ArrayList<>();
        amigos = new ArrayList<>();
        profissional = new ArrayList<>();
    }

    public void adicionaContato(Contato contato, List<Contato> listaContatos) {
        listaContatos.add(contato);
    }

    public void eliminaContato(String nome, List<Contato> listaContatos) throws ContatoNaoEncontradoException {
        boolean contatoEncontrado = false;

        for (Contato contato : listaContatos) {
            if (contato.getNome().equalsIgnoreCase(nome)) {
                listaContatos.remove(contato);
                contatoEncontrado = true;
                break;
            }
        }

        if (!contatoEncontrado) {
            throw new ContatoNaoEncontradoException("Contato não encontrado: " + nome);
        }
    }

    public void listaContatos(List<Contato> listaContatos) {
        for (Contato contato : listaContatos) {
            System.out.println(contato.toString());
        }
    }

    public Contato maisVelho(List<Contato> listaContatos) {
        Contato maisVelho = null;
        int idadeMaxima = Integer.MIN_VALUE;

        for (Contato contato : listaContatos) {
            if (contato.getIdade() > idadeMaxima) {
                idadeMaxima = contato.getIdade();
                maisVelho = contato;
            }
        }

        return maisVelho;
    }

    public Contato maisNovo(List<Contato> listaContatos) {
        Contato maisNovo = null;
        int idadeMinima = Integer.MAX_VALUE;

        for (Contato contato : listaContatos) {
            if (contato.getIdade() < idadeMinima) {
                idadeMinima = contato.getIdade();
                maisNovo = contato;
            }
        }

        return maisNovo;
    }
}

