#include <stdio.h>

int main() {
    int a, b, inicio, soma_linha_central, soma_linha_central2, total_pares;
    scanf("%d %d", &a, &b);

    inicio = 1;
    soma_linha_central = 0;
    soma_linha_central2 = 0;
    total_pares = 0;

    for (int i = 0; i < a; i++) {
        int inicio_linha = inicio;
        for (int j = 0; j < b; j++) {
            printf("%d ", inicio);
            if (inicio % 2 == 0) {
                total_pares = total_pares + 1;
            }
            if (i == a / 2) {
                soma_linha_central = soma_linha_central + inicio;
            }
            if ((a % 2 == 0 && i == a / 2 - 1) || (a % 2 == 1 && i == a / 2)) {
                soma_linha_central2 = soma_linha_central2 + inicio;
            }
            inicio=inicio + 1;
        }
        printf("\n");

        
    }

    if (a % 2 == 0) {
        printf("%d\n%d\n%d\n", soma_linha_central, soma_linha_central2, total_pares);
    } else {
        printf("%d\n%d\n", soma_linha_central, total_pares);
    }

    return 0;
}