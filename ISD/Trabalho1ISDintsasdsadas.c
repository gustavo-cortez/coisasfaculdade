#include <stdio.h>
#include <stdlib.h>

// Função para converter um número binário em inteiro
int binarioParaInteiro(int *binario, int tamanho) {
    int inteiro = 0;
    int multiplicador = 1;
    int i;

    // Verifica se o número é negativo (complemento de dois)
    if (binario[0] == 1) {
        for (i = tamanho - 1; i > 0; i--) {
            inteiro += (binario[i] == 0) ? multiplicador : 0;
            multiplicador *= 2;
        }
        inteiro = -(multiplicador - inteiro); // Inverte o sinal
    } else {
        for (i = tamanho - 1; i >= 0; i--) {
            inteiro += binario[i] * multiplicador;
            multiplicador *= 2;
        }
    }

    return inteiro;
}

// Função para converter um número binário em hexadecimal
char* binarioParaHexadecimal(int *binario, int tamanho) {
    int inteiro = binarioParaInteiro(binario, tamanho);
    char *hexadecimal = (char *) malloc(3 * sizeof(char)); // Será necessário 2 caracteres hexadecimais e um caractere nulo
    sprintf(hexadecimal, "%02X", inteiro);
    return hexadecimal;
}

// Função para exibir um número binário
void exibirBinario(int *binario, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d", binario[i]);
    }
    printf("\n");
}

// Função para realizar a soma de dois números binários
void somaBinaria(int *num1, int *num2, int tamanho, int *resultado) {
    int carry = 0;
    int i;

    for (i = tamanho - 1; i >= 0; i--) {
        int soma = num1[i] + num2[i] + carry;
        resultado[i] = soma % 2;
        carry = soma / 2;
    }
}

// Função para realizar a subtração de dois números binários
void subtracaoBinaria(int *num1, int *num2, int tamanho, int *resultado) {
    int carry = 0;
    int i;

    for (i = tamanho - 1; i >= 0; i--) {
        int diferenca = num1[i] - num2[i] - carry;
        if (diferenca < 0) {
            diferenca += 2;
            carry = 1;
        } else {
            carry = 0;
        }
        resultado[i] = diferenca;
    }
}

int main() {
    int num1[8], num2[8], num3[8];
    char operacao1, operacao2;

    while (1) {
        printf("Informe o PRIMEIRO número binário ou -1 para encerrar: ");
        for (int i = 0; i < 8; i++) {
            scanf("%1d", &num1[i]);
        }

        if (num1[0] == -1)
            break;

        printf("Informe uma operação (+ ou -): ");
        scanf(" %c", &operacao1);

        printf("Informe o SEGUNDO número binário: ");
        for (int i = 0; i < 8; i++) {
            scanf("%1d", &num2[i]);
        }

        printf("Informe uma operação (+ ou -): ");
        scanf(" %c", &operacao2);

        printf("Informe o TERCEIRO número binário: ");
        for (int i = 0; i < 8; i++) {
            scanf("%1d", &num3[i]);
        }

        // Realiza as operações conforme as entradas do usuário
        int resultado[8];
        if (operacao1 == '+') {
            somaBinaria(num1, num2, 8, resultado);
        } else if (operacao1 == '-') {
            subtracaoBinaria(num1, num2, 8, resultado);
        }

        if (operacao2 == '+') {
            somaBinaria(resultado, num3, 8, resultado);
        } else if (operacao2 == '-') {
            subtracaoBinaria(resultado, num3, 8, resultado);
        }

        // Apresenta os resultados
        printf("Números binários:\n");
        printf("%d: ", binarioParaInteiro(num1, 8));
        exibirBinario(num1, 8);
        printf("%d: ", binarioParaInteiro(num2, 8));
        exibirBinario(num2, 8);
        printf("%d: ", binarioParaInteiro(num3, 8));
        exibirBinario(num3, 8);
        printf("=\n");
        printf("%d: ", binarioParaInteiro(resultado, 8));
        exibirBinario(resultado, 8);

        printf("Números hexadecimais:\n");
        printf("%s\n", binarioParaHexadecimal(num1, 8));
        printf("%s\n", binarioParaHexadecimal(num2, 8));
        printf("%s\n", binarioParaHexadecimal(num3, 8));
        printf("=\n");
        printf("%s\n", binarioParaHexadecimal(resultado, 8));
    }

    return 0;
}
