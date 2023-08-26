package exA;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class CadastroProgram {
    private JFrame frame;
    private JFrame preencherDadosFrame;
    private JComboBox<String> cpfComboBox;
    private List<Usuario> usuarios;

    public void initialize() {
        frame = new JFrame();
        frame.setTitle("Cadastro de Usuários");
        frame.setSize(300, 150);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new FlowLayout());

        JButton preencherDadosButton = new JButton("Preencher Dados");
        preencherDadosButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                abrirPreencherDados();
            }
        });
        frame.add(preencherDadosButton);

        JButton visualizarDadosButton = new JButton("Visualizar Dados");
        visualizarDadosButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                abrirVisualizarDados();
            }
        });
        frame.add(visualizarDadosButton);

        frame.setVisible(true);

        usuarios = new ArrayList<>();
    }

    private void abrirPreencherDados() {
        preencherDadosFrame = new JFrame();
        preencherDadosFrame.setTitle("Preencher Dados");
        preencherDadosFrame.setSize(400, 300);
        preencherDadosFrame.setLayout(new GridLayout(9, 2));

        JLabel nomeLabel = new JLabel("Nome:");
        JTextField nomeField = new JTextField();
        JLabel cpfLabel = new JLabel("CPF:");
        JTextField cpfField = new JTextField();
        JLabel dataNascimentoLabel = new JLabel("Data de Nascimento:");
        JTextField dataNascimentoField = new JTextField();
        JLabel sexoLabel = new JLabel("Sexo:");
        JComboBox<String> sexoComboBox = new JComboBox<>(new String[]{"Masculino", "Feminino", "Outro"});
        JLabel contaLabel = new JLabel("Número da Conta:");
        JTextField contaField = new JTextField();
        JLabel senhaLabel = new JLabel("Senha:");
        JPasswordField senhaField = new JPasswordField();
        JLabel emailLabel = new JLabel("Email:");
        JTextField emailField = new JTextField();
        JCheckBox noticiasCheckbox = new JCheckBox("Desejo receber notícias");

        JButton salvarButton = new JButton("Salvar");
        salvarButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (validarCampos(nomeField, cpfField, contaField)) {
                    Usuario usuario = new Usuario(
                            nomeField.getText(),
                            cpfField.getText(),
                            dataNascimentoField.getText(),
                            sexoComboBox.getSelectedItem().toString(),
                            contaField.getText(),
                            new String(senhaField.getPassword()),
                            emailField.getText(),
                            noticiasCheckbox.isSelected()
                    );
                    usuarios.add(usuario);
                    salvarDados();
                    preencherDadosFrame.dispose();
                } else {
                    exibirMensagemErro("Preencha todos os campos corretamente.");
                }
            }
        });

        JButton cancelarButton = new JButton("Cancelar");
        cancelarButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                preencherDadosFrame.dispose();
            }
        });

        preencherDadosFrame.add(nomeLabel);
        preencherDadosFrame.add(nomeField);
        preencherDadosFrame.add(cpfLabel);
        preencherDadosFrame.add(cpfField);
        preencherDadosFrame.add(dataNascimentoLabel);
        preencherDadosFrame.add(dataNascimentoField);
        preencherDadosFrame.add(sexoLabel);
        preencherDadosFrame.add(sexoComboBox);
        preencherDadosFrame.add(contaLabel);
        preencherDadosFrame.add(contaField);
        preencherDadosFrame.add(senhaLabel);
        preencherDadosFrame.add(senhaField);
        preencherDadosFrame.add(emailLabel);
        preencherDadosFrame.add(emailField);
        preencherDadosFrame.add(noticiasCheckbox);
        preencherDadosFrame.add(salvarButton);
        preencherDadosFrame.add(cancelarButton);

        preencherDadosFrame.setVisible(true);
    }

    private boolean validarCampos(JTextField nomeField, JTextField cpfField, JTextField contaField) {
        return !nomeField.getText().isEmpty() &&
                !cpfField.getText().isEmpty() &&
                isNumeric(cpfField.getText()) &&
                !contaField.getText().isEmpty() &&
                isNumeric(contaField.getText());
    }

    private boolean isNumeric(String str) {
        return str.matches("\\d+");
    }

    private void exibirMensagemErro(String mensagem) {
        JOptionPane.showMessageDialog(frame, mensagem, "Erro", JOptionPane.ERROR_MESSAGE);
    }

    private void salvarDados() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("dados.txt"))) {
            for (Usuario usuario : usuarios) {
                writer.write(usuario.toString());
                writer.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void abrirVisualizarDados() {
        JFrame visualizarDadosFrame = new JFrame();
        visualizarDadosFrame.setTitle("Visualizar Dados");
        visualizarDadosFrame.setSize(300, 150);
        visualizarDadosFrame.setLayout(new FlowLayout());

        cpfComboBox = new JComboBox<>();
        for (Usuario usuario : usuarios) {
            cpfComboBox.addItem(usuario.getCpf());
        }

        JButton selecionarButton = new JButton("Selecionar");
        selecionarButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String cpfSelecionado = cpfComboBox.getSelectedItem().toString();
                Usuario usuarioSelecionado = null;
                for (Usuario usuario : usuarios) {
                    if (usuario.getCpf().equals(cpfSelecionado)) {
                        usuarioSelecionado = usuario;
                        break;
                    }
                }
                if (usuarioSelecionado != null) {
                    abrirPreencherDados(usuarioSelecionado);
                }
            }
        });

        visualizarDadosFrame.add(cpfComboBox);
        visualizarDadosFrame.add(selecionarButton);

        visualizarDadosFrame.setVisible(true);
    }

    private void abrirPreencherDados(Usuario usuario) {
        abrirPreencherDados();
        JTextField nomeField = (JTextField) preencherDadosFrame.getContentPane().getComponent(1);
        JTextField cpfField = (JTextField) preencherDadosFrame.getContentPane().getComponent(3);
        JTextField dataNascimentoField = (JTextField) preencherDadosFrame.getContentPane().getComponent(5);
        JComboBox<String> sexoComboBox = (JComboBox<String>) preencherDadosFrame.getContentPane().getComponent(7);
        JTextField contaField = (JTextField) preencherDadosFrame.getContentPane().getComponent(9);
        JPasswordField senhaField = (JPasswordField) preencherDadosFrame.getContentPane().getComponent(11);
        JTextField emailField = (JTextField) preencherDadosFrame.getContentPane().getComponent(13);
        JCheckBox noticiasCheckbox = (JCheckBox) preencherDadosFrame.getContentPane().getComponent(15);

        nomeField.setText(usuario.getNome());
        cpfField.setText(usuario.getCpf());
        dataNascimentoField.setText(usuario.getDataNascimento());
        sexoComboBox.setSelectedItem(usuario.getSexo());
        contaField.setText(usuario.getConta());
        senhaField.setText(usuario.getSenha());
        emailField.setText(usuario.getEmail());
        noticiasCheckbox.setSelected(usuario.isReceberNoticias());
    }

    private class Usuario {
        private String nome;
        private String cpf;
        private String dataNascimento;
        private String sexo;
        private String conta;
        private String senha;
        private String email;
        private boolean receberNoticias;

        public Usuario(String nome, String cpf, String dataNascimento, String sexo, String conta, String senha, String email, boolean receberNoticias) {
            this.nome = nome;
            this.cpf = cpf;
            this.dataNascimento = dataNascimento;
            this.sexo = sexo;
            this.conta = conta;
            this.senha = senha;
            this.email = email;
            this.receberNoticias = receberNoticias;
        }

        public String getNome() {
            return nome;
        }

        public String getCpf() {
            return cpf;
        }

        public String getDataNascimento() {
            return dataNascimento;
        }

        public String getSexo() {
            return sexo;
        }

        public String getConta() {
            return conta;
        }

        public String getSenha() {
            return senha;
        }

        public String getEmail() {
            return email;
        }

        public boolean isReceberNoticias() {
            return receberNoticias;
        }

        @Override
        public String toString() {
            return nome + ";" + cpf + ";" + dataNascimento + ";" + sexo + ";" + conta + ";" + senha + ";" + email + ";" + receberNoticias;
        }
    }
}
