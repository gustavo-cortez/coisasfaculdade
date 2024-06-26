#include <stdio.h>
#include <stdlib.h>

// Estrutura para um nó da lista encadeada
struct sequen {
    int num;
    struct sequen* prox;
};

typedef struct sequen seq;

// Função para inserir um elemento no final de uma lista encadeada
void insere(seq** lista, int item) {
    seq* p, * q, * nova;
    p = *lista;
    q = NULL;
    nova = (seq*)malloc(sizeof(seq));
    if (nova != NULL) {
        nova->num = item;
        nova->prox = NULL;
        if (*lista != NULL) {
            p = *lista;
            while (p != NULL) {
                q = p;
                p = q->prox;
            }
            q->prox = nova;
        } else {
            *lista = nova;
        }
    }
}
// Função para inserir um elemento em ordem não decrescente em uma lista encadeada
void insereNaoDecrescente(seq** lista, int item) {
    seq* nova = (seq*)malloc(sizeof(seq));
    nova->num = item;
    nova->prox = NULL;

    seq* atual = *lista;
    seq* anterior = NULL;

    while (atual != NULL && atual->num <= item) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        nova->prox = *lista;
        *lista = nova;
    } else {
        anterior->prox = nova;
        nova->prox = atual;
    }
}

// Função para inserir um elemento em ordem não crescente em uma lista encadeada
void insereNaoCrescente(seq** lista, int item) {
    seq* nova = (seq*)malloc(sizeof(seq));
    nova->num = item;
    nova->prox = NULL;

    seq* atual = *lista;
    seq* anterior = NULL;

    while (atual != NULL && atual->num >= item) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) {
        nova->prox = *lista;
        *lista = nova;
    } else {
        anterior->prox = nova;
        nova->prox = atual;
    }
}

// Função para imprimir os elementos de uma lista encadeada
void mostra(seq* lista) {
    seq* p;
    while(lista != NULL){
        p = lista;
        printf("%d ", p->num);
        lista = lista->prox;
    }
}

// Função para separar os números pares e ímpares em listas diferentes
void separa(seq** lista, seq** pares, seq** impares) {
    seq* p = *lista;
    seq* q = NULL;
    while (p != NULL) {
        if (p->num % 2 == 0) {
            insereNaoDecrescente(pares, p->num);
        } else {
            insereNaoCrescente(impares, p->num);
        }
        q = p;
        p = q->prox;
    }
}

// Função principal
int main() {
    seq* lista = NULL;
    seq* pares = NULL;
    seq* impares = NULL;

    int n, num;

    printf("Quantos números deseja inserir? ");
    scanf("%d", &n);

    printf("Digite os números:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insere(&lista, num);
    }

    separa(&lista, &pares, &impares);

    printf("Lista com todos os elementos: ");
    mostra(lista);
    printf("\n");

    printf("Lista com números pares ordenados não decrescentemente: ");
    mostra(pares);
    printf("\n");

    printf("Lista com números ímpares ordenados não crescentemente: ");
    mostra(impares);
    printf("\n");

    // Libera a memória alocada para os nós das listas
    while (lista != NULL) {
        seq* temp = lista;
        lista = lista->prox;
        free(temp);
    }
    while (pares != NULL) {
        seq* temp = pares;
        pares = pares->prox;
        free(temp);
    }
    while (impares != NULL) {
        seq* temp = impares;
        impares = impares->prox;
        free(temp);
    }

    return 0;
}
