package Funcoes;

public enum OpcaoMenu{
    CRIAR_CONSULTA(1, "Criar Consulta"),
    ALTERAR_DADOS_PESSOAIS(2, "Alterar Dados Pessoais"),
    ALTERAR_DATA(3, "Alterar Data"),
    ALTERAR_HORA(4, "Alterar Hora"),
    SAIR(5, "Sair");

    private final int numero;
    private final String descricao;

    OpcaoMenu(int numero, String descricao) {
        this.numero = numero;
        this.descricao = descricao;
    }

    public int getNumero() {
        return numero;
    }

    public String getDescricao() {
        return descricao;
    }

    public static OpcaoMenu valueOf(int numero) {
        for (OpcaoMenu opcao : values()) {
            if (opcao.numero == numero) {
                return opcao;
            }
        }
        System.out.println("Opção inválida! Por favor, selecione uma opção válida.");
        return null;
    }
}