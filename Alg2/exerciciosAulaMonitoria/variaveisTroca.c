#include <stdio.h>

int main() {
    int x, y, z, temp;

    // Recebendo os valores de entrada
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    printf("Digite o valor de z: ");
    scanf("%d", &z);

    // Ordenando os valores
    if (x > y) {
        temp = x;
        x = y;
        y = temp;
    }
    if (x > z) {
        temp = x;
        x = z;
        z = temp;
    }
    if (y > z) {
        temp = y;
        y = z;
        z = temp;
    }

    // Exibindo os valores ordenados
    printf("Valores ordenados: %d, %d, %d\n", x, y, z);

    return 0;
}
