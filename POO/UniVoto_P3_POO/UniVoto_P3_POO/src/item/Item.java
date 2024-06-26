package item;

import java.util.ArrayList;

/**
 *
 * @author gustavo.cortez
 * @param <T>
 */
public class Item<T>{
    private String nome;
    private ArrayList<Opcao> opcoes = new ArrayList();;
    
    public Item(String nome){
        this.nome = nome;
        Branco branco = new Branco();
        this.opcoes.add(branco);
    }

    public ArrayList<Opcao> getOpcoes() {
        return opcoes;
    }

    public <T> void adcionarOpcao(ArrayList<T> opcoes){
        Opcao op = null;
        for(int i = 1; i < opcoes.size(); i++){
            op = (Opcao) opcoes.get(i);
        }
        this.opcoes.add(op);
    }

    @Override
    public String toString() {
        return "Item: " + " Nome = " + nome + ", Opcoes = " + opcoes.toString() + '}';
    }
    
}
