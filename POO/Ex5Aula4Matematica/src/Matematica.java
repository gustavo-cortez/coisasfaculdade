import javax.swing.JOptionPane;

/**
 *
 * @author Gustavo
 */
public class Matematica {
    public static void main(String[] args) {
        String operacoes = "Escolha a operação:\n" +
                           "1 - Multiplicação\n" +
                           "2 - Elevação\n" +
                           "3 - Soma\n" +
                           "4 - Máximo\n" +
                           "5 - Mínimo";
        
        String inputOperacao = JOptionPane.showInputDialog(null, operacoes, "Escolha da Operação", JOptionPane.PLAIN_MESSAGE);
        int operacao = Integer.parseInt(inputOperacao);

        double valor1 = Double.parseDouble(JOptionPane.showInputDialog("Digite o primeiro valor:"));
        double valor2 = Double.parseDouble(JOptionPane.showInputDialog("Digite o segundo valor:"));

        double resultado;

        switch (operacao) {
            case 1 -> resultado = OperacacoesMatematica.multiplicar(valor1, valor2);
            case 2 -> resultado = OperacacoesMatematica.elevar(valor1, (int) valor2);
            case 3 -> resultado = OperacacoesMatematica.somar(valor1, valor2);
            case 4 -> resultado = OperacacoesMatematica.maximo(valor1, valor2);
            case 5 -> resultado = OperacacoesMatematica.minimo(valor1, valor2);
            default -> {
                JOptionPane.showMessageDialog(null, "Operação inválida!");
                return;
            }
        }

        JOptionPane.showMessageDialog(null, "Resultado: " + resultado);
    }
}

