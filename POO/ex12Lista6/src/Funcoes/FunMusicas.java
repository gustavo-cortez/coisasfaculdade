package Funcoes;
import Classe.*;
import java.util.ArrayList;
import java.util.Iterator;
import javax.swing.JOptionPane;
/**
 *
 * @author Gustavo
 */
public class FunMusicas {
    
    private ArrayList<Musicas> musicas;

    public FunMusicas() {
        this.musicas = new ArrayList<>();
    }

    public void cadastrarMusica(String titulo, String artista, String genero) {
        Musicas novaMusica = new Musicas(titulo, artista, genero);
        musicas.add(novaMusica);
        JOptionPane.showMessageDialog(null, "Música cadastrada com sucesso!");
    }

    public void listarMusicas() {
        if (musicas.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Não há músicas cadastradas.");
        } else {
            StringBuilder mensagem = new StringBuilder("Lista de músicas:\n");
            for (Musicas musica : musicas) {
                mensagem.append(musica).append("\n");
            }
            JOptionPane.showMessageDialog(null, mensagem.toString());
        }
    }

    public void procurarMusica(String termo) {
        boolean encontrou = false;
        StringBuilder mensagem = new StringBuilder();
        for (Musicas musica : musicas) {
            if (musica.getTitulo().toLowerCase().contains(termo.toLowerCase()) ||
                    musica.getArtista().toLowerCase().contains(termo.toLowerCase()) ||
                    musica.getGenero().toLowerCase().contains(termo.toLowerCase())) {
                mensagem.append(musica).append("\n");
                encontrou = true;
            }
        }
        if (!encontrou) {
            JOptionPane.showMessageDialog(null, "Nenhuma música encontrada com o termo '" + termo + "'.");
        } else {
            JOptionPane.showMessageDialog(null, mensagem.toString());
        }
    }

    public void removerMusica(String termo) {
        Iterator<Musicas> iterator = musicas.iterator();
        boolean removido = false;
        while (iterator.hasNext()) {
            Musicas musica = iterator.next();
            if (musica.getTitulo().toLowerCase().contains(termo.toLowerCase()) ||
                    musica.getArtista().toLowerCase().contains(termo.toLowerCase()) ||
                    musica.getGenero().toLowerCase().contains(termo.toLowerCase())) {
                iterator.remove();
                removido = true;
            }
        }
        if (removido) {
            JOptionPane.showMessageDialog(null, "Música(s) removida(s) com sucesso!");
        } else {
            JOptionPane.showMessageDialog(null, "Nenhuma música encontrada com o termo '" + termo + "'.");
        }
    }
}
