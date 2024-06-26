package Funcoes;

import java.time.LocalDate;
import java.time.LocalTime;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        
        Scanner scanner = new Scanner(System.in);
        Consultas consulta = null;

        while (true) {
            System.out.println("\nSelecione uma opção:");
            for (OpcaoMenu opcao : OpcaoMenu.values()) {
                System.out.println(opcao.getNumero() + "- " + opcao.getDescricao());
            }

            int opcaoNumero = scanner.nextInt();
            scanner.nextLine();
            OpcaoMenu opcao = OpcaoMenu.valueOf(opcaoNumero);

            switch (opcao) {
                case CRIAR_CONSULTA:
                    System.out.println("Informe o nome:");
                    String nome = scanner.nextLine();
                    System.out.println("Informe o telefone:");
                    String telefone = scanner.nextLine();
                    System.out.println("Informe o e-mail:");
                    String email = scanner.nextLine();
                    System.out.println("Informe a data da consulta (AAAA-MM-DD):");
                    String dataConsultaStr = scanner.nextLine();
                    LocalDate dataConsulta = LocalDate.parse(dataConsultaStr);
                    System.out.println("Informe a hora da consulta (HH:MM):");
                    String horaConsultaStr = scanner.nextLine();
                    LocalTime horaConsulta = LocalTime.parse(horaConsultaStr);
                    consulta = new Consultas(nome, telefone, email, dataConsulta, horaConsulta);
                    System.out.println("Consulta criada com sucesso!");
                    break;
                case ALTERAR_DADOS_PESSOAIS:
                    if (consulta != null) {
                        System.out.println("Informe o novo nome:");
                        consulta.setNome(scanner.nextLine());
                        System.out.println("Informe o novo telefone:");
                        consulta.setTelefone(scanner.nextLine());
                        System.out.println("Informe o novo e-mail:");
                        consulta.setEmail(scanner.nextLine());
                        System.out.println("Dados pessoais alterados com sucesso!");
                    } else {
                        System.out.println("Crie uma consulta antes de alterar os dados pessoais.");
                    }
                    break;
                case ALTERAR_DATA:
                    if (consulta != null) {
                        System.out.println("Informe a nova data da consulta (AAAA-MM-DD):");
                        String novaDataStr = scanner.nextLine();
                        LocalDate novaData = LocalDate.parse(novaDataStr);
                        consulta.setDataConsulta(novaData);
                        System.out.println("Data da consulta alterada com sucesso!");
                    } else {
                        System.out.println("Crie uma consulta antes de alterar a data.");
                    }
                    break;
                case ALTERAR_HORA:
                    if (consulta != null) {
                        System.out.println("Informe a nova hora da consulta (HH:MM):");
                        String novaHoraStr = scanner.nextLine();
                        LocalTime novaHora = LocalTime.parse(novaHoraStr);
                        consulta.setHoraConsulta(novaHora);
                        System.out.println("Hora da consulta alterada com sucesso!");
                    } else {
                        System.out.println("Crie uma consulta antes de alterar a hora.");
                    }
                    break;
                case SAIR:
                    System.out.println("Saindo do programa...");
                    System.exit(0);
            }
        }
    }
}
