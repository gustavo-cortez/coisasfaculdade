import Exception.LascouException;
import Classes.Pessoa;
/**
 *
 * @author Gustavo
 */
public class Main {
    public static void main(String[] args) {
        Pessoa pessoa1 = new Pessoa();
        Pessoa pessoa2 = new Pessoa();
        Pessoa pessoa3 = new Pessoa();

        try {
            pessoa1.setNome("Gustavo");
            pessoa1.setIdade(21); // Idade válida
        } catch (LascouException e) {
            System.err.println(e.getMessage());
        }

        try {
            pessoa2.setNome("Ray");
            pessoa2.setIdade(-20); // Idade inválida
        } catch (LascouException e) {
            System.err.println(e.getMessage());
        }

        try {
            pessoa3.setNome("Mayara");
            pessoa3.setIdade(200); // Idade inválida 
        } catch (LascouException e) {
            System.err.println(e.getMessage());
        }
    }
}

