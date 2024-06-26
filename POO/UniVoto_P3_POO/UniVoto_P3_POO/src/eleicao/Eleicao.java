package eleicao;

import eleitor.TipoEleitor;
import item.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

/**
 *
 * @author gustavo.cortez
 */
public class Eleicao {
    private String nome;
    private String descricao;
    private LocalDateTime inicio;
    private LocalDateTime fim;
    private Map<TipoEleitor, Integer> peso = new HashMap();
    private List<Item> itens = new ArrayList();
    private ArrayList<Urna> urnas = new ArrayList();
    public Eleicao(String nome, String descricao, LocalDateTime inicio, LocalDateTime fim, Map<TipoEleitor, Integer> peso, List<Item> itens) {
        this.nome = nome;
        this.descricao = descricao;
        this.inicio = inicio;
        this.fim = fim;
        this.peso = peso;
        this.itens = itens;
    }

    public LocalDateTime getInicio() {
        return inicio;
    }

    public LocalDateTime getFim() {
        return fim;
    }

    public ArrayList<Urna> getUrnas() {
        return urnas;
    }

    public void criarUrnas(List<Secao> secoes){
        try{
            if(!secoes.isEmpty()){
                for(Secao sec : secoes){
                    Urna urna = new Urna(this,sec);
                    urnas.add(urna);
                }
            }
            else{
                throw new Exception("Erro criar urnas! Há seções vazias.");
            }
        }catch(Exception e){
            System.out.println(e);
        }
    }
    
    public String apurar(){
        StringBuilder mensagem = new StringBuilder();
        try{
            int valor = 0;
            for(Urna urnasApurar : urnas){
                if(urnasApurar.getEleicao().equals(this)){
                    for (Item item : itens) {
                        Iterator it = item.getOpcoes().iterator();
                        if(it != null){
                            while(it.hasNext()) {
                                Opcao opc = (Opcao) it.next();
                                valor = urnasApurar.obterTotalVotos(item, opc);
                            }
                        }
                        else{
                            throw new Exception("Erro sem sem itens para apurar");
                        }
                        mensagem.append("" + nome + item.toString() + " " + valor + " ");
                        mensagem.append("\n");
                        Iterator it2 = urnasApurar.getVotos().iterator();
                        if(it2 != null){
                            while(it2.hasNext()){
                                Voto votos = (Voto) it.next();

                                mensagem.append(" " + peso.get(votos.getTipo()).intValue());
                            }
                        }
                        else{
                            throw new Exception("Erro sem votos para apurar");
                        }
                          
                    }
                }

            }
        }
        catch(Exception e){
            return e.toString();
        }
        return mensagem.toString();
    }
}
