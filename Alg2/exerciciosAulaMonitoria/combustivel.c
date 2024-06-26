#include <stdio.h>

int main() {
    char tipo_combustivel;
    float preco_litro, quantidade, valor_total;

    printf("Digite o tipo de combustivel (A para Álcool, D para Diesel, G para Gasolina): ");
    scanf(" %c", &tipo_combustivel);

    switch (tipo_combustivel) {
        case 'A':
            preco_litro = 2.10;
            break;
        case 'D':
            preco_litro = 2.45;
            break;
        case 'G':
            preco_litro = 3.15;
            break;
        default:
            printf("Tipo de combustível inválido.\n");
            return 1;
    }

    printf("Digite a quantidade em litros: ");
    scanf("%f", &quantidade);

    valor_total = preco_litro * quantidade;

    printf("Valor a ser pago: R$ %.2f\n", valor_total);

    return 0;
}
