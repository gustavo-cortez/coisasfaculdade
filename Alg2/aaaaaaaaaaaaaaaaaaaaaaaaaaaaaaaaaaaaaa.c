#include <stdio.h>

#define MAX_FILA 50

// Definição da estrutura da fila
typedef struct {
    int itens[MAX_FILA];
    int ini, fim;
} Fila;
void furafila(Fila *fila, int x) {
    // Verifica se a fila está cheia
    if (fila->ini != fila->fim && fila->fim + 1 != 50 ) {
        if (fila->ini == -1) {
            fila->ini = 0;
            fila->fim = 1;
        } else {
            fila->ini = fila->ini - 1;
            if (fila->ini < 0) {
                fila->ini = fila->ini + 50;  // 50 - 1, assumindo que o tamanho máximo é 50
            }
            fila->itens[fila->ini] = x;
        }
    } else {
        printf("Fila cheia\n");
    }
}

void imprimefila(Fila *fila) {
    printf("Conteúdo da fila: ");
    int i = fila->ini;

    while (i != fila->fim) {
        printf("%d ", fila->itens[i]);

        // Incrementa o índice e ajusta se necessário
        i = (i + 1) % MAX_FILA;
    }

    printf("\n");
}

int main() {
    // Exemplo de uso
    Fila minhaFila = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                       21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                       41, 42, 43, 44, 45, 46, 47, 48},
                      0, 48};
    imprimefila(&minhaFila);
    furafila(&minhaFila, 20);
    imprimefila(&minhaFila);
    return 0;
}