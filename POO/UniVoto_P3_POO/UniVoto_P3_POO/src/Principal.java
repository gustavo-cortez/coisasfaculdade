import eleicao.*;
import eleitor.*;
import item.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 *
 * @author gustavo.cortez
 */
public class Principal {

    public static void main(String[] args) {
        ArrayList<Secao> secoes = new ArrayList();
        ArrayList<Eleitor> eleitores = new ArrayList();
        ArrayList<Eleicao> eleicoes = new ArrayList();
        System.out.println("UniVoto");

        Secao secao1 = new Secao(1);
        Secao secao2 = new Secao(2);
        Secao secao3 = new Secao(3);
        Secao secao4 = new Secao(4);
        Secao secao5 = new Secao(5);
        Secao secao6 = new Secao(6);
        secoes.add(secao1);
        secoes.add(secao2);
        secoes.add(secao3);
        secoes.add(secao4);
        secoes.add(secao5);
        secoes.add(secao6);

        Eleitor eleitor1 = new Eleitor("Gustavo", "123456", secao1, TipoEleitor.ESTUDANTE);
        Eleitor eleitor2 = new Eleitor("Humberto", "654321", secao1, TipoEleitor.DOCENTE);
        Eleitor eleitor3 = new Eleitor("Mayara", "777777", secao1, TipoEleitor.ESTUDANTE);
        Eleitor eleitor4 = new Eleitor("Ray", "123456", secao1, TipoEleitor.ESTUDANTE);
        Eleitor eleitor5 = new Eleitor("Luiza", "29191009", secao1, TipoEleitor.ESTUDANTE);
        Eleitor eleitor6 = new Eleitor("Ronaldo", "123456", secao1, TipoEleitor.DOCENTE);
        Eleitor eleitor7 = new Eleitor("Ivone", "123456", secao1, TipoEleitor.DOCENTE);
        Eleitor eleitor8 = new Eleitor("Luciana", "010101", secao1, TipoEleitor.TECNICO);
        Eleitor eleitor9 = new Eleitor("Márcio", "020202", secao1, TipoEleitor.TECNICO);

        eleitores.add(eleitor1);
        eleitores.add(eleitor2);
        eleitores.add(eleitor3);
        eleitores.add(eleitor4);
        eleitores.add(eleitor5);
        eleitores.add(eleitor6);
        eleitores.add(eleitor7);
        eleitores.add(eleitor8);
        eleitores.add(eleitor9);

        Map<TipoEleitor, Integer> peso = new HashMap();

        peso.put(TipoEleitor.DOCENTE, 33);
        peso.put(TipoEleitor.ESTUDANTE, 33);
        peso.put(TipoEleitor.TECNICO, 33);

        Candidato candidado1 = new Candidato("Rafael", 111);
        Candidato candidado2 = new Candidato("Roberto", 222);
        Candidato candidado3 = new Candidato("Rosana", 333);
        Candidato candidado4 = new Candidato("Junior", 444);
        Candidato candidado5 = new Candidato("Vitor", 555);
        Candidato candidado6 = new Candidato("Anny", 666);

        Simples simples1 = new Simples("Sei la o que é isso");
        Simples simples2 = new Simples("Não sei o que é");

        ArrayList<Candidato> candidatos = new ArrayList();
        candidatos.add(candidado1);
        candidatos.add(candidado2);
        candidatos.add(candidado3);
        candidatos.add(candidado4);
        candidatos.add(candidado5);
        candidatos.add(candidado6);

        Item itens = new Item("Reitor");
        itens.adcionarOpcao(candidatos);

        List<Item> itenslista = new ArrayList();
        itenslista.add(itens);

        Eleicao eleicao1 = new Eleicao("Eleição reitor", "Vai eleger um reitor", LocalDateTime.now().minusDays(1), LocalDateTime.now().plusDays(60), peso, itenslista);
        eleicao1.criarUrnas(secoes);
        Map<TipoEleitor, Integer> peso2 = new HashMap();
        peso2.put(TipoEleitor.DOCENTE, 50);
        peso2.put(TipoEleitor.ESTUDANTE, 25);
        peso2.put(TipoEleitor.TECNICO, 25);

        Item itens2 = new Item("Coordenador");
        itens2.adcionarOpcao(candidatos);

        List<Item> itenslista2 = new ArrayList();
        itenslista2.add(itens2);

        Eleicao eleicao2 = new Eleicao("Eleição coordenador", "Vai eleger um coordenador", LocalDateTime.now().minusDays(1), LocalDateTime.now().plusDays(1), peso2, itenslista2);
        eleicao2.criarUrnas(secoes);
        Map<TipoEleitor, Integer> peso3 = new HashMap();
        peso3.put(TipoEleitor.DOCENTE, 50);
        peso3.put(TipoEleitor.ESTUDANTE, 25);
        peso3.put(TipoEleitor.TECNICO, 25);

        Eleicao eleicao3 = new Eleicao("Eleição reitor - Campus CPTL", "Vai eleger um reitor em CPTL", LocalDateTime.now(), LocalDateTime.now().plusDays(20), peso, itenslista);
        eleicao3.criarUrnas(secoes);

        eleicoes.add(eleicao1);
        eleicoes.add(eleicao2);
        eleicoes.add(eleicao3);

        for (int i = 0; i < eleicao1.getUrnas().size(); i++) {
            eleicao1.getUrnas().get(i).adicionarVoto(eleitor1, itens, candidado1);
        }
        for (int i = 0; i < eleicao1.getUrnas().size(); i++) {
            eleicao1.getUrnas().get(i).adicionarVoto(eleitor2, itens, candidado2);
        }
        for (int i = 0; i < eleicao1.getUrnas().size(); i++) {
            eleicao1.getUrnas().get(i).adicionarVoto(eleitor3, itens, candidado4);
        }
        for (int i = 0; i < eleicao1.getUrnas().size(); i++) {
            eleicao1.getUrnas().get(i).adicionarVoto(eleitor6, itens, candidado5);
        }
        for (int i = 0; i < eleicao2.getUrnas().size(); i++) {
            eleicao2.getUrnas().get(i).adicionarVoto(eleitor1, itens2, candidado5);
        }
        for (int i = 0; i < eleicao2.getUrnas().size(); i++) {
            eleicao2.getUrnas().get(i).adicionarVoto(eleitor7, itens2, candidado2);
        }
        for (int i = 0; i < eleicao3.getUrnas().size(); i++) {
            eleicao3.getUrnas().get(i).adicionarVoto(eleitor5, itens, candidado1);
        }
        for (int i = 0; i < eleicao3.getUrnas().size(); i++) {
            eleicao3.getUrnas().get(i).adicionarVoto(eleitor7, itens, candidado1);
        }

        System.out.println(eleicao1.apurar());
        System.out.println(eleicao2.apurar());
        System.out.println(eleicao3.apurar());
    }
}
