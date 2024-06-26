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
public class Gado implements EmissaoCarbono {
    private double peso;

    public Gado(double peso) {
        this.peso = peso;
    }

    @Override
    public double calculaEmissao() {
        return peso * 0.7;
    }
}

