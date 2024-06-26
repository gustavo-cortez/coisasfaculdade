#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para converter um número binário de 8 bits para inteiro
int binarioParaInteiro(char *binario) {
    int inteiro = 0;
    for (int i = 0; i < 8; i++) {
        inteiro = inteiro * 2 + (binario[i] - '0');
    }
    return inteiro;
}

// Função para realizar a soma entre dois números binários
char *somarBinarios(char *binario1, char *binario2) {
    int inteiro1 = binarioParaInteiro(binario1);
    int inteiro2 = binarioParaInteiro(binario2);
    int resultado = inteiro1 + inteiro2;

    // Converter o resultado de volta para binário
    char *resultadoBinario = (char *)malloc(9);
    for (int i = 7; i >= 0; i--) {
        resultadoBinario[i] = (resultado % 2) + '0';
        resultado /= 2;
    }
    resultadoBinario[8] = '\0';

    return resultadoBinario;
}

// Função principal
int main() {
    char primeiro[9], segundo[9], terceiro[9];
    char operacao1, operacao2;

    while (1) {
        printf("Digite o PRIMEIRO número binário (ou -1 para encerrar): ");
        scanf("%s", primeiro);

        if (strcmp(primeiro, "-1") == 0) {
            printf("Programa encerrado.\n");
            break;
        }

        printf("Digite a operação (+ ou -): ");
        scanf(" %c", &operacao1);

        printf("Digite o SEGUNDO número binário: ");
        scanf("%s", segundo);

        printf("Digite a operação (+ ou -): ");
        scanf(" %c", &operacao2);

        printf("Digite o TERCEIRO número binário: ");
        scanf("%s", terceiro);

        // Realizar as operações
        char *resultado1 = somarBinarios(primeiro, segundo);
        char *resultado2 = somarBinarios(resultado1, terceiro);

        // Imprimir resultados
        printf("\nResultados:\n");
        printf("%s (%di %xh) %c %s (%di %xh)\n", primeiro, binarioParaInteiro(primeiro), binarioParaInteiro(primeiro), operacao1, segundo, binarioParaInteiro(segundo), binarioParaInteiro(segundo));
        printf("%c\n", operacao2);
        printf("%s (%di %xh)\n", terceiro, binarioParaInteiro(terceiro), binarioParaInteiro(terceiro));
        printf("%s (%di %xh)\n", resultado2, binarioParaInteiro(resultado2), binarioParaInteiro(resultado2));

        free(resultado1);
        free(resultado2);
    }

    return 0;
}
