#include <stdio.h>

int main() {
    int taxa, selos3 = 0, selos5 = 0, totalSelos = 0;
    
    printf("Digite o valor da taxa (em centavos): ");
    scanf("%d", &taxa);
    
    // Adiciona selos de 5 centavos até atingir o valor ou ultrapassar
    while (totalSelos + 5 <= taxa) {
        selos5++;
        totalSelos += 5;
    }
    
    // Verifica se é necessário adicionar selos de 3 centavos para completar a taxa
    while (totalSelos < taxa) {
        selos3++;
        totalSelos += 3;
    }

    // Se ultrapassou a taxa, ajusta a quantidade de selos de 5 centavos
    if (totalSelos > taxa) {
        selos3 = selos3 + 1;
        selos5 = selos5 - 1;
        totalSelos += 3;
        totalSelos -= 5;
    }
    if (totalSelos < taxa) {
        selos3 = selos3 + 2;
        selos5 = selos5 - 1;
    }
    
    printf("Número mínimo de selos de 3 centavos: %d\n", selos3);
    printf("Número mínimo de selos de 5 centavos: %d\n", selos5);
    
    return 0;
}
