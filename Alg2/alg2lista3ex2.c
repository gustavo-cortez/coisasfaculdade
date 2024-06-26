#include <stdio.h>

#define MAX 100

void inverte(int n, int v[MAX]) {
    int inicio = 0;
    int fim = n - 1;

    // Troca os elementos do vetor enquanto o índice de início for menor que o índice de fim.
    while (inicio < fim) {
        // Troca v[inicio] com v[fim]
        int temp = v[inicio];
        v[inicio] = v[fim];
        v[fim] = temp;

        // Move os índices para o próximo par de elementos.
        inicio++;
        fim--;
    }
}

int somavet(int A[], int n)
{
    if (n == 1)
        return A[0];
    else
        return somavet(A, n - 1) + A[n - 1];
}

int main() {
    int n, soma;
    printf("Digite o tamanho do vetor (n > 0): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Tamanho do vetor inválido.\n");
        return 1;
    }

    int v[MAX];

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    printf("Vetor antes da inversão:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    inverte(n, v);

    printf("\nVetor após a inversão:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    soma = somavet(v, n);

    printf("\n");
    
    printf("%d", soma);

    printf("\n");

    return 0;
}