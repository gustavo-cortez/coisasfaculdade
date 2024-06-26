package automotivo;

/**
 * Exercício 10 Lista POO
 * @professor Humberto
 * @Autor Gustavo
 */
public class Pneu {
    private String marca;
    private int tamanhoAro;

    public Pneu(String marca, int tamanhoAro) {
        this.marca = marca;
        this.tamanhoAro = tamanhoAro;
    }

    @Override
    public String toString() {
        return "Pneu: Marca=" + marca + ", Tamanho do Aro=" + tamanhoAro;
    }
}


