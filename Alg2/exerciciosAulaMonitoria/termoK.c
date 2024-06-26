#include <stdio.h>

int main() {
    float x, epsilon;
    printf("Digite o valor de x: ");
    scanf("%f", &x);
    printf("Digite o valor de epsilon: ");
    scanf("%f", &epsilon);

    float exponencial = 1; // Começamos com o primeiro termo da série
    float termo = 1; // Termo inicial
    int k = 1; // Começamos com k = 1
    int termos_usados = 1; // Contador para o número de termos usados

    while (termo >= epsilon) {
        termo *= x / k; // Calcula o próximo termo da série
        exponencial += termo; // Adiciona o próximo termo à exponencial
        k++; // Incrementa k
        termos_usados++; // Incrementa o contador de termos usados
    }

    printf("Valor computado de e^x: %.6f\n", exponencial);
    printf("Número total de termos usados na série: %d\n", termos_usados);

    return 0;
}
