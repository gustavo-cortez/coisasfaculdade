package eleicao;

import eleitor.Eleitor;
import item.*;
import java.time.LocalDateTime;
import java.util.ArrayList;

public class Urna {
    private ArrayList<Eleitor> votantes = new ArrayList<>();
    private Eleicao eleicao;
    private ArrayList<Voto> votos = new ArrayList<>();
    private Secao secao;

    public Urna(Eleicao eleicao, Secao secao) {
        this.eleicao = eleicao;
        this.secao = secao;
    }

    public Eleicao getEleicao() {
        return eleicao;
    }

    public ArrayList<Voto> getVotos() {
        return votos;
    }

    public void adicionarVoto(Eleitor votante, Item item, Opcao opcao) {
        try {
            if (votante.getSecao().equals(secao) && permiteVotar()) {
                Voto voto;
                if (opcao instanceof Candidato) {
                    Candidato candidato = (Candidato) opcao;
                    voto = new Voto(votante.getTipo(), candidato, item);
                } else if (opcao instanceof Simples) {
                    Simples simples = (Simples) opcao;
                    voto = new Voto(votante.getTipo(), simples, item);
                } else {
                    Branco branco = new Branco();
                    voto = new Voto(votante.getTipo(), branco, item);
                }
                votos.add(voto);
                votantes.add(votante);
            } else {
                throw new Exception("Seção inválida para votar ou período de votação acabou!");
            }
        } catch (Exception e) {
            System.out.println("Erro: " + e);
        }
    }

    public int obterTotalVotos(Item item, Opcao opcao) {
        int i = 0;
        for (Voto contVoto : votos) {
            if (contVoto.getItem().equals(item) && contVoto.getOpcao().equals(opcao)) {
                i++;
            }
        }
        return i;
    }

    public boolean permiteVotar() {
        return LocalDateTime.now().isBefore(eleicao.getFim());
    }
}
