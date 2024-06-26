import classes.*;
import interfaces.EmissaoCarbono;
import java.util.ArrayList;
/**
 *
 * @author Gustavo
 */
public class main {
    public static void main(String[] args) {
        ArrayList<EmissaoCarbono> listaEmissoes = new ArrayList<>();

        Construcao construcao1 = new Construcao();
        construcao1.addChamine(2.5, 40);/*Mudar para um número menor que 10 ou maior que 1000 gera um java Exception*/
        construcao1.addChamine(3.0, 700);

        Veiculo veiculo1 = new Veiculo(4, 3000, "gasolina");
        Veiculo veiculo2 = new Veiculo(6, 4000, "diesel");

        Gado gado1 = new Gado(500);
        Gado gado2 = new Gado(800);

        listaEmissoes.add(construcao1);
        listaEmissoes.add(veiculo1);
        listaEmissoes.add(veiculo2);
        listaEmissoes.add(gado1);
        listaEmissoes.add(gado2);

        double totalEmissao = 0.0;
        for (EmissaoCarbono emissao : listaEmissoes) {
            totalEmissao += emissao.calculaEmissao();
        }

        System.out.println("Quantidade total de carbono emitida: " + totalEmissao);
    }
}
