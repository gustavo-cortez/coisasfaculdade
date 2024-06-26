package item;

/**
 *
 * @author gustavo.cortez
 */
public class Candidato extends Opcao {
    private String nome;
    private int numero;

    public Candidato(String nome, int numero) {
        this.nome = nome;
        this.numero = numero;
    }

    public String getNome() {
        return nome;
    }

    public int getNumero() {
        return numero;
    }
    
    
}
