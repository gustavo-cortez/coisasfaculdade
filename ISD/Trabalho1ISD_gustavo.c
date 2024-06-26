/******************************************
* *
* Nome: Gustavo Cortez de Paula
* Trabalho Prático *
* Disciplina: Introdução a Sistemas Digitais *
* Professores: Maxwell Sampaio *
* *
******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para converter um número binário em inteiro usando complemento de dois
int binarioParaInteiro(int *binario, int tamanho) {
    int inteiro = 0;
    int multiplicador = 1;
    int i, j, binAux[8];
    int negativo;

    for(j = 0; j<8;j++){

        binAux[j] = binario[j];

    }

    // Verifica se o número é negativo (complemento de dois)
    if (binAux[0] == 1) {
        // Inverte os bits do número
        for (i = tamanho - 1; i >= 0; i--) {
            binAux[i] = !binAux[i]; // Inverte o bit
        }
        // Adiciona 1 ao número binário invertido (somando 1 em binário)
        for (i = tamanho - 1; i >= 0; i--) {
            if (binAux[i] == 0) {
                binAux[i] = 1;
                break;
            } else {
                binAux[i] = 0;
            }
        }
        // Calcula o valor do número negativo
        for (i = tamanho - 1; i >= 0; i--) {
            inteiro += binAux[i] * multiplicador;
            multiplicador *= 2;
        }
        // Ajusta o sinal do número
        return -inteiro;
    } else {
        // Calcula o valor do número positivo
        for (i = tamanho - 1; i >= 0; i--) {
            inteiro += binAux[i] * multiplicador;
            multiplicador *= 2;
        }
    }
    return inteiro;
}


// Função para converter um número Inteiro em hexadecimal
void inteiroParaHexadecimal(int inteiro, char *hexadecimal) {
    char hexaDigitos[] = "0123456789ABCDEF";
    int index = 1; // Começa da posição mais à direita do resultado
    int temp = inteiro;

    // Inicializa a string hexadecimal
    hexadecimal[2] = '\0';

    // Se o número é negativo, converte para positivo, considerando a representação de complemento de dois
    if (temp < 0) {
        temp = 256 + temp; // Para números de 8 bits, converte para o intervalo 0-255
    }

    do {
        hexadecimal[index--] = hexaDigitos[temp % 16];
        temp /= 16;
    } while (temp > 0);

    // Preenche com 0s à esquerda se necessário
    if (index == 0) {
        hexadecimal[0] = '0';
    }
}

// Função para converter um número binário em hexadecimal
char* binarioParaHexadecimal(int *binario, int tamanho) {
    int inteiro = binarioParaInteiro(binario, tamanho);
    char *hexadecimal = (char *) malloc(3 * sizeof(char)); // Será necessário 2 caracteres hexadecimais e um caractere nulo
    inteiroParaHexadecimal(inteiro, hexadecimal);
    return hexadecimal;
}

// Função para exibir um número binário
void exibirBinario(int *binario, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d", binario[i]);
    }
    printf("b");
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
            diferenca += 2; // Corrigindo o empréstimo
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
    char entrada[9]; // Para ler até 8 dígitos binários ou "-1"

    while (1) {
        int sair = 1;
        printf("Informe o PRIMEIRO número binário ou -1 para encerrar: ");
        scanf("%s", entrada);

        if (strcmp(entrada, "-1") == 0) {
            break;
        }

        for (int i = 0; i < 8; i++) {
            num1[i] = entrada[i] - '0'; // Converte char para int
        }

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
        
        printf("Números binários:\n");
        exibirBinario(num1, 8);
        printf(" (%di , %sh)\n", binarioParaInteiro(num1, 8), binarioParaHexadecimal(num1, 8));
        printf("%c\n", operacao1);
        exibirBinario(num2, 8);
        printf(" (%di , %sh)\n", binarioParaInteiro(num2, 8), binarioParaHexadecimal(num2, 8));
        printf("%c\n", operacao2);
        exibirBinario(num3, 8);
        printf(" (%di , %sh)\n", binarioParaInteiro(num3, 8), binarioParaHexadecimal(num3, 8));
        printf("=\n");
        exibirBinario(resultado, 8);
        printf(" (%di , %sh)\n", binarioParaInteiro(resultado, 8), binarioParaHexadecimal(resultado, 8));
    }

    return 0;
}
