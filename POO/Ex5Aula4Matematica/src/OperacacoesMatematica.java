/**
 *
 * @author Gustavo
 */
public class OperacacoesMatematica {
    public static double multiplicar(double a, double b) {
        return a * b;
    }

    public static double elevar(double base, int expoente) {
        double resultado = 1;
        for (int i = 0; i < expoente; i++) {
            resultado *= base;
        }
        return resultado;
    }

    public static double somar(double a, double b) {
        return a + b;
    }

    public static double maximo(double a, double b) {
        return Math.max(a, b);
    }

    public static double minimo(double a, double b) {
        return Math.min(a, b);
    }
}
