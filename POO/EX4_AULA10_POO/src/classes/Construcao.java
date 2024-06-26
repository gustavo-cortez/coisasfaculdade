package classes;
import java.util.ArrayList;
import interfaces.EmissaoCarbono;
/**
 *
 * @author Gustavo
 */
public class Construcao implements EmissaoCarbono {
    private ArrayList<Chamine> chamines;

    public Construcao() {
        chamines = new ArrayList<>();
    }

    public void addChamine(double largura, int indiceAtividade) {
        if (indiceAtividade < 10 || indiceAtividade > 1000) {
            throw new IllegalArgumentException("Índice de atividade deve estar entre 10 e 1000.");
        }
        chamines.add(new Chamine(largura, indiceAtividade));
    }

    @Override
    public double calculaEmissao() {
        double totalEmissao = 0.0;
        for (Chamine chamine : chamines) {
            totalEmissao += chamine.largura * chamine.indiceAtividade;
        }
        return totalEmissao;
    }

    private class Chamine {
        double largura;
        int indiceAtividade;

        Chamine(double largura, int indiceAtividade) {
            this.largura = largura;
            this.indiceAtividade = indiceAtividade;
        }
    }
}

