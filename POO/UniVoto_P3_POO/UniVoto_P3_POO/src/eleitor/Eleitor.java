package eleitor;

import eleicao.Secao;

/**
 *
 * @author gustavo.cortez
 */
public class Eleitor {
    private String nome;
    private String CPF;
    private Secao secao;
    private TipoEleitor tipo;

    public Eleitor(String nome, String CPF, Secao secao, TipoEleitor tipo) {
        this.nome = nome;
        this.CPF = CPF;
        this.secao = secao;
        this.tipo = tipo;
    }

    public Secao getSecao() {
        return secao;
    }

    public TipoEleitor getTipo() {
        return tipo;
    }
    
}
