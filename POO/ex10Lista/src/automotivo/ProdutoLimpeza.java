package automotivo;

/**
 * Exercício 10 Lista POO
 * @professor Humberto
 * @Autor Gustavo
 */
public class ProdutoLimpeza {
    private String tipo;
    private String marca;
    private int qtdMl;

    public ProdutoLimpeza(String tipo, String marca, int qtdMl) {
        this.tipo = tipo;
        this.marca = marca;
        this.qtdMl = qtdMl;
    }

    @Override
    public String toString() {
        return "Produto de Limpeza: Tipo=" + tipo + ", Marca=" + marca + ", Quantidade (ml)=" + qtdMl;
    }
}
