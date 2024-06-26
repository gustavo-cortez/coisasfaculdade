package eletronicos;

/**
 * Exercício 10 Lista POO
 * @professor Humberto
 * @Autor Gustavo
 */
public class Celular {
    private String marca;
    private String modelo;
    private int qtdMemoria;
    private int qtdArmazenamento;

    public Celular(String marca, String modelo, int qtdMemoria, int qtdArmazenamento) {
        this.marca = marca;
        this.modelo = modelo;
        this.qtdMemoria = qtdMemoria;
        this.qtdArmazenamento = qtdArmazenamento;
    }

    @Override
    public String toString() {
        return "Celular: Marca=" + marca + ", Modelo=" + modelo + ", Memória=" + qtdMemoria + "GB, Armazenamento=" + qtdArmazenamento + "GB";
    }
}

