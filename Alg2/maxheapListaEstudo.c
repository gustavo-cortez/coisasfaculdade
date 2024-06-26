#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* esquerdo;
    struct No* direito;
};

typedef struct No No;

No* criaNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerdo = NULL;
    novoNo->direito = NULL;
    return novoNo;
}

void troca(int* n, int* nmaior) {
    int aux = *nmaior;
    *nmaior = *n;
    *n = aux;
}

void desce(No* raiz) {
    if (raiz == NULL) return;

    No* maior = raiz;
    No* esquerdo = raiz->esquerdo;
    No* direito = raiz->direito;

    if (esquerdo != NULL && esquerdo->valor > maior->valor) {
        maior = esquerdo;
    }

    if (direito != NULL && direito->valor > maior->valor) {
        maior = direito;
    }

    if (maior != raiz) {
        troca(&raiz->valor, &maior->valor);
        desce(maior);
    }
}

void sobe(No* no) {
    while (no != NULL && no->esquerdo != NULL && no->esquerdo->valor > no->valor) {
        troca(&no->valor, &no->esquerdo->valor);
        no = no->esquerdo;
    }
}

void constroiMaxHeap(No* raiz) {
    if (raiz == NULL) return;

    constroiMaxHeap(raiz->esquerdo);
    constroiMaxHeap(raiz->direito);

    desce(raiz);
}

void insereElemento(No** raiz, int valor) {
    No* novoNo = criaNo(valor);

    if (*raiz == NULL) {
        *raiz = novoNo;
    } else {
        // Insere na última posição
        // (para manter a propriedade de árvore completa)
        No* temp = *raiz;
        while (temp->esquerdo != NULL) {
            temp = temp->esquerdo;
        }

        if (temp->esquerdo == NULL) {
            temp->esquerdo = novoNo;
        } else {
            temp->direito = novoNo;
        }

        // Restaura a propriedade de max-heap
        sobe(novoNo);
    }
}

void imprimeArvore(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimeArvore(raiz->esquerdo);
        imprimeArvore(raiz->direito);
    }
}

void heapsort(No* raiz) {
    if (raiz == NULL) return;

    // Construir max-heap
    constroiMaxHeap(raiz);

    // Heapsort
    No* ultimo = NULL;
    while (raiz->direito != NULL) {
        // Trocar raiz com o último nó não ordenado
        troca(&raiz->valor, &ultimo->valor);

        // Remover o último nó (que agora contém o maior valor)
        No* temp = raiz;
        while (temp->direito != NULL) {
            temp = temp->direito;
        }
        free(temp);

        // Restaurar propriedade de max-heap
        desce(raiz);
    }
}

int main() {
    No* raiz = NULL;
    int n, i, valor;

    printf("Informe o número de elementos na árvore:\n");
    scanf("%d", &n);

    printf("Informe os elementos:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &valor);
        insereElemento(&raiz, valor);
    }

    printf("Árvore antes da construção do max-heap:\n");
    imprimeArvore(raiz);
    printf("\n");

    constroiMaxHeap(raiz);

    printf("Árvore após a construção do max-heap:\n");
    imprimeArvore(raiz);

    heapsort(raiz);

    printf("Árvore após o heapsort:\n");
    imprimeArvore(raiz);
    printf("\n");

    return 0;
}
