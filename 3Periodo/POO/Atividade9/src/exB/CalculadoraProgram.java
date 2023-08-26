package exB;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class CalculadoraProgram {
    private JFrame frame;
    private List<Integer> numeros;

    public void initialize() {
        frame = new JFrame();
        frame.setTitle("Calculadora");
        frame.setSize(300, 250);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(new GridLayout(7, 1));

        JLabel labelNumero = new JLabel("Digite o número:");
        JTextField numeroField = new JTextField();
        JButton okButton = new JButton("OK");
        JButton exibirButton = new JButton("Exibir");

        JLabel labelMaior = new JLabel("Maior >>>");
        JLabel labelMenor = new JLabel("Menor >>>");
        JLabel labelMedia = new JLabel("Média >>>");
        JButton calcularButton = new JButton("Calcular");
        JComboBox<String> operacaoComboBox = new JComboBox<>(new String[]{"Somar", "Multiplicar"});

        JTextArea numerosArea = new JTextArea();
        JScrollPane scrollPane = new JScrollPane(numerosArea);
        numerosArea.setEditable(false);

        JLabel valorMaior = new JLabel();
        JLabel valorMenor = new JLabel();
        JLabel valorMedia = new JLabel();

        okButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String numeroText = numeroField.getText();
                try {
                    int numero = Integer.parseInt(numeroText);
                    if (numeros == null) {
                        numeros = new ArrayList<>();
                    }
                    numeros.add(numero);
                    numeroField.setText("");
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(frame, "Digite um número válido.", "Erro", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        exibirButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (numeros != null && !numeros.isEmpty()) {
                    StringBuilder numerosText = new StringBuilder();
                    for (int numero : numeros) {
                        numerosText.append(numero).append("\n");
                    }
                    JOptionPane.showMessageDialog(frame, numerosText.toString(), "Números Digitados", JOptionPane.INFORMATION_MESSAGE);
                } else {
                    JOptionPane.showMessageDialog(frame, "Nenhum número digitado.", "Números Digitados", JOptionPane.INFORMATION_MESSAGE);
                }
            }
        });

        calcularButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (numeros != null && !numeros.isEmpty()) {
                    String operacao = operacaoComboBox.getSelectedItem().toString();
                    int resultado;
                    if (operacao.equals("Somar")) {
                        resultado = somarNumeros();
                    } else {
                        resultado = multiplicarNumeros();
                    }
                    JOptionPane.showMessageDialog(frame, "Resultado: " + resultado, "Cálculo", JOptionPane.INFORMATION_MESSAGE);
                } else {
                    JOptionPane.showMessageDialog(frame, "Nenhum número digitado.", "Erro", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        frame.add(labelNumero);
        frame.add(numeroField);
        frame.add(okButton);
        frame.add(exibirButton);
        frame.add(labelMaior);
        frame.add(valorMaior);
        frame.add(labelMenor);
        frame.add(valorMenor);
        frame.add(labelMedia);
        frame.add(valorMedia);
        frame.add(operacaoComboBox);
        frame.add(calcularButton);
        frame.add(scrollPane);

        frame.setVisible(true);
    }

    private int somarNumeros() {
        int soma = 0;
        int contador = 0;
        int menor = Integer.MAX_VALUE;
        int maior = Integer.MIN_VALUE;
        for (int numero : numeros) {
            soma += numero;
            contador++;
            if (numero < menor) {
                menor = numero;
            }
            if (numero > maior) {
                maior = numero;
            }
        }
        double media = (double) soma / contador;

        valorMaior.setText(String.valueOf(maior));
        valorMenor.setText(String.valueOf(menor));
        valorMedia.setText(String.format("%.2f", media));

        return soma;
    }

    private int multiplicarNumeros() {
        int resultado = 1;
        int menor = Integer.MAX_VALUE;
        int maior = Integer.MIN_VALUE;
        for (int numero : numeros) {
            resultado *= numero;
            if (numero < menor) {
                menor = numero;
            }
            if (numero > maior) {
                maior = numero;
            }
        }
        double media = Math.pow((double) resultado, 1.0 / numeros.size());

        valorMaior.setText(String.valueOf(maior));
        valorMenor.setText(String.valueOf(menor));
        valorMedia.setText(String.format("%.2f", media));

        return resultado;
    }
}

