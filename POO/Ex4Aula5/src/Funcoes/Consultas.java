package Funcoes;

import java.time.LocalDate;
import java.time.LocalTime;
import java.time.Period;

class Consultas{
    private String nome;
    private String telefone;
    private String email;
    private LocalDate dataConsulta;
    private LocalTime horaConsulta;

    // Construtor
    public Consultas(String nome, String telefone, String email, LocalDate dataConsulta, LocalTime horaConsulta) {
        this.nome = nome;
        this.telefone = telefone;
        this.email = email;
        this.dataConsulta = dataConsulta;
        this.horaConsulta = horaConsulta;
    }

    // Métodos para acessar e modificar os dados
    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTelefone() {
        return telefone;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public LocalDate getDataConsulta() {
        return dataConsulta;
    }

    public void setDataConsulta(LocalDate dataConsulta) {
        this.dataConsulta = dataConsulta;
    }

    public LocalTime getHoraConsulta() {
        return horaConsulta;
    }

    public void setHoraConsulta(LocalTime horaConsulta) {
        this.horaConsulta = horaConsulta;
    }

}

