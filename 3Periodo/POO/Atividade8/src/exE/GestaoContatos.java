package exE;
import java.io.*;
import java.util.*;

class GestaoContatos implements Serializable {
    private Map<String, Contato> familia;
    private Map<String, Contato> amigos;
    private Map<String, Contato> profissional;

    public GestaoContatos() {
        familia = new HashMap<>();
        amigos = new HashMap<>();
        profissional = new HashMap<>();
    }

    public void adicionaContato(Contato contato, Map<String, Contato> mapaContatos) {
        mapaContatos.put(contato.getNome(), contato);
    }

    public void eliminaContato(String nome, Map<String, Contato> mapaContatos) throws ContatoNaoEncontradoException {
        if (mapaContatos.remove(nome) == null) {
            throw new ContatoNaoEncontradoException("Contato não encontrado: " + nome);
        }
    }

    public void listaContatos(Map<String, Contato> mapaContatos) {
        for (Contato contato : mapaContatos.values()) {
            System.out.println(contato.toString());
        }
    }

    public Contato maisVelho(Map<String, Contato> mapaContatos) {
        Contato maisVelho = null;
        int idadeMaxima = Integer.MIN_VALUE;

        for (Contato contato : mapaContatos.values()) {
            if (contato.getIdade() > idadeMaxima) {
                idadeMaxima = contato.getIdade();
                maisVelho = contato;
            }
        }

        return maisVelho;
    }

    public Contato maisNovo(Map<String, Contato> mapaContatos) {
        Contato maisNovo = null;
        int idadeMinima = Integer.MAX_VALUE;

        for (Contato contato : mapaContatos.values()) {
            if (contato.getIdade() < idadeMinima) {
                idadeMinima = contato.getIdade();
                maisNovo = contato;
            }
        }

        return maisNovo;
    }

    public Map<String, Contato> getFamilia() {
        return familia;
    }

    public Map<String, Contato> getAmigos() {
        return amigos;
    }

    public Map<String, Contato> getProfissional() {
        return profissional;
    }
}

