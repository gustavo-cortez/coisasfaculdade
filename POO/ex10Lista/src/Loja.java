/**
 * Exercício 10 Lista POO
 * @professor Humberto
 * @Autor Gustavo
 */

import java.util.Scanner;
import eletronicos.*;
import bijouteria.*;
import automotivo.*;

public class Loja {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Lendo informações para Celular
        System.out.println("Digite a marca do celular:");
        String marcaCelular = scanner.nextLine();
        System.out.println("Digite o modelo do celular:");
        String modeloCelular = scanner.nextLine();
        System.out.println("Digite a quantidade de memória do celular (em GB):");
        int memoriaCelular = scanner.nextInt();
        System.out.println("Digite a quantidade de armazenamento do celular (em GB):");
        int armazenamentoCelular = scanner.nextInt();
        scanner.nextLine(); // Limpar o buffer do scanner

        Celular celular = new Celular(marcaCelular, modeloCelular, memoriaCelular, armazenamentoCelular);
        System.out.println(celular);

        // Lendo informações para TV
        System.out.println("\nDigite a marca da TV:");
        String marcaTV = scanner.nextLine();
        System.out.println("Digite o modelo da TV:");
        String modeloTV = scanner.nextLine();
        System.out.println("Digite o número de polegadas da TV:");
        int polegadasTV = scanner.nextInt();
        scanner.nextLine(); // Limpar o buffer do scanner

        TV tv = new TV(marcaTV, modeloTV, polegadasTV);
        System.out.println(tv);

        // Lendo informações para Anel
        System.out.println("\nDigite o tipo de material do anel:");
        String materialAnel = scanner.nextLine();
        System.out.println("Digite a largura do anel (em mm):");
        double larguraAnel = scanner.nextDouble();
        System.out.println("Digite o diâmetro do anel (em mm):");
        double diametroAnel = scanner.nextDouble();
        scanner.nextLine(); // Limpar o buffer do scanner

        Anel anel = new Anel(materialAnel, larguraAnel, diametroAnel);
        System.out.println(anel);

        // Lendo informações para Brinco
        System.out.println("\nDigite a descrição do brinco:");
        String descricaoBrinco = scanner.nextLine();
        System.out.println("Digite o tipo de material do brinco:");
        String materialBrinco = scanner.nextLine();
        System.out.println("Digite o comprimento do brinco (em mm):");
        double comprimentoBrinco = scanner.nextDouble();
        scanner.nextLine(); // Limpar o buffer do scanner

        Brinco brinco = new Brinco(descricaoBrinco, materialBrinco, comprimentoBrinco);
        System.out.println(brinco);

        // Lendo informações para Pneu
        System.out.println("\nDigite a marca do pneu:");
        String marcaPneu = scanner.nextLine();
        System.out.println("Digite o tamanho do aro do pneu:");
        int tamanhoAroPneu = scanner.nextInt();
        scanner.nextLine(); // Limpar o buffer do scanner

        Pneu pneu = new Pneu(marcaPneu, tamanhoAroPneu);
        System.out.println(pneu);

        // Lendo informações para Produto de Limpeza
        System.out.println("\nDigite o tipo do produto de limpeza:");
        String tipoLimpeza = scanner.nextLine();
        System.out.println("Digite a marca do produto de limpeza:");
        String marcaLimpeza = scanner.nextLine();
        System.out.println("Digite a quantidade (em ml) do produto de limpeza:");
        int qtdMlLimpeza = scanner.nextInt();

        ProdutoLimpeza produtoLimpeza = new ProdutoLimpeza(tipoLimpeza, marcaLimpeza, qtdMlLimpeza);
        System.out.println(produtoLimpeza);

        scanner.close();
    }
}

