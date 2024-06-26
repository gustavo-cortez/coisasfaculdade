package bijouteria;

/**
 * Exercício 10 Lista POO
 * @professor Humberto
 * @Autor Gustavo
 */
public class Anel {
    private String tipoMaterial;
    private double largura;
    private double diametro;

    public Anel(String tipoMaterial, double largura, double diametro) {
        this.tipoMaterial = tipoMaterial;
        this.largura = largura;
        this.diametro = diametro;
    }

    @Override
    public String toString() {
        return "Anel: Tipo de Material=" + tipoMaterial + ", Largura=" + largura + "mm, Diâmetro=" + diametro + "mm";
    }
}

