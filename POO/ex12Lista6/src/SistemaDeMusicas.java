import javax.swing.JOptionPane;
import Classe.*;
import Funcoes.*;
/**
 *
 * @author Gustavo
 */
public class SistemaDeMusicas {
    
    public static void main(String[] args) {
        
        FunMusicas musicasIns = new FunMusicas();

        while (true) {
            String[] opcoes = {"Cadastrar música", "Listar músicas", "Procurar música", "Remover música", "Sair"};
            int escolha = JOptionPane.showOptionDialog(null, "Escolha uma opção:", "Menu",
                    JOptionPane.DEFAULT_OPTION, JOptionPane.PLAIN_MESSAGE, null, opcoes, opcoes[0]);

            switch (escolha) {
                case 0:
                    String titulo = JOptionPane.showInputDialog("Digite o título da música:");
                    String artista = JOptionPane.showInputDialog("Digite o artista da música:");
                    String genero = JOptionPane.showInputDialog("Digite o gênero da música:");
                    musicasIns.cadastrarMusica(titulo, artista, genero);
                    break;
                case 1:
                    musicasIns.listarMusicas();
                    break;
                case 2:
                    String termoBusca = JOptionPane.showInputDialog("Digite o termo de busca:");
                    musicasIns.procurarMusica(termoBusca);
                    break;
                case 3:
                    String termoRemover = JOptionPane.showInputDialog("Digite o termo para remover:");
                    musicasIns.removerMusica(termoRemover);
                    break;
                case 4:
                    JOptionPane.showMessageDialog(null, "Saindo...");
                    System.exit(0);
                    break;
                default:
                    JOptionPane.showMessageDialog(null, "Opção inválida!");
            }
        }
    }
}
