package eleicao;

import eleitor.TipoEleitor;
import item.*;

public class Voto {
    private TipoEleitor tipo;
    private Opcao opcao;
    private Item item;

    public Voto(TipoEleitor tipo, Opcao opcao, Item item) {
        this.tipo = tipo;
        this.opcao = opcao;
        this.item = item;
    }

    public TipoEleitor getTipo() {
        return tipo;
    }

    public Opcao getOpcao() {
        return opcao;
    }

    public Item getItem() {
        return item;
    }
}
