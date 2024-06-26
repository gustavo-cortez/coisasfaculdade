/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package classes;
import interfaces.EmissaoCarbono;
/**
 *
 * @author Gustavo
 */
public class Veiculo implements EmissaoCarbono {
    private int numeroCilindrosMotor;
    private int rotacoesPorMinutoMotor;
    private int fatorDePoluicao;

    public Veiculo(int numeroCilindrosMotor, int rotacoesPorMinutoMotor, String tipoCombustivel) {
        this.numeroCilindrosMotor = numeroCilindrosMotor;
        this.rotacoesPorMinutoMotor = rotacoesPorMinutoMotor;
        switch (tipoCombustivel.toLowerCase()) {
            case "álcool":
                this.fatorDePoluicao = 1;
                break;
            case "gasolina":
                this.fatorDePoluicao = 2;
                break;
            case "diesel":
                this.fatorDePoluicao = 3;
                break;
            default:
                throw new IllegalArgumentException("Tipo de combustível inválido.");
        }
    }

    @Override
    public double calculaEmissao() {
        return (numeroCilindrosMotor * rotacoesPorMinutoMotor / 1000.0) * fatorDePoluicao;
    }
}

