package classes;

/**
 *
 * @author Gustavo
 */
public class ProfessorDaFaculdade extends EmpregadoDaFaculdade {
    private int horasAula;

    public int getHorasAula() {
        return horasAula;
    }

    public void setHorasAula(int horasAula) {
        this.horasAula = horasAula;
    }

    @Override
    public double getGastos() {
        return getSalario() + (horasAula * 0.1);
    }

    @Override
    public String toString() {
        return "ProfessorDaFaculdade{" +
                "nome='" + getNome() + '\'' +
                ", salario=" + getSalario() +
                ", horasAula=" + horasAula +
                ", gastos=" + getGastos() +
                '}';
    }
}
