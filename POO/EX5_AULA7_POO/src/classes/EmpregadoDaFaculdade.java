package classes;

/**
 *
 * @author Gustavo
 */
public class EmpregadoDaFaculdade {
    private String nome;
    private double salario;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public double getGastos() {
        return salario;
    }

    @Override
    public String toString() {
        return "EmpregadoDaFaculdade{" +
                "nome='" + nome + '\'' +
                ", salario=" + salario +
                '}';
    }
}

