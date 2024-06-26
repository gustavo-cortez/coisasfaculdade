import classes.*;
/**
 *
 * @author Gustavo
 */
public class main {
    public static void main(String[] args) {
        EmpregadoDaFaculdade empregado = new EmpregadoDaFaculdade();
        empregado.setNome("João");
        empregado.setSalario(3000.0);

        ProfessorDaFaculdade professor = new ProfessorDaFaculdade();
        professor.setNome("Maria");
        professor.setSalario(4000.0);
        professor.setHorasAula(200);

        System.out.println(empregado.toString());
        System.out.println("Gastos: " + empregado.getGastos());

        System.out.println(professor.toString());
        System.out.println("Gastos: " + professor.getGastos());
    }
}

