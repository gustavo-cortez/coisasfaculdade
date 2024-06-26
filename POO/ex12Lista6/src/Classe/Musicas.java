package Classe;

/**
 *
 * @author Gustavo
 */
public class Musicas {
    
    private String titulo;
    private String artista;
    private String genero;

    public Musicas(String titulo, String artista, String genero) {
        this.titulo = titulo;
        this.artista = artista;
        this.genero = genero;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getArtista() {
        return artista;
    }

    public String getGenero() {
        return genero;
    }

    @Override
    public String toString() {
        return "Título: " + titulo + ", Artista: " + artista + ", Gênero: " + genero;
    }
}
