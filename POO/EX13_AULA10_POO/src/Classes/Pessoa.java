package Classes;
import Exception.LascouException;
/**
 *
 * @author Gustavo
 */
public class Pessoa {
    private String nome;
    private int idade;

    // Construtor vazio
    public Pessoa() {}

    // Getters e Setters
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) throws LascouException {
        if (idade < 1 || idade > 150) {
            throw new LascouException("Idade de " + this.nome + " eh inválida: " + idade);
        }
        else{
            System.out.println("Idade de " + this.nome + " eh : " + idade);
        }
        this.idade = idade;
    }
}

