package exE;
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        GestaoContatos gestaoContatos = new GestaoContatos();
        Scanner scanner = new Scanner(System.in);

        int opcao = 0;

        while (opcao != 6) {
            System.out.println("\n===== MENU =====");
            System.out.println("1. Adicionar contato");
            System.out.println("2. Remover contato");
            System.out.println("3. Listar contatos de familiares");
            System.out.println("4. Listar contatos de amigos");
            System.out.println("5. Listar contatos profissionais");
            System.out.println("6. Sair");
            System.out.print("Digite a opção desejada: ");
            opcao = Integer.parseInt(scanner.nextLine());

            switch (opcao) {
                case 1:
                    System.out.println("\n===== ADICIONAR CONTATO =====");
                    System.out.print("Nome: ");
                    String nome = scanner.nextLine();
                    System.out.print("Idade: ");
                    int idade = Integer.parseInt(scanner.nextLine());
                    System.out.print("Sexo: ");
                    String sexo = scanner.nextLine();
                    System.out.print("Profissão: ");
                    String profissao = scanner.nextLine();
                    System.out.print("Telefone: ");
                    String telefone = scanner.nextLine();
                    System.out.print("Email: ");
                    String email = scanner.nextLine();

                    Contato novoContato = new Contato(nome, idade, sexo, profissao, telefone, email);

                    System.out.println("Escolha a lista para adicionar o contato:");
                    System.out.println("1. Familiar");
                    System.out.println("2. Amigo");
                    System.out.println("3. Profissional");
                    System.out.print("Digite a opção desejada: ");
                    int opcaoLista = Integer.parseInt(scanner.nextLine());

                    switch (opcaoLista) {
                        case 1:
                            gestaoContatos.adicionaContato(novoContato, gestaoContatos.getFamilia());
                            break;
                        case 2:
                            gestaoContatos.adicionaContato(novoContato, gestaoContatos.getAmigos());
                            break;
                        case 3:
                            gestaoContatos.adicionaContato(novoContato, gestaoContatos.getProfissional());
                            break;
                        default:
                            System.out.println("Opção inválida.");
                    }

                    System.out.println("Contato adicionado com sucesso!");
                    break;
                case 2:
                    System.out.println("\n===== REMOVER CONTATO =====");
                    System.out.print("Digite o nome do contato a ser removido: ");
                    String nomeRemover = scanner.nextLine();

                    try {
                        gestaoContatos.eliminaContato(nomeRemover, gestaoContatos.getFamilia());
                        System.out.println("Contato removido da lista de familiares.");
                    } catch (ContatoNaoEncontradoException e1) {
                        try {
                            gestaoContatos.eliminaContato(nomeRemover, gestaoContatos.getAmigos());
                            System.out.println("Contato removido da lista de amigos.");
                        } catch (ContatoNaoEncontradoException e2) {
                            try {
                                gestaoContatos.eliminaContato(nomeRemover, gestaoContatos.getProfissional());
                                System.out.println("Contato removido da lista de profissionais.");
                            } catch (ContatoNaoEncontradoException e3) {
                                System.out.println(e3.getMessage());
                            }
                        }
                    }
                    break;
                case 3:
                    System.out.println("\n===== LISTA DE FAMILIARES =====");
                    gestaoContatos.listaContatos(gestaoContatos.getFamilia());
                    break;
                case 4:
                    System.out.println("\n===== LISTA DE AMIGOS =====");
                    gestaoContatos.listaContatos(gestaoContatos.getAmigos());
                    break;
                case 5:
                    System.out.println("\n===== LISTA DE CONTATOS PROFISSIONAIS =====");
                    gestaoContatos.listaContatos(gestaoContatos.getProfissional());
                    break;
                case 6:
                    System.out.println("Saindo...");
                    break;
                default:
                    System.out.println("Opção inválida.");
            }
        }

        try {
            FileOutputStream fileOut = new FileOutputStream("contatos.ser");
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(gestaoContatos);
            out.close();
            fileOut.close();
            System.out.println("As informações foram salvas no arquivo contatos.ser");
        } catch (IOException e) {
            System.out.println("Erro ao salvar as informações em arquivo: " + e.getMessage());
        }

        try {
            FileInputStream fileIn = new FileInputStream("contatos.ser");
            ObjectInputStream in = new ObjectInputStream(fileIn);
            gestaoContatos = (GestaoContatos) in.readObject();
            in.close();
            fileIn.close();
            System.out.println("As informações foram carregadas do arquivo contatos.ser");
        } catch (IOException e) {
            System.out.println("Erro ao carregar as informações do arquivo: " + e.getMessage());
        } catch (ClassNotFoundException e) {
            System.out.println("Classe não encontrada: " + e.getMessage());
        }
    }
}
