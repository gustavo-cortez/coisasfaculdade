
import javax.swing.JOptionPane;

/**
 *
 * @author Gustavo
 */
public class HTMLString {

     public static void main(String[] args) {
        String html = "A disciplina de <i>Programação Orientada a Objetos</i> está sendo ministrada no primeiro semestre de 2022 de modo <b>híbrido</b>.";

        String tagInicio = "<i>";
        String tagFim = "</i>";
        int startIndex = html.indexOf(tagInicio);
        int endIndex = html.indexOf(tagFim);

        while (startIndex != -1 && endIndex != -1) {
            String textoEntreTags = html.substring(startIndex + tagInicio.length(), endIndex);
            JOptionPane.showMessageDialog(null, textoEntreTags);

            startIndex = html.indexOf(tagInicio, endIndex + tagFim.length());
            endIndex = html.indexOf(tagFim, startIndex + tagInicio.length());
        }

        tagInicio = "<b>";
        tagFim = "</b>";
        startIndex = html.indexOf(tagInicio);
        endIndex = html.indexOf(tagFim);

        while (startIndex != -1 && endIndex != -1) {
            String textoEntreTags = html.substring(startIndex + tagInicio.length(), endIndex);
            JOptionPane.showMessageDialog(null, textoEntreTags);

            startIndex = html.indexOf(tagInicio, endIndex + tagFim.length());
            endIndex = html.indexOf(tagFim, startIndex + tagInicio.length());
        }
    }
}
